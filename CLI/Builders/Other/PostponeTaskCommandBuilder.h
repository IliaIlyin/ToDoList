//
// Created by Ilya on 9/14/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_OTHER_POSTPONETASKCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_OTHER_POSTPONETASKCOMMANDBUILDER_H_
#include "Builder.h"
#include "Commands/CancelCommand.h"
#include "InputStateMachine.h"
#include "Validators/InputValidators/TaskIdValidator.h"
#include "Validators/InputValidators/DateValidator.h"
#include "States/InputDataStates/TaskIdState.h"
#include "Validators/InputValidators/ExitValidator.h"
#include "States/InputDataStates/TaskDateState.h"
#include "Commands/CancelCommand.h"
#include "Commands/Other/PostponeTaskCommand.h"

class PostponeTaskCommandBuilder : public Builder {
 public:
  std::shared_ptr<Command> buildCommand(std::shared_ptr<CoreAPIInterface> service) override;
 public:
  PostponeTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine);
 private:
  std::unique_ptr<InputStateMachineInterface> machine_;
};

#endif //TODOLIST_CLI_BUILDERS_OTHER_POSTPONETASKCOMMANDBUILDER_H_
