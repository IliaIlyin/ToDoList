//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_VIEWS_LABELVIEW_H_
#define TODOLIST_VIEWS_LABELVIEW_H_
#include"../Display/Display.h"
#include"../Model/HashTaskEntity.h"
#include"../Model/TaskEntity.h"
#include"../Model/IdGenerator.h"

#include<map>
#include<vector>
#include<memory>
#include <ctime>
class LabelView {
 public:
  std::vector<std::weak_ptr<TaskEntity> > showAllByLabel();
  std::vector<std::weak_ptr<TaskEntity> > showTodayByLabel();
  std::vector<std::weak_ptr<TaskEntity> > showDueDateByLabel(time_t date);
 private:
  std::multimap<std::string,std::weak_ptr<TaskEntity> > labels;
};

#endif //TODOLIST_VIEWS_LABELVIEW_H_
