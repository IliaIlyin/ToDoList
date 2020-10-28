#include <iostream>

#include "StateMachine.h"
int main() {
  StateMachine machine = StateMachine::CreateMachine();
  machine.run();
  return 0;
}
