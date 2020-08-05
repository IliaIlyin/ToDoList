//
// Created by Ilya on 8/1/2020.
//

#ifndef TODOLIST_MODEL_STORAGESERVICE_H_
#define TODOLIST_MODEL_STORAGESERVICE_H_
#include "Storage.h"

#include <optional>

class StorageService {

 public:
  std::shared_ptr<TaskEntity> addTask(std::string taskName, time_t date = 0,
                                      Task::Priority priority = Task::Priority::NONE, std::string label = "");
  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent,
                                                                std::string taskName,
                                                                time_t date = 0,
                                                                Task::Priority priority = Task::Priority::NONE,
                                                                std::string label = "");
  std::shared_ptr<TaskEntity> addTask(Task &task);
  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent, Task &task);
  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent, TaskEntity &task_entity);
  std::optional<std::shared_ptr<TaskEntity>> getTask(TaskEntity &task_entity);

 public:
  bool postponeTask(TaskEntity &task, time_t dueDate);
  bool deleteTask(TaskEntity &task);
  bool completeTask(TaskEntity &task);

 private:
  Storage     storage_;
  IdGenerator id_generator_;
};

#endif //TODOLIST_MODEL_STORAGESERVICE_H_
