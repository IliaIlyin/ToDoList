//
// Created by ilya on 16.10.20.
//

#ifndef TODOLIST_CLI_STATEMACHINEINTERFACE_H_
#define TODOLIST_CLI_STATEMACHINEINTERFACE_H_
#include "States/State.h"
#include "Contexts/Context.h"
#include "Factories/VisitorFactory.h"
#include "States/BaseState.h"
#include "Factories/BuilderFactory.h"
#include "API/CoreAPI.h"
/*
 * state machine that operates states that operate users' commands
 *
 * @author Ilya Ilyin
 */
class StateMachineInterface {



 public:
  /*
   * run state machine
   *
   * @return void
   */
  virtual void run() =0;


};
#endif //TODOLIST_CLI_STATEMACHINEINTERFACE_H_
