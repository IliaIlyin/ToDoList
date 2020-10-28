//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_STATES_TASKIDSTATE_H_
#define TODOLIST_CLI_STATES_TASKIDSTATE_H_

#include "States/InputState.h"
#include "Validators/Validator.h"
#include "API/TaskID.h"
#include <memory>
/*
 * class to input task id
 *
 * @author Ilya Ilyin
 */
template<typename T_NEXT, typename T_VALIDATOR>
class TaskIdState : public InputState {

 public:
  TaskIdState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator) : validator_(std::move(
      validator)) {
  };

 public:
  GeneralInputValidator::InputToken read(std::shared_ptr<IOStreamInterface> inputer) override {
    std::string s;
    inputer->print("Input task id or write cancel command to cancel command");
    s = inputer->input();
    if (validator_->validate(s) == GeneralInputValidator::InputToken::CORRECT)
      this->id_ = TaskID(std::stoi(s));
    return validator_->validate(s);
  }

  std::shared_ptr<InputState> changeState() override {
    std::shared_ptr<T_VALIDATOR> validator = std::make_shared<T_VALIDATOR>();
    return std::make_shared<T_NEXT>(validator);
  }

  InputContext fillContext(const InputContext &context) override {
    InputContext input_context(context);
    input_context.setId(id_);
    return input_context;
  }

 private:
  std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator_;
  TaskID id_;
};

#endif //TODOLIST_CLI_STATES_TASKIDSTATE_H_
