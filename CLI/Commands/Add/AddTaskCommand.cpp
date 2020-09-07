//
// Created by illia.ilin on 8/28/2020.
//

#include "AddTaskCommand.h"

bool AddTaskCommand::execute() {
  return service_->addTask(parent_);
}
AddTaskCommand::AddTaskCommand(std::shared_ptr<TaskService> service, const Task &parent)
    : service_(service), parent_(parent) {
}
void AddTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitAddTaskCommand(*this);
}

