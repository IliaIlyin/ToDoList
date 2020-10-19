//
// Created by ilya on 17.10.20.
//

#include "InputContextCreator.h"
std::unique_ptr<InputContextInterface> InputContextCreator::create() {
  return std::unique_ptr<InputContext>();
}
