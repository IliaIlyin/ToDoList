//
// Created by ilya on 04.10.20.
//

#include "CoreAPI.h"

//
// Created by Ilya on 5/20/2020
//

#include "CoreAPI.h"

bool CoreAPI::postponeTask(const TaskID &task, boost::gregorian::date date) {
  return service_->postponeTask(task, date);
}

bool CoreAPI::addTask(std::string taskName,
                      boost::gregorian::date date,
                      Task::Priority priority,
                      std::string label) {
  return service_->addTask(taskName, date, priority, label);
}

bool CoreAPI::deleteTask(const TaskID &task) {
  return service_->deleteTask(task);
}

bool CoreAPI::completeTask(const TaskID &task) {
  return service_->completeTask(task);
}

bool CoreAPI::addSubTaskToParent(const TaskID &parent, std::string taskName, boost::gregorian::date date,
                                 Task::Priority priority,
                                 std::string label) {
  return service_->addSubTaskToParent(parent, taskName, date, priority, label);
}

bool CoreAPI::addTask(Task &task) {
  return service_->addTask(task);
}

bool CoreAPI::addSubTaskToParent(const TaskID &parent, Task &task) {
  return service_->addSubTaskToParent(parent, task);
}

std::vector<TaskDTO> CoreAPI::showAllByPriority() {
  auto service = service_->showAllByPriority();
  return dtoConvertor::convert(service);
}

std::vector<TaskDTO> CoreAPI::showAllByLabel() {
  auto service = service_->showAllByLabel();
  return dtoConvertor::convert(service);
}

std::vector<TaskDTO> CoreAPI::showAllByDate() {
  auto service = service_->showAllByDate();
  return dtoConvertor::convert(service);
}

std::vector<TaskDTO> CoreAPI::showTodayByPriority() {
  auto service = service_->showTodayByPriority();
  return dtoConvertor::convert(service);
}

std::vector<TaskDTO> CoreAPI::showTodayByLabel() {
  auto service = service_->showTodayByLabel();
  return dtoConvertor::convert(service);
}

std::vector<TaskDTO> CoreAPI::showDueDateByPriority(boost::gregorian::date date) {
  auto service = service_->showDueDateByPriority(date);
  return dtoConvertor::convert(service);
}

std::vector<TaskDTO> CoreAPI::showDueDateByLabel(boost::gregorian::date date) {
  auto service = service_->showDueDateByLabel(date);
  return dtoConvertor::convert(service);
}

std::vector<TaskDTO> CoreAPI::showDueDateByDate(boost::gregorian::date date) {
  auto service = service_->showDueDateByDate(date);
  return dtoConvertor::convert(service);
}

std::optional<std::vector<TaskDTO>> CoreAPI::getSubTasks(const TaskID &id) {
  auto it = service_->getSubTasks(id);
  if (it.has_value()) {
    std::vector<std::shared_ptr<TaskEntity>> vector = it.value();
    return dtoConvertor::convert(vector);
  }
  return std::nullopt;
}

std::optional<TaskDTO> CoreAPI::getTask(const TaskID &id) {
  auto it = service_->getTask(id);
  if (it.has_value()) {
    return dtoConvertor::convert(it.value());
  }
  return std::nullopt;
}

bool CoreAPI::save(std::string fileName) {
  return service_->save(fileName);
}
bool CoreAPI::load(std::string fileName) {
  return service_->load(fileName);
}
CoreAPI CoreAPI::create() {
  auto factory = std::make_shared<AllDataStorageFactory>();
  return CoreAPI(std::make_unique<TaskService>(factory));
}
CoreAPI::CoreAPI(std::unique_ptr<TaskServiceInterface> service) : service_(std::move(service)) {
}


