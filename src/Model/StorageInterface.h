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
  virtual  std::shared_ptr<TaskEntity> addTask(TaskEntity &task_entity)=0;
/*
 * deletes task from the storage
 *
 * @param task_entity Id of the task to delete
 *
 * @return true, if task was found
 * @return false, otherwise
 */
  virtual  bool deleteTask(const TaskID &task_entity)=0;

  /*
* gets the task from the storage
*
* @param id Id of the task to delete
*
* @return true, if task was found
* @return false, otherwise
*/
  virtual  std::optional<std::shared_ptr<TaskEntity>> getTask(TaskID id)=0;

};


#endif //TODOLIST_SRC_MODEL_STORAGEINTERFACE_H_
