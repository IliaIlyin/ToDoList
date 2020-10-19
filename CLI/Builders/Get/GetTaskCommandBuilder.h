//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_GET_GETTASKCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_GET_GETTASKCOMMANDBUILDER_H_
#include "Builder.h"
#include "InputStateMachine.h"
#include "Validators/InputValidators/TaskIdValidator.h"
#include "States/InputDataStates/TaskIdState.h"
#include "Commands/CancelCommand.h"
#include "Commands/Get/GetTaskCommand.h"
#include "States/InputDataStates/ExitState.h"
#include "Validators/InputValidators/ExitValidator.h"
class GetTaskCommandBuilder : public Builder {
 public:
  std::shared_ptr<Command> buildCommand(std::shared_ptr<CoreAPIInterface> service) override;
 public:
  GetTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine);
 private:
  std::unique_ptr<InputStateMachineInterface> machine_;
};

#endif //TODOLIST_CLI_BUILDERS_GET_GETTASKCOMMANDBUILDER_H_
