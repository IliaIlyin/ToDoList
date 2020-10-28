//
// Created by illia.ilin on 9/7/2020.
//

#include "AddSubTaskCommandVisitor.h"
void AddSubTaskCommandVisitor::visitAddSubTaskCommand(AddSubTaskCommand &command) {
  command.execute();
  bool result = command.getAddSubTaskResult();
  if (result) {
    outputer_->print("SubTask was added successfully");
  } else {
    outputer_->print("Parent was not found");
  }
}
AddSubTaskCommandVisitor::AddSubTaskCommandVisitor(const std::shared_ptr<IOStreamInterface> &outputer) : outputer_(
    outputer) {

}
