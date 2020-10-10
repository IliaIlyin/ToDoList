//
// Created by ilya on 01.10.20.
//
#include "PersistorUtils.h"

protoStorage::Task serializeToTask(const Task &task) {
  protoStorage::Task result;
  result.set_name(task.getName());
  result.set_date(task.getDate().day_number());
  result.set_priority(convertPriority(task.getPriority()));
  result.set_label(task.getLabel());
  return result;
}

protoStorage::TaskEntity serializeToTaskEntity(TaskEntity &entity) {
  protoStorage::TaskEntity result;
  auto task = serializeToTask(entity.getTask());
  result.set_allocated_task(new protoStorage::Task(task));
  result.set_complete(entity.checkStatus());
  for (auto i = entity.getSubTasks().begin(); i < entity.getSubTasks().end(); i++) {
    auto subtask = result.add_subtasks();
    subtask->CopyFrom(protoStorage::TaskEntity(serializeToTaskEntity(i->operator*())));
    auto f = result.subtasks(0);
    int x = 1;
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
  return result;
}
Task deserializeFromTask(const protoStorage::Task &entity) {
  return Task::createTask(entity.name(),
                          boost::gregorian::date(entity.date()),
                          convertPriority(entity.priority()),
                          entity.label());
}


void serializeTaskEntities(const protoStorage::Storage &storage,
                                      std::shared_ptr<AllDataStorageInterface> ptr) {
  for (int i = 0; i < storage.tasks_size(); i++) {
    auto entity = storage.tasks(i);
    Task t = deserializeFromTask(entity.task());
    TaskID id = ptr->addTask(t, entity.complete());
    serializeSubTasks(entity, id, ptr);
  }
}

void serializeSubTasks(const protoStorage::TaskEntity &entity,
                                  const TaskID &id,
                                  std::shared_ptr<AllDataStorageInterface> ptr) {
  for (int i = 0; i < entity.subtasks_size(); i++) {
    auto subTask = entity.subtasks(i);
    Task t2 = deserializeFromTask(subTask.task());
    auto subTaskId = ptr->addSubTaskToParent(id, t2, subTask.complete());
    serializeSubTasks(subTask, subTaskId.value(),ptr);
  }
}
