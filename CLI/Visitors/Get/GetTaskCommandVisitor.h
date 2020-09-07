//
// Created by illia.ilin on 9/7/2020.
//

#ifndef TODOLIST_CLI_VISITORS_GET_GETTASKCOMMANDVISITOR_H_
#define TODOLIST_CLI_VISITORS_GET_GETTASKCOMMANDVISITOR_H_

#include "Visitor.h"

class GetTaskCommandVisitor : public Visitor {

 public:
  Context &visitAddTaskCommand(AddTaskCommand &command) override;
  Context &visitAddSubTaskCommand(AddSubTaskCommand &command) override;

 public:
  Context &visitGetTaskCommand(GetTaskCommand &command) override;
  Context &visitGetSubTaskCommand(GetSubTaskCommand &command) override;

 public:
  Context &visitCompleteTaskCommand(CompleteTaskCommand &command) override;
  Context &visitDeleteTaskCommand(DeleteTaskCommand &command) override;
  Context &visitPostponeTaskCommand(PostponeTaskCommand &command) override;

 public:
  Context &visitShowAllByDateCommand(ShowAllByDateCommand &command) override;
  Context &visitShowAllByLabelCommand(ShowAllByLabelCommand &command) override;
  Context &visitShowAllByPriorityCommand(ShowAllByPriorityCommand &command) override;

 public:
  Context &visitShowDueDateByDateCommand(ShowDueDateByDateCommand &command) override;
  Context &visitShowDueDateByLabelCommand(ShowDueDateByLabelCommand &command) override;
  Context &visitShowDueDateByPriorityCommand(ShowDueDateByPriorityCommand &command) override;

 public:
  Context &visitShowTodayByLabelCommand(ShowTodayByLabelCommand &command) override;
  Context &visitShowTodayPriorityCommand(ShowTodayByPriorityCommand &command) override;

 public:
  AddTaskCommandVisitor(Context &context);
 private:
  Context &context_;
};

#endif //TODOLIST_CLI_VISITORS_GET_GETTASKCOMMANDVISITOR_H_
