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

bool StorageService::addSubTaskToParent(TaskEntity &parent, std::string taskName, time_t date,
                                        Task::Priority priority,
                                        std::string label) {
  Task t = Task::createTask(std::move(taskName), date, priority, std::move(label));
  TaskEntity taskEntity = TaskEntity::createTaskEntity(t, this->id_generator_);
  return this->addSubTaskToParent(parent, taskEntity);
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
  return this->addSubTaskToParent(parent, taskEntity);
}

bool StorageService::addSubTaskToParent(TaskEntity &parent, TaskEntity &task_entity) {
  auto iter = storage_.getTask(parent);
  iter.addsubtask(std::make_shared<TaskEntity>(task_entity));
  storage_.addTask(iter);
  return true;
}

bool StorageService::postponeTask(TaskEntity &task, time_t dueDate) {
  auto iter = storage_.getTask(task);
  Task t = Task::createTask(task.getTask().getName(),
                            dueDate + task.getTask().getDate(),
                            task.getTask().getPriority(), task.getTask().getLabel());

  TaskEntity taskEntity(t, task.getTaskId(), task.checkStatus(),
                        task.getSubtasks());

  this->deleteTask(task);
  return storage_.addTask(taskEntity);
}

bool StorageService::completeTask(TaskEntity &task) {
  auto it = storage_.getTask(task);
  it.completeTask();
  auto vec = it.getSubtasks();
  for (auto i = vec.begin(); i != vec.end(); i++) {
    i->get()->completeTask();
  }
  storage_.addTask(it);
  return true;
}
