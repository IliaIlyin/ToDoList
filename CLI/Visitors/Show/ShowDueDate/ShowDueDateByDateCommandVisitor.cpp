//
// Created by Ilya on 9/21/2020.
//

#include "ShowDueDateByDateCommandVisitor.h"
void ShowDueDateByDateCommandVisitor::visitShowDueDateByDateCommand(ShowDueDateByDateCommand &command) {
  command.execute();
  auto result = command.getCommandResult();
  context_->SetDtos(result);
}
ShowDueDateByDateCommandVisitor::ShowDueDateByDateCommandVisitor(const std::shared_ptr<Context> &context) : context_(
    context) {}
