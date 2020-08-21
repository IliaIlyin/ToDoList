//
// Created by illia.ilin on 8/20/2020.
//

#include "Validator.h"
Validator::ValidateResult Validator::validateShowAll(std::string s) {
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
Validator::ValidateResult Validator::validateShowToday(std::string s) {
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
Validator::ValidateResult Validator::validateShowLabel(std::string s) {
  std::string f = "show label ";
  if (s.substr(0, f.size()) == f) {
    if (s.substr(f.size(), s.size()) != "")
      return ValidateResult::CORRECT;
    return ValidateResult::INCORRECT_INPUT;
  }
  return ValidateResult::INCORRECT_COMMAND;
}
Validator::ValidateResult Validator::validateShowDueDate(std::string s) {
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
Validator::ValidateResult Validator::validateAddTask(std::string s) {
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
