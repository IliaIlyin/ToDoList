//
// Created by ilya on 17.10.20.
//

#include "InputStateMachineCreator.h"
std::unique_ptr<InputStateMachineInterface> InputStateMachineCreator::create(const std::shared_ptr<InputState> &begin, InputContext &context) {
  return std::make_unique<InputStateMachine>(begin, context);
}
