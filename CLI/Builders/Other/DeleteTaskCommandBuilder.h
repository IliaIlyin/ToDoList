//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_OTHER_DELETETASKCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_OTHER_DELETETASKCOMMANDBUILDER_H_

#include "Builder.h"
#include "InputStateMachine.h"
#include "Validators/InputValidators/TaskIdValidator.h"
#include "States/InputDataStates/TaskIdState.h"
#include "Commands/CancelCommand.h"
#include "Validators/InputValidators/ExitValidator.h"
#include "Commands/Other/DeleteTaskCommand.h"

class DeleteTaskCommandBuilder : public Builder {
 public:
  std::shared_ptr<Command> buildCommand(std::shared_ptr<ClientInterface> service) override;
 public:
  DeleteTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine);
 private:
  std::unique_ptr<InputStateMachineInterface> machine_;
};

#endif //TODOLIST_CLI_BUILDERS_OTHER_DELETETASKCOMMANDBUILDER_H_
