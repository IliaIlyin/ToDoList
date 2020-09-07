//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_TOKENIZER_H_
#define TODOLIST_CLI_TOKENIZER_H_

#include <string>
class Tokenizer {
 public:
  enum class CommandToken{
    ADD_TASK,
    ADD_SUBTASK,
    DELETE_TASK,
    SHOW_ALL,
    SHOW_TODAY,
    SHOW_DUE_DATE,
    COMPLETE_TASK,
    POSTPONE_TASK,
    ERROR,
    GET_TASK,
    GET_SUBTASK,
  };
  CommandToken tokenize(const std::string& str);
};

#endif //TODOLIST_CLI_TOKENIZER_H_
