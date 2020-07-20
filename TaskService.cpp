//
// Created by Ilya on 5/20/2020
//

#include "TaskService.h"

void TaskService::postponeTask(TaskEntity task, time_t dueDate) {
    auto iter=tasks.find(task);
    if(iter!=tasks.end()){
        Task t = Task::createTask(task.getTask()->getName(),dueDate+task.getTask()->getDate(),
                task.getTask()->getPriority(),task.getTask()->getLabel());

        TaskEntity taskEntity(t,task.getTaskId(),task.checkStatus(),task.getSubtasks());
        tasks.erase(iter);
        tasks.insert(taskEntity);
    }
    else{
        std::cout<<"task "<<task.getTask()->getName()<<" Not found"<<std::endl;
    }
}
