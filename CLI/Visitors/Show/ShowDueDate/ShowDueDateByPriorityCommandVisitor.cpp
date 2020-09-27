//
// Created by Ilya on 9/21/2020.
//

#include "ShowDueDateByPriorityCommandVisitor.h"
void ShowDueDateByPriorityCommandVisitor::visitShowDueDateByPriorityCommand(ShowDueDateByPriorityCommand &command) {
  command.execute();
  auto result = command.getCommandResult();
  context_->SetDtos(result);
}
ShowDueDateByPriorityCommandVisitor::ShowDueDateByPriorityCommandVisitor(const std::shared_ptr<Context> &context)
    : context_(context) {}
