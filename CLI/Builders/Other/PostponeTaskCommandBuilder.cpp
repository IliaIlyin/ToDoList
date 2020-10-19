//
// Created by Ilya on 9/14/2020.
//

#include "PostponeTaskCommandBuilder.h"

std::shared_ptr<Command> PostponeTaskCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  if (machine_->run() == GeneralInputValidator::InputToken::SUCCESS) {
    auto context = machine_->GetContext();
    TaskID id(context.getId());
    boost::gregorian::date date(context.getDate());
    return std::make_shared<PostponeTaskCommand>(service, id, date);
  } else {
    return std::make_shared<CancelCommand>();
  }
}
PostponeTaskCommandBuilder::PostponeTaskCommandBuilder(std::unique_ptr<InputStateMachineInterface> machine) : machine_(
    std::move(machine)) {

}

