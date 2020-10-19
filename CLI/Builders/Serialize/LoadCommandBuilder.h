//
// Created by ilya on 11.10.20.
//

#ifndef TODOLIST_CLI_BUILDERS_SERIALIZE_LOADCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_SERIALIZE_LOADCOMMANDBUILDER_H_

#include "Builder.h"
#include "InputStateMachine.h"
#include "Commands/CancelCommand.h"
#include "Commands/Serialize/LoadCommand.h"
#include "States/InputDataStates/TaskLabelState.h"
#include "Validators/InputValidators/LabelValidator.h"

class LoadCommandBuilder : public Builder {
 public:
  std::shared_ptr<Command> buildCommand(std::shared_ptr<CoreAPIInterface> service) override;
 public:
  LoadCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine);
 private:
  std::unique_ptr<InputStateMachineInterface> machine_;
};

#endif //TODOLIST_CLI_BUILDERS_SERIALIZE_LOADCOMMANDBUILDER_H_
