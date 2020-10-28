//
// Created by ilya on 18.10.20.
//

#ifndef TODOLIST_TESTS_CLI_MOCKS_INPUTSTATEMACHINE_H_
#define TODOLIST_TESTS_CLI_MOCKS_INPUTSTATEMACHINE_H_
#include "InputStateMachineInterface.h"
class InputStateMachineMock : public InputStateMachineInterface {
 public:
  MOCK_METHOD(GeneralInputValidator::InputToken,
              run,
              (),
              (override));
  MOCK_METHOD(InputContext, GetContext,
              (), (const override));
};
#endif //TODOLIST_TESTS_CLI_MOCKS_INPUTSTATEMACHINE_H_
