//
// Created by Ilya on 9/15/2020.
//

#include "DeleteTaskCommandBuilder.h"
std::shared_ptr<Command> DeleteTaskCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  if (machine_->run()
      == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    TaskID id = context.getId();
    return std::make_shared<DeleteTaskCommand>(service, id);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
DeleteTaskCommandBuilder::DeleteTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine)
    : machine_(std::move(machine)) {

}
