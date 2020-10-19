//
// Created by Ilya on 9/14/2020.
//

#ifndef TODOLIST_CLI_FACTORIES_INPUTVALIDATOR_H_
#define TODOLIST_CLI_FACTORIES_INPUTVALIDATOR_H_

#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

/*
 * class that contains methods to validate input data needed to build Task
 *
 * @see Task
 *
 * @author Ilya Ilyin
 */
class GeneralInputValidator {

 public:
  /*
   * enum class to represent the validation result
   */
  enum class InputToken {
    INCORRECT_INPUT_NAME,
    INCORRECT_INPUT_DATE,
    INCORRECT_INPUT_PRIORITY,
    INCORRECT_INPUT_LABEL,
    INCORRECT_INPUT_ID,
    CANCEL_COMMAND,
    CORRECT,
    SUCCESS,
  };

 public:
  /*
   * method that transforms Input Token to string to show user
   *
   * @return transformed string
   */
  static std::string interpretResult(InputToken result);

 public:
  /*
   * validates task name
   *
   * @input string to validate
   *
   * @return CORRECT if the string can be a task name
   * @return INCORRECT_INPUT_NAME if the string cannot be a task name
   * @return CANCEL_COMMAND if isNotCancelled(s) return CANCEL_COMMAND
   */
  static InputToken validateName(const std::string &s);
  /*
   * validates task date
   *
   * @input string to validate
   *
   * @return CORRECT if the string can be a task date
   * @return INCORRECT_INPUT_NAME if the string cannot be a task date
   * @return CANCEL_COMMAND if isNotCancelled(s) return CANCEL_COMMAND
 */
  static InputToken validateDate(const std::string &s);
  /*
 * validates task priority
   *
   * @input string to validate
   *
   * @return CORRECT if the string can be a task priority
   * @return INCORRECT_INPUT_NAME if the string cannot be a task priority
   * @return CANCEL_COMMAND if isNotCancelled(s) return CANCEL_COMMAND
 */
  static InputToken validatePriority(const std::string &s);
  /*
 * validates task label
   *
   * @input string to validate
   *
   * @return CORRECT if the string can be a task priority
   * @return INCORRECT_INPUT_NAME if the string cannot be a task priority
   * @return CANCEL_COMMAND if isNotCancelled(s) return CANCEL_COMMAND
 */
  static InputToken validateLabel(const std::string &s);
  /*
 * validates task id
   *
   * @input string to validate
   *
   * @return CORRECT if the string can be a task id
   * @return INCORRECT_INPUT_NAME if the string cannot be a task id
   * @return CANCEL_COMMAND if isNotCancelled(s) return CANCEL_COMMAND
 */
  static InputToken validateId(const std::string &s);
  /*
 * checks whether the command is cancelled
   *
   * @input string to check
   *
   * @return CANCEL_COMMAND if the string is "cancel command"
   * @return false, otherwise
 */
  static InputToken isNotCancelled(const std::string &s);
};

#endif //TODOLIST_CLI_FACTORIES_INPUTVALIDATOR_H_
