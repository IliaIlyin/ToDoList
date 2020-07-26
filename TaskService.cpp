//
// Created by Ilya on 5/20/2020
//

#include "TaskService.h"

#include <utility>

void TaskService::postponeTask(TaskEntity& task, time_t dueDate) {
    auto iter=tasks.find(std::make_shared<TaskEntity> (task));
    if(iter!=tasks.end()){
        Task t = Task::createTask(task.getTask()->getName(),dueDate+task.getTask()->getDate(),
                task.getTask()->getPriority(),task.getTask()->getLabel());

        TaskEntity taskEntity(t,task.getTaskId(),task.checkStatus(),task.getSubtasks());

        deleteTask(task);
        insertEntity(taskEntity);
    }
    else{
        std::cout<<"task "<<task.getTask()->getName()<<" Not found"<<std::endl;
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
    insertEntity(taskEntity);
}

void TaskService::insertEntity(TaskEntity& taskEntity) {
    auto ptr=std::make_shared<TaskEntity>(taskEntity);
    tasks.insert(ptr);
    priorities.insert(std::pair<Task::Priority,std::weak_ptr<TaskEntity> > (taskEntity.getTask()->getPriority(),ptr));
    dates.insert(std::pair<time_t,std::weak_ptr<TaskEntity> > (taskEntity.getTask()->getDate(),ptr));
    labels.insert(std::pair<std::string,std::weak_ptr<TaskEntity> > (taskEntity.getTask()->getLabel(),ptr));
}

void TaskService::deleteTask(TaskEntity& task) {
    auto iter=tasks.find(std::make_shared<TaskEntity> (task));
    tasks.erase(iter);
    cleanPrioritiesWithCertainPriority(task.getTask()->getPriority());
    cleanDatesWithCertainDate(task.getTask()->getDate());
    cleanLabelsWithCertainLabel(task.getTask()->getLabel());
}

void TaskService::completeTask(TaskEntity &task) {
    task.completeTask();
    auto vec=task.getSubtasks();
    for(auto i=vec.begin();i!=vec.end();i++){
        i->get()->completeTask();
    }
}

void TaskService::addSubTaskToParent(TaskEntity& parent, std::string taskName, time_t date, Task::Priority priority,
                                     std::string label) {

    Task t=Task::createTask(std::move(taskName),date,priority,std::move(label));
    TaskEntity taskEntity(t,this->idGenerator);
    parent.addsubtask(taskEntity);
}

void TaskService::showAllByPriority() {
    for(auto i=priorities.begin();i!=priorities.end();i++)
        this->view.viewEntity(i->second.lock().operator*());
}

void TaskService::addTask(Task &task) {
    TaskEntity taskEntity(task,this->idGenerator);
    insertEntity(taskEntity);
}

void TaskService::addSubTaskToParent(TaskEntity &parent, Task &task) {
    TaskEntity taskEntity(task,this->idGenerator);
    parent.addsubtask(taskEntity);
}



IdGenerator &TaskService::getIdGenerator() {
    return idGenerator;
}





