//
// Created by ilya on 25.10.20.
//

#ifndef TODOLIST_TESTS_CLI_MOCKS_STATEMOCK_H_
#define TODOLIST_TESTS_CLI_MOCKS_STATEMOCK_H_
#include "States/State.h"
#include <gmock/gmock.h>
class StateMock : public State {
 public:

  MOCK_METHOD(GeneralCommandsValidator::CommandToken, read, (std::shared_ptr<IOStreamInterface> inputer), (override));

  MOCK_METHOD(std::shared_ptr<State>, changeState, (), (override));

  MOCK_METHOD(void, execute, (std::shared_ptr<Command> command, std::shared_ptr<Visitor> visitor), (override));

  MOCK_METHOD(void, print, (std::shared_ptr<Context> context, std::shared_ptr<IOStreamInterface> printer), (override));
};

#endif //TODOLIST_TESTS_CLI_MOCKS_STATEMOCK_H_
