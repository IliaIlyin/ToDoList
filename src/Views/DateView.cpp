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

std::vector<std::weak_ptr<TaskEntity> > DateView::showDueDate(time_t date) {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  auto aTime = gmtime(&date);
  int day = aTime->tm_mday;
  int year = aTime->tm_year;
  int month = aTime->tm_mon;
  for (auto i = dates.begin(); i != dates.end(); i++) {
    time_t t = i->second.lock()->getTask().getDate();
    auto tmp = gmtime(&t);
    if (tmp->tm_mday < day && tmp->tm_year < year && tmp->tm_mon < month) {
      vector.push_back(i->second);
    }
  }
  return vector;
}

std::vector<std::weak_ptr<TaskEntity>> DateView::showToday() {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  time_t theTime = time(NULL);
  auto aTime = localtime(&theTime);
  int day = aTime->tm_mday;
  int year = aTime->tm_year;
  int month = aTime->tm_mon;
  for (auto i = dates.begin(); i != dates.end(); i++) {
    time_t t = i->second.lock()->getTask().getDate();
    auto tmp = gmtime(&t);
    if (tmp->tm_mday == day && tmp->tm_year == year && tmp->tm_mon == month) {
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
  dates.insert(std::pair<time_t, std::weak_ptr<TaskEntity> >
                   (taskEntity.operator*().getTask().getDate(), taskEntity));
  return true;
}

