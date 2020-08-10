//
// Created by Ilya on 5/20/2020.
//

#include "TaskEntity.h"

TaskEntity::TaskEntity(const Task &task, IdGenerator &idGenerator) : task(task),
                                                                     taskID(idGenerator.generateId()) {
    this->subtasks = std::vector<std::shared_ptr<TaskEntity> >();
    this->status = false;
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
    for (auto i = subtasks.begin(); i != subtasks.end(); i++) {
        i->operator*().completeTask();
    }
}

void TaskEntity::addsubtask(std::shared_ptr<TaskEntity> taskEntity) {
    this->subtasks.push_back(taskEntity);
}

bool TaskEntity::operator==(const TaskEntity &t) const {
    return this->getTaskId().getId() == t.getTaskId().getId();
}

TaskEntity::TaskEntity(const Task &task, const TaskID &id, bool status,
                       const std::vector<std::shared_ptr<TaskEntity>> &subtasks) : task((task)),
                                                                                   taskID(id), status(status),
                                                                                   subtasks(subtasks) {
}

TaskEntity TaskEntity::createTaskEntity(const Task &task, IdGenerator &idGenerator) {
    return TaskEntity(task, idGenerator);
}

const Task &TaskEntity::getTask() const {
    return task;
}

