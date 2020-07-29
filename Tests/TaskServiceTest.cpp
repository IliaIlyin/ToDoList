//
// Created by Ilya on 7/26/2020.
//
#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "../API/TaskService.h"

using testing::Eq;

class TaskServiceTest : public ::testing::Test {
public:
    std::shared_ptr<Task> ptr;
    TaskService taskService;
    Task t = Task::createTask("RRR", 18, Task::Priority::SECOND, "epicenter");
    std::shared_ptr<TaskEntity> taskEntity;

    TaskServiceTest() {
        ptr = std::make_shared<Task>(Task::createTask("LOL"));
        taskEntity = std::make_shared<TaskEntity>(t, taskService.getIdGenerator());
    }
};


