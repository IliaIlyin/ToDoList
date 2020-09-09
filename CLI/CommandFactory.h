//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDFACTORY_H_
#define TODOLIST_CLI_COMMANDFACTORY_H_

#include "Command.h"
#include "Tokenizer.h"

#include "Commands/Other/CompleteTaskCommand.h"
#include "Commands/Add/AddSubTaskCommand.h"
#include "Commands/Add/AddTaskCommand.h"
#include "Commands/Show/ShowAll/ShowAllByLabelCommand.h"
#include "Commands/Get/GetTaskCommand.h"
#include "Commands/Get/GetSubtasksCommand.h"
#include "Commands/Other/PostponeTaskCommand.h"
#include "Commands/Other/DeleteTaskCommand.h"
#include "Commands/Other/CompleteTaskCommand.h"
#include "Commands/ShowTodayCommand.h"
#include "Commands/Show/ShowDueDate/ShowDueDateByDateCommand.h"
#include "Commands/Show/ShowDueDate/ShowDueDateByDateCommand.h"

#include <memory>

class CommandFactory {
 public:
  std::unique_ptr<Command> create(const Tokenizer::CommandToken&);
};

#endif //TODOLIST_CLI_COMMANDFACTORY_H_
