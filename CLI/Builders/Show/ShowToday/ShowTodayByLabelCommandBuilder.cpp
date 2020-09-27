//
// Created by Ilya on 9/15/2020.
//

#include "ShowTodayByLabelCommandBuilder.h"
std::shared_ptr<Command> ShowTodayByLabelCommandBuilder::buildCommand(std::shared_ptr<TaskService> service) {
  return std::make_shared<ShowTodayByLabelCommand>(service);
}
