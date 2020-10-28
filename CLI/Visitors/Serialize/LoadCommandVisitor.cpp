//
// Created by ilya on 12.10.20.
//

#include "LoadCommandVisitor.h"
void LoadCommandVisitor::visitLoadCommand(LoadCommand &command) {
  command.execute();
  bool result = command.getLoadResult();
  if (result) {
    outputer_->print("System has loaded");
  } else {
    outputer_->print("Wrong file. System is not loaded.");
  }
}
LoadCommandVisitor::LoadCommandVisitor(const std::shared_ptr<IOStreamInterface> &outputer) : outputer_(outputer) {}
