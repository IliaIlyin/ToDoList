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
  std::shared_ptr<TaskEntity>
  addTask(std::string taskName, boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time),
          Task::Priority priority = Task::Priority::NONE, std::string label = "");

  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent,
                                                                std::string taskName,
                                                                boost::gregorian::date date = boost::gregorian::date(
                                                                    boost::gregorian::min_date_time),
                                                                Task::Priority priority = Task::Priority::NONE,
                                                                std::string label = "");

  std::shared_ptr<TaskEntity> addTask(Task &task);

  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent, Task &task);

  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(TaskEntity &parent, TaskEntity &task_entity);

  std::optional<std::shared_ptr<TaskEntity>> getTask(TaskID id);

  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(TaskID id);

 public:
  bool postponeTask(TaskEntity &task, boost::gregorian::date dueDate);

  bool deleteTask(TaskEntity &task);

  bool completeTask(TaskEntity &task);

 private:
  Storage storage_;
  IdGenerator id_generator_;
};

#endif //TODOLIST_MODEL_STORAGESERVICE_H_
