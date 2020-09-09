//
// Created by illia.ilin on 8/28/2020.
//

#include "Tokenizer.h"
Tokenizer::CommandToken Tokenizer::tokenize(const std::string& str) {
 if(str=="Add task")
   return CommandToken::ADD_TASK;
 if(str=="Add subtask")
   return CommandToken::ADD_SUBTASK;
 if(str=="show all")
   return CommandToken::SHOW_ALL;
 if(str=="show today")
   return CommandToken::SHOW_TODAY;
 if(str=="show due date")
   return CommandToken::SHOW_DUE_DATE;
 if(str=="postpone task")
   return CommandToken::POSTPONE_TASK;
 if(str=="get task")
   return CommandToken::GET_TASK;
 if(str=="get subtask")
   return CommandToken::GET_SUBTASK;
 if(str=="complete task")
   return CommandToken::COMPLETE_TASK;
 if(str=="delete task")
   return CommandToken::DELETE_TASK;
 return CommandToken::ERROR;
}
