//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <ctime>
#include <vector>
#include <map>
#include <unordered_set>
#include <memory>
#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"

/*
 * class to represents Tasks in the system
 */
class Task {

public:
    enum class Priority {
        FIRST,
        SECOND,
        THIRD,
        NONE,
    };

public:
  /*
   * fabric method to create Task object
   *
  * @param name task name
  * @param date representing the date to complete task. Set to boost::gregorian::min_date_time by default
  * @param priority Task Priority. Set to NONE by default
  * @param label Task label. Set empty by default
  *
   * @return Task object
*/
    static Task
    createTask(std::string name, boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time),
               Task::Priority priority = Task::Priority::NONE,
               std::string label = "");

public:

    const std::string &getName() const;

    boost::gregorian::date getDate() const;

    Priority getPriority() const;

    const std::string &getLabel() const;

private:
    explicit Task(std::string name,
                  boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time),
                  Task::Priority priority = Task::Priority::NONE,
                  std::string label = "");

private:
    std::string name;
    boost::gregorian::date date;
    Priority priority;
    std::string label;
};

std::ostream &operator<<(std::ostream &os, const Task::Priority &priority1);

bool operator==(const Task &task, const Task& task2);

#endif //TODOLIST_TASK_H
