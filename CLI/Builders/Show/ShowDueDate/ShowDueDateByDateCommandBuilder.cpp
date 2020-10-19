//
// Created by Ilya on 9/15/2020.
//

#include "ShowDueDateByDateCommandBuilder.h"
std::shared_ptr<Command> ShowDueDateByDateCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  if (machine_->run()
      == GeneralInputValidator::InputToken::SUCCESS) {
    auto context =machine_->GetContext();
    auto date = context.getDate();
    return std::make_shared<ShowDueDateByDateCommand>(service, date);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
ShowDueDateByDateCommandBuilder::ShowDueDateByDateCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine)
    : machine_(std::move(machine)) {

}
