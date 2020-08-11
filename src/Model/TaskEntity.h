//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKENTITY_H
#define TODOLIST_TASKENTITY_H

#include "Task.h"
#include "IdGenerator.h"
#include "TaskID.h"
#include <memory>
/*
 *class that represents task information for concrete user in the model.
 * Wraps Task and additionally stores task status, subtasks, id.
 *
 * @see Task
 *
 * @author Ilya Ilyin
 */
class TaskEntity {

public:
/*
 * static method to create task entity.
 *
 * @param task to wrap
 * @param idGenerator to generate id for entity
 * @return a new TaskEntity instance
 */
    static TaskEntity createTaskEntity(const Task &task, IdGenerator &idGenerator);

public:
     /*
      * copy constructor.
      */
    TaskEntity(const Task &task, const TaskID &id, bool status,
               const std::vector<std::shared_ptr<TaskEntity>> &subtasks);
public:

    const Task &getTask() const;

    const TaskID &getTaskId() const;

    bool checkStatus() const;

    const std::vector<std::shared_ptr<TaskEntity>> &getSubtasks() const;

public:
/*
 * sets status = true
 */
    void completeTask();
/*
 * adds subtask to the instance.
 *
 * @param taskEntity shared_ptr to the entity that is to be added
 */
    void addsubtask(std::shared_ptr<TaskEntity> taskEntity);

private:

    TaskEntity(const Task &task, IdGenerator &idGenerator);

private:
    Task task_;
    TaskID taskID_;
    bool status_;
    std::vector<std::shared_ptr<TaskEntity>> subtasks_;
};
bool operator==(const TaskEntity &t, const TaskEntity & t2);

#endif //TODOLIST_TASKENTITY_H
