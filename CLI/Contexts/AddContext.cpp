//
// Created by illia.ilin on 8/28/2020.
//

#include "AddContext.h"
const std::string &AddContext::getName() const {
  return name_;
}
const boost::gregorian::date &AddContext::getDate() const {
  return date_;
}
Task::Priority AddContext::getPriority() const {
  return priority_;
}
const std::string &AddContext::getLabel() const {
  return label_;
}
void AddContext::SetName(const std::string &name) {
  name_ = name;
}
void AddContext::SetDate(const boost::gregorian::date &date) {
  date_ = date;
}
void AddContext::SetPriority(Task::Priority priority) {
  priority_ = priority;
}
void AddContext::SetLabel(const std::string &label) {
  label_ = label;
}
