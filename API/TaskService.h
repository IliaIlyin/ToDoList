//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKSERVICE_H
#define TODOLIST_TASKSERVICE_H

#include"../Display/Display.h"
#include"../Model/HashTaskEntity.h"
#include"../Model/TaskEntity.h"
#include"../Model/IdGenerator.h"
#include"../Views/LabelView.h"
#include"../Views/PriorityView.h"
#include"../Views/DateView.h"
#include"../Model/Storage.h"

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
    std::vector<std::weak_ptr<TaskEntity> > showAllByPriority();
    std::vector<std::weak_ptr<TaskEntity> > showAllByLabel();
    std::vector<std::weak_ptr<TaskEntity> > showAllByDate();
    std::vector<std::weak_ptr<TaskEntity> > showTodayByPriority();
    std::vector<std::weak_ptr<TaskEntity> > showTodayByLabel();
    std::vector<std::weak_ptr<TaskEntity> > showDueDateByPriority(time_t date);
    std::vector<std::weak_ptr<TaskEntity> > showDueDateByLabel(time_t date);
    std::vector<std::weak_ptr<TaskEntity> > showDueDateByDate(time_t date);

private:
    void cleanPrioritiesWithCertainPriority(Task::Priority priority); //deletes null ptrs from priorities
    void cleanDatesWithCertainDate(time_t date);//deletes null ptrs from dates
    void cleanLabelsWithCertainLabel(std::string label); //deletes null ptrs from labels

public: //for test
    void insertEntity(std::shared_ptr<TaskEntity> entity);
private:
    Display display_;
    LabelView label_view_;
    PriorityView priority_view_;
    DateView date_view_;
    IdGenerator idGenerator_;
    Storage storage_;
};


#endif //TODOLIST_TASKSERVICE_H
