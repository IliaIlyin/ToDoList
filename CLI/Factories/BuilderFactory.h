//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDFACTORY_H_
#define TODOLIST_CLI_COMMANDFACTORY_H_

#include "Factories/Validators/GeneralCommandsValidator.h"
#include "Builder.h"
#include "BuilderFactoryInterface.h"
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

#include "Builders/Serialize/SaveCommandBuilder.h"
#include "Builders/Serialize/LoadCommandBuilder.h"
#include <memory>
#include "Utils/InputStateMachineCreator.h"
/*
 * factory to build Builders
 *
 * @see Builder
 *
 * @author Ilya Ilyin
 */
class BuilderFactory : public BuilderFactoryInterface {
 public:

  std::shared_ptr<Builder> create(const GeneralCommandsValidator::CommandToken &token,
                                  std::shared_ptr<InputStateMachineCreatorInterface> creator,
                                  std::shared_ptr<IOStreamInterface> outpute) override;

 public:
  std::shared_ptr<Builder> BuildAddTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                      std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildAddSubTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                         std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildDeleteTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                         std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildShowDueByDateCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                            std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildShowDueDateByLabelCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                 std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildShowDueDateByPriorityCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                    std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildCompleteTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                           std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildPostponeTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                           std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildGetTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                      std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildGetSubTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                         std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildSaveCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                   std::shared_ptr<IOStreamInterface> outpute) const override;
  std::shared_ptr<Builder> BuildLoadCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                   std::shared_ptr<IOStreamInterface> outpute) const override;
};

#endif //TODOLIST_CLI_COMMANDFACTORY_H_
