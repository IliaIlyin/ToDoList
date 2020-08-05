//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_VIEWS_DATEVIEW_H_
#define TODOLIST_VIEWS_DATEVIEW_H_
#include "GeneralView.h"

#include <map>
#include <vector>
#include <memory>
#include <ctime>

class DateView : public GeneralView {
 public:
  std::vector<std::weak_ptr<TaskEntity>> showAll() override;
  std::vector<std::weak_ptr<TaskEntity>> showToday() override;
  std::vector<std::weak_ptr<TaskEntity>> showDueDate(time_t date) override;
 public:
  void clean() override;
  bool insert(std::shared_ptr<TaskEntity> taskEntity) override;
 private:
  std::multimap<time_t, std::weak_ptr<TaskEntity> > dates;
};

#endif //TODOLIST_VIEWS_DATEVIEW_H_
