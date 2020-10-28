//
// Created by ilya on 25.10.20.
//

#ifndef TODOLIST_CLI_FACTORIES_VALIDATORS_BUILDERFACTORYINTERFACE_H_
#define TODOLIST_CLI_FACTORIES_VALIDATORS_BUILDERFACTORYINTERFACE_H_
/*
* factory to build Builders
*
* @see Builder
*
* @author Ilya Ilyin
*/
#include "Builder.h"
#include "Input_Output/IOStreamInterface.h"
#include "Utils/InputStateMachineCreator.h"
#include "Factories/Validators/GeneralCommandsValidator.h"

class BuilderFactoryInterface {

 public:
  virtual ~BuilderFactoryInterface() = default;
  /*
   * method that creates command builder.
   *
   * @input token corresponding to the needed command
   *
   * @return pointer to the builder
   */
  virtual std::shared_ptr<Builder> create(const GeneralCommandsValidator::CommandToken &token,
                                          std::shared_ptr<InputStateMachineCreatorInterface> creator,
                                          std::shared_ptr<IOStreamInterface> outpute) = 0;

 public:
  virtual std::shared_ptr<Builder> BuildAddTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                              std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildAddSubTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                 std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildDeleteTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                 std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildShowDueByDateCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                    std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildShowDueDateByLabelCommandBuilder(std::shared_ptr<
      InputStateMachineCreatorInterface> &creator,
                                                                         std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildShowDueDateByPriorityCommandBuilder(std::shared_ptr<
      InputStateMachineCreatorInterface> &creator,
                                                                            std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildCompleteTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                   std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildPostponeTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                   std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildGetTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                              std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildGetSubTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                 std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildSaveCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                           std::shared_ptr<IOStreamInterface> outpute) const = 0;
  virtual std::shared_ptr<Builder> BuildLoadCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                           std::shared_ptr<IOStreamInterface> outpute) const = 0;

};
#endif //TODOLIST_CLI_FACTORIES_VALIDATORS_BUILDERFACTORYINTERFACE_H_
