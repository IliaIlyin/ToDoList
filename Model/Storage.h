//
// Created by Ilya on 7/31/2020.
//

#ifndef TODOLIST_MODEL_STORAGE_H_
#define TODOLIST_MODEL_STORAGE_H_
#include<unordered_map>
#include"TaskEntity.h"
#include"HashTaskID.h"
class Storage {

 public:
  bool postponeTask(std::shared_ptr<TaskEntity>  task, time_t dueDate);
  bool completeTask(std::shared_ptr<TaskEntity>  task);

 public:
  bool addTask(TaskEntity &task_entity);
  bool deleteTask(TaskEntity &task_entity);
  TaskEntity getTask(TaskEntity &task_entity);
  bool addSubTaskToParent(std::shared_ptr<TaskEntity> parent, TaskEntity &task_entity);
 private:
  std::unordered_map<TaskID, TaskEntity, HashTaskID> tasks_;
};

#endif //TODOLIST_MODEL_STORAGE_H_
