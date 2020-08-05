//
// Created by Ilya on 8/4/2020.
//

//
// Created by Ilya on 7/26/2020.
//

#include<gtest/gtest.h>

#include "Model/TaskDTO.h"
using testing::Eq;

class TaskDTOTest : public ::testing::Test {

};

TEST_F(TaskDTOTest,shouldCreateTaskDTO){
  Task task = Task::createTask("Lol",200,Task::Priority::FIRST,"label");
  IdGenerator idGenerator;
  std::vector<std::shared_ptr<TaskDTO>> vec;
  TaskID taskId(0);
  TaskDTO TaskDTO=TaskDTO::createTaskDTO(task,idGenerator);
  ASSERT_TRUE(TaskDTO.getTask().getName()== task.getName());
  ASSERT_TRUE(TaskDTO.getTask().getLabel()==task.getLabel());
  ASSERT_EQ(TaskDTO.getTask().getDate(),task.getDate());
  ASSERT_EQ(TaskDTO.getTask().getPriority(),task.getPriority());
  ASSERT_EQ((taskId.getId()),(TaskDTO.getTaskId().getId()));
  ASSERT_EQ(false,TaskDTO.checkStatus());
  ASSERT_EQ(vec,TaskDTO.getSubtasks());
}
TEST_F(TaskDTOTest,shouldAddSubTasks){
  Task task = Task::createTask("Lol",200,Task::Priority::FIRST,"label");
  IdGenerator idGenerator;
  TaskDTO Taskdto=TaskDTO::createTaskDTO(task,idGenerator);
  Task task2 = Task::createTask("fsdfds",200,Task::Priority::THIRD,"label");
  Task task3 = Task::createTask("Lgdfgdfgsdf",200,Task::Priority::SECOND,"label");
  std::shared_ptr<TaskDTO> ptr=std::make_shared<TaskDTO>(TaskDTO::createTaskDTO(task2,idGenerator));
  Taskdto.addsubtask(ptr);
  std::shared_ptr<TaskDTO> ptr2=std::make_shared<TaskDTO>(TaskDTO::createTaskDTO(task3,idGenerator));
  ptr->addsubtask(ptr2);
  ASSERT_EQ(1,Taskdto.getSubtasks().size());
  ASSERT_EQ(ptr.operator*(),Taskdto.getSubtasks().begin().operator*().operator*());
  ASSERT_EQ(ptr2.operator*(),Taskdto.getSubtasks().begin()->operator*().getSubtasks().begin()->operator*());
}
/*
TEST_F(TaskDTOTest,shouldCompleteTask){
  Task task = Task::createTask("Lol",200,Task::Priority::FIRST,"label");
  IdGenerator idGenerator;
  TaskDTO Taskdto=TaskDTO::createTaskDTO(task,idGenerator);
  Task task2 = Task::createTask("fsdfds",200,Task::Priority::THIRD,"label");
  Task task3 = Task::createTask("Lgdfgdfgsdf",200,Task::Priority::SECOND,"label");
  std::shared_ptr<TaskDTO> ptr=std::make_shared<TaskDTO>(TaskDTO::createTaskDTO(task2,idGenerator));
  Taskdto.addsubtask(ptr);
  std::shared_ptr<TaskDTO> ptr2=std::make_shared<TaskDTO>(TaskDTO::createTaskDTO(task3,idGenerator));
  ptr->addsubtask(ptr2);
  Taskdto.completeTask();
  ASSERT_EQ(true,TaskDTO.checkStatus());
  ASSERT_EQ(true,TaskDTO.getSubtasks().begin()->operator*().checkStatus());
  ASSERT_EQ(true,TaskDTO.getSubtasks().begin()->operator*().getSubtasks().begin()->operator*().checkStatus());
}
 */