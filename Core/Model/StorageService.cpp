//
// Created by Ilya on 8/1/2020.
//

#include "StorageService.h"

bool StorageService::deleteTask(const TaskID &task_entity) {
  return storage_->deleteTask(task_entity);
}

std::optional<std::shared_ptr<TaskEntity>> StorageService::getTask(const TaskID &id) {
  return storage_->getTask(id);
}

std::shared_ptr<TaskEntity> StorageService::addTask(Task &task) {
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_);
  return storage_->addTask(taskEntity);
}

std::optional<std::shared_ptr<TaskEntity>> StorageService::addSubTaskToParent(const TaskID &parent, Task &task) {
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_);
  auto it = storage_->getTask(parent);
  if (it.has_value()) {
    auto iter = it.value();
    iter.operator*().addSubTask(std::make_shared<TaskEntity>(taskEntity));
    return storage_->addTask(iter.operator*());
  }
  return nullptr;
}

bool StorageService::postponeTask(const TaskID &task, boost::gregorian::date dueDate) {
  auto r = storage_->getTask(task);
  if (r.has_value()) {
    auto iter = r.value();
    Task t = Task::createTask(r->operator*().getTask().getName(),
                              dueDate,
                              r->operator*().getTask().getPriority(), r->operator*().getTask().getLabel());

    TaskEntity taskEntity(t, r->operator*().getTaskId(), r->operator*().checkStatus(),
                          r->operator*().getSubTasks());

    this->deleteTask(r->operator*().getTaskId());
    storage_->addTask(taskEntity);
    return true;
  }
  return false;
}

bool StorageService::completeTask(const TaskID &task) {
  auto r = storage_->getTask(task);
  if (r.has_value()) {
    auto it = r.value().operator*();
    it.completeTask();
    auto vec = it.getSubTasks();
    for (auto i = vec.begin(); i != vec.end(); i++) {
      i->get()->completeTask();
    }
    storage_->addTask(it);
    return true;
  }
  return false;
}

std::optional<std::vector<std::shared_ptr<TaskEntity>>> StorageService::getSubTasks(const TaskID &id) {
  auto f = storage_->getTask(id);
  if (f.has_value()) {
    return f.value()->getSubTasks();
  }
  return std::nullopt;
}
StorageService::StorageService(std::unique_ptr<StorageInterface> interface) : storage_(std::move(interface)) {}

std::vector<std::shared_ptr<TaskEntity>> StorageService::getAllTasks() {
  return storage_->getAllTasks();
}
std::shared_ptr<TaskEntity> StorageService::addTask(Task &task, bool status) {
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_,status);
  return storage_->addTask(taskEntity);
}
std::optional<std::shared_ptr<TaskEntity>> StorageService::addSubTaskToParent(const TaskID &parent,
                                                                              Task &task,
                                                                              bool status) {
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, this->id_generator_,status);
  auto it = storage_->getTask(parent);
  if (it.has_value()) {
    auto iter = it.value();
    iter.operator*().addSubTask(std::make_shared<TaskEntity>(taskEntity));
    return storage_->addTask(iter.operator*());
  }
  return nullptr;
}

