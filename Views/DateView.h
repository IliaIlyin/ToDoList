//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_VIEWS_DATEVIEW_H_
#define TODOLIST_VIEWS_DATEVIEW_H_
#include"../Display/Display.h"
#include"../Model/HashTaskEntity.h"
#include"../Model/TaskEntity.h"
#include"../Model/IdGenerator.h"

#include<map>
#include<vector>
#include<memory>
#include <ctime>



class DateView {
 public:
  std::vector<std::weak_ptr<TaskEntity> > showAllByDate();
  std::vector<std::weak_ptr<TaskEntity> > showDueDateByDate(time_t date);
 private:
  std::multimap<time_t,std::weak_ptr<TaskEntity> > dates;
};

#endif //TODOLIST_VIEWS_DATEVIEW_H_
