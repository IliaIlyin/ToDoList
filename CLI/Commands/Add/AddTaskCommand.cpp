//
// Created by illia.ilin on 8/28/2020.
//

#include "AddTaskCommand.h"


AddTaskCommand::AddTaskCommand(std::shared_ptr<TaskService> service, const Task &parent)
    : service_(service), parent_(parent) {
}

void AddTaskCommand::execute() {
  addTaskResult_ = service_->addTask(parent_);
}

bool AddTaskCommand::getAddTaskResult() const {
  return addTaskResult_;
}

void AddTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitAddTaskCommand(*this);
}

