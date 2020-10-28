//
// Created by illia.ilin on 8/20/2020.
//

#include "BaseState.h"
GeneralCommandsValidator::CommandToken BaseState::read(std::shared_ptr<IOStreamInterface> inputer) {
  std::string cmd;
  cmd = inputer->input();
  auto token = validator_->validate(cmd);
  return token;
}

void BaseState::print(std::shared_ptr<Context> context, std::shared_ptr<IOStreamInterface> printer) {
  auto task = context->GetDto();
  if (task.has_value()) {
    std::stringstream str;
    str << "Task Name: ";
    str << task.value().getTask().getName();
    printer->print(str.str());
    str.str(std::string());//clears stringstream
    str << "Task Date: " << task.value().getTask().getDate();
    printer->print(str.str());
    str.str(std::string());
    str << "Task Label: " << task.value().getTask().getLabel();
    printer->print(str.str());
    str.str(std::string());
    str << "Task Priority: " << task.value().getTask().getPriority();
    printer->print(str.str());
    str.str(std::string());
    str << "Task status: " << task.value().checkStatus();
    printer->print(str.str());
    str.str(std::string());
  }
  auto vec = context->GetDtos();
  if (vec.has_value()) {
    if (!vec.value().empty()) {
      for (auto i = vec.value().begin(); i != vec.value().end(); i++) {
        std::stringstream str;
        str << "Task Id: " << i->getTaskId().getId();
        printer->print(str.str());
        str.str(std::string());
        str << "Task Name: " << i->getTask().getName();
        printer->print(str.str());
        str.str(std::string());
      }
    } else {
      std::stringstream str;
      str << "No tasks";
      printer->print(str.str());
      str.str(std::string());
    }
  }
  std::stringstream str;
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
  str << input;
  printer->print(str.str());
  str.str(std::string());
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


