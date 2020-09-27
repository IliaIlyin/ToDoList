//
// Created by Ilya on 9/15/2020.
//

#include "AddTaskCommandBuilder.h"
std::shared_ptr<Command> AddTaskCommandBuilder::buildCommand(std::shared_ptr<TaskService> service) {
  InputStateMachine machine;
  InputContext context;
  std::shared_ptr<TaskNameValidator> validator=std::make_shared<TaskNameValidator>();
  if (machine.run(std::make_shared<TaskNameState>(validator), context) == GeneralInputValidator::InputToken::SUCCESS) {
    Task t = Task::createTask(context.getName(), context.getDate(), context.getPriority(), context.getLabel());
    return std::make_shared<AddTaskCommand>(service, t);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
