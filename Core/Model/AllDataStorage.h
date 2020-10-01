//
// Created by Ilya on 8/3/2020.
//

#ifndef TODOLIST_MODEL_ALLDATASTORAGE_H_
#define TODOLIST_MODEL_ALLDATASTORAGE_H_

#include "Views/ViewService.h"
#include "StorageService.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "AllDataStorageInterface.h"
/*
 * class to store views and main data storage
 */
class AllDataStorage : public AllDataStorageInterface {
 public:
  AllDataStorage(std::unique_ptr<StorageServiceInterface> interface);
 public:
  TaskID addTask(Task &task, bool status) override;
  std::optional<TaskID> addSubTaskToParent(const TaskID  &parent, Task &task, bool status) override;
  /*
   * adds task to storage and updates views
   *
   * @param task Task to Add
   *
   * @return true, if adding was completed succesfully.
   * @return false, otherwise.
*/
  bool addTask(Task &task) override;
  /*
   * adds subtask to parent and updates views
   *
   * @param parent Task to Add to
   * @param task Task to Add
   *
   * @return true, if adding was completed succesfully.
   * @return false, otherwise.
*/
  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID &parent, Task &task) override;

  /*
   * gets Task by id
   *
   * @return shared_ptr on task, if the task was found
   * @return nullptr, it it wasn't found
   */
  std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID &id) override;
  /*
   * gets subTasks of the Task by its id
   *
   * @return container of subTasks, if the task was found
   * @return nullptr, it it wasn't found
   */
  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID &id) override;

 public:
  /*
   * postpones the task by id
   *
   * @param task id of the task to be postponed
   * @param dueDate new date of the task to expire
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  bool postponeTask(const TaskID &task, boost::gregorian::date dueDate) override;
/*
   * deletes the task by id. Also deletes subTasks
   *
   * @param task id of the task to be deleted
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  bool deleteTask(const TaskID &task) override;
/*
   * completes the task by id. Also completes subTasks
   *
   * @param task id of the task to be completed
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  bool completeTask(const TaskID &task) override;
  std::vector<std::shared_ptr<TaskEntity>> getAllTasks() override;
 public:
  const ViewService &getViewService() const override;

 private:
  ViewService view_service_;
  std::unique_ptr<StorageServiceInterface> storage_service_;
};

#endif //TODOLIST_MODEL_ALLDATASTORAGE_H_
