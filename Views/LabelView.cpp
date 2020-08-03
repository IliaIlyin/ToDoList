//
// Created by Ilya on 7/30/2020.
//

#include "LabelView.h"
std::vector<std::weak_ptr<TaskEntity> > LabelView::showDueDate(time_t date) {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  auto aTime = gmtime(&date);
  int day = aTime->tm_mday;
  int year = aTime->tm_year;
  int month = aTime->tm_mon;
  for (auto i = labels.begin(); i != labels.end(); i++) {
    time_t t = i->second.lock()->getTask().getDate();
    auto tmp = gmtime(&t);
    if (tmp->tm_mday < day && tmp->tm_year < year && tmp->tm_mon < month) {
      vector.push_back(i->second);
    }
  }
  return vector;
}

std::vector<std::weak_ptr<TaskEntity> > LabelView::showToday() {
  std::vector<std::weak_ptr<TaskEntity> > vector;
  time_t theTime = time(NULL);
  auto aTime = localtime(&theTime);
  int day = aTime->tm_mday;
  int year = aTime->tm_year;
  int month = aTime->tm_mon;
  for (auto i = labels.begin(); i != labels.end(); i++) {
    time_t t = i->second.lock()->getTask().getDate();
    auto tmp = gmtime(&t);
    if (tmp->tm_mday == day && tmp->tm_year == year && tmp->tm_mon == month) {
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


