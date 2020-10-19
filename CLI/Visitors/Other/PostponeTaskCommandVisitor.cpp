//
// Created by Ilya on 9/15/2020.
//

#include "PostponeTaskCommandVisitor.h"
void PostponeTaskCommandVisitor::visitPostponeTaskCommand(PostponeTaskCommand &command) {
  command.execute();
  bool result = command.getPostponeTaskCommandResult();
  if (result) {
    std::cout << "Task was completed" << std::endl;
  } else {
    std::cout << "Could not find task" << std::endl;
  }
}
