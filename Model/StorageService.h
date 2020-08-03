//
// Created by Ilya on 8/1/2020.
//

#ifndef TODOLIST_MODEL_STORAGESERVICE_H_
#define TODOLIST_MODEL_STORAGESERVICE_H_
#include "Storage.h"
class StorageService {

 public:
  bool addTask(std::string taskName, time_t date = 0,
               Task::Priority priority = Task::Priority::NONE, std::string label = "");
  bool addSubTaskToParent(TaskEntity &parent, std::string taskName, time_t date = 0,
                          Task::Priority priority = Task::Priority::NONE, std::string label = "");
  bool addTask(Task &task);
  bool addSubTaskToParent(TaskEntity &parent, Task &task);
  bool addSubTaskToParent(TaskEntity &parent, TaskEntity &task_entity);
  TaskEntity getTask(TaskEntity &task_entity);

 public:
  bool postponeTask(TaskEntity &task, time_t dueDate);
  bool deleteTask(TaskEntity &task);
  bool completeTask(TaskEntity &task);

 private:
  Storage storage_;
  IdGenerator id_generator_;
};

#endif //TODOLIST_MODEL_STORAGESERVICE_H_
