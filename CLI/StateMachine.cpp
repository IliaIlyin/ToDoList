//
// Created by illia.ilin on 8/20/2020.
//

#include "StateMachine.h"
void StateMachine::run() {
  while (true) {
    state_->print(context_, outputer_);
    auto token = state_->read(outputer_);
    outputer_->print(GeneralCommandsValidator::interpretResult(token));
    if (token == GeneralCommandsValidator::CommandToken::EXIT)
      break;
    if (token == GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND) {
      continue;
    }
    auto builder = builder_factory_->create(token, creator_, outputer_);
    auto cmd = builder->buildCommand(service_);
    auto visitor = visitor_factory_->createVisitor(token, context_, outputer_);
    state_->execute(cmd, visitor);
    state_ = state_->changeState();
  }
}

StateMachine::StateMachine(std::shared_ptr<State> state,
                           std::shared_ptr<Context> context,
                           std::shared_ptr<BuilderFactoryInterface> builder_factory,
                           std::shared_ptr<VisitorFactoryInterface> visitor_factory,
                           std::shared_ptr<IOStreamInterface> outputer,
                           std::shared_ptr<ClientInterface> service,
                           std::shared_ptr<InputStateMachineCreatorInterface> creator)
    : state_(std::move(state)),
      context_(context),
      builder_factory_(builder_factory),
      visitor_factory_(visitor_factory), outputer_(outputer), service_(service), creator_(creator) {
}
StateMachine StateMachine::CreateMachine() {
  std::shared_ptr<BaseStateValidator> validator = std::make_shared<BaseStateValidator>();
  std::shared_ptr<BaseState> base = std::make_shared<BaseState>(validator);
  std::shared_ptr<Context> context = std::make_shared<Context>();
  std::shared_ptr<BuilderFactoryInterface> builder_factory = std::make_shared<BuilderFactory>();
  std::shared_ptr<VisitorFactoryInterface> visitor_factory = std::make_shared<VisitorFactory>();
  std::shared_ptr<IOStreamInterface> outputer = std::make_shared<IOStream>();
  std::shared_ptr<InputStateMachineCreatorInterface> creator = std::make_shared<InputStateMachineCreator>();
  std::string target_str = "localhost:50051";
  std::shared_ptr<Client>
      service = std::make_shared<Client>(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
  return StateMachine(base, context, builder_factory, visitor_factory, outputer, service, creator);
}
