//
// Created by Ilya on 7/31/2020.
//

#include "Storage.h"

std::shared_ptr<TaskEntity> Storage::addTask(const TaskEntity &task_entity) {
  if (tasks_.count(task_entity.getTaskId()) == 1) {
    auto ptr = tasks_.find(task_entity.getTaskId());
    return ptr->second;
  } else {
    auto it = tasks_.insert(std::make_pair(task_entity.getTaskId(), std::make_shared<TaskEntity>(task_entity)));
    return it.first->second;
  }
}

bool Storage::deleteTask(const TaskID &task_entity) {
  return tasks_.erase(task_entity);
}

std::optional<std::shared_ptr<TaskEntity>> Storage::getTask(TaskID id) {
  for (auto i = tasks_.begin(); i != tasks_.end(); i++) {
    if (i->second->getTaskId() == id) {
      return i->second;
    } else {
      std::optional<std::shared_ptr<TaskEntity>> result = search(id, i->second->getSubTasks());
      if (result.has_value())
        return result;
    }
  }
  return std::nullopt;
}

std::optional<std::shared_ptr<TaskEntity>> Storage::search(TaskID id, std::vector<std::shared_ptr<TaskEntity>> vector) {
  for (auto i = vector.begin(); i != vector.end(); i++) {
    if (i->operator*().getTaskId() == id) {
      return *i;
    } else {
      std::optional<std::shared_ptr<TaskEntity>> result = search(id, i->operator*().getSubTasks());
      if (result.has_value())
        return result;
    }
  }
  return std::nullopt;
}

std::vector<std::shared_ptr<TaskEntity>> Storage::getAllTasks() {
  std::vector<std::shared_ptr<TaskEntity>> result;
  for (auto i = tasks_.begin(); i != tasks_.end(); i++) {
    result.push_back(i->second);
  }
  return result;
}


