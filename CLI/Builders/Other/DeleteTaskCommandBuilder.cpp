//
// Created by Ilya on 9/15/2020.
//

#include "DeleteTaskCommandBuilder.h"
std::shared_ptr<Command> DeleteTaskCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  InputStateMachine machine;
  InputContext context;
  std::shared_ptr<TaskIdValidator> validator=std::make_shared<TaskIdValidator>();
  if (machine.run(std::make_shared<TaskIdState<ExitState, ExitValidator>>(validator), context)
      == GeneralInputValidator::InputToken::SUCCESS) {
    TaskID id = context.getId();
    return std::make_shared<DeleteTaskCommand>(service, id);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
