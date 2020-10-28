//
// Created by ilya on 25.10.20.
//

#ifndef TODOLIST_TESTS_CLI_MOCKS_BUILDERFACTORYMOCK_H_
#define TODOLIST_TESTS_CLI_MOCKS_BUILDERFACTORYMOCK_H_
#include "Factories/BuilderFactoryInterface.h"
#include <gmock/gmock.h>
class BuilderFactoryMock : public BuilderFactoryInterface {
 public:
  MOCK_METHOD(std::shared_ptr<Builder>, create, (const GeneralCommandsValidator::CommandToken &token,
      std::shared_ptr<InputStateMachineCreatorInterface> creator,
      std::shared_ptr<IOStreamInterface> outpute), (override));

 public:
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildAddTaskCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildAddSubTaskCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildDeleteTaskCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildShowDueByDateCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildShowDueDateByLabelCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildShowDueDateByPriorityCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildCompleteTaskCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildPostponeTaskCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildGetTaskCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildGetSubTaskCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildSaveCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));
  MOCK_METHOD(std::shared_ptr<Builder>,
              BuildLoadCommandBuilder,
              (std::shared_ptr<InputStateMachineCreatorInterface> & creator,
                  std::shared_ptr<IOStreamInterface> outpute),
              (const override));

};

#endif //TODOLIST_TESTS_CLI_MOCKS_BUILDERFACTORYMOCK_H_
