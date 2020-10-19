//
// Created by illia.ilin on 8/17/2020.
//

#ifndef TODOLIST_SRC_MODEL_STORAGEINTERFACE_H_
#define TODOLIST_SRC_MODEL_STORAGEINTERFACE_H_

#include "TaskEntity.h"
#include "HashTaskID.h"

#include<optional>
#include<unordered_map>

/*
 * main storage of TaskEntity objects
 */
class StorageInterface {

 public:
  /*
 * adds task entity to the storage
 *
 * @param task_entity entity to add
 *
 * @return pointer to the added entity in the storage
 */
  virtual std::shared_ptr<TaskEntity> addTask(const TaskEntity &task_entity) = 0;
/*
 * deletes task from the storage
 *
 * @param task_entity Id of the task to delete
 *
 * @return true, if the task was found and deleted
 * @return false, otherwise
 */
  virtual bool deleteTask(const TaskID &task_entity) = 0;
  /*
* gets the task from the storage
*
* @param id Id of the task to find
*
* @return pointer to the entity in the storage, if the task was found;
* @return nullopt, otherwise
*/
  virtual std::optional<std::shared_ptr<TaskEntity>> getTask(TaskID id) = 0;
/*
 * gets all tasks from the storage
 *
 * @return container of pointers to the tasks
 */

  virtual std::vector<std::shared_ptr<TaskEntity>> getAllTasks() = 0;

  virtual ~StorageInterface()=default;

};

#endif //TODOLIST_SRC_MODEL_STORAGEINTERFACE_H_
