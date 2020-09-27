//
// Created by Ilya on 8/3/2020.
//

#include "AllDataStorage.h"

std::optional<std::shared_ptr<TaskEntity>> AllDataStorage::addSubTaskToParent(const TaskID &parent, Task &task) {
  auto result = storage_service_->addSubTaskToParent(parent, task);
  return result;
}

bool AllDataStorage::addTask(Task &task) {
  auto it = storage_service_->addTask(task);
  view_service_.insert(it);
  return true;
}

std::optional<std::shared_ptr<TaskEntity>> AllDataStorage::getTask(const TaskID &id) {
  return storage_service_->getTask(id);
}

bool AllDataStorage::postponeTask(const TaskID &task, boost::gregorian::date dueDate) {
  storage_service_->postponeTask(task, dueDate);
  return true;
}

bool AllDataStorage::deleteTask(const TaskID &task) {
  storage_service_->deleteTask(task);
  view_service_.clean();
  return true;
}

bool AllDataStorage::completeTask(const TaskID &task) {
  return storage_service_->completeTask(task);
}

std::optional<std::vector<std::shared_ptr<TaskEntity>>> AllDataStorage::getSubTasks(const TaskID &id) {
  return storage_service_->getSubTasks(id);
}
const ViewService &AllDataStorage::getViewService() const {
  return view_service_;
}
AllDataStorage::AllDataStorage(std::unique_ptr<StorageServiceInterface> interface) : storage_service_(std::move(
    interface)) {
  std::shared_ptr<PriorityView> priority = std::make_shared<PriorityView>();
  std::shared_ptr<DateView> dates = std::make_shared<DateView>();
  std::shared_ptr<LabelView> labels = std::make_shared<LabelView>();
  view_service_ = ViewService(priority, labels, dates);
}





