//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_SHOW_SHOWTODAY_SHOWTODAYBYPRIORITYCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_SHOW_SHOWTODAY_SHOWTODAYBYPRIORITYCOMMANDBUILDER_H_

#include "Builder.h"
#include "InputStateMachine.h"
#include "Validators/InputValidators/TaskIdValidator.h"
#include "States/InputDataStates/TaskIdState.h"
#include "Commands/Show/ShowToday/ShowTodayByPriorityCommand.h"
class ShowTodayByPriorityCommandBuilder : public Builder {
  std::shared_ptr<Command> buildCommand(std::shared_ptr<CoreAPIInterface> service) override;
};

#endif //TODOLIST_CLI_BUILDERS_SHOW_SHOWTODAY_SHOWTODAYBYPRIORITYCOMMANDBUILDER_H_
