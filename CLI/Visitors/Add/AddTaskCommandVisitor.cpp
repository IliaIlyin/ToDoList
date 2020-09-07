//
// Created by illia.ilin on 9/7/2020.
//

#include "AddTaskCommandVisitor.h"
bool AddTaskCommandVisitor::visitAddTaskCommand(AddTaskCommand &command) {
 return command.execute();
}