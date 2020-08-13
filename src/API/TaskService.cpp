//
// Created by Ilya on 5/20/2020
//

#include "TaskService.h"

#include <utility>

bool TaskService::postponeTask(TaskDTO &task, boost::gregorian::date date) {
  TaskEntity entity = dto_convertor_.convert(task);
  return storage_.postponeTask(entity, date);
}

bool TaskService::addTask(std::string taskName, boost::gregorian::date date, Task::Priority priority, std::string label) {
    if(taskName=="" || date.day()<=0 || date.day()>31 || date.month()<1 || date.month()>12)
        return false;
  return storage_.addTask(taskName, date, priority, label);
}

bool TaskService::deleteTask(TaskDTO &task) {
  TaskEntity entity = dto_convertor_.convert(task);
  return storage_.deleteTask(entity);
}

bool TaskService::completeTask(TaskDTO &task) {
  TaskEntity entity = dto_convertor_.convert(task);
  return storage_.completeTask(entity);
}

bool TaskService::addSubTaskToParent(TaskDTO &parent, std::string taskName, boost::gregorian::date date,
                                     Task::Priority priority,
                                     std::string label) {
  TaskEntity entity = dto_convertor_.convert(parent);
  if (storage_.addSubTaskToParent(entity, taskName, date, priority, label).has_value())
    return true;
  return false;
}

bool TaskService::addTask(Task &task) {
  return storage_.addTask(task);
}

bool TaskService::addSubTaskToParent(TaskDTO &parent, Task &task) {
  TaskEntity entity = dto_convertor_.convert(parent);
  if (storage_.addSubTaskToParent(entity, task).has_value())
    return true;
  return false;
}

std::vector<TaskDTO> TaskService::showAllByPriority() {
  auto service=storage_.getViewService();
  return dto_convertor_.convert(service.showAllByPriority());
}

std::vector<TaskDTO> TaskService::showAllByLabel() {
  auto service=storage_.getViewService();
  return dto_convertor_.convert(service.showAllByLabel());
}

std::vector<TaskDTO> TaskService::showAllByDate() {
  auto service=storage_.getViewService();
  return dto_convertor_.convert(service.showAllByDate());
}

std::vector<TaskDTO> TaskService::showTodayByPriority() {
  auto service=storage_.getViewService();
  return dto_convertor_.convert(service.showTodayByPriority());
}

std::vector<TaskDTO> TaskService::showTodayByLabel() {
  auto service=storage_.getViewService();
  return dto_convertor_.convert(service.showTodayByLabel());
}

std::vector<TaskDTO> TaskService::showDueDateByPriority(boost::gregorian::date date) {
  auto service=storage_.getViewService();
  return dto_convertor_.convert(service.showDueDateByPriority(date));
}

std::vector<TaskDTO> TaskService::showDueDateByLabel(boost::gregorian::date date) {
  auto service=storage_.getViewService();
  return dto_convertor_.convert(service.showDueDateByLabel(date));
}

std::vector<TaskDTO> TaskService::showDueDateByDate(boost::gregorian::date date) {
  auto service=storage_.getViewService();
  return dto_convertor_.convert(service.showDueDateByDate(date));
}

std::optional<std::vector<TaskDTO>> TaskService::getSubtasks(TaskID id) {
  auto it = storage_.getSubtasks(id);
  if (it.has_value()) {
    std::vector<std::shared_ptr<TaskEntity>> vector=it.value();
    return dto_convertor_.convert(vector);
  }
  return std::nullopt;
}

std::optional<TaskDTO> TaskService::getTask(TaskID id) {
  auto it = storage_.getTask(id);
  if (it.has_value()) {
    std::shared_ptr<TaskEntity> ptr = it.value();
    return dto_convertor_.convert(ptr.operator*());
  }
  return std::nullopt;
}





