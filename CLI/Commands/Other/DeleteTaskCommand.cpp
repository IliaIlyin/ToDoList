//
// Created by illia.ilin on 8/31/2020.
//

#include "DeleteTaskCommand.h"
DeleteTaskCommand::DeleteTaskCommand(std::shared_ptr<TaskService> service, const TaskID &id)
    : service_(service), id_(id) {
}
bool DeleteTaskCommand::execute() {
  return service_->deleteTask(id_);
}
void DeleteTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitDeleteTaskCommand(*this);
}


