//
// Created by Ilya on 5/20/2020.
//

#include "TaskEntity.h"

TaskEntity::TaskEntity(const Task &task, IdGenerator &idGenerator) : task_(task),
                                                                     taskID_(idGenerator.generateId()) {
    this->SubTasks_ = std::vector<std::shared_ptr<TaskEntity> >();
    this->status_ = false;
}

const TaskID &TaskEntity::getTaskId() const {
    return taskID_;
}

bool TaskEntity::checkStatus() const {
    return status_;
}

const std::vector<std::shared_ptr<TaskEntity>> &TaskEntity::getSubTasks() const {
    return SubTasks_;
}

void TaskEntity::completeTask() {
    this->status_ = true;
    for (auto i = SubTasks_.begin(); i != SubTasks_.end(); i++) {
        i->operator*().completeTask();
    }
}

void TaskEntity::addSubTask(std::shared_ptr<TaskEntity> taskEntity) {
    this->SubTasks_.push_back(taskEntity);
}

TaskEntity::TaskEntity(const Task &task, const TaskID &id, bool status_,
                       const std::vector<std::shared_ptr<TaskEntity>> &SubTasks) : task_((task)),
                                                                                   taskID_(id), status_(status_),
                                                                                   SubTasks_(SubTasks) {
}

TaskEntity TaskEntity::createTaskEntity(const Task &task, IdGenerator &idGenerator) {
    return TaskEntity(task, idGenerator);
}

const Task &TaskEntity::getTask() const {
    return task_;
}

bool operator==(const TaskEntity &t, const TaskEntity &t2) {
  return t2.getTaskId().getId() == t.getTaskId().getId();
}
