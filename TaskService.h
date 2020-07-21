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
    void postponeTask(TaskEntity& task, time_t dueDate);
    void deleteTask(TaskEntity& task);
    void completeTask(TaskEntity& task);

public:
    void addTask(std::string taskName, time_t date = 0,
            Task::Priority priority=Task::Priority::NONE,std::string label="");
    void addSubTaskToParent(TaskEntity& parent, std::string taskName, time_t date =0,
            Task::Priority priority=Task::Priority::NONE,std::string label="" );

public:
    std::vector<std::weak_ptr<TaskEntity>> showAllByPriority();
    std::vector<std::weak_ptr<TaskEntity>> showAllByLabel();
    std::vector<std::weak_ptr<TaskEntity>> showAllByDate();
    std::vector<std::weak_ptr<TaskEntity>> showTodayByPriority();
    std::vector<std::weak_ptr<TaskEntity>> showTodayByLabel();
    std::vector<std::weak_ptr<TaskEntity>> showDueDateByPriority(time_t date);
    std::vector<std::weak_ptr<TaskEntity>> showDueDateByLabel(time_t date);
    std::vector<std::weak_ptr<TaskEntity>> showDueDateByDate(time_t date);

private:
    void cleanPrioritiesWithCertainPriority(Task::Priority priority); //deletes null ptrs from priorities
    void cleanDatesWithCertainDate(time_t date);//deletes null ptrs from dates
    void cleanLabelsWithCertainLabel(std::string label); //deletes null ptrs from labels

private:
    void insertEntity(TaskEntity& entity);
private:
    View view;
    IdGenerator idGenerator;
    std::unordered_set< std::shared_ptr<TaskEntity>, HashTaskEntity > tasks;
    std::multimap<Task::Priority, std::weak_ptr<TaskEntity> > priorities;
    std::multimap<time_t,std::weak_ptr<TaskEntity> > dates;
    std::multimap<std::string,std::weak_ptr<TaskEntity> > labels;
};


#endif //TODOLIST_TASKSERVICE_H
