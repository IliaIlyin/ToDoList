//
// Created by Ilya on 9/21/2020.
//

#include "ShowAllByPriorityCommandVisitor.h"
void ShowAllByPriorityCommandVisitor::visitShowAllByPriorityCommand(ShowAllByPriorityCommand &command) {
  command.execute();
  auto result = command.getCommandResult();
  context_->SetDtos(result);
}
ShowAllByPriorityCommandVisitor::ShowAllByPriorityCommandVisitor(const std::shared_ptr<Context> &context) : context_(
    context) {}
