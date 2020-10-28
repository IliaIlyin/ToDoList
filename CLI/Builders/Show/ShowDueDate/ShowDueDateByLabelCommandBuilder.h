//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_SHOW_SHOWDUEDATE_SHOWDUEDATEBYLABELCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_SHOW_SHOWDUEDATE_SHOWDUEDATEBYLABELCOMMANDBUILDER_H_

#include "Builder.h"
#include "InputStateMachine.h"
#include "Validators/InputValidators/DateValidator.h"
#include "States/InputDataStates/TaskDateState.h"
#include "Commands/CancelCommand.h"
#include "Commands/Show/ShowDueDate/ShowDueDateByLabelCommand.h"

class ShowDueDateByLabelCommandBuilder : public Builder {
 public:
  std::shared_ptr<Command> buildCommand(std::shared_ptr<ClientInterface> service) override;
 public:
  ShowDueDateByLabelCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine);
 private:
  std::unique_ptr<InputStateMachineInterface> machine_;
};

#endif //TODOLIST_CLI_BUILDERS_SHOW_SHOWDUEDATE_SHOWDUEDATEBYLABELCOMMANDBUILDER_H_
