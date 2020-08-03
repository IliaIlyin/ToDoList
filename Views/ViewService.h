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
  bool cleanPrioritiesWithCertainPriority(Task::Priority priority); //deletes null ptrs from priorities
  bool cleanDatesWithCertainDate(time_t date);//deletes null ptrs from dates
  bool cleanLabelsWithCertainLabel(std::string label); //deletes null ptrs from labels
 private:
  std::vector<std::unique_ptr<GeneralView>> general_view_;

};

#endif //TODOLIST_VIEWS_VIEWSERVICE_H_
