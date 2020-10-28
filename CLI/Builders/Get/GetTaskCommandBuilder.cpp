//
// Created by Ilya on 9/15/2020.
//

#include "GetTaskCommandBuilder.h"
std::shared_ptr<Command> GetTaskCommandBuilder::buildCommand(std::shared_ptr<ClientInterface> service) {
  if (machine_->run()
      == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    TaskID id = context.getId();
    return std::make_shared<GetTaskCommand>(service, id);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
GetTaskCommandBuilder::GetTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine) : machine_(std::move(
    machine)) {

}
