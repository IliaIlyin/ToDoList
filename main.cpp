#include <iostream>
#include "Validators/BaseStateValidator.h"
#include "States/BaseState.h"
#include "StateMachine.h"
int main() {
    std::cout<<"main test"<<std::endl;
    std::shared_ptr<int> ptr = std::make_shared<int>(42);
    std::shared_ptr<int> ptr1=std::make_shared<int>(1);
    ptr.swap(ptr1);

    std::shared_ptr<BaseStateValidator> validator=std::make_shared<BaseStateValidator>();
    std::shared_ptr<BaseState> base = std::make_shared<BaseState>(validator);
    std::shared_ptr<Context> context = std::make_shared<Context>();
    std::shared_ptr<BuilderFactory> builder_factory=std::make_shared<BuilderFactory>();;
    std::shared_ptr<VisitorFactory> visitor_factory=std::make_shared<VisitorFactory>();;
    StateMachine machine(base,context,builder_factory,visitor_factory);
    machine.run();
    return 0;
}
