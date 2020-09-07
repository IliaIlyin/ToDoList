//
// Created by illia.ilin on 9/7/2020.
//

#include "GetSubTaskCommandVisitor.h"
Context &getSubTaskCommandVisitor::visitAddSubTaskCommand(AddSubTaskCommand &command) {
  bool result = command.execute();
  if(result){
    std::cout<<"Parent was not found"<<std::endl;
  }
  return context_;
}
