//
// Created by Ilya on 9/15/2020.
//

#include "AddSubTaskCommandBuilder.h"

std::shared_ptr<Command> AddSubTaskCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  InputStateMachine machine;
  InputContext context;
  std::shared_ptr<TaskIdValidator> validator=std::make_shared<TaskIdValidator>();
  if(machine.run(std::make_shared<TaskIdState<TaskNameState, TaskNameValidator>>(validator), context)==GeneralInputValidator::InputToken::SUCCESS) {
    Task t = Task::createTask(context.getName(), context.getDate(), context.getPriority(), context.getLabel());
    TaskID id = context.getId();
    return std::make_shared<AddSubTaskCommand>(service, id, t);
  }
  else{
    return std::make_shared<CancelCommand>();
  }
}
