//
// Created by Ilya on 7/30/2020.
//

#include "PriorityView.h"

std::vector<std::weak_ptr<TaskEntity> > PriorityView::showDueDate(boost::gregorian::date date) {
  std::vector<std::weak_ptr<TaskEntity> > vector;

  for (auto i = priorities.begin(); i != priorities.end(); i++) {
    auto t = i->second.lock()->getTask().getDate();
    if (t < date) {
      vector.push_back(i->second);
    }
  }
  return vector;
}

std::vector<std::weak_ptr<TaskEntity> > PriorityView::showToday() {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  for (auto i = priorities.begin(); i != priorities.end(); i++) {
    auto tmp = boost::gregorian::day_clock::local_day();
    if (tmp == i->second.lock()->getTask().getDate()) {
      vector.push_back(i->second);
    }
  }
  return vector;
}

std::vector<std::weak_ptr<TaskEntity> > PriorityView::showAll() {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  for (auto i = priorities.begin(); i != priorities.end(); i++)
    vector.push_back(i->second);
  return vector;
}

void PriorityView::clean() {
  auto it = priorities.begin();
  if (it == priorities.end()) {
    return;
  }
  for (++it; it != priorities.end(); it++) {
    auto prv = std::prev(it);
    if (!(prv->second.lock())) {
      priorities.erase(prv);
    }
  }
  auto prv = std::prev(it);
  if (!(prv->second.lock())) {
    priorities.erase(prv);
  }
}

bool PriorityView::insert(std::shared_ptr<TaskEntity> taskEntity) {
  auto vec=priorities.equal_range(taskEntity->getTask().getPriority());
  for(auto i=vec.first;i!=vec.second;i++){
    if(i->second.lock()==taskEntity)
      return false;
  }
  priorities.insert(std::pair<Task::Priority, std::weak_ptr<TaskEntity> >
                        (taskEntity.operator*().getTask().getPriority(), taskEntity));
  return true;
}

