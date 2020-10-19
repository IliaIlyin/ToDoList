//
// Created by Ilya on 9/15/2020.
//

#include "CompleteTaskCommandBuilder.h"
std::shared_ptr<Command> CompleteTaskCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  if (machine_->run()
      == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    TaskID id = context.getId();
    return std::make_shared<CompleteTaskCommand>(service, id);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
CompleteTaskCommandBuilder::CompleteTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine) : machine_(
    std::move(machine)) {

}
