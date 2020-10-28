//
// Created by ilya on 11.10.20.
//

#include "LoadCommandBuilder.h"
std::shared_ptr<Command> LoadCommandBuilder::buildCommand(std::shared_ptr<ClientInterface> service) {
  if (machine_->run() == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    std::string fileName = context.getLabel();
    return std::make_shared<LoadCommand>(service, fileName);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
LoadCommandBuilder::LoadCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine)
    : machine_(std::move(machine)) {

}
