//
// Created by Ilya on 7/30/2020.
//

#include "TaskDTO.h"

const TaskID &TaskDTO::getTaskId() const {
  return taskID;
}

bool TaskDTO::checkStatus() const {
  return status;
}

TaskDTO::TaskDTO(const Task &task, const TaskID &id, bool status) : task((task)),
                                                                    taskID(id), status(status) {
}

const Task &TaskDTO::getTask() const {
  return task;
}

TaskDTO::TaskDTO(const Task &task, IdGenerator &idGenerator) : task(task),
                                                               taskID(idGenerator.generateId()) {
  this->status = false;
}

TaskDTO TaskDTO::createTaskDTO(const Task &task, IdGenerator &idGenerator) {
  return TaskDTO(task, idGenerator);
}

bool TaskDTO::operator==(const TaskDTO &t) const {
  return this->getTaskId().getId() == t.getTaskId().getId();
}
