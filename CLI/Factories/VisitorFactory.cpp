//
// Created by Ilya on 9/14/2020.
//

#include "VisitorFactory.h"

std::shared_ptr<Visitor> VisitorFactory::createVisitor(const GeneralCommandsValidator::CommandToken &token,
                                                       std::shared_ptr<Context> context) {
  switch (token) {
    case GeneralCommandsValidator::CommandToken::ADD_TASK:
      return std::make_shared<AddTaskCommandVisitor>();
    case GeneralCommandsValidator::CommandToken::ADD_SUBTASK:
      return std::make_shared<AddSubTaskCommandVisitor>();
    case GeneralCommandsValidator::CommandToken::DELETE_TASK:
      return std::make_shared<DeleteTaskCommandVisitor>();
    case GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_PRIORITY:
      return std::make_shared<ShowAllByPriorityCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_DATE:
      return std::make_shared<ShowAllByDateCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_LABEL:
      return std::make_shared<ShowAllByLabelCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_PRIORITY:
      return std::make_shared<ShowTodayByPriorityCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_LABEL:
      return std::make_shared<ShowTodayByLabelCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_DATE:
      return std::make_shared<ShowDueDateByDateCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_LABEL:
      return std::make_shared<ShowDueDateByLabelCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_PRIORITY:
      return std::make_shared<ShowDueDateByPriorityCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::COMPLETE_TASK:
      return std::make_shared<CompleteTaskCommandVisitor>();
    case GeneralCommandsValidator::CommandToken::POSTPONE_TASK:
      return std::make_shared<PostponeTaskCommandVisitor>();
    case GeneralCommandsValidator::CommandToken::GET_TASK:
      return std::make_shared<GetTaskCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::GET_SUBTASK:
      return std::make_shared<GetSubTaskCommandVisitor>(context);
    case GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND:break;
    case GeneralCommandsValidator::CommandToken::EXIT:break;
  }
}
