//
// Created by Ilya on 9/15/2020.
//

#include "ShowDueDateByPriorityCommandBuilder.h"
std::shared_ptr<Command> ShowDueDateByPriorityCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  if (machine_->run()
      == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    auto date = context.getDate();
    return std::make_shared<ShowDueDateByPriorityCommand>(service, date);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
ShowDueDateByPriorityCommandBuilder::ShowDueDateByPriorityCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine)
    : machine_(
    std::move(machine)
) {
}
