//
// Created by Ilya on 9/21/2020.
//

#include "ShowDueDateByLabelCommandVisitor.h"
void ShowDueDateByLabelCommandVisitor::visitShowDueDateByLabelCommand(ShowDueDateByLabelCommand &command) {
  command.execute();
  auto result = command.getCommandResult();
  context_->SetDtos(result);
}
ShowDueDateByLabelCommandVisitor::ShowDueDateByLabelCommandVisitor(const std::shared_ptr<Context> &context) : context_(
    context) {}
