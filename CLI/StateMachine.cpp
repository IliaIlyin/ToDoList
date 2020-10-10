//
// Created by illia.ilin on 8/20/2020.
//

#include "StateMachine.h"
void StateMachine::run() {
  std::shared_ptr<CoreAPIInterface> service = std::make_shared<CoreAPI>(CoreAPI::create());
  while (true) {
    state_->print(context_);
    auto token = state_->read();
    std::cout << GeneralCommandsValidator::interpretResult(token) << std::endl;
    if(token==GeneralCommandsValidator::CommandToken::EXIT)
      break;
    if (token == GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND) {
      continue;
    }
    auto builder = builder_factory_->create(token);
    auto cmd = builder->buildCommand(service);
    auto visitor = visitor_factory_->createVisitor(token,context_);
    state_->execute(cmd, visitor);
    state_ = state_->changeState();
  }
}

StateMachine::StateMachine(std::shared_ptr<State> state,
                           std::shared_ptr<Context> context,
                           std::shared_ptr<BuilderFactory> builder_factory,
                           std::shared_ptr<VisitorFactory> visitor_factory)
    : state_(std::move(state)),
      context_(context),
      builder_factory_(builder_factory),
      visitor_factory_(visitor_factory) {
}
