//
// Created by ilya on 16.10.20.
//

#ifndef TODOLIST_CLI_VISITORS_INPUTSTATEMACHINEINTERFACE_H_
#define TODOLIST_CLI_VISITORS_INPUTSTATEMACHINEINTERFACE_H_

#include "Contexts/InputContext.h"
#include "States/InputState.h"
#include "States/InputDataStates/TaskNameState.h"
#include "Validators/InputValidators/TaskNameValidator.h"
#include <string>

/*
 * state machine that operates states to input data needed for users' commands
 */
class InputStateMachineInterface {

 public:
/*
 * run state machine
 *
 * @input pointer to the state to begin with
 * @input context to fill
 *
 * @return GeneralInputValidator::InputToken::SUCCESS if the machine run was completed successfully
 * @return GeneralInputValidator::InputToken::CANCEL_COMMAND if the user decided to cancel the command
 */
  virtual ~InputStateMachineInterface()=default;
  virtual GeneralInputValidator::InputToken run() = 0;
  virtual InputContext GetContext() const = 0;

};
#endif //TODOLIST_CLI_VISITORS_INPUTSTATEMACHINEINTERFACE_H_
