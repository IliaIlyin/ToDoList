//
// Created by illia.ilin on 8/31/2020.
//

#include "GetSubtasksCommand.h"
GetSubTaskCommand::GetSubTaskCommand(std::shared_ptr<TaskService> service, const TaskID &id) : service_(service),id_(id){

}
std::optional<std::vector<TaskDTO>> GetSubTaskCommand::execute() {
  return service_->getSubTasks(id_);
}
void GetSubTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitGetSubTaskCommand(*this);
}
