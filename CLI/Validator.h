//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_VALIDATOR_H_
#define TODOLIST_CLI_VALIDATOR_H_
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/algorithm/string.hpp>
class Validator {
 enum class ValidateResult{
   CORRECT,
   INCORRECT_COMMAND,
   INCORRECT_INPUT,
 };
 static ValidateResult validateShowAll(std::string s);
 static ValidateResult validateShowToday(std::string s);
 static ValidateResult validateShowLabel(std::string s);
 static ValidateResult validateShowDueDate(std::string s);
 static ValidateResult validateAddTask(std::string s);
 static ValidateResult validateAddSubTask(std::string s);
 static ValidateResult validateGetTask(std::string s);
 static ValidateResult validateGetSubTasks(std::string s);
 static ValidateResult validatePostponeTask(std::string s);
 static ValidateResult validateCompleteTask(std::string s);
 static ValidateResult validateDeleteTask(std::string s);

};

#endif //TODOLIST_CLI_VALIDATOR_H_
