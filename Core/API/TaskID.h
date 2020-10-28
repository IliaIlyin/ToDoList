//
// Created by Ilya on 5/20/2020
//

#ifndef TODOLIST_TASKID_H
#define TODOLIST_TASKID_H

#include "Task.h"
/*
 * class to represent the uniqueness of classes containing task
 * @see Task
 */
class TaskID {

 public:
  TaskID() = default;
  /*
   * constructs the object on the id
   */
  TaskID(int id);

  int getId() const;

 private:
  int id;
};

bool operator==(const TaskID &id, const TaskID &id2);

bool operator<(const TaskID &id, const TaskID &id2);

#endif //TODOLIST_TASKID_H
