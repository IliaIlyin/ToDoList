//
// Created by illia.ilin on 8/11/2020.
//
#include "gtest/gtest.h"

#include "Model/Storage.h"
using testing::Eq;

class StorageTest : public ::testing::Test {

};
TEST(StorageTest, shouldAddTask) {
  Storage storage;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  EXPECT_NO_THROW(storage.addTask(taskEntity));
  ASSERT_EQ(taskEntity, storage.addTask(taskEntity).operator*());
  ASSERT_EQ(taskEntity, storage.addTask(taskEntity).operator*());
}
TEST(StorageTest, shouldDeleteTask) {
  Storage storage;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  storage.addTask(taskEntity);
  ASSERT_EQ(true, storage.deleteTask(taskEntity));
  ASSERT_EQ(false,storage.deleteTask(taskEntity));
  EXPECT_NO_THROW(storage.deleteTask(taskEntity));
}
TEST(StorageTest, shouldGetTask) {
  Storage storage;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  std::shared_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task,idGenerator));
  taskEntity.addsubtask(entity);
  TaskID id(40);
  TaskID id2(1);
  storage.addTask(taskEntity);
  EXPECT_NO_THROW(storage.getTask(taskEntity.getTaskId()));
  ASSERT_EQ(nullptr,storage.getTask(id));
  ASSERT_EQ(entity,storage.getTask(id2));
  ASSERT_EQ(taskEntity,storage.getTask(taskEntity.getTaskId())->operator*());
}
TEST(StorageTest, shouldGetSubTasks) {
  Storage storage;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  std::shared_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task,idGenerator));
  taskEntity.addsubtask(entity);
  TaskID id(40);
  TaskID id2(1);
  storage.addTask(taskEntity);
  EXPECT_NO_THROW(storage.getSubtasks(taskEntity.getTaskId()));
  ASSERT_EQ(entity,(storage.getSubtasks(taskEntity.getTaskId())->begin()).operator*());
  ASSERT_EQ(nullptr,storage.getTask(id));
}