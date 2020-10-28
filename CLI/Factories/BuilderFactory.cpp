//
// Created by illia.ilin on 8/31/2020.
//

#include "BuilderFactory.h"
std::shared_ptr<Builder> BuilderFactory::create(const GeneralCommandsValidator::CommandToken &token,
                                                std::shared_ptr<InputStateMachineCreatorInterface> creator,
                                                std::shared_ptr<IOStreamInterface> outputer) {
  switch (token) {
    case GeneralCommandsValidator::CommandToken::ADD_TASK:return BuildAddTaskCommandBuilder(creator, outputer);
    case GeneralCommandsValidator::CommandToken::ADD_SUBTASK:return BuildAddSubTaskCommandBuilder(creator, outputer);
    case GeneralCommandsValidator::CommandToken::DELETE_TASK:return BuildDeleteTaskCommandBuilder(creator, outputer);
    case GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_PRIORITY:
      return std::make_shared<ShowAllByPriorityCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_DATE:return std::make_shared<ShowAllByDateCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_LABEL:
      return std::make_shared<ShowAllByLabelCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_PRIORITY:
      return std::make_shared<ShowTodayByPriorityCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_LABEL:
      return std::make_shared<ShowTodayByLabelCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_DATE:
      return BuildShowDueByDateCommandBuilder(creator,
                                              outputer);
    case GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_LABEL:
      return BuildShowDueDateByLabelCommandBuilder(creator,
                                                   outputer);
    case GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_PRIORITY:
      return BuildShowDueDateByPriorityCommandBuilder(creator,
                                                      outputer);
    case GeneralCommandsValidator::CommandToken::COMPLETE_TASK:
      return BuildCompleteTaskCommandBuilder(creator,
                                             outputer);
    case GeneralCommandsValidator::CommandToken::POSTPONE_TASK:
      return BuildPostponeTaskCommandBuilder(creator,
                                             outputer);
    case GeneralCommandsValidator::CommandToken::GET_TASK:return BuildGetTaskCommandBuilder(creator, outputer);
    case GeneralCommandsValidator::CommandToken::GET_SUBTASK:return BuildGetSubTaskCommandBuilder(creator, outputer);
    case GeneralCommandsValidator::CommandToken::SAVE:return BuildSaveCommandBuilder(creator, outputer);
    case GeneralCommandsValidator::CommandToken::LOAD:return BuildLoadCommandBuilder(creator, outputer);
    case GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND: /**/
      break;
    case GeneralCommandsValidator::CommandToken::EXIT:/**/
      break;
  }
}
std::shared_ptr<Builder> BuilderFactory::BuildLoadCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                 std::shared_ptr<IOStreamInterface> outputer) const {
  InputContext context;
  std::shared_ptr<LabelValidator> validator = std::make_shared<LabelValidator>();
  auto begin = std::make_shared<TaskLabelState>(validator,
                                                "Input file name or write cancel command to cancel command");
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<LoadCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildSaveCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                 std::shared_ptr<IOStreamInterface> outputer) const {
  InputContext context;
  std::shared_ptr<LabelValidator> validator = std::make_shared<LabelValidator>();
  auto begin = std::make_shared<TaskLabelState>(validator,
                                                "Input file name or write cancel command to cancel command");
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<SaveCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildGetSubTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                       std::shared_ptr<IOStreamInterface> outputer) const {
  std::shared_ptr<TaskIdValidator> validator = std::make_shared<TaskIdValidator>();
  auto begin = std::make_shared<TaskIdState<ExitState, ExitValidator>>(validator);
  InputContext context;
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<GetSubTasksCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildGetTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                    std::shared_ptr<IOStreamInterface> outputer) const {
  std::shared_ptr<TaskIdValidator> validator = std::make_shared<TaskIdValidator>();
  auto begin = std::make_shared<TaskIdState<ExitState, ExitValidator>>(validator);
  InputContext context;
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<GetTaskCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildPostponeTaskCommandBuilder(std::shared_ptr<
    InputStateMachineCreatorInterface> &creator, std::shared_ptr<IOStreamInterface> outputer) const {
  InputContext context;
  std::shared_ptr<TaskIdValidator> validator = std::make_shared<TaskIdValidator>();
  auto begin = std::make_shared<TaskIdState<TaskDateState<ExitState, ExitValidator>, DateValidator>>(validator);
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<PostponeTaskCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildCompleteTaskCommandBuilder(std::shared_ptr<
    InputStateMachineCreatorInterface> &creator, std::shared_ptr<IOStreamInterface> outputer) const {
  std::shared_ptr<TaskIdValidator> validator = std::make_shared<TaskIdValidator>();
  auto begin = std::make_shared<TaskIdState<ExitState, ExitValidator>>(validator);
  InputContext context;
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<CompleteTaskCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildShowDueDateByPriorityCommandBuilder(std::shared_ptr<
    InputStateMachineCreatorInterface> &creator, std::shared_ptr<IOStreamInterface> outputer) const {
  std::shared_ptr<DateValidator> validator = std::make_shared<DateValidator>();
  auto begin = std::make_shared<TaskDateState<ExitState, DateValidator>>(validator);
  InputContext context;
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<ShowDueDateByPriorityCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildShowDueDateByLabelCommandBuilder(std::shared_ptr<
    InputStateMachineCreatorInterface> &creator, std::shared_ptr<IOStreamInterface> outputer) const {
  std::shared_ptr<DateValidator> validator = std::make_shared<DateValidator>();
  auto begin = std::make_shared<TaskDateState<ExitState, DateValidator>>(validator);
  InputContext context;
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<ShowDueDateByLabelCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildShowDueByDateCommandBuilder(std::shared_ptr<
    InputStateMachineCreatorInterface> &creator, std::shared_ptr<IOStreamInterface> outputer) const {
  std::shared_ptr<DateValidator> validator = std::make_shared<DateValidator>();
  auto begin = std::make_shared<TaskDateState<ExitState, DateValidator>>(validator);
  InputContext context;
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<ShowDueDateByDateCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildDeleteTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                       std::shared_ptr<IOStreamInterface> outputer) const {
  std::shared_ptr<TaskIdValidator> validator = std::make_shared<TaskIdValidator>();
  InputContext context;
  auto begin = std::make_shared<TaskIdState<ExitState, ExitValidator>>(validator);
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<DeleteTaskCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildAddSubTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                       std::shared_ptr<IOStreamInterface> outputer) const {
  std::shared_ptr<TaskIdValidator> validator;
  auto begin = std::make_shared<TaskIdState<TaskNameState, TaskNameValidator>>(validator);
  InputContext context;
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<AddSubTaskCommandBuilder>(std::move(machine));
}
std::shared_ptr<Builder> BuilderFactory::BuildAddTaskCommandBuilder(std::shared_ptr<InputStateMachineCreatorInterface> &creator,
                                                                    std::shared_ptr<IOStreamInterface> outputer) const {
  std::shared_ptr<TaskNameValidator> validator = std::make_shared<TaskNameValidator>();
  auto begin = std::make_shared<TaskNameState>(validator);
  InputContext context;
  auto machine = creator->create(begin, context, outputer);
  return std::make_shared<AddTaskCommandBuilder>(std::move(machine));
}
