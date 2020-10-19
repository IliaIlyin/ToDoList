//
// Created by Ilya on 9/15/2020.
//

#include "ShowDueDateByLabelCommandBuilder.h"
std::shared_ptr<Command> ShowDueDateByLabelCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  if (machine_->run()
      == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    auto date = context.getDate();
    return std::make_shared<ShowDueDateByLabelCommand>(service, date);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
ShowDueDateByLabelCommandBuilder::ShowDueDateByLabelCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine)
    : machine_(std::move(machine)) {

}
