//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKSERVICE_H
#define TODOLIST_TASKSERVICE_H

#include "TaskDTO.h"
#include "Model/AllDataStorage.h"
#include "dtoConvertor.h"

#include <map>
#include <vector>
#include <memory>
#include <optional>

class TaskService {

 public:
  bool                       addTask(std::string taskName, time_t date = 0,
                                  Task::Priority priority = Task::Priority::NONE, std::string label = "");
  bool                       addSubTaskToParent(TaskDTO &parent, std::string taskName, time_t date = 0,
                                  Task::Priority priority = Task::Priority::NONE, std::string label = "");
  bool                       addTask(Task &task);
  bool                       addSubTaskToParent(TaskDTO &parent, Task &task);
  std::optional<TaskDTO>     getTask(TaskID id);
  std::optional<std::vector<TaskDTO>> getSubtasks(TaskID id);

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
  AllDataStorage  storage_;
  dtoConvertor    dto_convertor_;
};

#endif //TODOLIST_TASKSERVICE_H
