//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_STATEMACHINE_H_
#define TODOLIST_CLI_STATEMACHINE_H_

#include "States/State.h"
#include "Contexts/Context.h"
#include "Factories/VisitorFactory.h"
#include "States/BaseState.h"
#include "Factories/BuilderFactory.h"
/*
 * state machine that operates states that operate users' commands
 *
 * @author Ilya Ilyin
 */
class StateMachine {

 public:
  StateMachine(std::shared_ptr<State> state,
               std::shared_ptr<Context> context,
               std::shared_ptr<BuilderFactory> builder_factory_,
               std::shared_ptr<VisitorFactory> visitor_factory_
  );

 public:
  /*
   * run state machine
   *
   * @return void
   */
  void run();

 private:
  /*
   * current state
   */
  std::shared_ptr<State> state_;
  /*
   * factory to build commands
   */
  std::shared_ptr<BuilderFactory> builder_factory_;
  /*
   * factory to build visitors
   */
  std::shared_ptr<VisitorFactory> visitor_factory_;
  /*
   * state machine context
   */
  std::shared_ptr<Context> context_;
};

#endif //TODOLIST_CLI_STATEMACHINE_H_
