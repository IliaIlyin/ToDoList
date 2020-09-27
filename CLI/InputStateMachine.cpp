//
// Created by Ilya on 9/14/2020.
//

#include "InputStateMachine.h"
GeneralInputValidator::InputToken InputStateMachine::run(std::shared_ptr<InputState> begin,InputContext &context) {
  auto result = GeneralInputValidator::InputToken::CORRECT;
  while(result!= GeneralInputValidator::InputToken::CANCEL_COMMAND && result!= GeneralInputValidator::InputToken::SUCCESS){
    result=begin->read();
    if(result!=GeneralInputValidator::InputToken::CORRECT && result!=GeneralInputValidator::InputToken::SUCCESS) {
     std::cout<<GeneralInputValidator::interpretResult(result)<<std::endl;
     continue;
    }
    context=begin->fillContext(context);
    begin=begin->changeState();
  }
  return result;
}

