//
// Created by illia.ilin on 9/7/2020.
//

#include "GetTaskCommandVisitor.h"
void GetTaskCommandVisitor::visitGetTaskCommand(GetTaskCommand &command) {
  command.execute();
  auto vec = command.GetGetTaskCommandResult();
  if(vec.has_value()){
    result_->SetDto(vec.value());
  }
  else{
    std::cout<<"Task was not found"<<std::endl;
  }
}
GetTaskCommandVisitor::GetTaskCommandVisitor(const std::shared_ptr<Context> &result) : result_(result) {}
