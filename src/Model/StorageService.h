//
// Created by Ilya on 8/1/2020.
//

#ifndef TODOLIST_MODEL_STORAGESERVICE_H_
#define TODOLIST_MODEL_STORAGESERVICE_H_

#include "Storage.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "Model/StorageServiceInterface.h"
#include <optional>
/*
 * class that operates storage
 */
class StorageService : StorageServiceInterface{
 public:
  StorageService(std::unique_ptr<StorageInterface> interface);
 public:
/*
 * adds task to the model. If the task already exists, it Is
 * @param task Task to add
 * @return ptr if adding was completed succesfully.
* @return false, otherwise.
 */
  std::shared_ptr<TaskEntity> addTask(Task &task) override ;
 /*
   * adds subtask to parent and updates views
   *
   * @param parent Task to add to
   * @param task Task to add
   *
   * @return true, if adding was completed succesfully.
   * @return false, otherwise.
*/
  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID  &parent, Task &task) override;
  /*
   * gets task by id
   *
   * @param task id to look for
   *
   * @return shared_ptr to the entity in the storage if the task was found.
   * @return nullptr,otherwise.
   */
  std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID & id) override;
  /*
   * gets subTasks by id
   *
   * @param task id to look for
   *
   * @return container of shared_ptr to the entities in the storage if the task was found.
   * @return nullptr,otherwise.
   */
  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID & id) override;

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
  bool deleteTask(const TaskID & task) override;
/*
   * completes the task by id. Also completes subTasks
   *
   * @param task id of the task to be completed
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  bool completeTask(const TaskID  &task) override;

 private:
  std::unique_ptr<StorageInterface> storage_;
  IdGenerator id_generator_;
};

#endif //TODOLIST_MODEL_STORAGESERVICE_H_
