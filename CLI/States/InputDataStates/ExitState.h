//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_EXITSTATE_H_
#define TODOLIST_CLI_EXITSTATE_H_
#include "States/InputState.h"
#include "Validators/Validator.h"
#include <memory>
/*
 * class to exit InputStateMachine
 * @see InputStateMachine
 *
 * @author Ilya Ilyin
 */
class ExitState : public InputState {

 public:
  explicit ExitState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator);
 public:
  GeneralInputValidator::InputToken read() override;
  std::shared_ptr<InputState> changeState() override;
  InputContext fillContext(const InputContext &context) override;

};
#endif //TODOLIST_CLI_EXITSTATE_H_
