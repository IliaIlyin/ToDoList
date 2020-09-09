//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_COMMAND_H_
#define TODOLIST_CLI_VALIDATORS_COMMAND_H_

#include "Visitor.h"
#include "Contexts/Context.h"

template < typename T >
class Command{
 public:
  virtual T execute()=0;
  virtual void accept(std::shared_ptr<Visitor> v)=0;
};
#endif //TODOLIST_CLI_VALIDATORS_COMMAND_H_
