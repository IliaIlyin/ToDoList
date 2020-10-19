//
// Created by ilya on 12.10.20.
//

#include "SaveCommandVisitor.h"

void SaveCommandVisitor::visitSaveCommand(SaveCommand &command) {
  command.execute();
  bool result = command.getSaveResult();
  if (result) {
    std::cout << "System has been saved" << std::endl;
  } else {
    std::cout << "Something went wrong. System is not saved." << std::endl;
  }
}