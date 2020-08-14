//
// Created by Ilya on 8/1/2020.
//

#ifndef TODOLIST_MODEL_STORAGESERVICE_H_
#define TODOLIST_MODEL_STORAGESERVICE_H_

#include "Storage.h"
#include "boost/date_time/gregorian/gregorian.hpp"

#include <optional>
/*
 * class that operates storage
 */
class StorageService {

 public:
/*
 * adds task to the model. If the task already exists, it Is
 * @param task Task to add
 * @return ptr if adding was completed succesfully.
* @return false, otherwise.
 */
  std::shared_ptr<TaskEntity> addTask(Task &task);

  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID  &parent, Task &task);
  /*
   * gets task by id
   *
   * @param task id to look for
   *
   * @return shared_ptr to the entity in the storage if the task was found.
   * @return nullptr,otherwise.
   */
  std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID & id);

  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID & id);

 public:
  bool postponeTask(const TaskID &task, boost::gregorian::date dueDate);

  bool deleteTask(const TaskID & task);

  bool completeTask(const TaskID  &task);

 private:
  Storage storage_;
  IdGenerator id_generator_;
};

#endif //TODOLIST_MODEL_STORAGESERVICE_H_
