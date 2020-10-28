//
// Created by illia.ilin on 9/7/2020.
//

#include "GetTaskCommandVisitor.h"
void GetTaskCommandVisitor::visitGetTaskCommand(GetTaskCommand &command) {
  command.execute();
  auto vec = command.GetGetTaskCommandResult();
  if (vec.has_value()) {
    result_->SetDto(vec.value());
  } else {
    outputer_->print("Task was not found");
  }
}
GetTaskCommandVisitor::GetTaskCommandVisitor(const std::shared_ptr<Context> &result,
                                             std::shared_ptr<IOStreamInterface> outputer)
    : result_(result), outputer_(outputer) {}
