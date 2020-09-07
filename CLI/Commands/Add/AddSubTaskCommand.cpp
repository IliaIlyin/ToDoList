//
// Created by illia.ilin on 8/28/2020.
//

#include "AddSubTaskCommand.h"

bool AddSubTaskCommand::execute() {
  return service_->addSubTaskToParent(parent_, child_);
}

AddSubTaskCommand::AddSubTaskCommand(std::shared_ptr<TaskService> service, const TaskID &parent, const Task &child)
    : service_(service), parent_(parent), child_(child) {

}
void AddSubTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitAddSubTaskCommand(*this);
}

