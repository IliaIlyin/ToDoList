//
// Created by Ilya on 7/30/2020.
//

#include "TaskDTO.h"

const TaskID &TaskDTO::getTaskId() const {
  return task_id_;
}

bool TaskDTO::checkStatus() const {
  return status_;
}

TaskDTO::TaskDTO(const Task &task_, const TaskID &id, bool status_) : task_((task_)),
                                                                      task_id_(id), status_(status_) {
}

const Task &TaskDTO::getTask() const {
  return task_;
}

TaskDTO::TaskDTO(const Task &task_, IdGenerator &idGenerator) : task_(task_),
                                                                task_id_(idGenerator.generateId()) {
  this->status_ = false;
}

TaskDTO TaskDTO::createTaskDTO(const Task &task_, IdGenerator &idGenerator) {
  return TaskDTO(task_, idGenerator);
}

bool operator==(const TaskDTO &t, const TaskDTO &t2) {
  return t.getTaskId().getId() == t2.getTaskId().getId();
}
