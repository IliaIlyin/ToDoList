//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKENTITY_H
#define TODOLIST_TASKENTITY_H

#include "Task.h"
#include "IdGenerator.h"
#include "TaskID.h"
#include <memory>

class TaskEntity {

 public:

  static TaskEntity createTaskEntity(const Task &task, IdGenerator &idGenerator);

 public:

  TaskEntity(const Task &task, const TaskID &id, bool status,
             const std::vector<std::shared_ptr<TaskEntity>> &subtasks); //copy
 public:

  const Task &getTask() const;

  const TaskID &getTaskId() const;

  bool checkStatus() const;

  const std::vector<std::shared_ptr<TaskEntity>> &getSubtasks() const;

 public:

  void completeTask();

  void addsubtask(std::shared_ptr<TaskEntity> taskEntity);

  bool operator==(const TaskEntity &t) const;

 private:

  TaskEntity(const Task &task, IdGenerator &idGenerator);

 private:
  Task                                     task;
  TaskID                                   taskID;
  bool                                     status;
  std::vector<std::shared_ptr<TaskEntity>> subtasks;
};

#endif //TODOLIST_TASKENTITY_H
