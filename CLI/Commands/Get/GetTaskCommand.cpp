//
// Created by illia.ilin on 8/28/2020.
//

#include "GetTaskCommand.h"

GetTaskCommand::GetTaskCommand(std::shared_ptr<CoreAPIInterface> service, const TaskID &id)
    : service_(service), id_(id) {
}

void GetTaskCommand::execute() {
  getTaskCommandResult_ = service_->getTask(id_);
}

void GetTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitGetTaskCommand(*this);
}
const std::optional<TaskDTO> &GetTaskCommand::GetGetTaskCommandResult() const {
  return getTaskCommandResult_;
}

