//
// Created by ilya on 01.10.20.
//
#include "PersistorUtils.h"



std::shared_ptr<serializer::Task> serializeToTask(const Task &task) {
  serializer::Task result;
  result.set_name(task.getName());
  result.set_date(task.getDate().day_number());
  result.set_priority(convertPriority(task.getPriority()));
  result.set_label(task.getLabel());
  return std::make_shared<serializer::Task>(result);
}

std::shared_ptr<serializer::TaskEntity> serializeToTaskEntity(const TaskEntity &entity) {
  serializer::TaskEntity result;
  auto task = serializeToTask(entity.getTask());
  result.set_allocated_task(task.get());
  result.set_complete(entity.checkStatus());
  for (auto i = entity.getSubTasks().begin(); i < entity.getSubTasks().end(); i++) {
    auto subtask = result.add_subtasks();
    subtask = serializeToTaskEntity(i->operator*()).get();
  }
  return std::make_shared<serializer::TaskEntity>(result);
}

serializer::Task_Priority convertPriority(Task::Priority priority) {
  switch (priority) {
    case Task::Priority::FIRST:return serializer::Task_Priority_FIRST;
    case Task::Priority::SECOND:return serializer::Task_Priority_SECOND;
    case Task::Priority::THIRD:return serializer::Task_Priority_THIRD;
    case Task::Priority::NONE:return serializer::Task_Priority_NONE;
  }
}
Task::Priority convertPriority(serializer::Task_Priority priority) {
  switch (priority) {
    case serializer::Task_Priority_NONE:return Task::Priority::NONE;
    case serializer::Task_Priority_FIRST:return Task::Priority::FIRST;
    case serializer::Task_Priority_SECOND:return Task::Priority::SECOND;
    case serializer::Task_Priority_THIRD:return Task::Priority::THIRD;
  }
}
serializer::Storage serializeToStorage(std::vector<std::shared_ptr<TaskEntity>> vec) {
  serializer::Storage result;
  if (vec.empty())
    return result;
  else {
    for (auto i = vec.begin(); i != vec.end(); i++) {
      auto taskToAdd = result.add_tasks();
      taskToAdd = serializeToTaskEntity(i->operator*()).get();
    }
  }
  return result;
}
Task deserializeFromTask(const serializer::Task &entity) {
  return Task::createTask(entity.name(),
                          boost::gregorian::date(entity.date()),
                          convertPriority(entity.priority()),
                          entity.label());
}


