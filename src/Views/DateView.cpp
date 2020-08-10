//
// Created by Ilya on 7/30/2020.
//

#include "DateView.h"

std::vector<std::weak_ptr<TaskEntity> > DateView::showAll() {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  for (auto i = dates.begin(); i != dates.end(); i++)
    vector.push_back(i->second);
  return vector;
}

std::vector<std::weak_ptr<TaskEntity> > DateView::showDueDate(boost::gregorian::date date) {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  for (auto i = dates.begin(); i != dates.end(); i++) {
    boost::gregorian::date t = i->second.lock()->getTask().getDate();
    if (t<date) {
      vector.push_back(i->second);
    }
  }
  return vector;
}

std::vector<std::weak_ptr<TaskEntity>> DateView::showToday() {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  boost::gregorian::date today = boost::gregorian::date();
  for (auto i = dates.begin(); i != dates.end(); i++) {
    boost::gregorian::date t = i->second.lock()->getTask().getDate();
      auto tmp = boost::gregorian::day_clock::local_day();
    if (i->first==tmp) {
      vector.push_back(i->second);
    }
  }
  return vector;
}

void DateView::clean() {
  for (auto i = dates.begin(); i != dates.end(); i++) {
    if (!(i->second.lock()))
      dates.erase(i);
  }
}

bool DateView::insert(std::shared_ptr<TaskEntity> taskEntity) {
  dates.insert(std::pair<boost::gregorian::date, std::weak_ptr<TaskEntity> >
                   (taskEntity.operator*().getTask().getDate(), taskEntity));
  return true;
}

