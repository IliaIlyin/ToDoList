//
// Created by illia.ilin on 8/31/2020.
//

#include "CompleteTaskCommand.h"
CompleteTaskCommand::CompleteTaskCommand(std::shared_ptr<CoreAPIInterface> service, const TaskID &id)
    : service_(service), task_id_(id) {

}
void CompleteTaskCommand::execute() {
  completeTaskCommandResult_ = service_->completeTask(task_id_);
}

void CompleteTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitCompleteTaskCommand(*this);
}

bool CompleteTaskCommand::getCompleteTaskCommandResult() const {
  return completeTaskCommandResult_;
}

