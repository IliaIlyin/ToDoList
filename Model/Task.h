//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <ctime>
#include<vector>
#include<map>
#include<unordered_set>
#include <memory>
#include<iostream>

class Task {

 public:
  enum class Priority {
    FIRST,
    SECOND,
    THIRD,
    NONE,
  };

 public:
  static Task createTask(std::string name, time_t date = 0, Task::Priority priority = Task::Priority::NONE,
                         std::string label = "");

 public:

  const std::string &getName() const;

  time_t getDate() const;

  Priority getPriority() const;

  const std::string &getLabel() const;
 public:
  bool operator==(const Task &task) const;

 private:
  explicit Task(std::string name, time_t date = 0, Task::Priority priority = Task::Priority::NONE,
                std::string label = "");

 private:
  std::string name;
  time_t date;
  Priority priority;
  std::string label;
};
std::ostream &operator<<(std::ostream &os, const Task::Priority &priority1);

#endif //TODOLIST_TASK_H
