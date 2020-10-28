//
// Created by ilya on 11.10.20.
//

#ifndef TODOLIST_CLI_BUILDERS_SERIALIZE_SAVECOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_SERIALIZE_SAVECOMMANDBUILDER_H_

#include "Builder.h"
#include "InputStateMachine.h"
#include "Commands/CancelCommand.h"
#include "Commands/Serialize/SaveCommand.h"
#include "States/InputDataStates/TaskLabelState.h"
#include "Validators/InputValidators/LabelValidator.h"

class SaveCommandBuilder : public Builder {
 public:
  std::shared_ptr<Command> buildCommand(std::shared_ptr<ClientInterface> service) override;
 public:
  SaveCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine);
 private:
  std::unique_ptr<InputStateMachineInterface> machine_;
};

#endif //TODOLIST_CLI_BUILDERS_SERIALIZE_SAVECOMMANDBUILDER_H_
