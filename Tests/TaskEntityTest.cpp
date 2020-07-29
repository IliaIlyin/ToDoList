//
// Created by Ilya on 7/26/2020.
//

#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "../Model/TaskEntity.h"
using testing::Eq;

class TaskEntityTest : public ::testing::Test {

};

TEST_F(TaskEntityTest,shouldCreateTaskEntity){
    Task task = Task::createTask("Lol",200,Task::Priority::FIRST,"label");
    IdGenerator idGenerator;
    std::vector<std::shared_ptr<TaskEntity>> vec;
    TaskID taskId(0);
    TaskEntity taskEntity=TaskEntity::createTaskEntity(task,idGenerator);
    ASSERT_TRUE(taskEntity.getTask().getName()== task.getName());
    ASSERT_TRUE(taskEntity.getTask().getLabel()==task.getLabel());
    ASSERT_EQ(taskEntity.getTask().getDate(),task.getDate());
    ASSERT_EQ(taskEntity.getTask().getPriority(),task.getPriority());
    ASSERT_EQ((taskId.getId()),(taskEntity.getTaskId().getId()));
    ASSERT_EQ(false,taskEntity.checkStatus());
    ASSERT_EQ(vec,taskEntity.getSubtasks());
}
