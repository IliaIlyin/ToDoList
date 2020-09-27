//
// Created by Ilya on 9/21/2020.
//

#include "ShowAllByLabelCommandVisitor.h"
void ShowAllByLabelCommandVisitor::visitShowAllByLabelCommand(ShowAllByLabelCommand &command) {
  command.execute();
  auto result = command.getCommandResult();
  context_->SetDtos(result);
}
ShowAllByLabelCommandVisitor::ShowAllByLabelCommandVisitor(const std::shared_ptr<Context> &context)
    : context_(context) {}
