//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKENTITY_H
#define TODOLIST_TASKENTITY_H

#include "API/Task.h"
#include "IdGenerator.h"
#include "API/TaskID.h"
#include <memory>
/*
 *class that represents task information for concrete user in the model.
 * Wraps Task and additionally stores task status, SubTasks, id.
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
               const std::vector<std::shared_ptr<TaskEntity>> &SubTasks);
public:

    const Task &getTask() const;

    const TaskID &getTaskId() const;

    bool checkStatus() const;

    const std::vector<std::shared_ptr<TaskEntity>> &getSubTasks() const;

public:
/*
 * completes task (also completes subTasks)
 */
    void completeTask();
/*
 * adds SubTask to the instance.
 *
 * @param taskEntity shared_ptr to the entity that is to be added
 */
    void addSubTask(std::shared_ptr<TaskEntity> taskEntity);

private:

    TaskEntity(const Task &task, IdGenerator &idGenerator);

private:
    Task task_;
    TaskID taskID_;
    bool status_;
    std::vector<std::shared_ptr<TaskEntity>> SubTasks_;
};
bool operator==(const TaskEntity &t, const TaskEntity & t2);

#endif //TODOLIST_TASKENTITY_H
