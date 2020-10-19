//
// Created by illia.ilin on 9/3/2020.
//

#ifndef TODOLIST_CLI_VISITOR_H_
#define TODOLIST_CLI_VISITOR_H_

class AddTaskCommand;
class AddSubTaskCommand;
class GetTaskCommand;
class GetSubTaskCommand;
class CompleteTaskCommand;
class DeleteTaskCommand;
class PostponeTaskCommand;
class ShowAllByDateCommand;
class ShowAllByLabelCommand ;
class ShowAllByPriorityCommand ;
class ShowDueDateByDateCommand ;
class ShowDueDateByLabelCommand ;
class ShowDueDateByPriorityCommand ;
class ShowTodayByLabelCommand ;
class ShowTodayByPriorityCommand ;
class SaveCommand;
class LoadCommand;
#include <iostream>
/*
 * commands' visitor
 *
 * @author Ilya Ilyin
 */
class Visitor {

 public:
  virtual void visitAddTaskCommand(AddTaskCommand &command) = 0;
  virtual void visitAddSubTaskCommand(AddSubTaskCommand &command) = 0;

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
  virtual void visitSaveCommand(SaveCommand &command)=0;
  virtual void visitLoadCommand(LoadCommand &command)=0;
 public:
  virtual ~Visitor() = default;
};
#endif //TODOLIST_CLI_VISITOR_H_
