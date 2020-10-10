//
// Created by ilya on 05.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Serialization/Persistor.h"
#include "Model/AllDataStorageInterface.h"
#include "Model/AllDataStorageFactoryInterface.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class AllDataStorageMock : public AllDataStorageInterface {

 public:
  MOCK_METHOD(bool, addTask, (Task & task), (override));
  MOCK_METHOD(TaskID,addTask ,(Task &task, bool status), (override));
  MOCK_METHOD(std::optional<TaskID>, addSubTaskToParent, (const TaskID  &parent, Task &task, bool status),(override));
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>,
              addSubTaskToParent,
              (const TaskID  &parent, Task &task),
              (override));
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>, getTask, (const TaskID & id), (override));
  MOCK_METHOD(std::optional<std::vector<std::shared_ptr<TaskEntity>>>, getSubTasks, (const TaskID & id), (override));
  MOCK_METHOD(std::vector<std::shared_ptr<TaskEntity>>,getAllTasks,(),(override));
  MOCK_METHOD(bool, postponeTask, (const TaskID & task, boost::gregorian::date dueDate), (override));
  MOCK_METHOD(bool, deleteTask, (const TaskID & task), (override));
  MOCK_METHOD(bool, completeTask, (const TaskID &task), (override));
  MOCK_METHOD(std::shared_ptr<ViewServiceInterface>, getViewService, (), (const, override));
};

class AllDataStorageFactoryMock : public AllDataStorageFactoryInterface {
 public:
  MOCK_METHOD(std::shared_ptr<AllDataStorageInterface>, create, (), (override));
};

class PersistorTest : public ::testing::Test {

};

TEST_F(PersistorTest, shouldSaveReturnTrue) {
  auto stream = std::make_shared<std::stringstream>();
  std::shared_ptr<AllDataStorageMock> storage=std::make_shared<AllDataStorageMock>();
  std::shared_ptr<AllDataStorageFactoryMock> factory=std::make_shared<AllDataStorageFactoryMock>();
  std::vector<std::shared_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  Task task2 = Task::createTask("fsdfds", boost::gregorian::date{2000, 12, 9}, Task::Priority::THIRD, "label");
  Task task3 = Task::createTask("Lgdfgdfgsdf", boost::gregorian::date{2000, 12, 9}, Task::Priority::SECOND, "label");
  std::shared_ptr<TaskEntity> ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2, idGenerator));
  taskEntity.addSubTask(ptr);
  std::shared_ptr<TaskEntity>
  ptr2 = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3, idGenerator, true));
  vec.push_back(std::make_shared<TaskEntity>(taskEntity));
  vec.push_back(ptr2);
  EXPECT_CALL(storage.operator*(),getAllTasks()).Times(1).WillOnce(Return(vec));
  Persistor persistor = Persistor(stream,storage,factory);
  ASSERT_EQ(persistor.Save(),true);
}

TEST_F(PersistorTest, shouldLoadReturnTrue) {
  auto stream = std::make_shared<std::fstream>();
  std::shared_ptr<AllDataStorageMock> storage=std::make_shared<AllDataStorageMock>();
  std::shared_ptr<AllDataStorageFactoryMock> factory=std::make_shared<AllDataStorageFactoryMock>();
  Persistor persistor = Persistor(stream,storage,factory);
  std::shared_ptr<AllDataStorageMock> mock=std::make_shared<AllDataStorageMock>();
  EXPECT_CALL(factory.operator*(),create()).Times(1).WillOnce(Return(mock));
  ASSERT_EQ(persistor.Load(),true);
}

TEST_F(PersistorTest, shouldSerializeSubTasks) {
  auto stream = std::make_shared<std::fstream>();
  std::shared_ptr<AllDataStorageMock> storage=std::make_shared<AllDataStorageMock>();
  std::shared_ptr<AllDataStorageFactoryMock> factory=std::make_shared<AllDataStorageFactoryMock>();
  Persistor persistor = Persistor(stream,storage,factory);
  std::shared_ptr<AllDataStorageMock> mock=std::make_shared<AllDataStorageMock>();
  EXPECT_CALL(factory.operator*(),create()).Times(1).WillOnce(Return(mock));
  ASSERT_EQ(persistor.Load(),true);
}