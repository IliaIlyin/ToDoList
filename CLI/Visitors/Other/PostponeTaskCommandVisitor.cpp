//
// Created by Ilya on 9/15/2020.
//

#include "PostponeTaskCommandVisitor.h"
void PostponeTaskCommandVisitor::visitPostponeTaskCommand(PostponeTaskCommand &command) {
  command.execute();
  bool result = command.getPostponeTaskCommandResult();
  if (result) {
    outputer_->print("Task was postponed");
  } else {
    outputer_->print("Could not find task");
  }
}
