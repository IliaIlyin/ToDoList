//
// Created by Ilya on 9/14/2020.
//

#ifndef TODOLIST_CLI_INPUTSTATEMACHINE_H_
#define TODOLIST_CLI_INPUTSTATEMACHINE_H_

#include "Contexts/InputContext.h"
#include "States/InputState.h"
#include "States/InputDataStates/TaskNameState.h"
#include "Validators/InputValidators/TaskNameValidator.h"
#include <string>

/*
 * state machine that operates states to input data needed for users' commands
 */
class InputStateMachine {

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
  GeneralInputValidator::InputToken run(std::shared_ptr<InputState> begin,InputContext& context);

};

#endif //TODOLIST_CLI_INPUTSTATEMACHINE_H_
