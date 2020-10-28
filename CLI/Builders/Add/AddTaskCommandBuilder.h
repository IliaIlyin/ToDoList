//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_ADD_ADDTASKCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_ADD_ADDTASKCOMMANDBUILDER_H_
#include "Builder.h"
#include "InputStateMachine.h"
#include "Commands/CancelCommand.h"
#include "Commands/Add/AddTaskCommand.h"

class AddTaskCommandBuilder : public Builder {
 public:

  std::shared_ptr<Command> buildCommand(std::shared_ptr<ClientInterface> service) override;
 public:
  AddTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine);
 private:
  std::unique_ptr<InputStateMachineInterface> machine_;
};

#endif //TODOLIST_CLI_BUILDERS_ADD_ADDTASKCOMMANDBUILDER_H_
