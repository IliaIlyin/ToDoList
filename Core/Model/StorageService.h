//
// Created by Ilya on 8/1/2020.
//

#ifndef TODOLIST_MODEL_STORAGESERVICE_H_
#define TODOLIST_MODEL_STORAGESERVICE_H_

#include "Storage.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "Model/StorageServiceInterface.h"
#include <optional>
#include <fstream>
/*
 * class that operates storage
 */
class StorageService : public StorageServiceInterface {
 public:
  StorageService(std::unique_ptr<StorageInterface> interface);
 public:
  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID &parent,
                                                                Task &task,
                                                                bool status) override;
  std::shared_ptr<TaskEntity> addTask(Task &task, bool status) override;

  std::shared_ptr<TaskEntity> addTask(Task &task) override;

  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID &parent, Task &task) override;

  std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID &id) override;

  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID &id) override;

 public:

  bool postponeTask(const TaskID &task, boost::gregorian::date dueDate) override;

  bool deleteTask(const TaskID &task) override;

  bool completeTask(const TaskID &task) override;

  std::vector<std::shared_ptr<TaskEntity>> getAllTasks() override;

 private:
  std::unique_ptr<StorageInterface> storage_;
  IdGenerator id_generator_;
};

#endif //TODOLIST_MODEL_STORAGESERVICE_H_
