//
// Created by Ilya on 8/3/2020.
//

#ifndef TODOLIST_VIEWS_VIEWSERVICE_H_
#define TODOLIST_VIEWS_VIEWSERVICE_H_
#include"GeneralView.h"
#include "LabelView.h"
#include"PriorityView.h"
#include"DateView.h"
#include<vector>
#include<memory>

class ViewService {
 public:
  ViewService();
 public:
  std::vector<std::weak_ptr<TaskDTO> > showAllByPriority();
  std::vector<std::weak_ptr<TaskDTO> > showAllByLabel();
  std::vector<std::weak_ptr<TaskDTO> > showAllByDate();
  std::vector<std::weak_ptr<TaskDTO> > showTodayByPriority();
  std::vector<std::weak_ptr<TaskDTO> > showTodayByLabel();
  std::vector<std::weak_ptr<TaskDTO> > showDueDateByPriority(time_t date);
  std::vector<std::weak_ptr<TaskDTO> > showDueDateByLabel(time_t date);
  std::vector<std::weak_ptr<TaskDTO> > showDueDateByDate(time_t date);
 public:
  void clean();
 private:
  std::vector<std::unique_ptr<GeneralView>> general_view_;

};

#endif //TODOLIST_VIEWS_VIEWSERVICE_H_
