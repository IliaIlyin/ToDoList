//
// Created by illia.ilin on 8/31/2020.
//

#include "CompleteTaskCommand.h"
CompleteTaskCommand::CompleteTaskCommand(std::shared_ptr<TaskService> service, const TaskID &id)
    : service_(service), task_id_(id) {

}
bool CompleteTaskCommand::execute() {
  return service_->completeTask(task_id_);
}
void CompleteTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitCompleteTaskCommand(*this);
}
