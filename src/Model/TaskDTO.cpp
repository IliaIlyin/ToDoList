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

TaskDTO::TaskDTO(const Task &task, IdGenerator &idGenerator) : task(task),
                                                               taskID(idGenerator.generateId()) {
  this->subtasks = std::vector<std::shared_ptr<TaskDTO> >();
  this->status = false;
}

TaskDTO TaskDTO::createTaskDTO(const Task &task, IdGenerator &idGenerator) {
  return TaskDTO(task, idGenerator);
}

void TaskDTO::addsubtask(std::shared_ptr<TaskDTO> TaskDTO) {
  this->subtasks.push_back(TaskDTO);
}

bool TaskDTO::operator==(const TaskDTO &t) const {
  return this->getTaskId().getId() == t.getTaskId().getId();
}
