//
// Created by illia.ilin on 8/31/2020.
//

#include "ShowAllByLabelCommand.h"
ShowAllByLabelCommand::ShowAllByLabelCommand(std::shared_ptr<ClientInterface> service) : service_(service) {

}
void ShowAllByLabelCommand::execute() {
  commandResult_ = service_->showAllByLabel();

}
void ShowAllByLabelCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitShowAllByLabelCommand(*this);
}
std::vector<TaskDTO> ShowAllByLabelCommand::getCommandResult() {
  return commandResult_;
}
