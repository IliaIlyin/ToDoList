//
// Created by Ilya on 9/15/2020.
//

#include "DeleteTaskCommandVisitor.h"
void DeleteTaskCommandVisitor::visitDeleteTaskCommand(DeleteTaskCommand &command) {
  command.execute();
  bool result = command.getDeleteTaskCommandResult();
  if (result) {
    std::cout << "Task was deleted" << std::endl;
  } else {
    std::cout << "Could not find task" << std::endl;

  }
}
