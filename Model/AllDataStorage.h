//
// Created by Ilya on 8/3/2020.
//

#ifndef TODOLIST_MODEL_ALLDATASTORAGE_H_
#define TODOLIST_MODEL_ALLDATASTORAGE_H_
#include"../Views/ViewService.h"
#include"StorageService.h"
class AllDataStorage {
 public:
  bool addTask(std::string taskName, time_t date = 0,
               Task::Priority priority = Task::Priority::NONE, std::string label = "");
  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent, std::string taskName, time_t date = 0,
                          Task::Priority priority = Task::Priority::NONE, std::string label = "");
  bool addTask(Task &task);
  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent, Task &task);
  std::optional<std::shared_ptr<TaskEntity>> getTask(TaskEntity &task_entity);

 public:
  bool postponeTask(TaskEntity &task, time_t dueDate);
  bool deleteTask(TaskEntity &task);
  bool completeTask(TaskEntity &task);


 public:
  std::vector<std::weak_ptr<TaskEntity> > showAllByPriority();
  std::vector<std::weak_ptr<TaskEntity> > showAllByLabel();
  std::vector<std::weak_ptr<TaskEntity> > showAllByDate();
  std::vector<std::weak_ptr<TaskEntity> > showTodayByPriority();
  std::vector<std::weak_ptr<TaskEntity> > showTodayByLabel();
  std::vector<std::weak_ptr<TaskEntity> > showDueDateByPriority(time_t date);
  std::vector<std::weak_ptr<TaskEntity> > showDueDateByLabel(time_t date);
  std::vector<std::weak_ptr<TaskEntity> > showDueDateByDate(time_t date);



 private:
  ViewService view_service_;
  StorageService storage_service_;
};

#endif //TODOLIST_MODEL_ALLDATASTORAGE_H_
