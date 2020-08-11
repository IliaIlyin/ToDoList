//
// Created by Ilya on 8/4/2020.
//

//
// Created by Ilya on 7/26/2020.
//

#include<gtest/gtest.h>

#include "API/TaskDTO.h"
using testing::Eq;

class TaskDTOTest : public ::testing::Test {

};

TEST_F(TaskDTOTest, shouldCreateDTO) {
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskID taskId(0);
  TaskDTO taskDTO = TaskDTO::createTaskDTO(task, idGenerator);
  ASSERT_EQ(taskDTO.getTask(), task);
  ASSERT_EQ(taskDTO.getTaskId().getId(), 0);
  ASSERT_EQ(taskDTO.getTaskId(), taskId);
  ASSERT_EQ(taskDTO.checkStatus(), false);
  TaskDTO dto(task, taskId, true);
  ASSERT_EQ(dto.getTask(), task);
  ASSERT_EQ( dto.getTaskId().getId(), 0);
  ASSERT_EQ(dto.getTaskId(), taskId);
  ASSERT_EQ(dto.checkStatus(), true);
  TaskDTO dto2(task, taskId, false);
  ASSERT_EQ(dto2.getTask(), task);
  ASSERT_EQ(dto2.getTaskId().getId(), 0);
  ASSERT_EQ(dto2.getTaskId(), taskId);
  ASSERT_EQ(dto2.checkStatus(), false);
}

