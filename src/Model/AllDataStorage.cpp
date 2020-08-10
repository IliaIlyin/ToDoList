//
// Created by Ilya on 8/3/2020.
//

#include "AllDataStorage.h"

std::optional<std::shared_ptr<TaskEntity>> AllDataStorage::addSubTaskToParent(TaskEntity &parent, Task &task) {
    return storage_service_.addSubTaskToParent(parent, task);
}

bool
AllDataStorage::addTask(std::string taskName, boost::gregorian::date date, Task::Priority priority, std::string label) {
    auto it = storage_service_.addTask(taskName, date, priority, label);
    view_service_.insert(it);
    return true;
}

std::optional<std::shared_ptr<TaskEntity>> AllDataStorage::addSubTaskToParent(TaskEntity &parent,
                                                                              std::string taskName,
                                                                              boost::gregorian::date date,
                                                                              Task::Priority priority,
                                                                              std::string label) {
    return storage_service_.addSubTaskToParent(parent, taskName, date, priority, label);
}

bool AllDataStorage::addTask(Task &task) {
    auto it = storage_service_.addTask(task);
    view_service_.insert(it);
    return true;
}

std::optional<std::shared_ptr<TaskEntity>> AllDataStorage::getTask(TaskID id) {
    return storage_service_.getTask(id);
}

bool AllDataStorage::postponeTask(TaskEntity &task, boost::gregorian::date dueDate) {
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

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showDueDateByPriority(boost::gregorian::date date) {
    return view_service_.showDueDateByPriority(date);
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showDueDateByLabel(boost::gregorian::date date) {
    return view_service_.showDueDateByLabel(date);
}

std::vector<std::weak_ptr<TaskEntity> > AllDataStorage::showDueDateByDate(boost::gregorian::date date) {
    return view_service_.showDueDateByDate(date);
}

std::optional<std::vector<std::shared_ptr<TaskEntity>>> AllDataStorage::getSubtasks(TaskID id) {
    return storage_service_.getSubtasks(id);
}





