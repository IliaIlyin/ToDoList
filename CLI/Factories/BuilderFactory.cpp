//
// Created by illia.ilin on 8/31/2020.
//

#include "BuilderFactory.h"
std::shared_ptr<Builder> BuilderFactory::create(const GeneralCommandsValidator::CommandToken& token) {
  switch(token){
    case GeneralCommandsValidator::CommandToken::ADD_TASK:
      return std::make_shared<AddTaskCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::ADD_SUBTASK:
      return std::make_shared<AddSubTaskCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::DELETE_TASK:
      return std::make_shared<DeleteTaskCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_PRIORITY:
      return std::make_shared<ShowAllByPriorityCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_DATE:
      return std::make_shared<ShowAllByDateCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_LABEL:
      return std::make_shared<ShowAllByLabelCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_PRIORITY:
      return std::make_shared<ShowTodayByPriorityCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_LABEL:
      return std::make_shared<ShowTodayByLabelCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_DATE:
      return std::make_shared<ShowDueDateByDateCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_LABEL:
      return std::make_shared<ShowDueDateByLabelCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_PRIORITY:
      return std::make_shared<ShowDueDateByPriorityCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::COMPLETE_TASK:
      return std::make_shared<CompleteTaskCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::POSTPONE_TASK:
      return std::make_shared<PostponeTaskCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::GET_TASK:
      return std::make_shared<GetTaskCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::GET_SUBTASK:
      return std::make_shared<GetSubTasksCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND: /**/
      return std::make_shared<CompleteTaskCommandBuilder>();
    case GeneralCommandsValidator::CommandToken::EXIT:/**/
      return std::make_shared<CompleteTaskCommandBuilder>();
  }
}
