//
// Created by illia.ilin on 8/20/2020.
//

#include "BaseState.h"
GeneralCommandsValidator::CommandToken BaseState::read() {
  std::string cmd;
  std::getline(std::cin, cmd);
  auto token = validator_->validate(cmd);
  return token;
}

void BaseState::print(std::shared_ptr<Context> context) {
  auto task = context->GetDto();
  if (task.has_value()) {
    std::cout << "Task Name: " << task.value().getTask().getName() << std::endl;
    std::cout << "Task Date: " << task.value().getTask().getDate() << std::endl;
    std::cout << "Task Label: " << task.value().getTask().getLabel() << std::endl;
    std::cout << "Task Priority: " << task.value().getTask().getPriority() << std::endl;
    std::cout << "Task status: " << task.value().checkStatus() << std::endl;
  }
  auto vec = context->GetDtos();
  if (vec.has_value()) {
    if (!vec.value().empty()) {
      for (auto i = vec.value().begin(); i != vec.value().end(); i++) {
        std::cout << "Task Id: " << i->getTaskId().getId() << std::endl;
        std::cout << "Task Name: " << i->getTask().getName() << std::endl;
      }
    } else {
      std::cout << "No tasks" << std::endl;
    }
  }
  std::string input = "Welcome User! Available commands: \n"
                      "Add task\n"
                      "Add subTask\n"
                      "get task\n"
                      "get subTasks\n"
                      "postpone task\n"
                      "complete task\n"
                      "delete task\n"
                      "show all sort priority\n"
                      "show all sort date\n"
                      "show all sort label\n"
                      "show today sort priority\n"
                      "show today sort label\n"
                      "show due date sort label\n"
                      "show due date sort priority\n"
                      "show due date sort date\n"
                      "exit\n"
                      "save\n"
                      "load\n";
  std::cout << input << std::endl;
}

void BaseState::execute(std::shared_ptr<Command> command, std::shared_ptr<Visitor> visitor) {
  command->accept(visitor);
}

std::shared_ptr<State> BaseState::changeState() {
  return std::make_shared<BaseState>(validator_);
}
BaseState::BaseState(std::shared_ptr<Validator<GeneralCommandsValidator::CommandToken>> validator) : validator_(
    validator) {

}


