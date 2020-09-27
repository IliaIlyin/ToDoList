//
// Created by Ilya on 9/14/2020.
//

#ifndef TODOLIST_CLI_INPUTSTATE_H_
#define TODOLIST_CLI_INPUTSTATE_H_

#include "Factories/Validators/GeneralInputValidator.h"
#include <memory>
#include "Contexts/InputContext.h"
/*
 * class to input data needed for commands
 *
 * @author Ilya Ilyin
 */
class InputState{

 public:
  /*
   * method that reads users' input
   *
   * @return GeneralInputValidator::InputToken corresponding to the data token
   */
  virtual GeneralInputValidator::InputToken read()=0;
  /*
   * method that changes current state
   *
   * @return pointer to the next state
   */
  virtual std::shared_ptr<InputState> changeState()=0;
  /*
   * method that fills the context
   *
   * @input InputContext to fill
   *
   * @return filled InputContext
   */
  virtual InputContext fillContext(const InputContext& context)=0;

 public:
  virtual ~InputState()=default;
};

#endif //TODOLIST_CLI_INPUTSTATE_H_
