//
// Created by Ilya on 8/3/2020.
//

#ifndef TODOLIST_MODEL_ALLDATASTORAGE_H_
#define TODOLIST_MODEL_ALLDATASTORAGE_H_

#include "Views/ViewService.h"
#include "StorageService.h"
#include "boost/date_time/gregorian/gregorian.hpp"
/*
 * class to store views and main data storage
 */
class AllDataStorage {
 public:
  AllDataStorage(std::unique_ptr<StorageServiceInterface> interface);
 public:
  /*
   * adds task to storage and updates views
   *
   * @param task Task to add
   *
   * @return true, if adding was completed succesfully.
   * @return false, otherwise.
*/
  bool addTask(Task &task);
  /*
   * adds subtask to parent and updates views
   *
   * @param parent Task to add to
   * @param task Task to add
   *
   * @return true, if adding was completed succesfully.
   * @return false, otherwise.
*/
  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID  &parent, Task &task);

  /*
   * gets Task by id
   *
   * @return shared_ptr on task, if the task was found
   * @return nullptr, it it wasn't found
   */
  std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID & id);
  /*
   * gets subTasks of the Task by its id
   *
   * @return container of subTasks, if the task was found
   * @return nullptr, it it wasn't found
   */
  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID & id);

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
  bool postponeTask(const TaskID & task, boost::gregorian::date dueDate);
/*
   * deletes the task by id. Also deletes subTasks
   *
   * @param task id of the task to be deleted
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  bool deleteTask(const TaskID & task);
/*
   * completes the task by id. Also completes subTasks
   *
   * @param task id of the task to be completed
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  bool completeTask(const TaskID &task);

 public:
  const ViewService &getViewService() const;

 private:
  ViewService view_service_;
  std::unique_ptr<StorageServiceInterface> storage_service_;
};

#endif //TODOLIST_MODEL_ALLDATASTORAGE_H_
