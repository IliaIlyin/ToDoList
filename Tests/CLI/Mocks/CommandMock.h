//
// Created by ilya on 19.10.20.
//

#ifndef TODOLIST_TESTS_CLI_MOCKS_COMMANDMOCK_H_
#define TODOLIST_TESTS_CLI_MOCKS_COMMANDMOCK_H_
#include <gmock/gmock.h>
#include "Command.h"

class CommandMock : public Command {
 public:
  MOCK_METHOD(void, execute, (), (override));
  MOCK_METHOD(void, accept, (std::shared_ptr<Visitor> v), (override));
};
#endif //TODOLIST_TESTS_CLI_MOCKS_COMMANDMOCK_H_
