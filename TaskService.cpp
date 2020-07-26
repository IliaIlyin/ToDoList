//
// Created by Ilya on 5/20/2020
//

#include "TaskService.h"

#include <utility>

void TaskService::postponeTask(std::shared_ptr<TaskEntity>  task, time_t dueDate) {
    auto iter=tasks.find((task));
    if(iter!=tasks.end()){
        Task t = Task::createTask(task.operator*().getTask()->getName(),dueDate+task.operator*().getTask()->getDate(),
                task.operator*().getTask()->getPriority(),task.operator*().getTask()->getLabel());

        TaskEntity taskEntity(t,task.operator*().getTaskId(),task.operator*().checkStatus(),task.operator*().getSubtasks());

        deleteTask(task);
        insertEntity(std::make_shared<TaskEntity>(taskEntity));
    }
    else{
        std::cout<<"task "<<task.operator*().getTask()->getName()<<" Not found"<<std::endl;
    }
}

void TaskService::cleanPrioritiesWithCertainPriority(Task::Priority priority) {
    auto iter=priorities.equal_range(priority);
    for(auto i=iter.first;i!=iter.second;i++){
        if (!(i->second.lock())){
            priorities.erase(i);
        }
    }
}

void TaskService::cleanDatesWithCertainDate(time_t date) {
    auto iter=dates.equal_range(date);
    for(auto i=iter.first;i!=iter.second;i++){
        if (!(i->second.lock())){
            dates.erase(i);
        }
    }
}

void TaskService::cleanLabelsWithCertainLabel(std::string label) {
    auto iter=labels.equal_range(label);
    for(auto i=iter.first;i!=iter.second;i++){
        if (!(i->second.lock())){
            labels.erase(i);
        }
    }
}

void TaskService::addTask(std::string taskName, time_t date, Task::Priority priority, std::string label) {
    Task task = Task::createTask(std::move(taskName),date,priority,std::move(label));
    TaskEntity taskEntity(task,this->idGenerator);
    insertEntity(std::make_shared<TaskEntity>(taskEntity));
}

void TaskService::insertEntity(std::shared_ptr<TaskEntity> taskEntity) {
    tasks.insert(taskEntity);
    priorities.insert(std::pair<Task::Priority,std::weak_ptr<TaskEntity> >
            (taskEntity.operator*().getTask()->getPriority(),taskEntity));
    dates.insert(std::pair<time_t,std::weak_ptr<TaskEntity> > 
            (taskEntity.operator*().getTask()->getDate(),taskEntity));
    labels.insert(std::pair<std::string,std::weak_ptr<TaskEntity> > 
            (taskEntity.operator*().getTask()->getLabel(),taskEntity));
}

void TaskService::deleteTask(std::shared_ptr<TaskEntity>  task) {
    auto iter=tasks.find(task);
    tasks.erase(iter);
    cleanPrioritiesWithCertainPriority(task.operator*().getTask()->getPriority());
    cleanDatesWithCertainDate(task.operator*().getTask()->getDate());
    cleanLabelsWithCertainLabel(task.operator*().getTask()->getLabel());
}

void TaskService::completeTask(std::shared_ptr<TaskEntity> task) {
    task.operator*().completeTask();
    auto vec=task.operator*().getSubtasks();
    for(auto i=vec.begin();i!=vec.end();i++){
        i->get()->completeTask();
    }
}

void TaskService::addSubTaskToParent(std::shared_ptr<TaskEntity>  parent, std::string taskName, time_t date, Task::Priority priority,
                                     std::string label) {

    Task t=Task::createTask(std::move(taskName),date,priority,std::move(label));
    TaskEntity taskEntity(t,this->idGenerator);
    parent->addsubtask(std::make_shared<TaskEntity>(taskEntity));
}

void TaskService::showAllByPriority() {
    for(auto i=priorities.begin();i!=priorities.end();i++)
        this->view.viewEntity(i->second.lock().operator*());
}

void TaskService::addTask(Task &task) {
    TaskEntity taskEntity(task,this->idGenerator);
    insertEntity(std::make_shared<TaskEntity>(taskEntity));
}

void TaskService::addSubTaskToParent(std::shared_ptr<TaskEntity> parent, Task &task) {
    TaskEntity taskEntity(task,this->idGenerator);
    parent->addsubtask(std::make_shared<TaskEntity>(taskEntity));
}



IdGenerator &TaskService::getIdGenerator() {
    return idGenerator;
}

void TaskService::showAllByLabel() {
    for(auto i=labels.begin();i!=labels.end();i++)
        this->view.viewEntity(i->second.lock().operator*());
}

void TaskService::showAllByDate() {
    for(auto i=dates.begin();i!=dates.end();i++)
        this->view.viewEntity(i->second.lock().operator*());
}





