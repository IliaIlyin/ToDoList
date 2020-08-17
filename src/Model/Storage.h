//
// Created by Ilya on 7/31/2020.
//

#ifndef TODOLIST_MODEL_STORAGE_H_
#define TODOLIST_MODEL_STORAGE_H_

#include "TaskEntity.h"
#include "HashTaskID.h"

#include<optional>
#include<unordered_map>

/*
 * main storage of TaskEntity objects
 */
class Storage {

public:
    std::shared_ptr<TaskEntity> addTask(TaskEntity &task_entity);
/*
 * deletes task from the storage
 *
 * @param task_entity Id of the task to delete
 *
 * @return true, if task was found
 * @return false, otherwise
 */
    bool deleteTask(const TaskID &task_entity);

  /*
* gets the task from the storage
*
* @param id Id of the task to delete
*
* @return true, if task was found
* @return false, otherwise
*/
    std::optional<std::shared_ptr<TaskEntity>> getTask(TaskID id);

private:
    std::optional<std::shared_ptr<TaskEntity>> search(TaskID id, std::vector<std::shared_ptr<TaskEntity>> vector);

private:
    std::unordered_map<TaskID, std::shared_ptr<TaskEntity>, HashTaskID> tasks_;
};

#endif //TODOLIST_MODEL_STORAGE_H_
