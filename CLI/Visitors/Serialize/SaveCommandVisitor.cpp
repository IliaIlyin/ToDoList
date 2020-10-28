//
// Created by ilya on 12.10.20.
//

#include "SaveCommandVisitor.h"

void SaveCommandVisitor::visitSaveCommand(SaveCommand &command) {
  command.execute();
  bool result = command.getSaveResult();
  if (result) {
    outputer_->print("System has been saved");
  } else {
    outputer_->print("Something went wrong. System is not saved.");
  }
}
SaveCommandVisitor::SaveCommandVisitor(const std::shared_ptr<IOStreamInterface> &outputer) : outputer_(outputer) {}
