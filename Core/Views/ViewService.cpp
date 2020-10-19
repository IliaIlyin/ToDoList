//
// Created by Ilya on 8/3/2020.
//

#include "ViewService.h"

void ViewService::clean() {
  priority_view_->clean();
  label_view_->clean();
  date_view_->clean();
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showAllByPriority() {
  return priority_view_->showAll();
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showAllByLabel() {
  return label_view_->showAll();
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showAllByDate() {
  return date_view_->showAll();
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showTodayByPriority() {
  return priority_view_->showToday();
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showTodayByLabel() {
  return label_view_->showToday();
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showDueDateByPriority(boost::gregorian::date date) {
  return priority_view_->showDueDate(date);
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showDueDateByLabel(boost::gregorian::date date) {
  return label_view_->showDueDate(date);
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showDueDateByDate(boost::gregorian::date date) {
  return  date_view_->showDueDate(date);
}

bool ViewService::insert(std::shared_ptr<TaskEntity> taskEntity) {
  priority_view_->insert(taskEntity);
  label_view_->insert(taskEntity);
  date_view_->insert(taskEntity);
  return true;
}
ViewService::ViewService(std::shared_ptr<GeneralView> priority_view_,
                         std::shared_ptr<GeneralView> label_view_,
                         std::shared_ptr<GeneralView> date_view_) :
    priority_view_(std::move(priority_view_)),
    label_view_(std::move(label_view_)),
    date_view_(std::move(date_view_)) {}



