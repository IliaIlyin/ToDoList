//
// Created by Ilya on 7/31/2020.
//

#include "Storage.h"
std::shared_ptr<TaskEntity> Storage::addTask(TaskEntity &task_entity) {
  auto it=tasks_.insert_or_assign(task_entity.getTaskId(), std::make_shared<TaskEntity>(task_entity));
  return it.first->second;
}
bool Storage::deleteTask(TaskEntity &task_entity) {
  tasks_.erase(task_entity.getTaskId());
  return true;
}
std::shared_ptr<TaskEntity> Storage::getTask(TaskEntity &task_entity) {
  return tasks_.find(task_entity.getTaskId())->second;
}

