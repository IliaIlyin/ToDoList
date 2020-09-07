//
// Created by illia.ilin on 9/3/2020.
//

#include "Commands/Show/ShowAll/ShowAllByDateCommand.h"
ShowAllByDateCommand::ShowAllByDateCommand(std::shared_ptr<TaskService> service) : service_(service){

}
std::vector<TaskDTO> ShowAllByDateCommand::execute() {
  return service_->showAllByDate();
}
void ShowAllByDateCommand::accept(std::shared_ptr<Visitor> v) {
v->visitShowAllByDateCommand(*this);
}
