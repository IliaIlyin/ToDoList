//
// Created by illia.ilin on 8/11/2020.
//
#include "gtest/gtest.h"

#include "Model/Storage.h"
using testing::Eq;

class StorageTest : public ::testing::Test {

};

TEST_F(StorageTest, shouldAddTask) {
  Storage storage;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  auto res = storage.addTask(taskEntity);
  ASSERT_EQ(res.operator*(), taskEntity);
  ASSERT_EQ(res.get(), storage.addTask(taskEntity).get());
}

TEST_F(StorageTest, shouldDeleteTask) {
  Storage storage;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  TaskID id(0);
  storage.addTask(taskEntity);
  ASSERT_EQ(true, storage.deleteTask(id));
  ASSERT_EQ(false,storage.deleteTask(id));
  EXPECT_NO_THROW(storage.deleteTask(id));
}

TEST_F(StorageTest, shouldGetTask) {
  Storage storage;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  std::shared_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task,idGenerator));
  taskEntity.addSubTask(entity);
  TaskID id(40);
  TaskID id2(1);
  storage.addTask(taskEntity);
  EXPECT_NO_THROW(storage.getTask(taskEntity.getTaskId()));
  ASSERT_EQ(std::nullopt,storage.getTask(id));
  ASSERT_EQ(entity,storage.getTask(id2));
  ASSERT_EQ(taskEntity,storage.getTask(taskEntity.getTaskId())->operator*());
}

TEST_F(StorageTest,shouldGetAllTasks){
  Storage storage;
  std::vector<std::shared_ptr<TaskEntity>> vec;
  ASSERT_EQ(storage.getAllTasks(),vec);
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task,idGenerator);
  Task task2 = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  TaskEntity taskEntity2 = TaskEntity::createTaskEntity(task2,idGenerator);
  storage.addTask(taskEntity);
  storage.addTask(taskEntity2);
  auto vec2=storage.getAllTasks();
  ASSERT_EQ(vec2.size(),2);
  ASSERT_EQ(vec2[1].operator*(),taskEntity);
  ASSERT_EQ(vec2[0].operator*(),taskEntity2);
}
