//
// Created by Ilya on 8/3/2020.
//

#ifndef TODOLIST_MODEL_ALLDATASTORAGE_H_
#define TODOLIST_MODEL_ALLDATASTORAGE_H_

#include "Views/ViewService.h"
#include "StorageService.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "AllDataStorageInterface.h"
#include "Views/ViewServiceInterface.h"
/*
 * class to store views and main data storage
 */
class AllDataStorage : public AllDataStorageInterface {

 public:
  //view service is set by default
  AllDataStorage(std::unique_ptr<StorageServiceInterface> interface);
  //sets custom view service
  AllDataStorage(std::unique_ptr<StorageServiceInterface> interface, std::shared_ptr<ViewServiceInterface> service);

 public:
  TaskID addTask(Task &task, bool status) override;

  std::optional<TaskID> addSubTaskToParent(const TaskID &parent, Task &task, bool status) override;

  bool addTask(Task &task) override;

  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID &parent, Task &task) override;

  std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID &id) override;

  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID &id) override;

 public:

  bool postponeTask(const TaskID &task, boost::gregorian::date dueDate) override;

  bool deleteTask(const TaskID &task) override;

  bool completeTask(const TaskID &task) override;

  std::vector<std::shared_ptr<TaskEntity>> getAllTasks() override;
 public:
  std::shared_ptr<ViewServiceInterface> getViewService() const override;

 private:
  std::shared_ptr<ViewServiceInterface> view_service_;
  std::unique_ptr<StorageServiceInterface> storage_service_;
};

#endif //TODOLIST_MODEL_ALLDATASTORAGE_H_
