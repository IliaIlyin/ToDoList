//
// Created by ilya on 25.10.20.
//

#ifndef TODOLIST_TESTS_CLI_MOCKS_INPUTSTATEMACHINECREATORMOCK_H_
#define TODOLIST_TESTS_CLI_MOCKS_INPUTSTATEMACHINECREATORMOCK_H_
#include "Utils/InputStateMachineCreatorInterface.h"
#include <gmock/gmock.h>

class InputStateMachineCreatorMock : public InputStateMachineCreatorInterface {
 public:
  MOCK_METHOD(std::unique_ptr<InputStateMachineInterface>, create, (const std::shared_ptr<InputState> &begin,
      InputContext &context,
      std::shared_ptr<IOStreamInterface> outputer), (override));
};
#endif //TODOLIST_TESTS_CLI_MOCKS_INPUTSTATEMACHINECREATORMOCK_H_
