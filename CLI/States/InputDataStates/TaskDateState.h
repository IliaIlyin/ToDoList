//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_STATES_TASKDATESTATE_H_
#define TODOLIST_CLI_STATES_TASKDATESTATE_H_

#include "States/InputState.h"
#include "Validators/Validator.h"
#include <memory>
/*
 * class to input task date
 *
 * @author Ilya Ilyin
 */
template<typename T_NEXT, typename T_VALIDATOR>
class TaskDateState : public InputState {

 public:
  TaskDateState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator) : validator_(validator) {};

 public:
  GeneralInputValidator::InputToken read(std::shared_ptr<IOStreamInterface> inputer) override {
    inputer->print("Input task date or write cancel command to cancel command");
    std::string s;
    s = inputer->input();
    if (validator_->validate(s) == GeneralInputValidator::InputToken::CORRECT)
      this->date_ = boost::gregorian::from_string(s);
    return validator_->validate(s);
  }

  std::shared_ptr<InputState> changeState() override {
    std::shared_ptr<T_VALIDATOR> validator = std::make_shared<T_VALIDATOR>();
    return std::make_shared<T_NEXT>(validator);
  }

  InputContext fillContext(const InputContext &context) override {
    InputContext input_context(context);
    input_context.setDate(date_);
    return input_context;
  }

 private:
  std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator_;
  boost::gregorian::date date_;
};

#endif //TODOLIST_CLI_STATES_TASKDATESTATE_H_
