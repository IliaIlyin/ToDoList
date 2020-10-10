//
// Created by illia.ilin on 8/31/2020.
//

#include "GetSubtasksCommand.h"
GetSubTaskCommand::GetSubTaskCommand(std::shared_ptr<CoreAPIInterface> service, const TaskID &id)
    : service_(service), id_(id) {

}
void GetSubTaskCommand::execute() {
  getSubTaskCommandResult_=service_->getSubTasks(id_);

}
void GetSubTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitGetSubTaskCommand(*this);
}
const std::optional<std::vector<TaskDTO>> &GetSubTaskCommand::GetGetSubTaskCommandResult() const {
  return getSubTaskCommandResult_;
}

