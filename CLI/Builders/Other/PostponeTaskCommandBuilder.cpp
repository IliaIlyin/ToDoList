//
// Created by Ilya on 9/14/2020.
//

#include "PostponeTaskCommandBuilder.h"

std::shared_ptr<Command> PostponeTaskCommandBuilder::buildCommand(std::shared_ptr<TaskService> service) {
  InputContext context;
  std::shared_ptr<TaskIdValidator> validator=std::make_shared<TaskIdValidator>();
  std::shared_ptr<TaskIdState<TaskDateState<ExitState, ExitValidator>, DateValidator>>
      begin = std::make_shared<TaskIdState<TaskDateState<ExitState, ExitValidator>, DateValidator>>(validator);
  InputStateMachine machine;
  if (machine.run(begin, context) == GeneralInputValidator::InputToken::SUCCESS) {
    TaskID id(context.getId());
    boost::gregorian::date date(context.getDate());
    return std::make_shared<PostponeTaskCommand>(service, id, date);
  } else {
    return std::make_shared<CancelCommand>();
  }
}

