//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_MODEL_TASKDTO_H_
#define TODOLIST_MODEL_TASKDTO_H_

#include "Task.h"
#include "IdGenerator.h"
#include "TaskID.h"
#include <memory>

class TaskDTO {
 public:

  TaskDTO(const Task &task, const TaskID &id, bool status,
          const std::vector<std::shared_ptr<TaskDTO>> &subtasks); //copy

  static TaskDTO createTaskDTO(const Task &task, IdGenerator &idGenerator);

 public:

  const Task &getTask() const;

  const TaskID &getTaskId() const;

  bool checkStatus() const;

  const std::vector<std::shared_ptr<TaskDTO>> &getSubtasks() const;

  void addsubtask(std::shared_ptr<TaskDTO> TaskDTO);

  bool operator==(const TaskDTO &t) const;

 private:

  TaskDTO(const Task &task, IdGenerator &idGenerator);

 private:
  Task                                  task;
  TaskID                                taskID;
  bool                                  status;
  std::vector<std::shared_ptr<TaskDTO>> subtasks;
};

#endif //TODOLIST_MODEL_TASKDTO_H_
