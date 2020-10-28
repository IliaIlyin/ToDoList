//
// Created by ilya on 20.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "CLI/Mocks/IOStreamMock.h"
#include "InputStateMachine.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class InputStateMock : public InputState {
 public:
  MOCK_METHOD(GeneralInputValidator::InputToken, read, (std::shared_ptr<IOStreamInterface> inputer), (override));
  MOCK_METHOD(std::shared_ptr<InputState>, changeState, (), (override));
  MOCK_METHOD(InputContext, fillContext, (const InputContext &context), (override));
};
class InputStateMachineTest : public testing::Test {

};
TEST_F(InputStateMachineTest, shouldRunSMReturnCancelCommand) {
  InputContext context;
  std::shared_ptr<IOStreamInterface> inputer = std::make_shared<IOStreamMock>();
  auto begin = std::make_shared<InputStateMock>();
  EXPECT_CALL(begin.operator*(),
              read(inputer)).Times(1).WillOnce(Return(GeneralInputValidator::InputToken::CANCEL_COMMAND));
  // EXPECT_CALL(inputer.operator*(),print("Command is cancelled")).Times(1);
  InputStateMachine machine(begin, context, inputer);
  ASSERT_EQ(machine.run(), GeneralInputValidator::InputToken::CANCEL_COMMAND);
}
TEST_F(InputStateMachineTest, shouldRunSMReturnSuccess) {
  InputContext context;
  std::shared_ptr<IOStreamInterface> inputer = std::make_shared<IOStreamMock>();
  auto begin = std::make_shared<InputStateMock>();
  auto mock = std::make_shared<InputStateMock>();
  EXPECT_CALL(begin.operator*(),
              read(inputer)).Times(1).WillOnce(Return(GeneralInputValidator::InputToken::SUCCESS));
  EXPECT_CALL(begin.operator*(), fillContext(context)).Times(1).WillOnce(Return(context));
  EXPECT_CALL(begin.operator*(), changeState()).Times(1).WillOnce(Return(mock));
  // EXPECT_CALL(inputer.operator*(),print("success")).Times(1);
  InputStateMachine machine(begin, context, inputer);
  ASSERT_EQ(machine.run(), GeneralInputValidator::InputToken::SUCCESS);
}
