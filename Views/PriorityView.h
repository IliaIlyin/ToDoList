//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_VIEWS_PRIORITYVIEW_H_
#define TODOLIST_VIEWS_PRIORITYVIEW_H_
#include"../Display/Display.h"
#include"../Model/HashTaskEntity.h"
#include"../Model/TaskEntity.h"
#include"../Model/IdGenerator.h"

#include<map>
#include<vector>
#include<memory>
#include <ctime>

class PriorityView {
 public:

  std::vector<std::weak_ptr<TaskEntity> > showAllByPriority();
  std::vector<std::weak_ptr<TaskEntity> > showTodayByPriority();
  std::vector<std::weak_ptr<TaskEntity> > showDueDateByPriority(time_t date);
 private:
  std::multimap<Task::Priority, std::weak_ptr<TaskEntity> > priorities;
};

#endif //TODOLIST_VIEWS_PRIORITYVIEW_H_
