//
// Created by Ilya on 9/15/2020.
//

#include "CompleteTaskCommandVisitor.h"
void CompleteTaskCommandVisitor::visitCompleteTaskCommand(CompleteTaskCommand &command) {
  command.execute();
  bool result = command.getCompleteTaskCommandResult();
  if (result) {
    std::cout << "Task was completed" << std::endl;
  } else {
    std::cout << "Could not find task" << std::endl;
  }

}
