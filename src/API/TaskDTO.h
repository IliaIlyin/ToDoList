//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_MODEL_TASKDTO_H_
#define TODOLIST_MODEL_TASKDTO_H_

#include "Model/Task.h"
#include "Model/IdGenerator.h"
#include "TaskID.h"
#include <memory>

class TaskDTO {
 public:

  TaskDTO(const Task &task, const TaskID &id, bool status); //copy

  static TaskDTO createTaskDTO(const Task &task, IdGenerator &idGenerator);

 public:

  const Task &getTask() const;

  const TaskID &getTaskId() const;

  bool checkStatus() const;

  bool operator==(const TaskDTO &t) const;

 private:

  TaskDTO(const Task &task, IdGenerator &idGenerator);

 private:
  Task   task_;
  TaskID task_id_;
  bool   status_;
};

#endif //TODOLIST_MODEL_TASKDTO_H_
