//
// Created by Ilya on 7/31/2020.
//

#ifndef TODOLIST_MODEL_STORAGE_H_
#define TODOLIST_MODEL_STORAGE_H_
#include"TaskEntity.h"
#include"HashTaskID.h"

#include<optional>
#include<unordered_map>

class Storage {

 public:
  std::shared_ptr<TaskEntity> addTask(TaskEntity &task_entity);
  bool deleteTask(TaskEntity &task_entity);
  std::optional<std::shared_ptr<TaskEntity>> getTask(TaskID id);
  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubtasks(TaskID id);

 private:
  std::optional<std::shared_ptr<TaskEntity>> search(TaskID id, std::vector<std::shared_ptr<TaskEntity>> vector);
 private:
  std::unordered_map<TaskID, std::shared_ptr<TaskEntity>, HashTaskID> tasks_;
};

#endif //TODOLIST_MODEL_STORAGE_H_
