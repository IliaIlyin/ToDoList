//
// Created by Ilya on 9/15/2020.
//

#include "DeleteTaskCommandVisitor.h"
void DeleteTaskCommandVisitor::visitDeleteTaskCommand(DeleteTaskCommand &command) {
  command.execute();
  bool result = command.getDeleteTaskCommandResult();
  if (result) {
    outputer_->print("Task was deleted");
  } else {
    outputer_->print("Could not find task");
  }
}
