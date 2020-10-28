//
// Created by ilya on 25.10.20.
//

#ifndef TODOLIST_TESTS_CLI_MOCKS_VISITORFACTORYMOCK_H_
#define TODOLIST_TESTS_CLI_MOCKS_VISITORFACTORYMOCK_H_
#include "Factories/VisitorFactoryInterface.h"
#include <gmock/gmock.h>
class VisitorFactoryMock : public VisitorFactoryInterface {
 public:
  MOCK_METHOD(std::shared_ptr<Visitor>, createVisitor, (const GeneralCommandsValidator::CommandToken &token,
      std::shared_ptr<Context> context,
      std::shared_ptr<IOStreamInterface> outputer), (override));
};
#endif //TODOLIST_TESTS_CLI_MOCKS_VISITORFACTORYMOCK_H_
