//
// Created by Ilya on 8/9/2020.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Model/TaskService.h"
#include "Core/Mocks/AllDataStorageMock.h"
#include "Core/Mocks/ViewServiceMock.h"
#include "Core/Mocks/AllDataStorageFactoryMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class SerializerMock : public Serializer {
 public:
  MOCK_METHOD(bool, Save, (), (override));
  MOCK_METHOD(bool, Load, (), (override));
};

class TaskServiceTest : public ::testing::Test {

};
TEST_F(TaskServiceTest, shouldSave) {
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  std::vector<std::shared_ptr<TaskEntity>> vec;
  EXPECT_CALL(storage.operator*(),getAllTasks()).Times(1).WillOnce(Return(vec));
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.save("testSave.txt"), false);
}

TEST_F(TaskServiceTest, shouldLoad) {
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(2).WillRepeatedly(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.load("testSave.txt"), true);
}
TEST_F(TaskServiceTest, shouldAddTaskInputTask) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  EXPECT_CALL(storage.operator*(), addTask(task)).Times(1).WillOnce(Return(true));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.addTask(task), true);
}

TEST_F(TaskServiceTest, shouldAddTaskInputParams) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  AllDataStorageMock mock;
  EXPECT_CALL(storage.operator*(), addTask(task)).Times(1).WillOnce(Return(true));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.addTask("Lol",
                            boost::gregorian::date{2000, 12, 9},
                            Task::Priority::FIRST,
                            "labelgfd"), true);
}
TEST_F(TaskServiceTest, shouldAddSubTaskInputParams) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(1);
  IdGenerator generator;
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  EXPECT_CALL(storage.operator*(), addSubTaskToParent(id, task)).Times(1).WillOnce(Return(entity));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.addSubTaskToParent(id, "Lol",
                                       boost::gregorian::date{2000, 12, 9},
                                       Task::Priority::FIRST,
                                       "labelgfd"), true);
}

TEST_F(TaskServiceTest, shouldAddSubTaskInputTask) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(1);
  IdGenerator generator;
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  EXPECT_CALL(storage.operator*(), addSubTaskToParent(id, task)).Times(1).WillOnce(Return(entity));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.addSubTaskToParent(id, task), true);
}

TEST_F(TaskServiceTest, getTask) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(0);
  IdGenerator generator;
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  EXPECT_CALL(storage.operator*(), getTask(id)).Times(1).WillOnce(Return(entity));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.getTask(id), entity.operator*());
}

TEST_F(TaskServiceTest, getTaskReturnNullopt) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(0);
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  auto result=std::nullopt;
  EXPECT_CALL(storage.operator*(), getTask(id)).Times(1).WillOnce(Return(result));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.getTask(id), result);
}

TEST_F(TaskServiceTest, getSubTasks) {
  std::vector<std::shared_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(0);
  IdGenerator generator;
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  vec.push_back(entity);
  EXPECT_CALL(storage.operator*(), getSubTasks(id)).Times(1).WillOnce(Return(vec));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.getSubTasks(id), vec);;
}
TEST_F(TaskServiceTest, getSubTasksReturnNullopt) {
  std::vector<std::shared_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(0);
  IdGenerator generator;
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  auto result = std::nullopt;
  EXPECT_CALL(storage.operator*(), getSubTasks(id)).Times(1).WillOnce(Return(result));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.getSubTasks(id), result);;
}

TEST_F(TaskServiceTest, postponeTasks) {
  TaskID id(1);
  auto date = boost::gregorian::date{2000,8,3};
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  EXPECT_CALL(storage.operator*(), postponeTask(id,date)).Times(1).WillOnce(Return(true));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.postponeTask(id, date),true);
}
TEST_F(TaskServiceTest, deleteTask) {
  TaskID id(1);
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  EXPECT_CALL(storage.operator*(), deleteTask(id)).Times(1).WillOnce(Return(true));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.deleteTask(id),true);
}
TEST_F(TaskServiceTest, completeTask) {
  TaskID id(1);
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  EXPECT_CALL(storage.operator*(), completeTask(id)).Times(1).WillOnce(Return(true));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.completeTask(id), true);
}

TEST_F(TaskServiceTest, showAllByDate) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;
  std::weak_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  vec.push_back(entity);
  std::shared_ptr<ViewServiceMock> views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(),getViewService()).Times(2).WillRepeatedly(Return(views));
  EXPECT_CALL(views.operator*(),showAllByDate()).Times(2).WillRepeatedly(Return(vec));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.showAllByDate().size(), vec.size());
  ASSERT_EQ(service.showAllByDate()[0].lock(),vec[0].lock());
}

TEST_F(TaskServiceTest, showAllByLabel) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;
  std::weak_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  vec.push_back(entity);
  std::shared_ptr<ViewServiceMock> views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(),getViewService()).Times(2).WillRepeatedly(Return(views));
  EXPECT_CALL(views.operator*(),showAllByLabel()).Times(2).WillRepeatedly(Return(vec));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.showAllByLabel().size(), vec.size());
  ASSERT_EQ(service.showAllByLabel()[0].lock(),vec[0].lock());
}
TEST_F(TaskServiceTest, showAllByPriority) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;
  std::weak_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  vec.push_back(entity);
  std::shared_ptr<ViewServiceMock> views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(),getViewService()).Times(2).WillRepeatedly(Return(views));
  EXPECT_CALL(views.operator*(),showAllByPriority()).Times(2).WillRepeatedly(Return(vec));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.showAllByPriority().size(), vec.size());
  ASSERT_EQ(service.showAllByPriority()[0].lock(),vec[0].lock());
}
TEST_F(TaskServiceTest, showTodayByLabel) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;
  std::weak_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  vec.push_back(entity);
  std::shared_ptr<ViewServiceMock> views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(),getViewService()).Times(2).WillRepeatedly(Return(views));
  EXPECT_CALL(views.operator*(),showTodayByLabel()).Times(2).WillRepeatedly(Return(vec));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.showTodayByLabel().size(), vec.size());
  ASSERT_EQ(service.showTodayByLabel()[0].lock(),vec[0].lock());
}
TEST_F(TaskServiceTest, showTodayByPriority) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;
  std::weak_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  vec.push_back(entity);
  std::shared_ptr<ViewServiceMock> views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(),getViewService()).Times(2).WillRepeatedly(Return(views));
  EXPECT_CALL(views.operator*(),showTodayByPriority()).Times(2).WillRepeatedly(Return(vec));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.showTodayByPriority().size(), vec.size());
  ASSERT_EQ(service.showTodayByPriority()[0].lock(),vec[0].lock());
}
TEST_F(TaskServiceTest, showDueDateByPriority) {
  auto date = boost::gregorian::date{2000,8,3};
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;
  std::weak_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  vec.push_back(entity);
  std::shared_ptr<ViewServiceMock> views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(),getViewService()).Times(2).WillRepeatedly(Return(views));
  EXPECT_CALL(views.operator*(),showDueDateByPriority(date)).Times(2).WillRepeatedly(Return(vec));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.showDueDateByPriority(date).size(), vec.size());
  ASSERT_EQ(service.showDueDateByPriority(date)[0].lock(),vec[0].lock());
}
TEST_F(TaskServiceTest, showDueDateByLabel) {
  auto date = boost::gregorian::date{2000,8,3};
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;
  std::weak_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  vec.push_back(entity);
  std::shared_ptr<ViewServiceMock> views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(),getViewService()).Times(2).WillRepeatedly(Return(views));
  EXPECT_CALL(views.operator*(),showDueDateByLabel(date)).Times(2).WillRepeatedly(Return(vec));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.showDueDateByLabel(date).size(), vec.size());
  ASSERT_EQ(service.showDueDateByLabel(date)[0].lock(),vec[0].lock());
}
TEST_F(TaskServiceTest, showDueDateByDate) {
  auto date = boost::gregorian::date{2000,8,3};
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;
  std::weak_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::shared_ptr<AllDataStorageMock> storage = std::make_shared<AllDataStorageMock>();
  vec.push_back(entity);
  std::shared_ptr<ViewServiceMock> views = std::make_shared<ViewServiceMock>();
  EXPECT_CALL(storage.operator*(),getViewService()).Times(2).WillRepeatedly(Return(views));
  EXPECT_CALL(views.operator*(),showDueDateByDate(date)).Times(2).WillRepeatedly(Return(vec));
  auto factory = std::make_shared<AllDataStorageFactoryMock>();
  EXPECT_CALL(factory.operator*(), create()).Times(1).WillOnce(Return(storage));
  TaskService service(factory);
  ASSERT_EQ(service.showDueDateByDate(date).size(), vec.size());
  ASSERT_EQ(service.showDueDateByDate(date)[0].lock(),vec[0].lock());
}
