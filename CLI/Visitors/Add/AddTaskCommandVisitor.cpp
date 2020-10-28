//
// Created by illia.ilin on 9/7/2020.
//

#include "AddTaskCommandVisitor.h"
void AddTaskCommandVisitor::visitAddTaskCommand(AddTaskCommand &command) {
  command.execute();
  bool result = command.getAddTaskResult();
  if (result) {
    outputer_->print("Task was added successfully");
  } else {
    outputer_->print("Task was not added");
  }
}
AddTaskCommandVisitor::AddTaskCommandVisitor(const std::shared_ptr<IOStreamInterface> &outputer) : outputer_(outputer) {

}
