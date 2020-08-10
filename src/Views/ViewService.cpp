//
// Created by Ilya on 8/3/2020.
//

#include "ViewService.h"

ViewService::ViewService() {
    general_view_.push_back(std::unique_ptr<LabelView>());
    general_view_.push_back(std::unique_ptr<PriorityView>());
    general_view_.push_back(std::unique_ptr<DateView>());
}

void ViewService::clean() {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        i.operator*().operator*().clean();
    }
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showAllByPriority() {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        if (dynamic_cast<std::unique_ptr<PriorityView> &>(i->operator*()))
            return i->operator*().showAll();
    }
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showAllByLabel() {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        if (dynamic_cast<std::unique_ptr<LabelView> &>(i->operator*()))
            return i->operator*().showAll();
    }
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showAllByDate() {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        if (dynamic_cast<std::unique_ptr<DateView> &>(i->operator*()))
            return i->operator*().showAll();
    }
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showTodayByPriority() {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        if (dynamic_cast<std::unique_ptr<PriorityView> &>(i->operator*()))
            return i->operator*().showToday();
    }
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showTodayByLabel() {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        if (dynamic_cast<std::unique_ptr<LabelView> &>(i->operator*()))
            return i->operator*().showToday();
    }
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showDueDateByPriority(boost::gregorian::date date) {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        if (dynamic_cast<std::unique_ptr<PriorityView> &>(i->operator*()))
            return i->operator*().showDueDate(date);
    }
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showDueDateByLabel(boost::gregorian::date date) {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        if (dynamic_cast<std::unique_ptr<LabelView> &>(i->operator*()))
            return i->operator*().showDueDate(date);
    }
}

std::vector<std::weak_ptr<TaskEntity> > ViewService::showDueDateByDate(boost::gregorian::date date) {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        if (dynamic_cast<std::unique_ptr<DateView> &>(i->operator*()))
            return i->operator*().showDueDate(date);
    }
}

bool ViewService::insert(std::shared_ptr<TaskEntity> taskEntity) {
    for (auto i = general_view_.begin(); i != general_view_.end(); i++) {
        i->operator->()->insert(taskEntity);
    }
    return true;
}

