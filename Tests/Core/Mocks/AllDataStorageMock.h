//
// Created by ilya on 11.10.20.
//

#ifndef TODOLIST_TESTS_CORE_MOCKS_ALLDATASTORAGEMOCK_H_
#define TODOLIST_TESTS_CORE_MOCKS_ALLDATASTORAGEMOCK_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Model/AllDataStorageInterface.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class AllDataStorageMock : public AllDataStorageInterface {

 public:
  MOCK_METHOD(bool, addTask, (Task & task), (override));
  MOCK_METHOD(TaskID,addTask ,(Task &task, bool status), (override));
  MOCK_METHOD(std::optional<TaskID>, addSubTaskToParent, (const TaskID  &parent, Task &task, bool status),(override));
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>,
              addSubTaskToParent,
              (const TaskID  &parent, Task &task),
              (override));
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>, getTask, (const TaskID & id), (override));
  MOCK_METHOD(std::optional<std::vector<std::shared_ptr<TaskEntity>>>, getSubTasks, (const TaskID & id), (override));
  MOCK_METHOD(std::vector<std::shared_ptr<TaskEntity>>,getAllTasks,(),(override));
  MOCK_METHOD(bool, postponeTask, (const TaskID & task, boost::gregorian::date dueDate), (override));
  MOCK_METHOD(bool, deleteTask, (const TaskID & task), (override));
  MOCK_METHOD(bool, completeTask, (const TaskID &task), (override));
  MOCK_METHOD(std::shared_ptr<ViewServiceInterface>, getViewService, (), (const, override));
};
#endif //TODOLIST_TESTS_CORE_MOCKS_ALLDATASTORAGEMOCK_H_
