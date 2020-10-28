//
// Created by ilya on 18.10.20.
//

#ifndef TODOLIST_TESTS_CLI_MOCKS_VISITORMOCK_H_
#define TODOLIST_TESTS_CLI_MOCKS_VISITORMOCK_H_
#include "Visitor.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

#include "Commands/Add/AddSubTaskCommand.h"
#include "Commands/Add/AddTaskCommand.h"

#include "Commands/Get/GetSubtasksCommand.h"
#include "Commands/Get/GetTaskCommand.h"

#include "Commands/Other/CompleteTaskCommand.h"
#include "Commands/Other/DeleteTaskCommand.h"
#include "Commands/Other/PostponeTaskCommand.h"

#include "Commands/Show/ShowToday/ShowTodayByLabelCommand.h"
#include "Commands/Show/ShowToday/ShowTodayByPriorityCommand.h"

#include "Commands/Show/ShowAll/ShowAllByDateCommand.h"
#include "Commands/Show/ShowAll/ShowAllByLabelCommand.h"
#include "Commands/Show/ShowAll/ShowAllByPriorityCommand.h"

#include "Commands/Show/ShowDueDate/ShowDueDateByDateCommand.h"
#include "Commands/Show/ShowDueDate/ShowDueDateByLabelCommand.h"
#include "Commands/Show/ShowDueDate/ShowDueDateByPriorityCommand.h"

#include "Commands/Serialize/SaveCommand.h"
#include "Commands/Serialize/LoadCommand.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class VisitorMock : public Visitor {

 public:
  MOCK_METHOD(void, visitAddTaskCommand, (AddTaskCommand & command), (override));
  MOCK_METHOD(void, visitAddSubTaskCommand, (AddSubTaskCommand & command), (override));

 public:
  MOCK_METHOD(void, visitGetTaskCommand, (GetTaskCommand & command), (override));
  MOCK_METHOD(void, visitGetSubTaskCommand, (GetSubTaskCommand & command), (override));

 public:
  MOCK_METHOD(void, visitCompleteTaskCommand, (CompleteTaskCommand & command), (override));
  MOCK_METHOD(void, visitDeleteTaskCommand, (DeleteTaskCommand & command), (override));
  MOCK_METHOD(void, visitPostponeTaskCommand, (PostponeTaskCommand & command), (override));

 public:
  MOCK_METHOD(void, visitShowAllByDateCommand, (ShowAllByDateCommand & command), (override));
  MOCK_METHOD(void, visitShowAllByLabelCommand, (ShowAllByLabelCommand & command), (override));
  MOCK_METHOD(void, visitShowAllByPriorityCommand, (ShowAllByPriorityCommand & command), (override));

 public:
  MOCK_METHOD(void, visitShowDueDateByDateCommand, (ShowDueDateByDateCommand & command), (override));
  MOCK_METHOD(void, visitShowDueDateByLabelCommand, (ShowDueDateByLabelCommand & command), (override));
  MOCK_METHOD(void, visitShowDueDateByPriorityCommand, (ShowDueDateByPriorityCommand & command), (override));

 public:
  MOCK_METHOD(void, visitShowTodayByLabelCommand, (ShowTodayByLabelCommand & command), (override));
  MOCK_METHOD(void, visitShowTodayPriorityCommand, (ShowTodayByPriorityCommand & command), (override));

 public:
  MOCK_METHOD(void, visitSaveCommand, (SaveCommand & command), (override));
  MOCK_METHOD(void, visitLoadCommand, (LoadCommand & command), (override));

};
#endif //TODOLIST_TESTS_CLI_MOCKS_VISITORMOCK_H_
