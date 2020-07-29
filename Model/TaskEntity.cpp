//
// Created by Ilya on 5/20/2020.
//

#include "TaskEntity.h"

TaskEntity::TaskEntity(const Task &task, IdGenerator &idGenerator) : task(std::make_shared<Task>(task)),
                                                                     taskID(idGenerator.generateId()) {
    this->subtasks = std::vector<std::shared_ptr<TaskEntity> >();
    this->status = false;
}

std::shared_ptr<Task> &TaskEntity::getTask() {
    return task;
}

const TaskID &TaskEntity::getTaskId() const {
    return taskID;
}

bool TaskEntity::checkStatus() const {
    return status;
}

const std::vector<std::shared_ptr<TaskEntity>> &TaskEntity::getSubtasks() const {
    return subtasks;
}

void TaskEntity::completeTask() {
    this->status = true;
}

void TaskEntity::addsubtask(std::shared_ptr<TaskEntity> taskEntity) {
    this->subtasks.push_back(taskEntity);
}

TaskEntity::TaskEntity(TaskEntity &entity, TaskID taskId) : taskID(taskId) {
    this->subtasks.push_back(std::make_shared<TaskEntity>(entity));
}

bool TaskEntity::operator==(const TaskEntity &t) const {
    return this->getTaskId().getId() == t.getTaskId().getId();
}

TaskEntity::TaskEntity(const Task &task, const TaskID &id, bool status,
                       const std::vector<std::shared_ptr<TaskEntity>> &subtasks) : task(std::make_shared<Task>(task)),
                                                                                   taskID(id), status(status),
                                                                                   subtasks(subtasks) {
}

TaskEntity TaskEntity::createTaskEntity(const Task &task, IdGenerator &idGenerator) {
    return TaskEntity(task,idGenerator);
}

