//
// Created by illia.ilin on 8/20/2020.
//

#include "ExitState.h"

GeneralInputValidator::InputToken ExitState::read(std::shared_ptr<IOStreamInterface> inputer) {
  inputer->print("Finishing");
  return GeneralInputValidator::InputToken::SUCCESS;
}
ExitState::ExitState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator) {

}
std::shared_ptr<InputState> ExitState::changeState() {
  return std::shared_ptr<InputState>();
}
InputContext ExitState::fillContext(const InputContext &context) {
  return context;
}

