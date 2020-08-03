//
// Created by Ilya on 7/31/2020.
//

#include "Storage.h"
bool Storage::addTask(TaskEntity &task_entity) {
  tasks_.insert_or_assign(task_entity.getTaskId(), task_entity);
  return true;
}
bool Storage::deleteTask(TaskEntity &task_entity) {
  tasks_.erase(task_entity.getTaskId());
  return true;
}
TaskEntity Storage::getTask(TaskEntity &task_entity) {
  return tasks_.find(task_entity.getTaskId())->second;
}

