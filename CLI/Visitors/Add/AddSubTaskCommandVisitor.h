//
// Created by illia.ilin on 9/7/2020.
//

#ifndef TODOLIST_CLI_VISITORS_ADD_ADDSUBTASKCOMMANDVISITOR_H_
#define TODOLIST_CLI_VISITORS_ADD_ADDSUBTASKCOMMANDVISITOR_H_

#include "Visitor.h"
#include "Commands/Add/AddSubTaskCommand.h"

class AddSubTaskCommandVisitor : public Visitor {
 public:
  AddSubTaskCommandVisitor(const std::shared_ptr<IOStreamInterface> &outputer);
 public:
  void visitAddTaskCommand(AddTaskCommand &command) override {};
  void visitAddSubTaskCommand(AddSubTaskCommand &command) override;

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
  void visitShowDueDateByPriorityCommand(ShowDueDateByPriorityCommand &command) override {};

 public:
  void visitShowTodayByLabelCommand(ShowTodayByLabelCommand &command) override {};
  void visitShowTodayPriorityCommand(ShowTodayByPriorityCommand &command) override {};

 public:
  void visitSaveCommand(SaveCommand &command) override {};
  void visitLoadCommand(LoadCommand &command) override {};
 private:
  std::shared_ptr<IOStreamInterface> outputer_;
};

#endif //TODOLIST_CLI_VISITORS_ADD_ADDSUBTASKCOMMANDVISITOR_H_
