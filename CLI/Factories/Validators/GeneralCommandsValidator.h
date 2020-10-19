//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_COMMANDSVALIDATOR_H_
#define TODOLIST_CLI_COMMANDSVALIDATOR_H_
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/algorithm/string.hpp>
/*
 * class that checks whether the string can be a users' command
 *
 * @author Ilya Ilyin
 */
class GeneralCommandsValidator {

 public:
  /*
   * enum class to represent the validation result
   */
  enum class CommandToken {
    ADD_TASK,
    ADD_SUBTASK,
    DELETE_TASK,
    SHOW_ALL_SORT_PRIORITY,
    SHOW_ALL_SORT_DATE,
    SHOW_ALL_SORT_LABEL,
    SHOW_TODAY_SORT_PRIORITY,
    SHOW_TODAY_SORT_LABEL,
    SHOW_DUE_DATE_SORT_DATE,
    SHOW_DUE_DATE_SORT_LABEL,
    SHOW_DUE_DATE_SORT_PRIORITY,
    COMPLETE_TASK,
    POSTPONE_TASK,
    GET_TASK,
    GET_SUBTASK,
    INCORRECT_COMMAND,
    SAVE,
    LOAD,
    EXIT,
  };
 public:
  /*
  * method that transforms Command Token to string to show user
  *
  * @return transformed string
  */
  static std::string interpretResult(CommandToken result);

 public:
  /*
 * checks whether the string can represent show all command
 *
 * @input string to check
 *
 * @return SHOW_ALL_SORT_DATE if the string is "show all sort date"
 * @return SHOW_ALL_SORT_PRIORITY if the string is "show all sort priority"
 * @return SHOW_ALL_SORT_LABEL if the string is "show all sort label"
 * @return INCORRECT_COMMAND , otherwise
 */

  static CommandToken validateShowAll(const std::string &s);
  /*
 * checks whether the string can represent show today command
 *
 * @input string to check
 *
 * @return SHOW_TODAY_SORT_PRIORITY if the string is "show today sort priority"
 * @return SHOW_TODAY_SORT_LABEL if the string is "show today sort label"
 * @return INCORRECT_COMMAND , otherwise
 */
  static CommandToken validateShowToday(const std::string &s);
  /*
* checks whether the string can represent show due date command
*
* @input string to check
*
* @return SHOW_DUE_DATE_SORT_DATE if the string is "show due date sort date"
* @return SHOW_DUE_DATE_SORT_PRIORITY if the string is "show due date sort priority"
* @return SHOW_DUE_DATE_SORT_LABEL if the string is "show due date sort label"
* @return INCORRECT_COMMAND , otherwise
*/
  static CommandToken validateShowDueDate(const std::string &s);
/*
 * checks whether the string can represent add task command
 *
* @input string to check
*
* @return ADD_TASK if the string is "add task"
* @return INCORRECT_COMMAND , otherwise
 */
  static CommandToken validateAddTask(const std::string &s);
  /*
 * checks whether the string can represent add subTask command
 *
* @input string to check
*
* @return ADD_SUBTASK if the string is "add subTask"
* @return INCORRECT_COMMAND , otherwise
 */
  static CommandToken validateAddSubTask(const std::string &s);
  /*
 * checks whether the string can represent get task command
 *
* @input string to check
*
* @return GET_TASK if the string is "get task"
* @return INCORRECT_COMMAND , otherwise
 */
  static CommandToken validateGetTask(const std::string &s);
  /*
 * checks whether the string can represent get subTasks command
 *
* @input string to check
*
* @return GET_SUBTASK if the string is "get subTasks"
* @return INCORRECT_COMMAND , otherwise
 */
  static CommandToken validateGetSubTasks(const std::string &s);
  /*
 * checks whether the string can represent postpone task command
 *
* @input string to check
*
* @return POSTPONE_TASK if the string is "postpone task"
* @return INCORRECT_COMMAND , otherwise
 */
  static CommandToken validatePostponeTask(const std::string &s);
  /*
 * checks whether the string can represent complete task command
 *
* @input string to check
*
* @return COMPLETE_TASK if the string is "complete task"
* @return INCORRECT_COMMAND , otherwise
 */
  static CommandToken validateCompleteTask(const std::string &s);
  /*
* checks whether the string can represent delete task command
*
* @input string to check
*
* @return DELETE_TASK if the string is "delete task"
* @return INCORRECT_COMMAND , otherwise
*/
  static CommandToken validateDeleteTask(const std::string &s);
  /*
* checks whether the string can represent exit command
*
* @input string to check
*
* @return EXIT if the string is "exit"
* @return INCORRECT_COMMAND , otherwise
*/
  static CommandToken validateExit(const std::string &s);

  static CommandToken validateSave(const std::string &s);

  static CommandToken validateLoad(const std::string &s);

};

#endif //TODOLIST_CLI_COMMANDSVALIDATOR_H_
