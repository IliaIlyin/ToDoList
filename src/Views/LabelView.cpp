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
  auto it = labels.begin();
  if (it == labels.end()) {
    return;
  }
  for (++it; it != labels.end(); it++) {
    auto prv = std::prev(it);
    if (!(prv->second.lock())) {
      labels.erase(prv);
    }
  }
  auto prv = std::prev(it);
  if (!(prv->second.lock())) {
    labels.erase(prv);
  }
}

bool LabelView::insert(std::shared_ptr<TaskEntity> taskEntity) {
  auto vec=labels.equal_range(taskEntity->getTask().getLabel());
  for(auto i=vec.first;i!=vec.second;i++){
    if(i->second.lock()==taskEntity)
      return false;
  }
    labels.insert(std::pair<std::string, std::weak_ptr<TaskEntity> >
                          (taskEntity.operator*().getTask().getLabel(), taskEntity));
    return true;
}


