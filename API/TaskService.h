//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKSERVICE_H
#define TODOLIST_TASKSERVICE_H

#include"../Display/Display.h"
#include"../Model/HashTaskID.h"
#include"../Model/TaskDTO.h"
#include"../Model/IdGenerator.h"
#include"../Views/LabelView.h"
#include"../Views/PriorityView.h"
#include"../Views/DateView.h"
#include"../Model/dtoConvertor.h"
#include"../Model/Storage.h"
#include"../Model/StorageService.h"
#include"../Views/ViewService.h"
#include"../Model/AllDataStorage.h"
#include<map>
#include<vector>
#include<memory>
#include<optional>

class TaskService {

 public:
  bool addTask(std::string taskName, time_t date = 0,
               Task::Priority priority = Task::Priority::NONE, std::string label = "");
  bool addSubTaskToParent(TaskDTO &parent, std::string taskName, time_t date = 0,
                          Task::Priority priority = Task::Priority::NONE, std::string label = "");
  bool addTask(Task &task);
  bool addSubTaskToParent(TaskDTO &parent, Task &task);
  std::optional<TaskDTO> getTask(TaskDTO &task_entity);

 public:
  bool postponeTask(TaskDTO &task, time_t dueDate);
  bool deleteTask(TaskDTO &task);
  bool completeTask(TaskDTO &task);

 public:
  std::vector<TaskDTO> showAllByPriority();
  std::vector<TaskDTO> showAllByLabel();
  std::vector<TaskDTO> showAllByDate();
  std::vector<TaskDTO> showTodayByPriority();
  std::vector<TaskDTO> showTodayByLabel();
  std::vector<TaskDTO> showDueDateByPriority(time_t date);
  std::vector<TaskDTO> showDueDateByLabel(time_t date);
  std::vector<TaskDTO> showDueDateByDate(time_t date);

 private:
  Display display_;
  AllDataStorage storage_;
  dtoConvertor dto_convertor_;
};

#endif //TODOLIST_TASKSERVICE_H
