//
// Created by ilya on 17.10.20.
//

#ifndef TODOLIST_CLI_UTILS_INPUTCONTEXTCREATORINTERFACE_H_
#define TODOLIST_CLI_UTILS_INPUTCONTEXTCREATORINTERFACE_H_
#include "Contexts/InputContextInterface.h"
class InputContextCreatorInterface {
 public:
  virtual std::unique_ptr<InputContextInterface> create() = 0;
  virtual ~InputContextCreatorInterface() = default;
};

#endif //TODOLIST_CLI_UTILS_INPUTCONTEXTCREATORINTERFACE_H_
