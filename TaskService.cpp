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
        tasks.insert(std::make_shared<TaskEntity>(taskEntity));
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


