//
// Created by illia.ilin on 8/20/2020.
//

#include "Validator.h"
Validator::ValidateResult Validator::validateShowAll(const std::string& s) {
  std::string f = "show all";
  if (s == f) {
    return ValidateResult::CORRECT;
  }
  std::string f2 = "show all sort priority";
  if (s == f2) {
    return ValidateResult::CORRECT;
  } else {
    return ValidateResult::INCORRECT_COMMAND;
  }
}
Validator::ValidateResult Validator::validateShowToday(const std::string& s) {
  std::string f = "show today";
  if (s == f) {
    return ValidateResult::CORRECT;
  }
  std::string f2 = "show today sort priority";
  if (s == f2) {
    return ValidateResult::CORRECT;
  } else {
    return ValidateResult::INCORRECT_COMMAND;
  }
}
Validator::ValidateResult Validator::validateShowLabel(const std::string& s) {
  std::string f = "show label ";
  if (s.substr(0, f.size()) == f) {
    if (s.substr(f.size(), s.size()) != "")
      return ValidateResult::CORRECT;
    return ValidateResult::INCORRECT_INPUT;
  }
  return ValidateResult::INCORRECT_COMMAND;
}
Validator::ValidateResult Validator::validateShowDueDate(const std::string& s) {
  std::string f = "show due date ";
  if (s.substr(0, f.size()) == f) {
    try {
      boost::gregorian::from_string(s.substr(f.size() + 2, s.size()));
      return ValidateResult::CORRECT;
    }
    catch (...) {
      return ValidateResult::INCORRECT_INPUT;
    }
  }
  return ValidateResult::INCORRECT_COMMAND;
}
Validator::ValidateResult Validator::validateAddTask(const std::string& s) {
  std::vector<std::string> results;
  boost::split(results, s, [](char c) { return c == ' '; });
  int k = results.size();
  if(k<=2)
    return ValidateResult::INCORRECT_COMMAND;
  if (k >2  && results[0] == "add" && results[1] == "task"){

  }
  else{
    return ValidateResult::INCORRECT_COMMAND;

  }

  return ValidateResult::INCORRECT_COMMAND;
}

Validator::ValidateResult Validator::validateName(const std::string& s) {
  if(s!="")
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_INPUT_NAME;
}
Validator::ValidateResult Validator::validateDate(const std::string& s) {
  try {
    boost::gregorian::from_string(s);
    return ValidateResult::CORRECT;
  }
  catch (...) {
    return ValidateResult::INCORRECT_INPUT_DATE;
  }
}
Validator::ValidateResult Validator::validatePriority(const std::string &s) {
  if(s=="NONE" || s=="FIRST" || s=="SECOND" || s=="THIRD")
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_INPUT_PRIORITY;
}
Validator::ValidateResult Validator::validateLabel(const std::string &s) {
  if(s!="")
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_INPUT_LABEL;
}
