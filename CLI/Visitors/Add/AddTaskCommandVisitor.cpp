//
// Created by illia.ilin on 9/7/2020.
//

#include "AddTaskCommandVisitor.h"
void AddTaskCommandVisitor::visitAddTaskCommand(AddTaskCommand &command) {
  command.execute();
  bool result = command.getAddTaskResult();
  if (result) {
    std::cout << "Task was added successfully" << std::endl;
  } else {
    std::cout << "Task was not added" << std::endl;
  }
}