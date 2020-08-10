//
// Created by Ilya on 7/30/2020.
//

#include "LabelView.h"

std::vector<std::weak_ptr<TaskEntity> > LabelView::showDueDate(boost::gregorian::date date) {
    std::vector<std::weak_ptr<TaskEntity> > vector;
    for (auto i = labels.begin(); i != labels.end(); i++) {
        auto t = i->second.lock()->getTask().getDate();
        if (t < date) {
            vector.push_back(i->second);
        }
    }
    return vector;
}

std::vector<std::weak_ptr<TaskEntity> > LabelView::showToday() {
    std::vector<std::weak_ptr<TaskEntity> > vector;
    for (auto i = labels.begin(); i != labels.end(); i++) {
        auto tmp = boost::gregorian::day_clock::local_day();
        if (tmp == i->second.lock()->getTask().getDate()) {
            vector.push_back(i->second);
        }
    }
    return vector;

}

std::vector<std::weak_ptr<TaskEntity> > LabelView::showAll() {
    std::vector<std::weak_ptr<TaskEntity> > vector;
    for (auto i = labels.begin(); i != labels.end(); i++)
        vector.push_back(i->second);
    return vector;
}

void LabelView::clean() {
    for (auto i = labels.begin(); i != labels.end(); i++) {
        if (!(i->second.lock()))
            labels.erase(i);
    }
}

bool LabelView::insert(std::shared_ptr<TaskEntity> taskEntity) {
    labels.insert(std::pair<std::string, std::weak_ptr<TaskEntity> >
                          (taskEntity.operator*().getTask().getLabel(), taskEntity));
    return true;
}


