//
// Created by ilya on 12.10.20.
//

#include "LoadCommandVisitor.h"
void LoadCommandVisitor::visitLoadCommand(LoadCommand &command) {
  command.execute();
  bool result = command.getLoadResult();
  if (result) {
    std::cout << "System has loaded" << std::endl;
  } else {
    std::cout << "Wrong file. System is not loaded." << std::endl;
  }
}
