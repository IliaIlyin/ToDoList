//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_MODEL_TASKDTO_H_
#define TODOLIST_MODEL_TASKDTO_H_

#include "Task.h"
#include "Model/IdGenerator.h"
#include "TaskID.h"
#include <memory>

/*
 * class for user intercourse with the API
 */
class TaskDTO {
 public:

  TaskDTO(const Task &task, const TaskID &id, bool status);

  /*
   * fabric method to create task
   *
   * @param task to wrap
   * @param idGenerator Generator that generates TaskID
   *
   * @return TaskDTO object
   */
  static TaskDTO createTaskDTO(const Task &task, IdGenerator &idGenerator);

 public:

  const Task &getTask() const;

  const TaskID &getTaskId() const;
/*
 * checks if the task is completed
 *
 * @return true, if it is. False, otherwise.
 */
  bool checkStatus() const;

 private:

  TaskDTO(const Task &task, IdGenerator &idGenerator);

 private:
  Task task_;
  TaskID task_id_;
  bool status_;
};
bool operator==(const TaskDTO &t, const TaskDTO &t2);

#endif //TODOLIST_MODEL_TASKDTO_H_
