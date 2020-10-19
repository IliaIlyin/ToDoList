//
// Created by Ilya on 5/20/2020
//

#include "TaskService.h"

#include <utility>

bool TaskService::postponeTask(const TaskID &task, boost::gregorian::date date) {
  return storage_->postponeTask(task, date);
}

bool TaskService::addTask(std::string taskName,
                          boost::gregorian::date date,
                          Task::Priority priority,
                          std::string label) {
  if (taskName == "" || date.day() <= 0 || date.day() > 31 || date.month() < 1 || date.month() > 12)
    return false;
  Task t = Task::createTask(std::move(taskName), date, priority, std::move(label));
  return storage_->addTask(t);
}

bool TaskService::deleteTask(const TaskID &task) {
  return storage_->deleteTask(task);
}

bool TaskService::completeTask(const TaskID &task) {
  return storage_->completeTask(task);
}

bool TaskService::addSubTaskToParent(const TaskID &parent, std::string taskName, boost::gregorian::date date,
                                     Task::Priority priority,
                                     std::string label) {
  Task task = Task::createTask(std::move(taskName), date, priority, std::move(label));
  if (storage_->addSubTaskToParent(parent, task).has_value())
    return true;
  return false;
}

bool TaskService::addTask(Task &task) {
  auto res = storage_->addTask(task);
  return res;
}

bool TaskService::addSubTaskToParent(const TaskID &parent, Task &task) {
  if (storage_->addSubTaskToParent(parent, task).has_value())
    return true;
  return false;
}

std::vector<std::weak_ptr<TaskEntity>> TaskService::showAllByPriority() {
  auto service = storage_->getViewService();
  return (service->showAllByPriority());
}

std::vector<std::weak_ptr<TaskEntity>> TaskService::showAllByLabel() {
  auto service = storage_->getViewService();
  return (service->showAllByLabel());
}

std::vector<std::weak_ptr<TaskEntity>> TaskService::showAllByDate() {
  auto service = storage_->getViewService();
  return (service->showAllByDate());
}

std::vector<std::weak_ptr<TaskEntity>> TaskService::showTodayByPriority() {
  auto service = storage_->getViewService();
  return (service->showTodayByPriority());
}

std::vector<std::weak_ptr<TaskEntity>> TaskService::showTodayByLabel() {
  auto service = storage_->getViewService();
  return (service->showTodayByLabel());
}

std::vector<std::weak_ptr<TaskEntity>> TaskService::showDueDateByPriority(boost::gregorian::date date) {
  auto service = storage_->getViewService();
  return (service->showDueDateByPriority(date));
}

std::vector<std::weak_ptr<TaskEntity>> TaskService::showDueDateByLabel(boost::gregorian::date date) {
  auto service = storage_->getViewService();
  return (service->showDueDateByLabel(date));
}

std::vector<std::weak_ptr<TaskEntity>> TaskService::showDueDateByDate(boost::gregorian::date date) {
  auto service = storage_->getViewService();
  return (service->showDueDateByDate(date));
}

std::optional<std::vector<std::shared_ptr<TaskEntity>>> TaskService::getSubTasks(const TaskID &id) {
  auto it = storage_->getSubTasks(id);
  if (it.has_value()) {
    std::vector<std::shared_ptr<TaskEntity>> vector = it.value();
    return (vector);
  }
  return std::nullopt;
}

std::optional<TaskEntity> TaskService::getTask(const TaskID &id) {
  auto it = storage_->getTask(id);
  if (it.has_value()) {
    std::shared_ptr<TaskEntity> ptr = it.value();
    return (ptr.operator*());
  }
  return std::nullopt;
}
TaskService::TaskService(std::shared_ptr<AllDataStorageFactoryInterface> factory) :
    factory_(factory),
    storage_((factory->create())) {
}

bool TaskService::save(std::string fileName) {
  std::shared_ptr<std::fstream> file = std::make_shared<std::fstream>();
  file->open(fileName, std::ios::out);
  if (file->is_open()) {
    std::scoped_lock lock(mutex_);
    auto persistor = std::make_shared<Persistor>(file, storage_, factory_);
    auto res = std::async(std::bind(&Persistor::Save, persistor.operator*()));
    res.wait();
    file->close();
    return res.get();
  }
  return false;
}
bool TaskService::load(std::string fileName) {
  std::shared_ptr<std::fstream> file = std::make_shared<std::fstream>();
  file->open(fileName, std::ios::in);
  if(!file){
    std::cout<<"File not found"<<std::endl;
    return false;
  }
  if (file->is_open()) {
    std::scoped_lock lock(mutex_);
    auto persistor = std::make_shared<Persistor>(file, storage_, factory_);
    auto res = std::async(std::bind(&Persistor::Load, persistor.operator*()));
    res.wait();
    file->close();
    return res.get();
  }
  return false;
}





