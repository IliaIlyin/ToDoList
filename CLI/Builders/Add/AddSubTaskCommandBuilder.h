//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_ADD_ADDSUBTASKCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_ADD_ADDSUBTASKCOMMANDBUILDER_H_
#include "Builder.h"
#include "Validators/InputValidators/TaskIdValidator.h"
#include "Commands/Add/AddSubTaskCommand.h"
#include "Commands/CancelCommand.h"
#include "States/InputDataStates/TaskIdState.h"
#include "Utils/InputStateMachineCreatorInterface.h"
#include "InputStateMachine.h"

class AddSubTaskCommandBuilder : public Builder {
 public:
  std::shared_ptr<Command> buildCommand(std::shared_ptr<ClientInterface> service) override;
 public:
  AddSubTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine);
 private:
  std::unique_ptr<InputStateMachineInterface> machine_;

};

#endif //TODOLIST_CLI_BUILDERS_ADD_ADDSUBTASKCOMMANDBUILDER_H_
