//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_COMMANDSVALIDATOR_H_
#define TODOLIST_CLI_COMMANDSVALIDATOR_H_
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/algorithm/string.hpp>
class CommandsValidator {

 public:
  enum class ValidateResult {
    CORRECT,
    INCORRECT_COMMAND,
    INCORRECT_INPUT_NAME,
    INCORRECT_INPUT_DATE,
    INCORRECT_INPUT_PRIORITY,
    INCORRECT_INPUT_LABEL,
    INCORRECT_INPUT_ID,
  };
 public:
  static std::string interpretResult(ValidateResult result);

 public:
  static ValidateResult validateName(const std::string &s);
  static ValidateResult validateDate(const std::string &s);
  static ValidateResult validatePriority(const std::string &s);
  static ValidateResult validateLabel(const std::string &s);
  static ValidateResult validateId(const std::string &s);

 public:
  static ValidateResult validateShowAll(const std::string &s);
  static ValidateResult validateShowToday(const std::string &s);
  static ValidateResult validateShowLabel(const std::string &s);
  static ValidateResult validateShowDueDate(const std::string &s);
  static ValidateResult validateAddTask(const std::string &s);
  static ValidateResult validateAddSubTask(const std::string &s);
  static ValidateResult validateGetTask(const std::string &s);
  static ValidateResult validateGetSubTasks(const std::string &s);
  static ValidateResult validatePostponeTask(const std::string &s);
  static ValidateResult validateCompleteTask(const std::string &s);
  static ValidateResult validateDeleteTask(const std::string &s);

};

#endif //TODOLIST_CLI_COMMANDSVALIDATOR_H_
