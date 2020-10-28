//
// Created by illia.ilin on 9/7/2020.
//

#include "GetSubTaskCommandVisitor.h"
void GetSubTaskCommandVisitor::visitGetSubTaskCommand(GetSubTaskCommand &command) {
  command.execute();
  auto vec = command.GetGetSubTaskCommandResult();
  if (vec.has_value()) {
    result_->SetDtos(vec.value());
  } else {
    outputer_->print("Task was not found");
  }
}
GetSubTaskCommandVisitor::GetSubTaskCommandVisitor(const std::shared_ptr<Context> &result,
                                                   std::shared_ptr<IOStreamInterface> outputer)
    : result_(result), outputer_(outputer) {}
