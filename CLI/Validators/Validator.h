//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_VALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_VALIDATOR_H_

#include <string>
/*
 * class that operates input strings
 */
template<typename T>
class Validator {

 public:
  /*
   * method that validates strings as commands or task data
   */
  virtual T validate(const std::string &) = 0;
};

#endif //TODOLIST_CLI_VALIDATORS_VALIDATOR_H_
