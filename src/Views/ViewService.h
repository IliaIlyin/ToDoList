//
// Created by Ilya on 8/3/2020.
//

#ifndef TODOLIST_VIEWS_VIEWSERVICE_H_
#define TODOLIST_VIEWS_VIEWSERVICE_H_
#include "GeneralView.h"
#include "LabelView.h"
#include "PriorityView.h"
#include "DateView.h"
#include <vector>
#include <memory>

class ViewService {

 public:
  ViewService();

 public:

  std::vector<std::weak_ptr<TaskEntity>> showAllByPriority();
  std::vector<std::weak_ptr<TaskEntity>> showAllByLabel();
  std::vector<std::weak_ptr<TaskEntity>> showAllByDate();
  std::vector<std::weak_ptr<TaskEntity>> showTodayByPriority();
  std::vector<std::weak_ptr<TaskEntity>> showTodayByLabel();
  std::vector<std::weak_ptr<TaskEntity>> showDueDateByPriority(time_t date);
  std::vector<std::weak_ptr<TaskEntity>> showDueDateByLabel(time_t date);
  std::vector<std::weak_ptr<TaskEntity>> showDueDateByDate(time_t date);

 public:

  void clean();
  bool insert(std::shared_ptr<TaskEntity> taskEntity);

 private:
  std::vector<std::unique_ptr<GeneralView>> general_view_;

};

#endif //TODOLIST_VIEWS_VIEWSERVICE_H_
