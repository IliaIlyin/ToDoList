//
// Created by ilya on 17.10.20.
//

#ifndef TODOLIST_CLI_UTILS_INPUTSTATEMACHINECREATOR_H_
#define TODOLIST_CLI_UTILS_INPUTSTATEMACHINECREATOR_H_
#include "InputStateMachine.h"
#include "InputStateMachineCreatorInterface.h"
class InputStateMachineCreator : public InputStateMachineCreatorInterface{
  std::unique_ptr<InputStateMachineInterface> create( const std::shared_ptr<InputState> &begin, InputContext &context) override;
};

#endif //TODOLIST_CLI_UTILS_INPUTSTATEMACHINECREATOR_H_
