//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDFACTORY_H_
#define TODOLIST_CLI_COMMANDFACTORY_H_

#include "Factories/validators/GeneralCommandsValidator.h"
#include "Builder.h"

#include "Builders/Add/AddSubTaskCommandBuilder.h"
#include "Builders/Add/AddTaskCommandBuilder.h"

#include "Builders/Get/GetSubTasksCommandBuilder.h"
#include "Builders/Get/GetTaskCommandBuilder.h"

#include "Builders/Other/CompleteTaskCommandBuilder.h"
#include "Builders/Other/DeleteTaskCommandBuilder.h"
#include "Builders/Other/PostponeTaskCommandBuilder.h"

#include "Builders/Show/ShowToday/ShowTodayByLabelCommandBuilder.h"
#include "Builders/Show/ShowToday/ShowTodayByPriorityCommandBuilder.h"

#include "Builders/Show/ShowAll/ShowAllByDateCommandBuilder.h"
#include "Builders/Show/ShowAll/ShowAllByLabelCommandBuilder.h"
#include "Builders/Show/ShowAll/ShowAllByPriorityCommandBuilder.h"

#include "Builders/Show/ShowDueDate/ShowDueDateByDateCommandBuilder.h"
#include "Builders/Show/ShowDueDate/ShowDueDateByLabelCommandBuilder.h"
#include "Builders/Show/ShowDueDate/ShowDueDateByPriorityCommandBuilder.h"

#include <memory>
/*
 * factory to build Builders
 *
 * @see Builder
 *
 * @author Ilya Ilyin
 */
class BuilderFactory {
 public:
  /*
   * method that creates command builder.
   *
   * @input token corresponding to the needed command
   *
   * @return pointer to the builder
   */
  std::shared_ptr<Builder> create(const GeneralCommandsValidator::CommandToken& token);
};

#endif //TODOLIST_CLI_COMMANDFACTORY_H_
