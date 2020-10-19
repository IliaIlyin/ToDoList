//
// Created by Ilya on 8/4/2020.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Model/StorageInterface.h"
#include "Model/StorageService.h"
#include "Model/IdGenerator.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class StorageMock : public StorageInterface {
 public:
  MOCK_METHOD(std::shared_ptr<TaskEntity>, addTask, (const TaskEntity &task_entity), (override));
  MOCK_METHOD(bool, deleteTask, (const TaskID &task_entity), (override));
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>, getTask, (TaskID id), (override));
  MOCK_METHOD(std::vector<std::shared_ptr<TaskEntity>>, getAllTasks, (), (override));
};

class StorageServiceTest : public ::testing::Test {

};

TEST_F(StorageServiceTest, shouldDeleteTask) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  EXPECT_CALL(mock.operator*(), deleteTask(TaskID(0))).Times(1);
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  storage_service_->deleteTask(TaskID(0));
}

TEST_F(StorageServiceTest, shouldAddSubTaskWithStatusParentNotFound) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  auto f = std::nullopt;
  EXPECT_CALL(mock.operator*(), getTask(TaskID(1))).Times(1).WillOnce(Return(f));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  auto result = storage_service_->addSubTaskToParent(TaskID(1), task, true);
  EXPECT_EQ(result, std::nullopt);
}

TEST_F(StorageServiceTest, shouldAddSubTaskWithStatusTrue) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity entity = TaskEntity::createTaskEntity(task, idGenerator, true);
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator, false);
  std::shared_ptr<TaskEntity> ptr = std::make_shared<TaskEntity>(taskEntity);
  EXPECT_CALL(mock.operator*(), getTask(TaskID(1))).Times(1).WillOnce(Return(ptr));
  EXPECT_CALL(mock.operator*(), addTask(taskEntity)).Times(1).WillOnce(Return(ptr));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  auto result = storage_service_->addSubTaskToParent(TaskID(1), task, true);
  EXPECT_EQ(result.value()->getTaskId(), TaskID(1));
  EXPECT_EQ(result.value()->getSubTasks().size(), 1);
  EXPECT_EQ(result.value()->getSubTasks().begin().operator*().operator*().checkStatus(), entity.checkStatus());
  EXPECT_EQ(result.value()->getSubTasks().begin().operator*().operator*(), entity);
}

TEST_F(StorageServiceTest, shouldAddSubTaskWithStatusFalse) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity entity = TaskEntity::createTaskEntity(task, idGenerator, false);
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator, true);
  std::shared_ptr<TaskEntity> ptr = std::make_shared<TaskEntity>(taskEntity);
  EXPECT_CALL(mock.operator*(), getTask(TaskID(1))).Times(1).WillOnce(Return(ptr));
  EXPECT_CALL(mock.operator*(), addTask(taskEntity)).Times(1).WillOnce(Return(ptr));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  auto result = storage_service_->addSubTaskToParent(TaskID(1), task, false);
  EXPECT_EQ(result.value()->getTaskId(), TaskID(1));
  EXPECT_EQ(result.value()->getSubTasks().size(), 1);
  EXPECT_EQ(result.value()->getSubTasks().begin().operator*().operator*().checkStatus(), entity.checkStatus());
  EXPECT_EQ(result.value()->getSubTasks().begin().operator*().operator*(), entity);
}

TEST_F(StorageServiceTest, shouldAddSubTask) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity entity = TaskEntity::createTaskEntity(task, idGenerator);
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  std::shared_ptr<TaskEntity> ptr = std::make_shared<TaskEntity>(taskEntity);
  EXPECT_CALL(mock.operator*(), getTask(TaskID(1))).Times(1).WillOnce(Return(ptr));
  EXPECT_CALL(mock.operator*(), addTask(taskEntity)).Times(1).WillOnce(Return(ptr));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  auto result = storage_service_->addSubTaskToParent(TaskID(1), task);
  EXPECT_EQ(result.value()->getTaskId(), TaskID(1));
  EXPECT_EQ(result.value()->getSubTasks().size(), 1);
  EXPECT_EQ(result.value()->getSubTasks().begin().operator*().operator*().checkStatus(), entity.checkStatus());
  EXPECT_EQ(result.value()->getSubTasks().begin().operator*().operator*(), entity);
}

TEST_F(StorageServiceTest, shouldAddSubTaskParentNotFound) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  auto f = std::nullopt;
  EXPECT_CALL(mock.operator*(), getTask(TaskID(1))).Times(1).WillOnce(Return(f));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  auto result = storage_service_->addSubTaskToParent(TaskID(1), task);
  EXPECT_EQ(result, std::nullopt);
}
TEST_F(StorageServiceTest, shouldAddTask) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity entity = TaskEntity::createTaskEntity(task, idGenerator);
  auto ptr = std::make_shared<TaskEntity>(entity);
  EXPECT_CALL(mock.operator*(), addTask(entity)).Times(1).WillOnce(Return(ptr));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(ptr, storage_service_->addTask(task));
}

TEST_F(StorageServiceTest, shouldAddTaskWithStatusTrue) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity entity = TaskEntity::createTaskEntity(task, idGenerator, true);
  auto ptr = std::make_shared<TaskEntity>(entity);
  EXPECT_CALL(mock.operator*(), addTask(entity)).Times(1).WillOnce(Return(ptr));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  auto result = storage_service_->addTask(task, true).operator*();
  ASSERT_EQ(entity, result);
  ASSERT_EQ(entity.checkStatus(), result.checkStatus());
  ASSERT_NE(false, result.checkStatus());
}

TEST_F(StorageServiceTest, shouldPostponeTaskReturnTrue) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  auto new_date = boost::gregorian::date{2200, 11, 18};
  TaskID id(0);
  EXPECT_CALL(mock.operator*(), getTask(id)).Times(1).WillOnce(Return(entity));
  Task new_task = Task::createTask("Lol", new_date, Task::Priority::FIRST, "label");
  IdGenerator id_generator2;
  TaskEntity entity2 = TaskEntity::createTaskEntity(new_task, id_generator2);
  EXPECT_CALL(mock.operator*(), addTask(entity2)).Times(1);
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(storage_service_->postponeTask(id, new_date), true);
}

TEST_F(StorageServiceTest, shouldPostponeTaskReturnFalse) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  auto result = std::nullopt;
  auto new_date = boost::gregorian::date{2200, 11, 18};
  TaskID id(0);
  EXPECT_CALL(mock.operator*(), getTask(id)).Times(1).WillOnce(Return(result));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(storage_service_->postponeTask(id, new_date), false);
}

TEST_F(StorageServiceTest, shouldCompleteTaskReturnFalse) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  auto result = std::nullopt;
  TaskID id(0);
  EXPECT_CALL(mock.operator*(), getTask(id)).Times(1).WillOnce(Return(result));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(storage_service_->completeTask(id), false);
}

TEST_F(StorageServiceTest, shouldCompleteTaskReturnTrue) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  Task task2 = Task::createTask("fsdfds", boost::gregorian::date{2000, 12, 9}, Task::Priority::THIRD, "label");
  Task task3 = Task::createTask("Lgdfgdfgsdf", boost::gregorian::date{2000, 12, 9}, Task::Priority::SECOND, "label");
  std::shared_ptr<TaskEntity> ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2, idGenerator));
  taskEntity->addSubTask(ptr);
  std::shared_ptr<TaskEntity>
      ptr2 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3, idGenerator));
  ptr->addSubTask(ptr2);
  TaskID id(0);
  EXPECT_CALL(mock.operator*(), getTask(id)).Times(1).WillOnce(Return(taskEntity));
  EXPECT_CALL(mock.operator*(), addTask(taskEntity.operator*())).Times(1);
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(storage_service_->completeTask(id), true);
}
TEST_F(StorageServiceTest, shouldGetTaskReturnNullopt) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  TaskID id(0);
  auto result = std::nullopt;
  EXPECT_CALL(mock.operator*(), getTask(id)).Times(1).WillOnce(Return(result));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(storage_service_->getTask(id), result);
}
TEST_F(StorageServiceTest, shouldGetTask) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  TaskID id(0);
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  EXPECT_CALL(mock.operator*(), getTask(id)).Times(1).WillOnce(Return(taskEntity));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(storage_service_->getTask(id), taskEntity);
}
TEST_F(StorageServiceTest, shouldGetSubTasksReturnNullopt) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  TaskID id(0);
  auto result = std::nullopt;
  EXPECT_CALL(mock.operator*(), getTask(id)).Times(1).WillOnce(Return(result));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(storage_service_->getSubTasks(id), result);
}
TEST_F(StorageServiceTest, shouldGetSubTasks) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  auto taskEntity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  Task task2 = Task::createTask("fsdfds", boost::gregorian::date{2000, 12, 9}, Task::Priority::THIRD, "label");
  Task task3 = Task::createTask("Lgdfgdfgsdf", boost::gregorian::date{2000, 12, 9}, Task::Priority::SECOND, "label");
  std::shared_ptr<TaskEntity> ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2, idGenerator));
  taskEntity->addSubTask(ptr);
  std::shared_ptr<TaskEntity>
      ptr2 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3, idGenerator));
  ptr->addSubTask(ptr2);
  TaskID id(0);
  std::vector<std::shared_ptr<TaskEntity>> vec;
  vec.push_back(ptr);
  EXPECT_CALL(mock.operator*(), getTask(id)).Times(1).WillOnce(Return(taskEntity));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(storage_service_->getSubTasks(id), vec);
}
TEST_F(StorageServiceTest, shouldGetAllTasks) {
  std::unique_ptr<StorageMock> mock = std::make_unique<StorageMock>();
  std::vector<std::shared_ptr<TaskEntity>> vec;
  EXPECT_CALL(mock.operator*(), getAllTasks()).Times(1).WillOnce(Return(vec));
  auto storage_service_ = std::make_unique<StorageService>(std::move(mock));
  ASSERT_EQ(storage_service_->getAllTasks(), vec);
}