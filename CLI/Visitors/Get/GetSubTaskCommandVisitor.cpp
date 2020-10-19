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
    std::cout << "Task was not found" << std::endl;
  }
}
GetSubTaskCommandVisitor::GetSubTaskCommandVisitor(const std::shared_ptr<Context> &result) : result_(result) {}
