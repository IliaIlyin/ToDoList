//
// Created by ilya on 17.10.20.
//

#ifndef TODOLIST_CLI_UTILS_INPUTSTATEMACHINECREATORINTERFACE_H_
#define TODOLIST_CLI_UTILS_INPUTSTATEMACHINECREATORINTERFACE_H_
#include "InputStateMachine.h"
class InputStateMachineCreatorInterface{
 public:
  virtual std::unique_ptr<InputStateMachineInterface> create(const std::shared_ptr<InputState> &begin, InputContext &context)=0;
  virtual ~InputStateMachineCreatorInterface()=default;
};
#endif //TODOLIST_CLI_UTILS_INPUTSTATEMACHINECREATORINTERFACE_H_
