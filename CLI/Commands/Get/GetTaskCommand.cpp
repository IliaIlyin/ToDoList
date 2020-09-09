//
// Created by illia.ilin on 8/28/2020.
//

#include "GetTaskCommand.h"
std::optional<TaskDTO> GetTaskCommand::execute() {
  return service_->getTask(id_);
}
GetTaskCommand::GetTaskCommand(std::shared_ptr<TaskService> service, const TaskID &id) : service_(service),id_(id){
}
void GetTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitGetTaskCommand(*this);
}
