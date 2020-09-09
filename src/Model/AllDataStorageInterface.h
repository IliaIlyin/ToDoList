//
// Created by illia.ilin on 8/17/2020.
//

#ifndef TODOLIST_SRC_MODEL_ALLDATASTORAGEINTERFACE_H_
#define TODOLIST_SRC_MODEL_ALLDATASTORAGEINTERFACE_H_

#include "Views/ViewService.h"
#include "StorageService.h"
#include "boost/date_time/gregorian/gregorian.hpp"
/*
 * class to store views and main data storage
 */
class AllDataStorageInterface {

 public:
  /*
   * adds task to storage and updates views
   *
   * @param task Task to Add
   *
   * @return true, if adding was completed succesfully.
   * @return false, otherwise.
*/
  virtual bool addTask(Task &task)=0;
  /*
   * adds subtask to parent and updates views
   *
   * @param parent Task to Add to
   * @param task Task to Add
   *
   * @return true, if adding was completed succesfully.
   * @return false, otherwise.
*/
  virtual std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID  &parent, Task &task)=0;

  /*
   * gets Task by id
   *
   * @return shared_ptr on task, if the task was found
   * @return nullptr, it it wasn't found
   */
 virtual std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID & id)=0;
  /*
   * gets subTasks of the Task by its id
   *
   * @return container of subTasks, if the task was found
   * @return nullptr, it it wasn't found
   */
  virtual std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID & id)=0;

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
  virtual bool postponeTask(const TaskID & task, boost::gregorian::date dueDate)=0;
/*
   * deletes the task by id. Also deletes subTasks
   *
   * @param task id of the task to be deleted
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  virtual bool deleteTask(const TaskID & task)=0;
/*
   * completes the task by id. Also completes subTasks
   *
   * @param task id of the task to be completed
   *
   * @return true, if the task was found
   * @return false otherwise
   */
  virtual bool completeTask(const TaskID &task)=0;
  virtual ~AllDataStorageInterface()=default;
 public:
  virtual const ViewService &getViewService() const =0;

};

#endif //TODOLIST_SRC_MODEL_ALLDATASTORAGEINTERFACE_H_
