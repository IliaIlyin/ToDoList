//
// Created by Ilya on 9/15/2020.
//

#include "ShowTodayByPriorityCommandBuilder.h"
std::shared_ptr<Command> ShowTodayByPriorityCommandBuilder::buildCommand(std::shared_ptr<TaskService> service) {
  return std::make_shared<ShowTodayByPriorityCommand>(service);
}
