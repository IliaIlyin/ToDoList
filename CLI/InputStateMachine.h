//
// Created by Ilya on 9/14/2020.
//

#ifndef TODOLIST_CLI_INPUTSTATEMACHINE_H_
#define TODOLIST_CLI_INPUTSTATEMACHINE_H_

#include "Contexts/InputContext.h"
#include "States/InputState.h"
#include "States/InputDataStates/TaskNameState.h"
#include "Validators/InputValidators/TaskNameValidator.h"
#include "InputStateMachineInterface.h"
#include <string>
#include "Input_Output/IOStream.h"
/*
 * state machine that operates states to input data needed for users' commands
 */
class InputStateMachine : public InputStateMachineInterface {

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
  GeneralInputValidator::InputToken run() override;
  InputStateMachine(const std::shared_ptr<InputState> &begin,
                    InputContext &context,
                    std::shared_ptr<IOStreamInterface> outputer);
  InputContext GetContext() const;
 private:
  std::shared_ptr<InputState> begin_;
  InputContext context_;
  std::shared_ptr<IOStreamInterface> outputer_;
};

#endif //TODOLIST_CLI_INPUTSTATEMACHINE_H_
