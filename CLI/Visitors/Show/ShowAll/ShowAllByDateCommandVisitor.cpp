//
// Created by Ilya on 9/21/2020.
//

#include "ShowAllByDateCommandVisitor.h"
void ShowAllByDateCommandVisitor::visitShowAllByDateCommand(ShowAllByDateCommand &command) {
  command.execute();
  auto result = command.getCommandResult();
  context_->SetDtos(result);
}
ShowAllByDateCommandVisitor::ShowAllByDateCommandVisitor(const std::shared_ptr<Context> &context) : context_(context) {}
