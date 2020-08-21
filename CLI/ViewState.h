//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_VIEWSTATE_H_
#define TODOLIST_CLI_VIEWSTATE_H_

#include "State.h"
#include <map>
#include <string>
#include <iostream>
#include <memory>
#include "API/TaskDTO.h"

class ViewState : State{

 public:

   void read(Context& context) override ;
   std::unique_ptr<State> changeState() override ;
   void execute(Context& context) override ;
   void print() override ;

};

#endif //TODOLIST_CLI_VIEWSTATE_H_
