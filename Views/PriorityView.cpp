//
// Created by Ilya on 7/30/2020.
//

#include "PriorityView.h"

std::vector<std::weak_ptr<TaskEntity> > PriorityView::showDueDate(time_t date) {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  auto aTime = gmtime(&date);
  int day = aTime->tm_mday;
  int year = aTime->tm_year;
  int month = aTime->tm_mon;
  for (auto i = priorities.begin(); i != priorities.end(); i++) {
    time_t t = i->second.lock()->getTask().getDate();
    auto tmp = gmtime(&t);
    if (tmp->tm_mday < day && tmp->tm_year < year && tmp->tm_mon < month) {
      vector.push_back(i->second);
    }
  }
  return vector;
}


std::vector<std::weak_ptr<TaskEntity> > PriorityView::showToday() {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  time_t theTime = time(NULL);
  auto aTime = localtime(&theTime);
  int day = aTime->tm_mday;
  int year = aTime->tm_year;
  int month = aTime->tm_mon;
  for (auto i = priorities.begin(); i != priorities.end(); i++) {
    time_t t = i->second.lock()->getTask().getDate();
    auto tmp = gmtime(&t);
    if (tmp->tm_mday == day && tmp->tm_year == year && tmp->tm_mon == month) {
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

bool PriorityView::cleanPrioritiesWithCertainPriority(Task::Priority priority) {
  auto iter = priorities.equal_range(priority);
  for (auto i = iter.first; i != iter.second; i++) {
    if (!(i->second.lock())) {
      priorities.erase(i);
    }
  }
  return true;
}
