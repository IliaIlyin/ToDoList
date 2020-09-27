//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_GET_GETSUBTASKSCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_GET_GETSUBTASKSCOMMANDBUILDER_H_

#include "Builder.h"
#include "InputStateMachine.h"
#include "Validators/InputValidators/TaskIdValidator.h"
#include "States/InputDataStates/TaskIdState.h"
#include "States/InputDataStates/ExitState.h"
#include "Validators/InputValidators/ExitValidator.h"
#include "Commands/CancelCommand.h"
#include "Commands/Get/GetSubtasksCommand.h"
class GetSubTasksCommandBuilder : public Builder {
  std::shared_ptr<Command> buildCommand(std::shared_ptr<TaskService> service) override;
};

#endif //TODOLIST_CLI_BUILDERS_GET_GETSUBTASKSCOMMANDBUILDER_H_
