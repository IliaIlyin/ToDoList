#include <iostream>
#include "API/TaskService.h"
#include<gtest/gtest.h>
#include<gmock/gmock.h>
int main(int argc, char* argv[]) {
    TaskService taskService;
    std::shared_ptr<Task> ptr = std::make_shared<Task>(Task::createTask("LOL"));
    taskService.addTask(ptr.operator*());
    Task t=Task::createTask("RRR",18,Task::Priority::SECOND,"epicenter");
    std::shared_ptr<TaskEntity> taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity
        (t,taskService.getIdGenerator()));
    taskService.insertEntity(taskEntity);
    taskService.addSubTaskToParent(taskEntity,ptr.operator*());
    taskService.completeTask(taskEntity);
    taskService.showAllByPriority();

    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();
    return 0;
}
