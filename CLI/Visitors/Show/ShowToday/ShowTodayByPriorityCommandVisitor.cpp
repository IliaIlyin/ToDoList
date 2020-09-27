//
// Created by Ilya on 9/21/2020.
//

#include "ShowTodayByPriorityCommandVisitor.h"
void ShowTodayByPriorityCommandVisitor::visitShowTodayPriorityCommand(ShowTodayByPriorityCommand &command) {
  command.execute();
  auto result = command.getCommandResult();
  context_->SetDtos(result);
}
ShowTodayByPriorityCommandVisitor::ShowTodayByPriorityCommandVisitor(const std::shared_ptr<Context> &context)
    : context_(context) {}
