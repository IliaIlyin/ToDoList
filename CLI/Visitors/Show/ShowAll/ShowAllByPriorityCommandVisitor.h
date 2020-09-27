//
// Created by Ilya on 9/21/2020.
//

#ifndef TODOLIST_CLI_VISITORS_SHOW_SHOWALL_SHOWALLBYPRIORITYCOMMANDVISITOR_H_
#define TODOLIST_CLI_VISITORS_SHOW_SHOWALL_SHOWALLBYPRIORITYCOMMANDVISITOR_H_
#include "Visitor.h"

#include "Commands/Show/ShowAll/ShowAllByPriorityCommand.h"
#include "Contexts/Context.h"


class ShowAllByPriorityCommandVisitor  : public Visitor {
 public:
  void visitAddTaskCommand(AddTaskCommand &command) override{};
  void visitAddSubTaskCommand(AddSubTaskCommand &command) override{};

 public:
  void visitGetTaskCommand(GetTaskCommand &command) override{};
  void visitGetSubTaskCommand(GetSubTaskCommand &command) override{};

 public:
  void visitCompleteTaskCommand(CompleteTaskCommand &command) override{};
  void visitDeleteTaskCommand(DeleteTaskCommand &command) override{};
  void visitPostponeTaskCommand(PostponeTaskCommand &command) override{};

 public:
  void visitShowAllByDateCommand(ShowAllByDateCommand &command) override{};
  void visitShowAllByLabelCommand(ShowAllByLabelCommand &command) override{};
  void visitShowAllByPriorityCommand(ShowAllByPriorityCommand &command) override;

 public:
  void visitShowDueDateByDateCommand(ShowDueDateByDateCommand &command) override{};
  void visitShowDueDateByLabelCommand(ShowDueDateByLabelCommand &command) override{};
  void visitShowDueDateByPriorityCommand(ShowDueDateByPriorityCommand &command) override{};

 public:
  void visitShowTodayByLabelCommand(ShowTodayByLabelCommand &command) override{};
  void visitShowTodayPriorityCommand(ShowTodayByPriorityCommand &command) override{};

 public:
  ShowAllByPriorityCommandVisitor(const std::shared_ptr<Context> &context);

 private:
  std::shared_ptr<Context> context_;
};

#endif //TODOLIST_CLI_VISITORS_SHOW_SHOWALL_SHOWALLBYPRIORITYCOMMANDVISITOR_H_
