//
// Created by illia.ilin on 9/3/2020.
//

#include "ShowAllByPriorityCommand.h"
ShowAllByPriorityCommand::ShowAllByPriorityCommand(std::shared_ptr<TaskService> service) : service_(service){

}
std::vector<TaskDTO> ShowAllByPriorityCommand::execute() {
  return service_->showAllByPriority();
}
void ShowAllByPriorityCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitShowAllByPriorityCommand(*this);
}
