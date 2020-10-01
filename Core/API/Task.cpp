//
// Created by Ilya on 5/20/2020.
//

#include "Task.h"

#include <utility>

Task::Task(std::string name, boost::gregorian::date date, Task::Priority priority, std::string label) : name(std::move(
    name)),
                                                                                                        date(date),
                                                                                                        priority(
                                                                                                            priority),
                                                                                                        label(std::move(
                                                                                                            label)) {

}

const std::string &Task::getName() const {
  return name;
}

boost::gregorian::date Task::getDate() const {
  return date;
}

Task::Priority Task::getPriority() const {
  return priority;
}

const std::string &Task::getLabel() const {
  return label;
}

Task Task::createTask(std::string name, boost::gregorian::date date, Task::Priority priority, std::string label) {
  return Task(name, date, priority, label);
}

bool operator==(const Task &task, const Task &task2) {
  return task.getPriority() == task2.getPriority() &&
      task.getLabel() == task2.getLabel() &&
      task.getName() == task2.getName() &&
      task.getDate() == task2.getDate();
}

std::ostream &operator<<(std::ostream &os, const Task::Priority &priority1) {
  switch (priority1) {
    case Task::Priority::NONE :os << "No priority set";
      break;
    case Task::Priority::FIRST :os << "First priority";
      break;
    case Task::Priority::SECOND :os << "Second priority";
      break;
    case Task::Priority::THIRD :os << "Third priority";
      break;
  }
  return os;
}

Task::Priority getPriorityFromString(std::string s) {
  if (s == "NONE" || s == "FIRST" || s == "SECOND" || s == "THIRD")
    if (s == "FIRST")
      return Task::Priority::FIRST;
  if (s == "SECOND")
    return Task::Priority::SECOND;
  if (s == "THIRD")
    return Task::Priority::THIRD;
  if (s == "NONE")
    return Task::Priority::NONE;
  return Task::Priority::NONE;
}
