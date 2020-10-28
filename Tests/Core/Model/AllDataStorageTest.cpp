//
// Created by ilya on 10.10.20.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Model/AllDataStorage.h"
#include "Model/StorageServiceInterface.h"
#include "Views/ViewServiceInterface.h"
#include "Core/Mocks/ViewServiceMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class StorageServiceMock : public StorageServiceInterface {
 public:
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>, addSubTaskToParent, (const TaskID &parent,
      Task &task,
      bool status), (override));
  MOCK_METHOD(std::shared_ptr<TaskEntity>, addTask, (Task & task), (override));
  MOCK_METHOD(std::shared_ptr<TaskEntity>, addTask, (Task & task, bool status), (override));
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>,
              addSubTaskToParent,
              (const TaskID &parent, Task &task),
              (override));
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>, getTask, (const TaskID &id), (override));
  MOCK_METHOD(std::optional<std::vector<std::shared_ptr<TaskEntity>>>, getSubTasks, (const TaskID &id), (override));
  MOCK_METHOD(bool, postponeTask, (const TaskID &task, boost::gregorian::date dueDate), (override));
  MOCK_METHOD(bool, deleteTask, (const TaskID &task), (override));
  MOCK_METHOD(bool, completeTask, (const TaskID &task), (override));
  MOCK_METHOD(std::vector<std::shared_ptr<TaskEntity>>, getAllTasks, (), (override));
};

class AllDataStorageTest : public ::testing::Test {

};

TEST_F(AllDataStorageTest, shouldAddTask) {
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  EXPECT_CALL(storage.operator*(), addTask(task)).WillOnce(Return(entity));
  EXPECT_CALL(views.operator*(), insert(entity));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.addTask(task), true);
}

TEST_F(AllDataStorageTest, shouldAddSubTaskWithStatusReturnNullopt) {
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  TaskID id(0);
  bool status = true;
  auto result = std::nullopt;
  EXPECT_CALL(storage.operator*(), addSubTaskToParent(id, task, status)).WillOnce(Return(result));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.addSubTaskToParent(id, task, status), std::nullopt);
}

TEST_F(AllDataStorageTest, shouldAddSubTaskWithStatus) {
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskID id(0);
  bool status = true;
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  EXPECT_CALL(storage.operator*(), addSubTaskToParent(id, task, status)).WillOnce(Return(entity));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.addSubTaskToParent(id, task, status), id);
}

TEST_F(AllDataStorageTest, shouldAddSubTask) {
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskID id(0);
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  EXPECT_CALL(storage.operator*(), addSubTaskToParent(id, task)).WillOnce(Return(entity));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.addSubTaskToParent(id, task), entity);
}

TEST_F(AllDataStorageTest, shouldAddSubTaskReturnNullopt) {
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  TaskID id(0);
  auto result = std::nullopt;
  EXPECT_CALL(storage.operator*(), addSubTaskToParent(id, task)).WillOnce(Return(result));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.addSubTaskToParent(id, task), std::nullopt);
}

TEST_F(AllDataStorageTest, shouldAddTaskWithStatus) {
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator, true));
  EXPECT_CALL(storage.operator*(), addTask(task, true)).WillOnce(Return(entity));
  EXPECT_CALL(views.operator*(), insert(entity));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.addTask(task, true), entity->getTaskId());
}

TEST_F(AllDataStorageTest, shouldGetTask) {
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  TaskID id(0);
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator, true));
  EXPECT_CALL(storage.operator*(), getTask(id)).Times(1).WillOnce(Return(entity));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.getTask(id), entity);
}
TEST_F(AllDataStorageTest, shouldGetTaskReturnNullopt) {
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  TaskID id(0);
  auto result = std::nullopt;
  EXPECT_CALL(storage.operator*(), getTask(id)).Times(1).WillOnce(Return(result));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.getTask(id), std::nullopt);
}
TEST_F(AllDataStorageTest, shouldGetSubTasksReturnNullopt) {
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  TaskID id(0);
  auto result = std::nullopt;
  EXPECT_CALL(storage.operator*(), getSubTasks(id)).Times(1).WillOnce(Return(result));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.getSubTasks(id), std::nullopt);
}
TEST_F(AllDataStorageTest, shouldGetSubTasks) {
  std::vector<std::shared_ptr<TaskEntity>> vec;
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskID id(0);
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  vec.push_back(entity);
  EXPECT_CALL(storage.operator*(), getSubTasks(id)).Times(1).WillOnce(Return(vec));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.getSubTasks(id), vec);
}
TEST_F(AllDataStorageTest, shouldPostponeTask) {
  TaskID id(0);
  auto date = boost::gregorian::date{2200, 11, 8};
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(), postponeTask(id, date)).Times(1);
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.postponeTask(id, date), true);
}
TEST_F(AllDataStorageTest, shouldCompleteTask) {
  TaskID id(0);
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(), completeTask(id)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.completeTask(id), true);
  ASSERT_EQ(data.completeTask(id), false);
}
TEST_F(AllDataStorageTest, shouldDeleteTask) {
  TaskID id(0);
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(), deleteTask(id)).Times(1);
  EXPECT_CALL(views.operator*(), clean()).Times(1);
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.deleteTask(id), true);
}
TEST_F(AllDataStorageTest, shouldGetAllTasks) {
  std::vector<std::shared_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  vec.push_back(entity);
  auto storage = std::make_unique<StorageServiceMock>();
  auto views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(), getAllTasks()).Times(1).WillOnce(Return(vec));
  AllDataStorage data(std::move(storage), views);
  ASSERT_EQ(data.getAllTasks(), vec);
}