//
// Created by illia.ilin on 8/17/2020.
//

#ifndef TODOLIST_SRC_MODEL_STORAGESERVICEINTERFACE_H_
#define TODOLIST_SRC_MODEL_STORAGESERVICEINTERFACE_H_

#include "boost/date_time/gregorian/gregorian.hpp"
#include <optional>
#include "SerializeModel.pb.h"
/*
 * storage interface
 */
class StorageServiceInterface {

 public:
  virtual std::shared_ptr<TaskEntity> addTask(Task& task, bool status)=0;
  virtual std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID &parent,
                                                                        Task &task,
                                                                        bool status) = 0;
  /*
 * adds task to the model. If the task already exists, it Is
 * @param task Task to Add
 * @return ptr if adding was completed succesfully.
* @return false, otherwise.
 */
  virtual std::shared_ptr<TaskEntity> addTask(Task &task) = 0;
  /*
    * adds subtask to parent and updates views
    *
    * @param parent Task to Add to
    * @param task Task to Add
    *
    * @return true, if adding was completed succesfully.
    * @return false, otherwise.
 */
  virtual std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID &parent, Task &task) = 0;
  /*
   * gets task by id
   *
   * @param task id to look for
   *
   * @return shared_ptr to the entity in the storage if the task was found.
   * @return nullptr,otherwise.
   */
  virtual std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID &id) = 0;
  /*
   * gets subTasks by id
   *
   * @param task id to look for
   *
   * @return container of shared_ptr to the entities in the storage if the task was found.
   * @return nullptr,otherwise.
   */
  virtual std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID &id) = 0;

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
  virtual bool postponeTask(const TaskID &task, boost::gregorian::date dueDate) = 0;
/*
   * deletes the task by id. Also deletes subTasks
   *
   * @param task id of the task to be deleted
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  virtual bool deleteTask(const TaskID &task) = 0;
/*
   * completes the task by id. Also completes subTasks
   *
   * @param task id of the task to be completed
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  virtual bool completeTask(const TaskID &task) = 0;

  virtual std::vector<std::shared_ptr<TaskEntity>> getAllTasks() =0;

  virtual ~StorageServiceInterface() = default;
};

#endif //TODOLIST_SRC_MODEL_STORAGESERVICEINTERFACE_H_
