//
// Created by Ilya on 8/3/2020.
//

#include "AllDataStorage.h"

std::optional<std::shared_ptr<TaskEntity>> AllDataStorage::addSubTaskToParent(TaskEntity &parent, Task &task) {
  return storage_service_.addSubTaskToParent(parent, task);
}

bool AllDataStorage::addTask(std::string taskName, time_t date, Task::Priority priority, std::string label) {
  auto it = storage_service_.addTask(taskName, date, priority, label);
  view_service_.insert(it);
  return true;
}

std::optional<std::shared_ptr<TaskEntity>> AllDataStorage::addSubTaskToParent(TaskEntity &parent,
                                                                              std::string taskName,
                                                                              time_t date,
                                                                              Task::Priority priority,
                                                                              std::string label) {
  return storage_service_.addSubTaskToParent(parent, taskName, date, priority, label);
}

bool AllDataStorage::addTask(Task &task) {
  auto it = storage_service_.addTask(task);
  view_service_.insert(it);
  return true;
}

std::optional<std::shared_ptr<TaskEntity>> AllDataStorage::getTask(TaskEntity &task_entity) {
  return storage_service_.getTask(task_entity);
}

bool AllDataStorage::postponeTask(TaskEntity &task, time_t dueDate) {
  storage_service_.postponeTask(task, dueDate);
  return true;
}

bool AllDataStorage::deleteTask(TaskEntity &task) {
  storage_service_.deleteTask(task);
  view_service_.clean();
  return true;
}

bool AllDataStorage::completeTask(TaskEntity &task) {
  return storage_service_.completeTask(task);
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showAllByPriority() {
  return view_service_.showAllByPriority();
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showAllByLabel() {
  return view_service_.showAllByLabel();
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showAllByDate() {
  return view_service_.showAllByDate();
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showTodayByPriority() {
  return view_service_.showTodayByPriority();
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showTodayByLabel() {
  return view_service_.showTodayByLabel();
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showDueDateByPriority(time_t date) {
  return view_service_.showDueDateByPriority(date);
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showDueDateByLabel(time_t date) {
  return view_service_.showDueDateByLabel(date);
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showDueDateByDate(time_t date) {
  return view_service_.showDueDateByDate(date);
}





