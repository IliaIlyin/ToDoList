#include <iostream>
#include "TaskService.h"
int main() {
    TaskService taskService;
    std::shared_ptr<Task> ptr = std::make_shared<Task>(Task::createTask("LOL"));
    taskService.addTask(ptr.operator*());
    Task t=Task::createTask("RRR",18,Task::Priority::SECOND,"epicenter");
    std::shared_ptr<TaskEntity> taskEntity = std::make_shared<TaskEntity>(t,taskService.getIdGenerator());
    taskService.insertEntity(taskEntity);
    taskService.addSubTaskToParent(taskEntity,ptr.operator*());
    taskService.completeTask(taskEntity);
    taskService.showAllByPriority();
    return 0;
}
