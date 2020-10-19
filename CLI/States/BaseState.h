//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_BASESTATE_H_
#define TODOLIST_CLI_BASESTATE_H_
#include "States/State.h"
#include "Validators/Validator.h"
#include "Factories/BuilderFactory.h"
#include <memory>

/*
 * Base State that operates input commands
 *
 * @author Ilya Ilyin
 */
class BaseState : public State {

 public:
  GeneralCommandsValidator::CommandToken read() override;
  std::shared_ptr<State> changeState() override;
  void execute(std::shared_ptr<Command> command, std::shared_ptr<Visitor> visitor) override;
  void print(std::shared_ptr<Context> context) override;

 public:
  BaseState(std::shared_ptr<Validator<GeneralCommandsValidator::CommandToken>> validator);

 private:
  std::shared_ptr<Validator<GeneralCommandsValidator::CommandToken>> validator_;

};

#endif //TODOLIST_CLI_BASESTATE_H_
