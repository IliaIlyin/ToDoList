//
// Created by Ilya on 9/15/2020.
//

#include "CompleteTaskCommandVisitor.h"
void CompleteTaskCommandVisitor::visitCompleteTaskCommand(CompleteTaskCommand &command) {
  command.execute();
  bool result = command.getCompleteTaskCommandResult();
  if (result) {
    outputer_->print("Task was completed");
  } else {
    outputer_->print("Could not find task");
  }

}
