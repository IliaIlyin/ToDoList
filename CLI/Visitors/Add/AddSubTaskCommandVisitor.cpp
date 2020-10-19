//
// Created by illia.ilin on 9/7/2020.
//

#include "AddSubTaskCommandVisitor.h"
void AddSubTaskCommandVisitor::visitAddSubTaskCommand(AddSubTaskCommand &command) {
  command.execute();
  bool result = command.getAddSubTaskResult();
  if (result) {
    std::cout << "SubTask was added successfully" << std::endl;
  } else {
    std::cout << "Parent was not found" << std::endl;
  }
}
