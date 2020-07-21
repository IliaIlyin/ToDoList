//
// Created by Ilya on 5/20/2020
//

#include "TaskService.h"

void TaskService::postponeTask(TaskEntity task, time_t dueDate) {
    auto iter=tasks.find(std::make_shared<TaskEntity> (task));
    if(iter!=tasks.end()){
        Task t = Task::createTask(task.getTask()->getName(),dueDate+task.getTask()->getDate(),
                task.getTask()->getPriority(),task.getTask()->getLabel());

        TaskEntity taskEntity(t,task.getTaskId(),task.checkStatus(),task.getSubtasks());

        tasks.erase(iter);
        cleanPrioritiesWithCertainPriority(t.getPriority());
        cleanDatesWithCertainDate(t.getDate());
        cleanLabelsWithCertainLabel(t.getLabel());

        auto ptr=std::make_shared<TaskEntity>(taskEntity);

        tasks.insert(ptr);
        priorities.insert(std::pair<Task::Priority,std::weak_ptr<TaskEntity> > (task.getTask()->getPriority(),ptr));
        dates.insert(std::pair<time_t,std::weak_ptr<TaskEntity> > (task.getTask()->getDate(),ptr));
        labels.insert(std::pair<std::string,std::weak_ptr<TaskEntity> > (task.getTask()->getLabel(),ptr));
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


