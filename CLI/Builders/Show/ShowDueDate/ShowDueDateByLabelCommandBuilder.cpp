//
// Created by Ilya on 9/15/2020.
//

#include "ShowDueDateByLabelCommandBuilder.h"
std::shared_ptr<Command> ShowDueDateByLabelCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  InputContext context;
  InputStateMachine machine;
  std::shared_ptr<DateValidator> validator=std::make_shared<DateValidator>();;
  if(machine.run(std::make_shared<TaskDateState<ExitState,DateValidator>>(validator),context)==GeneralInputValidator::InputToken::SUCCESS){
  auto date = context.getDate();
  return std::make_shared<ShowDueDateByLabelCommand>(service,date);
  }
  else{
    return std::make_shared<CancelCommand>();
  }
}
