//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_CONTEXTS_ADDCONTEXT_H_
#define TODOLIST_CLI_CONTEXTS_ADDCONTEXT_H_
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "API/Task.h"
class AddContext {

 public:
  void SetName(const std::string &name);
  void SetDate(const boost::gregorian::date &date);
  void SetPriority(Task::Priority priority);
  void SetLabel(const std::string &label);

 public:
  const std::string &getName() const;
  const boost::gregorian::date &getDate() const;
  Task::Priority getPriority() const;
  const std::string &getLabel() const;
  
 private:
  std::string name_;
  boost::gregorian::date date_;
  Task::Priority priority_;
  std::string label_;
};

#endif //TODOLIST_CLI_CONTEXTS_ADDCONTEXT_H_
