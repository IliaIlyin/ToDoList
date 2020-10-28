//
// Created by ilya on 20.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "CLI/Mocks/IOStreamMock.h"
#include "StateMachine.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "Factories/BuilderFactoryInterface.h"
#include "Factories/VisitorFactoryInterface.h"
#include "CLI/Mocks/InputStateMachineCreatorMock.h"
#include "CLI/Mocks/StateMock.h"
#include "CLI/Mocks/VisitorFactoryMock.h"
#include "CLI/Mocks/BuilderFactoryMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class StateMachineTest : public testing::Test {

};

TEST_F(StateMachineTest, shouldExitStateMachine) {
  std::shared_ptr<Context> context;
  auto inputer = std::make_shared<IOStreamMock>();
  auto core = std::make_shared<CoreAPIMock>();
  auto builder_mock = std::make_shared<BuilderFactoryMock>();
  auto visitor_mock = std::make_shared<VisitorFactoryMock>();
  auto creator = std::make_shared<InputStateMachineCreatorMock>();
  auto begin = std::make_shared<StateMock>();
  StateMachine machine(begin, context, builder_mock, visitor_mock, inputer, core, creator);
//  EXPECT_CALL(begin.operator*(), print(context, inputer)).Times(1);
//  EXPECT_CALL(begin.operator*(), read(inputer)).Times(1).WillOnce(Return(GeneralCommandsValidator::CommandToken::EXIT));
 // EXPECT_CALL(inputer.operator*(), print("Exiting. Thanks for using!")).Times(1);
//  machine.run();
}
