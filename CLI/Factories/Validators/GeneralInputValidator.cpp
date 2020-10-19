//
// Created by Ilya on 9/14/2020.
//

#include "GeneralInputValidator.h"
GeneralInputValidator::InputToken GeneralInputValidator::validateName(const std::string &s) {
  if (isNotCancelled(s) == InputToken::CORRECT) {
    if (s != "")
      return InputToken::CORRECT;
    return InputToken::INCORRECT_INPUT_NAME;
  }
  return InputToken::CANCEL_COMMAND;
}

GeneralInputValidator::InputToken GeneralInputValidator::validateDate(const std::string &s) {
  if (isNotCancelled(s) == InputToken::CORRECT) {
    try {
      boost::gregorian::from_string(s);
      return InputToken::CORRECT;
    }
    catch (...) {
      return InputToken::INCORRECT_INPUT_DATE;
    }
  }
  return InputToken::CANCEL_COMMAND;
}

GeneralInputValidator::InputToken GeneralInputValidator::validatePriority(const std::string &s) {
  if (isNotCancelled(s) == InputToken::CORRECT) {
    if (s == "NONE" || s == "FIRST" || s == "SECOND" || s == "THIRD")
      return InputToken::CORRECT;
    return InputToken::INCORRECT_INPUT_PRIORITY;
  }
  return InputToken::CANCEL_COMMAND;
}

GeneralInputValidator::InputToken GeneralInputValidator::validateLabel(const std::string &s) {
  if (isNotCancelled(s) == InputToken::CORRECT) {
    if (s != "")
      return InputToken::CORRECT;
    return InputToken::INCORRECT_INPUT_LABEL;
  }
  return InputToken::CANCEL_COMMAND;

}

GeneralInputValidator::InputToken GeneralInputValidator::validateId(const std::string &s) {
  if (isNotCancelled(s) == InputToken::CORRECT) {
    int num = std::stoi(s);
    if (s == std::to_string(num))
      return InputToken::CORRECT;
    return InputToken::INCORRECT_INPUT_ID;
  }
  return InputToken::CANCEL_COMMAND;

}
std::string GeneralInputValidator::interpretResult(GeneralInputValidator::InputToken result) {
  switch (result) {
    case InputToken::CORRECT:return "Correct input";
    case InputToken::INCORRECT_INPUT_DATE:return "Incorrect input date";
    case InputToken::INCORRECT_INPUT_ID:return "Incorrect input id";
    case InputToken::INCORRECT_INPUT_LABEL:return "Incorrect input label";
    case InputToken::INCORRECT_INPUT_NAME:return "Incorrect input task name";
    case InputToken::INCORRECT_INPUT_PRIORITY:return "Incorrect input priority";
    case InputToken::CANCEL_COMMAND:return "Command is cancelled";
  }
}
GeneralInputValidator::InputToken GeneralInputValidator::isNotCancelled(const std::string &s) {
  if (s == "cancel command")
    return InputToken::CANCEL_COMMAND;
  return InputToken::CORRECT;
}
