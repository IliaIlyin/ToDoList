//
// Created by ilya on 17.10.20.
//

#ifndef TODOLIST_CLI_UTILS_INPUTCONTEXTCREATOR_H_
#define TODOLIST_CLI_UTILS_INPUTCONTEXTCREATOR_H_
#include "Contexts/InputContext.h"
#include "InputContextCreatorInterface.h"
class InputContextCreator : public InputContextCreatorInterface {
 public:
  std::unique_ptr<InputContextInterface> create() override;
};

#endif //TODOLIST_CLI_UTILS_INPUTCONTEXTCREATOR_H_
