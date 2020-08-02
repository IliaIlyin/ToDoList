//
// Created by Ilya on 8/1/2020.
//

#include "StorageService.h"

bool StorageService::addTask(std::string taskName, time_t date, Task::Priority priority, std::string label) {
  Task task = Task::createTask(std::move(taskName), date, priority, std::move(label));
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_);
  return storage_.addTask(taskEntity);
}

bool StorageService::deleteTask(TaskEntity &task_entity) {
  return storage_.deleteTask(task_entity);
}

bool StorageService::completeTask(TaskEntity &task) {
  return storage_.completeTask(task);
}

bool StorageService::addSubTaskToParent(TaskEntity &parent, std::string taskName, time_t date,
                                        Task::Priority priority,
                                        std::string label) {
  Task t = Task::createTask(std::move(taskName), date, priority, std::move(label));
  TaskEntity taskEntity = TaskEntity::createTaskEntity(t, this->id_generator_);
  return storage_.addSubTaskToParent(parent, taskEntity);
}

TaskEntity StorageService::getTask(TaskEntity &task_entity) {
  return storage_.getTask(task_entity);
}

bool StorageService::addTask(Task &task) {
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_);
  return storage_.addTask(taskEntity);
}

bool StorageService::addSubTaskToParent(TaskEntity &parent, Task &task) {
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_);
  return storage_.addSubTaskToParent(parent, taskEntity);
}
bool StorageService::postponeTask(TaskEntity &task, time_t dueDate) {
  return storage_.postponeTask(task, dueDate);
}
