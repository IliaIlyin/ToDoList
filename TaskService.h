//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKSERVICE_H
#define TODOLIST_TASKSERVICE_H

#include"View.h"
#include"HashTaskEntity.h"
#include"TaskEntity.h"
#include"IdGenerator.h"

#include<map>
#include<vector>
#include<memory>

class TaskService {

public:
    void postponeTask(std::shared_ptr<TaskEntity>  task, time_t dueDate);
    void deleteTask(std::shared_ptr<TaskEntity>  task);
    void completeTask(std::shared_ptr<TaskEntity>  task);

public:
    void addTask(std::string taskName, time_t date = 0,
            Task::Priority priority=Task::Priority::NONE,std::string label="");
    void addSubTaskToParent(std::shared_ptr<TaskEntity>  parent, std::string taskName, time_t date =0,
            Task::Priority priority=Task::Priority::NONE,std::string label="" );
    void addTask(Task& task);
    void addSubTaskToParent(std::shared_ptr<TaskEntity>  parent, Task& task);
public:
    void showAllByPriority();
    void showAllByLabel();
    void showAllByDate();
    void showTodayByPriority();
    void showTodayByLabel();
    void showDueDateByPriority(time_t date);
    void showDueDateByLabel(time_t date);
    void showDueDateByDate(time_t date);

public://for test
    IdGenerator &getIdGenerator();

private:
    void cleanPrioritiesWithCertainPriority(Task::Priority priority); //deletes null ptrs from priorities
    void cleanDatesWithCertainDate(time_t date);//deletes null ptrs from dates
    void cleanLabelsWithCertainLabel(std::string label); //deletes null ptrs from labels

public: //for test
    void insertEntity(std::shared_ptr<TaskEntity> entity);
private:
    View view;
    IdGenerator idGenerator;
    std::unordered_set< std::shared_ptr<TaskEntity>, HashTaskEntity > tasks;
    std::multimap<Task::Priority, std::weak_ptr<TaskEntity> > priorities;
    std::multimap<time_t,std::weak_ptr<TaskEntity> > dates;
    std::multimap<std::string,std::weak_ptr<TaskEntity> > labels;
};


#endif //TODOLIST_TASKSERVICE_H
