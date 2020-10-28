//
// Created by ilya on 11.10.20.
//

#include "SaveCommandBuilder.h"
std::shared_ptr<Command> SaveCommandBuilder::buildCommand(std::shared_ptr<ClientInterface> service) {
  if (machine_->run() == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    std::string fileName = context.getLabel();
    return std::make_shared<SaveCommand>(service, fileName);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
SaveCommandBuilder::SaveCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine)
    : machine_(std::move(machine)) {

}
