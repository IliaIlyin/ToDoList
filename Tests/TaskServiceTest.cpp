//
// Created by Ilya on 7/26/2020.
//
#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "../API/TaskService.h"
#include <vector>
using testing::Eq;

class TaskServiceTest : public ::testing::Test {

};
TEST_F(TaskServiceTest, shouldAddTask) {
  TaskService task_service;
  Task task = Task::createTask("Lol", 200, Task::Priority::FIRST, "label");
  ASSERT_EQ(true,task_service.addTask(task));
  auto vec = task_service.showAllByPriority();
  ASSERT_EQ(vec.size(), 1);
  ASSERT_EQ(vec.begin()->getTask(), task);
  ASSERT_EQ(0, vec.begin()->getTaskId().getId());
  ASSERT_EQ(0, vec.begin()->getSubtasks().size());
}

