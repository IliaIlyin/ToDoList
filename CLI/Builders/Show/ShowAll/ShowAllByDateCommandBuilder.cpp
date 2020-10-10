//
// Created by Ilya on 9/15/2020.
//

#include "ShowAllByDateCommandBuilder.h"
std::shared_ptr<Command> ShowAllByDateCommandBuilder::buildCommand(std::shared_ptr<CoreAPIInterface> service) {
  return std::make_shared<ShowAllByDateCommand>(service);
}
