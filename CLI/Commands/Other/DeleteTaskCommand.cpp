//
// Created by illia.ilin on 8/31/2020.
//

#include "DeleteTaskCommand.h"
DeleteTaskCommand::DeleteTaskCommand(std::shared_ptr<CoreAPIInterface> service, const TaskID &id)
    : service_(service), id_(id) {
}

void DeleteTaskCommand::execute() {
  deleteTaskCommandResult_ = service_->deleteTask(id_);
}

void DeleteTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitDeleteTaskCommand(*this);
}
bool DeleteTaskCommand::IsDeleteTaskCommandResult() const {
  return deleteTaskCommandResult_;
}


