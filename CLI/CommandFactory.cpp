//
// Created by illia.ilin on 8/31/2020.
//

#include "CommandFactory.h"
std::unique_ptr<Command> CommandFactory::create(const Tokenizer::CommandToken& token) {
  switch(token){
    case Tokenizer::CommandToken::COMPLETE_TASK: {
      CompleteTaskCommand cd;
      return std::make_unique<CompleteTaskCommand>(cd);
    }
    case Tokenizer::CommandToken::DELETE_TASK: {
      DeleteTaskCommand del;
      return std::make_unique<DeleteTaskCommand>(del);
    }
    case Tokenizer::CommandToken::ADD_TASK:{
      AddTaskCommand add;
      return std::make_unique<AddTaskCommand>(add);
    }
    case Tokenizer::CommandToken::ADD_SUBTASK:{
      AddSubTaskCommand addsub;
      return std::make_unique<AddSubTaskCommand>(addsub);
    }
    case Tokenizer::CommandToken::SHOW_ALL:break;
    case Tokenizer::CommandToken::SHOW_TODAY:break;
    case Tokenizer::CommandToken::SHOW_DUE_DATE:break;
    case Tokenizer::CommandToken::POSTPONE_TASK:break;
    case Tokenizer::CommandToken::ERROR:break;
    case Tokenizer::CommandToken::GET_TASK:break;
    case Tokenizer::CommandToken::GET_SUBTASK:break;
  }
}
