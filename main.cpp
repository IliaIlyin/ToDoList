#include <iostream>
#include "Validators/BaseStateValidator.h"
#include "States/BaseState.h"
#include "StateMachine.h"
int main() {

    std::shared_ptr<BaseStateValidator> validator=std::make_shared<BaseStateValidator>();
    std::shared_ptr<BaseState> base = std::make_shared<BaseState>(validator);
    std::shared_ptr<Context> context = std::make_shared<Context>();
    std::shared_ptr<BuilderFactory> builder_factory=std::make_shared<BuilderFactory>();;
    std::shared_ptr<VisitorFactory> visitor_factory=std::make_shared<VisitorFactory>();;
    StateMachine machine(base,context,builder_factory,visitor_factory);
    machine.run();
    return 0;
}
