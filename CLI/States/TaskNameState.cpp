//
// Created by illia.ilin on 8/25/2020.
//

#include "TaskNameState.h"
void TaskNameState::read() {
  std::string name;
  std::cin >> name;
  if(CommandsValidator::interpretResult(validator_->validate(name))=="correct"){
    return command(name);
  }
  else{

  }

}
