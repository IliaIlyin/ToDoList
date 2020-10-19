//
// Created by Ilya on 9/15/2020.
//

#include "ShowAllByLabelCommandBuilder.h"
std::shared_ptr<Command> ShowAllByLabelCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  return std::make_shared<ShowAllByLabelCommand>(service);
}
