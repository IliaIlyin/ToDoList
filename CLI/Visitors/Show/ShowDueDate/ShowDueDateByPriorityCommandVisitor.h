//
// Created by Ilya on 9/21/2020.
//

#ifndef TODOLIST_CLI_VISITORS_SHOW_SHOWDUEDATE_SHOWDUEDATEBYPRIORITYCOMMANDVISITOR_H_
#define TODOLIST_CLI_VISITORS_SHOW_SHOWDUEDATE_SHOWDUEDATEBYPRIORITYCOMMANDVISITOR_H_
#include "Visitor.h"
#include "Commands/Show/ShowDueDate/ShowDueDateByPriorityCommand.h"
#include "Contexts/Context.h"

class ShowDueDateByPriorityCommandVisitor : public Visitor {
 public:
  void visitAddTaskCommand(AddTaskCommand &command) override {};
  void visitAddSubTaskCommand(AddSubTaskCommand &command) override {};

 public:
  void visitSaveCommand(SaveCommand &command) override {};
  void visitLoadCommand(LoadCommand &command) override {};
 public:
  void visitGetTaskCommand(GetTaskCommand &command) override {};
  void visitGetSubTaskCommand(GetSubTaskCommand &command) override {};

 public:
  void visitCompleteTaskCommand(CompleteTaskCommand &command) override {};
  void visitDeleteTaskCommand(DeleteTaskCommand &command) override {};
  void visitPostponeTaskCommand(PostponeTaskCommand &command) override {};

 public:
  void visitShowAllByDateCommand(ShowAllByDateCommand &command) override {};
  void visitShowAllByLabelCommand(ShowAllByLabelCommand &command) override {};
  void visitShowAllByPriorityCommand(ShowAllByPriorityCommand &command) override {};

 public:
  void visitShowDueDateByDateCommand(ShowDueDateByDateCommand &command) override {};
  void visitShowDueDateByLabelCommand(ShowDueDateByLabelCommand &command) override {};
  void visitShowDueDateByPriorityCommand(ShowDueDateByPriorityCommand &command) override;

 public:
  void visitShowTodayByLabelCommand(ShowTodayByLabelCommand &command) override {};
  void visitShowTodayPriorityCommand(ShowTodayByPriorityCommand &command) override {};
  ShowDueDateByPriorityCommandVisitor(const std::shared_ptr<Context> &context);
 private:
  std::shared_ptr<Context> context_;
};

#endif //TODOLIST_CLI_VISITORS_SHOW_SHOWDUEDATE_SHOWDUEDATEBYPRIORITYCOMMANDVISITOR_H_
