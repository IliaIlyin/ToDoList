//
// Created by Ilya on 9/15/2020.
//

#include "AddTaskCommandBuilder.h"
std::shared_ptr<Command> AddTaskCommandBuilder::buildCommand(std::shared_ptr<ClientInterface> service) {
  if (machine_->run() == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    Task t = Task::createTask(context.getName(), context.getDate(), context.getPriority(), context.getLabel());
    return std::make_shared<AddTaskCommand>(service, t);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
AddTaskCommandBuilder::AddTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine) : machine_(std::move(
    machine)) {

}
