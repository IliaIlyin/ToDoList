//
// Created by Ilya on 8/1/2020.
//

#ifndef TODOLIST_MODEL_STORAGESERVICE_H_
#define TODOLIST_MODEL_STORAGESERVICE_H_

#include "Storage.h"
#include "boost/date_time/gregorian/gregorian.hpp"

#include <optional>

class StorageService {

 public:

  std::shared_ptr<TaskEntity> addTask(Task &task);

  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID  &parent, Task &task);

  std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID & id);

  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID & id);

 public:
  bool postponeTask(const TaskID &task, boost::gregorian::date dueDate);

  bool deleteTask(const TaskID & task);

  bool completeTask(const TaskID  &task);

 private:
  Storage storage_;
  IdGenerator id_generator_;
};

#endif //TODOLIST_MODEL_STORAGESERVICE_H_
