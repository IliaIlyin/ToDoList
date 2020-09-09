//
// Created by illia.ilin on 9/3/2020.
//

#ifndef TODOLIST_CLI_VISITOR_H_
#define TODOLIST_CLI_VISITOR_H_

#include "Commands/Add/AddTaskCommand.h"
#include "Commands/Add/AddSubTaskCommand.h"

#include "Commands/Get/GetSubtasksCommand.h"
#include "Commands/Get/GetTaskCommand.h"

#include "Commands/Other/CompleteTaskCommand.h"
#include "Commands/Other/DeleteTaskCommand.h"
#include "Commands/Other/PostponeTaskCommand.h"

#include "Commands/Show/ShowAll/ShowAllByDateCommand.h"
#include "Commands/Show/ShowAll/ShowAllByLabelCommand.h"
#include "Commands/Show/ShowAll/ShowAllByPriorityCommand.h"

#include "Commands/Show/ShowDueDate/ShowDueDateByDateCommand.h"
#include "Commands/Show/ShowDueDate/ShowDueDateByLabelCommand.h"
#include "Commands/Show/ShowDueDate/ShowDueDateByPriorityCommand.h"

#include "Commands/Show/ShowToday/ShowTodayByLabelCommand.h"
#include "Commands/Show/ShowToday/ShowTodayByPriorityCommand.h"

class Visitor {

 public:
  virtual bool visitAddTaskCommand(AddTaskCommand &command) = 0;
  virtual bool visitAddSubTaskCommand(AddSubTaskCommand &command) = 0;

 public:
  virtual void visitGetTaskCommand( GetTaskCommand &command) = 0;
  virtual void visitGetSubTaskCommand( GetSubTaskCommand &command) = 0;

 public:
  virtual void visitCompleteTaskCommand( CompleteTaskCommand &command) = 0;
  virtual void visitDeleteTaskCommand( DeleteTaskCommand &command) = 0;
  virtual void visitPostponeTaskCommand( PostponeTaskCommand &command) = 0;

 public:
  virtual void visitShowAllByDateCommand( ShowAllByDateCommand &command) = 0;
  virtual void visitShowAllByLabelCommand( ShowAllByLabelCommand &command) = 0;
  virtual void visitShowAllByPriorityCommand( ShowAllByPriorityCommand &command) = 0;

 public:
  virtual void visitShowDueDateByDateCommand( ShowDueDateByDateCommand &command) = 0;
  virtual void visitShowDueDateByLabelCommand( ShowDueDateByLabelCommand &command) = 0;
  virtual void visitShowDueDateByPriorityCommand( ShowDueDateByPriorityCommand &command) = 0;

 public:
  virtual void visitShowTodayByLabelCommand( ShowTodayByLabelCommand &command) = 0;
  virtual void visitShowTodayPriorityCommand( ShowTodayByPriorityCommand &command) = 0;

 public:
  virtual ~Visitor() = default;
};
#endif //TODOLIST_CLI_VISITOR_H_
