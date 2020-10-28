//
// Created by Ilya on 9/15/2020.
//

#include "AddSubTaskCommandBuilder.h"

std::shared_ptr<Command> AddSubTaskCommandBuilder::buildCommand(std::shared_ptr<ClientInterface> service) {
  if (machine_->run()
      == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    Task t = Task::createTask(context.getName(), context.getDate(), context.getPriority(), context.getLabel());
    TaskID id = context.getId();
    return std::make_shared<AddSubTaskCommand>(service, id, t);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
AddSubTaskCommandBuilder::AddSubTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine)
    : machine_(std::move(machine)) {}
