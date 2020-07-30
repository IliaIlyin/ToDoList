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

const std::vector<std::shared_ptr<TaskDTO>> &TaskDTO::getSubtasks() const {
  return subtasks;
}

TaskDTO::TaskDTO(const Task &task, const TaskID &id, bool status,
                       const std::vector<std::shared_ptr<TaskDTO>> &subtasks) : task((task)),
                                                                                   taskID(id), status(status),
                                                                                   subtasks(subtasks) {
}


const Task &TaskDTO::getTask() const {
  return task;
}