//
// Created by Ilya on 8/1/2020.
//

#include "StorageService.h"

std::shared_ptr<TaskEntity> StorageService::addTask(std::string taskName,
                                                    time_t date,
                                                    Task::Priority priority,
                                                    std::string label) {
  Task task = Task::createTask(std::move(taskName), date, priority, std::move(label));
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_);
  return storage_.addTask(taskEntity);
}

bool StorageService::deleteTask(TaskEntity &task_entity) {
  return storage_.deleteTask(task_entity);
}

std::optional<std::shared_ptr<TaskEntity>> StorageService::addSubTaskToParent(TaskEntity &parent,
                                                                              std::string taskName,
                                                                              time_t date,
                                                                              Task::Priority priority,
                                                                              std::string label) {
  Task t = Task::createTask(std::move(taskName), date, priority, std::move(label));
  TaskEntity taskEntity = TaskEntity::createTaskEntity(t, this->id_generator_);
  return this->addSubTaskToParent(parent, taskEntity);
}

std::optional<std::shared_ptr<TaskEntity>> StorageService::getTask(TaskID id) {
  return storage_.getTask(id);
}

std::shared_ptr<TaskEntity> StorageService::addTask(Task &task) {
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_);
  return storage_.addTask(taskEntity);
}

std::optional<std::shared_ptr<TaskEntity>> StorageService::addSubTaskToParent(TaskEntity &parent, Task &task) {
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_);
  return this->addSubTaskToParent(parent, taskEntity);
}

std::optional<std::shared_ptr<TaskEntity>> StorageService::addSubTaskToParent(TaskEntity &parent,
                                                                              TaskEntity &task_entity) {
  auto it = storage_.getTask(parent.getTaskId());
  if (it.has_value()) {
    auto iter = it.value();
    iter.operator*().addsubtask(std::make_shared<TaskEntity>(task_entity));
    return storage_.addTask(iter.operator*());
  }
  return nullptr;
}

bool StorageService::postponeTask(TaskEntity &task, time_t dueDate) {
  auto r = storage_.getTask(task.getTaskId());
  if (r.has_value()) {
    auto iter = r.value();
    Task t = Task::createTask(task.getTask().getName(),
                              dueDate + task.getTask().getDate(),
                              task.getTask().getPriority(), task.getTask().getLabel());

    TaskEntity taskEntity(t, task.getTaskId(), task.checkStatus(),
                          task.getSubtasks());

    this->deleteTask(iter.operator*());
    storage_.addTask(taskEntity);
    return true;
  }
  return false;
}

bool StorageService::completeTask(TaskEntity &task) {
  auto r = storage_.getTask(task.getTaskId());
  if (r.has_value()) {
    auto it = r.value().operator*();
    it.completeTask();
    auto vec = it.getSubtasks();
    for (auto i = vec.begin(); i != vec.end(); i++) {
      i->get()->completeTask();
    }
    storage_.addTask(it);
    return true;
  }
  return false;
}
std::optional<std::vector<std::shared_ptr<TaskEntity>>> StorageService::getSubtasks(TaskID id) {
  return storage_.getSubtasks(id);
}
