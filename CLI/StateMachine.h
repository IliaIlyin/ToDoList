//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_STATEMACHINE_H_
#define TODOLIST_CLI_STATEMACHINE_H_

#include "States/State.h"
#include "Contexts/Context.h"
#include "Factories/VisitorFactory.h"
#include "States/BaseState.h"
#include "Input_Output/IOStream.h"
#include "Factories/BuilderFactory.h"
#include "API/CoreAPI.h"
#include "StateMachineInterface.h"
#include "Validators/BaseStateValidator.h"
#include "Factories/BuilderFactoryInterface.h"
#include "Factories/VisitorFactoryInterface.h"
#include "Client.h"

/*
 * state machine that operates states that operate users' commands
 *
 * @author Ilya Ilyin
 */
class StateMachine : public StateMachineInterface {

 public:
  StateMachine(std::shared_ptr<State> state,
               std::shared_ptr<Context> context,
               std::shared_ptr<BuilderFactoryInterface> builder_factory_,
               std::shared_ptr<VisitorFactoryInterface> visitor_factory_,
               std::shared_ptr<IOStreamInterface> outputer,
               std::shared_ptr<ClientInterface> service,
               std::shared_ptr<InputStateMachineCreatorInterface> creator
  );
  static StateMachine CreateMachine();
 public:
  /*
   * run state machine
   *
   * @return void
   */
  void run() override;

 private:
  /*
   * class to output/input info
   */
  std::shared_ptr<IOStreamInterface> outputer_;
  /*
   * current state
   */
  std::shared_ptr<State> state_;
  /*
   * factory to build commands
   */
  std::shared_ptr<BuilderFactoryInterface> builder_factory_;
  /*
   * factory to build visitors
   */
  std::shared_ptr<VisitorFactoryInterface> visitor_factory_;
  /*
   * state machine context
   */
  std::shared_ptr<Context> context_;
/*
 * Core
 */
  std::shared_ptr<ClientInterface> service_;
/*
 * class to create input state machines
 */
  std::shared_ptr<InputStateMachineCreatorInterface> creator_;

};

#endif //TODOLIST_CLI_STATEMACHINE_H_
