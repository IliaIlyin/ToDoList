//
// Created by ilya on 01.10.20.
//
#include <Model/dtoConvertor.h>
#include "SerializationUtils.h"
boost::gregorian::date convertDate(protoStorage::TaskDate date) {
  return boost::gregorian::date(date.date());
}
protoStorage::TaskDate convertDate(boost::gregorian::date date) {
  protoStorage::TaskDate task_date;
  task_date.set_date(date.day_number());
  return task_date;
}
coreService::TaskID convertTaskID(TaskID id) {
  coreService::TaskID task_id;
  task_id.set_id(id.getId());
  return task_id;
}
TaskID convertTaskID(coreService::TaskID id) {
  return TaskID(id.id());
}
TaskDTO convertTaskDTO(coreService::TaskDTO dto) {
  return TaskDTO(convertTask(dto.task()), convertTaskID(dto.id()), dto.complete());
}
coreService::TaskDTO convertTaskDTO(TaskDTO dto) {
  coreService::TaskDTO task_dto;
  task_dto.set_allocated_task(new protoStorage::Task(convertTask(dto.getTask())));
  task_dto.set_allocated_id(new coreService::TaskID(convertTaskID(dto.getTaskId())));
  task_dto.set_complete(dto.checkStatus());
  return task_dto;
}
coreService::TasksContainer convertTasksContainer(std::optional<std::vector<std::shared_ptr<TaskEntity>>> result) {
  coreService::TasksContainer tasks_container;
  bool f = result.has_value();
  tasks_container.set_isfound(f);
  for (auto i = result.value().begin(); i != result.value().end(); i++) {
    auto ptr = tasks_container.add_result();
    ptr->CopyFrom(convertTaskDTO(dtoConvertor::convert(i.operator*().operator*())));
  }
  return tasks_container;
}
coreService::TasksContainer convertTasksContainer(std::vector<std::weak_ptr<TaskEntity>> result) {
  coreService::TasksContainer tasks_container;
  tasks_container.set_isfound(true);
  for (auto i = result.begin(); i != result.end(); i++) {
    auto ptr = tasks_container.add_result();
    ptr->CopyFrom(convertTaskDTO(dtoConvertor::convert(i.operator*().lock().operator*())));
  }
  return tasks_container;
}
std::optional<std::vector<TaskDTO>> convertTasksContainer(coreService::TasksContainer result) {
  if (!result.isfound())
    return std::nullopt;
  std::vector<TaskDTO> vec;
  for (auto i = 0; i < result.result_size(); i++) {
    vec.push_back(convertTaskDTO(result.result(i)));
  }
  return vec;
}
coreService::GetTaskResult convertGetTaskResult(std::optional<TaskEntity> result) {
  coreService::GetTaskResult core_service_result;
  core_service_result.set_isfound(result.has_value());
  if (result.has_value())
    core_service_result.set_allocated_result(new coreService::TaskDTO(convertTaskDTO(dtoConvertor::convert(result.value()))));
  return core_service_result;
}
std::optional<TaskDTO> convertGetTaskResult(coreService::GetTaskResult result) {
  if (result.isfound())
    return TaskDTO(convertTaskDTO(result.result()));
  return std::nullopt;
}
coreService::PostponeTaskRequest convertPostponeTaskRequest(TaskID id, boost::gregorian::date date) {
  coreService::PostponeTaskRequest request;
  request.set_allocated_date(new protoStorage::TaskDate(convertDate(date)));
  request.set_allocated_id(new coreService::TaskID(convertTaskID(id)));
  return request;
}
protoStorage::Task convertTask(const Task &task) {
  protoStorage::Task result;
  result.set_name(task.getName());
  result.set_allocated_date(new protoStorage::TaskDate(convertDate(task.getDate())));
  result.set_priority(convertPriority(task.getPriority()));
  result.set_label(task.getLabel());
  return result;
}

protoStorage::TaskEntity serializeToTaskEntity(TaskEntity &entity) {
  protoStorage::TaskEntity result;
  auto task = convertTask(entity.getTask());
  result.set_allocated_task(new protoStorage::Task(task));
  result.set_complete(entity.checkStatus());
  for (auto i = entity.getSubTasks().begin(); i < entity.getSubTasks().end(); i++) {
    auto subtask = result.add_subtasks();
    subtask->CopyFrom(protoStorage::TaskEntity(serializeToTaskEntity(i->operator*())));
  }
  return result;
}

protoStorage::Task_Priority convertPriority(Task::Priority priority) {
  switch (priority) {
    case Task::Priority::FIRST:return protoStorage::Task_Priority_FIRST;
    case Task::Priority::SECOND:return protoStorage::Task_Priority_SECOND;
    case Task::Priority::THIRD:return protoStorage::Task_Priority_THIRD;
    case Task::Priority::NONE:return protoStorage::Task_Priority_NONE;
  }
}
Task::Priority convertPriority(protoStorage::Task_Priority priority) {
  switch (priority) {
    case protoStorage::Task_Priority_NONE:return Task::Priority::NONE;
    case protoStorage::Task_Priority_FIRST:return Task::Priority::FIRST;
    case protoStorage::Task_Priority_SECOND:return Task::Priority::SECOND;
    case protoStorage::Task_Priority_THIRD:return Task::Priority::THIRD;
  }
}
protoStorage::Storage serializeToStorage(std::vector<std::shared_ptr<TaskEntity>> vec) {
  protoStorage::Storage result;
  for (auto i = vec.begin(); i != vec.end(); i++) {
    auto taskToAdd = result.add_tasks();
    taskToAdd->CopyFrom(protoStorage::TaskEntity(serializeToTaskEntity(i->operator*())));
  }
  auto f = result.tasks(0);
  return result;
}
Task convertTask(const protoStorage::Task &entity) {
  return Task::createTask(entity.name(),
                          boost::gregorian::date(convertDate(entity.date())),
                          convertPriority(entity.priority()),
                          entity.label());
}

void serializeTaskEntities(const protoStorage::Storage &storage,
                           std::shared_ptr<AllDataStorageInterface> ptr) {
  for (int i = 0; i < storage.tasks_size(); i++) {
    auto entity = storage.tasks(i);
    Task t = convertTask(entity.task());
    TaskID id = ptr->addTask(t, entity.complete());
    serializeSubTasks(entity, id, ptr);
  }
}

void serializeSubTasks(const protoStorage::TaskEntity &entity,
                       const TaskID &id,
                       std::shared_ptr<AllDataStorageInterface> ptr) {
  for (int i = 0; i < entity.subtasks_size(); i++) {
    auto subTask = entity.subtasks(i);
    Task t2 = convertTask(subTask.task());
    auto subTaskId = ptr->addSubTaskToParent(id, t2, subTask.complete());
    serializeSubTasks(subTask, subTaskId.value(), ptr);
  }
}