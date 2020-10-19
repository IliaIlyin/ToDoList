//
// Created by ilya on 11.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "API/CoreAPI.h"
#include "Model/dtoConvertor.h"
#include "Model/TaskServiceInterface.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class TaskServiceMock : public TaskServiceInterface {

 public:
  MOCK_METHOD(bool, save, (std::string fileName), (override));
  MOCK_METHOD(bool, load, (std::string fileName), (override));
 public:
  MOCK_METHOD(bool,
              addTask,
              (std::string taskName, boost::gregorian::date date,
                  Task::Priority priority, std::string label),
              (override));

  MOCK_METHOD(bool, addSubTaskToParent, (const TaskID &parent, std::string taskName,
      boost::gregorian::date,
      Task::Priority priority, std::string label ), (override));

  MOCK_METHOD(bool, addTask, (Task & task), (override));

  MOCK_METHOD(bool, addSubTaskToParent, (const TaskID &parent, Task &task), (override));

  MOCK_METHOD(std::optional<TaskEntity>, getTask, (const TaskID &id), (override));

  MOCK_METHOD(std::optional<std::vector<std::shared_ptr<TaskEntity>>>, getSubTasks, (const TaskID &id), (override));

 public:

  MOCK_METHOD(bool, postponeTask, (const TaskID &task,
      boost::gregorian::date), (override));

  MOCK_METHOD(bool, deleteTask, (const TaskID &task), (override));

  MOCK_METHOD(bool, completeTask, (const TaskID &task), (override));

 public:

  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAllByPriority, (), (override));

  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAllByLabel, (), (override));

  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAllByDate, (), (override));

  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showTodayByPriority, (), (override));

  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showTodayByLabel, (), (override));

  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>,
              showDueDateByPriority,
              (boost::gregorian::date),
              (override));

  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>,
              showDueDateByLabel,
              (boost::gregorian::date),
              (override));

  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>,
              showDueDateByDate,
              (boost::gregorian::date),
              (override));

};

class CoreApiTest : public ::testing::Test {

};

TEST_F(CoreApiTest, shouldSave) {
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  std::string name = "GFD";
  EXPECT_CALL(service.operator*(), save(name)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.save(name), true);
  ASSERT_EQ(api.save(name), false);
}

TEST_F(CoreApiTest, shouldLoad) {
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  std::string name = "GFD";
  EXPECT_CALL(service.operator*(), load(name)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.load(name), true);
  ASSERT_EQ(api.load(name), false);
}

TEST_F(CoreApiTest, shouldAddTaskInputTask) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  EXPECT_CALL(service.operator*(), addTask(task)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.addTask(task), true);
  ASSERT_EQ(api.addTask(task), false);
}

TEST_F(CoreApiTest, shouldAddTaskInputParams) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  EXPECT_CALL(service.operator*(), addTask("Lol",
                                           boost::gregorian::date{2000, 12, 9},
                                           Task::Priority::FIRST,
                                           "labelgfd")).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.addTask("Lol",
                        boost::gregorian::date{2000, 12, 9},
                        Task::Priority::FIRST,
                        "labelgfd"), true);
  ASSERT_EQ(api.addTask("Lol",
                        boost::gregorian::date{2000, 12, 9},
                        Task::Priority::FIRST,
                        "labelgfd"), false);
}
TEST_F(CoreApiTest, shouldAddSubTaskInputParams) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(1);
  IdGenerator generator;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  EXPECT_CALL(service.operator*(), addSubTaskToParent(id, "Lol",
                                                      boost::gregorian::date{2000, 12, 9},
                                                      Task::Priority::FIRST,
                                                      "labelgfd")).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.addSubTaskToParent(id, "Lol",
                                   boost::gregorian::date{2000, 12, 9},
                                   Task::Priority::FIRST,
                                   "labelgfd"), true);
  ASSERT_EQ(api.addSubTaskToParent(id, "Lol",
                                   boost::gregorian::date{2000, 12, 9},
                                   Task::Priority::FIRST,
                                   "labelgfd"), false);
}

TEST_F(CoreApiTest, shouldAddSubTaskInputTask) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(1);
  IdGenerator generator;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  EXPECT_CALL(service.operator*(),
              addSubTaskToParent(id, task)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.addSubTaskToParent(id, task), true);
  ASSERT_EQ(api.addSubTaskToParent(id, task), false);
}

TEST_F(CoreApiTest, getTask) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(0);
  IdGenerator generator;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  auto dto = dtoConvertor::convert(entity.operator*());
  EXPECT_CALL(service.operator*(), getTask(id)).Times(1).WillOnce(Return(entity.operator*()));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.getTask(id), dto);
}

TEST_F(CoreApiTest, getTaskReturnNullopt) {
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(0);
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  auto result = std::nullopt;
  EXPECT_CALL(service.operator*(), getTask(id)).Times(1).WillOnce(Return(result));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.getTask(id), result);
}

TEST_F(CoreApiTest, getSubTasks) {
  std::vector<std::shared_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(0);
  IdGenerator generator;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  auto entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  vec.push_back(entity);
  auto dto = dtoConvertor::convert(vec);
  EXPECT_CALL(service.operator*(), getSubTasks(id)).Times(1).WillOnce(Return(vec));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.getSubTasks(id), dto);;
}
TEST_F(CoreApiTest, getSubTasksReturnNullopt) {
  std::vector<std::shared_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(0);
  IdGenerator generator;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  auto result = std::nullopt;
  EXPECT_CALL(service.operator*(), getSubTasks(id)).Times(1).WillOnce(Return(result));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.getSubTasks(id), result);;
}

TEST_F(CoreApiTest, postponeTasks) {
  TaskID id(1);
  auto date = boost::gregorian::date{2000, 8, 3};
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  EXPECT_CALL(service.operator*(), postponeTask(id, date)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));

  CoreAPI api(std::move(service));
  ASSERT_EQ(api.postponeTask(id, date), true);
  ASSERT_EQ(api.postponeTask(id, date), false);
}
TEST_F(CoreApiTest, deleteTask) {
  TaskID id(1);
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  EXPECT_CALL(service.operator*(), deleteTask(id)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.deleteTask(id), true);
  ASSERT_EQ(api.deleteTask(id), false);

}
TEST_F(CoreApiTest, completeTask) {
  TaskID id(1);
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  EXPECT_CALL(service.operator*(), completeTask(id)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.completeTask(id), true);
  ASSERT_EQ(api.completeTask(id), false);

}

TEST_F(CoreApiTest, showAllByDate) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;
  auto ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::weak_ptr<TaskEntity> entity = ptr;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  vec.push_back(entity);
  auto dtos = dtoConvertor::convert(vec);
  EXPECT_CALL(service.operator*(), showAllByDate()).Times(2).WillRepeatedly(Return(vec));
  CoreAPI api(std::move(service));
  ASSERT_EQ(api.showAllByDate().size(), dtos.size());
  ASSERT_EQ(api.showAllByDate()[0], dtos[0]);
}

TEST_F(CoreApiTest, showAllByLabel) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;

  auto ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::weak_ptr<TaskEntity> entity = ptr;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  vec.push_back(entity);
  auto dtos = dtoConvertor::convert(vec);

  EXPECT_CALL(service.operator*(), showAllByLabel()).Times(2).WillRepeatedly(Return(vec));

  CoreAPI api(std::move(service));
  ASSERT_EQ(api.showAllByLabel().size(), vec.size());
  ASSERT_EQ(api.showAllByLabel()[0], dtos[0]);
}
TEST_F(CoreApiTest, showAllByPriority) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;

  auto ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::weak_ptr<TaskEntity> entity = ptr;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  vec.push_back(entity);
  auto dtos = dtoConvertor::convert(vec);

  EXPECT_CALL(service.operator*(), showAllByPriority()).Times(2).WillRepeatedly(Return(vec));

  CoreAPI api(std::move(service));
  ASSERT_EQ(api.showAllByPriority().size(), vec.size());
  ASSERT_EQ(api.showAllByPriority()[0], dtos[0]);
}
TEST_F(CoreApiTest, showTodayByLabel) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;

  auto ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::weak_ptr<TaskEntity> entity = ptr;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  vec.push_back(entity);
  auto dtos = dtoConvertor::convert(vec);

  EXPECT_CALL(service.operator*(), showTodayByLabel()).Times(2).WillRepeatedly(Return(vec));

  CoreAPI api(std::move(service));
  ASSERT_EQ(api.showTodayByLabel().size(), vec.size());
  ASSERT_EQ(api.showTodayByLabel()[0], dtos[0]);
}
TEST_F(CoreApiTest, showTodayByPriority) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;

  auto ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::weak_ptr<TaskEntity> entity = ptr;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  vec.push_back(entity);
  auto dtos = dtoConvertor::convert(vec);

  EXPECT_CALL(service.operator*(), showTodayByPriority()).Times(2).WillRepeatedly(Return(vec));

  CoreAPI api(std::move(service));
  ASSERT_EQ(api.showTodayByPriority().size(), vec.size());
  ASSERT_EQ(api.showTodayByPriority()[0], dtos[0]);
}
TEST_F(CoreApiTest, showDueDateByPriority) {
  auto date = boost::gregorian::date{2000, 8, 3};
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;

  auto ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::weak_ptr<TaskEntity> entity = ptr;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  vec.push_back(entity);
  auto dtos = dtoConvertor::convert(vec);

  EXPECT_CALL(service.operator*(), showDueDateByPriority(date)).Times(2).WillRepeatedly(Return(vec));

  CoreAPI api(std::move(service));
  ASSERT_EQ(api.showDueDateByPriority(date).size(), vec.size());
  ASSERT_EQ(api.showDueDateByPriority(date)[0], dtos[0]);
}
TEST_F(CoreApiTest, showDueDateByLabel) {
  auto date = boost::gregorian::date{2000, 8, 3};
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;

  auto ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::weak_ptr<TaskEntity> entity = ptr;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  vec.push_back(entity);
  auto dtos = dtoConvertor::convert(vec);

  EXPECT_CALL(service.operator*(), showDueDateByLabel(date)).Times(2).WillRepeatedly(Return(vec));

  CoreAPI api(std::move(service));
  ASSERT_EQ(api.showDueDateByLabel(date).size(), vec.size());
  ASSERT_EQ(api.showDueDateByLabel(date)[0], dtos[0]);
}
TEST_F(CoreApiTest, showDueDateByDate) {
  auto date = boost::gregorian::date{2000, 8, 3};
  std::vector<std::weak_ptr<TaskEntity>> vec;
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  IdGenerator generator;

  auto ptr = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, generator));
  std::weak_ptr<TaskEntity> entity = ptr;
  std::unique_ptr<TaskServiceMock> service = std::make_unique<TaskServiceMock>();
  vec.push_back(entity);
  auto dtos = dtoConvertor::convert(vec);

  EXPECT_CALL(service.operator*(), showDueDateByDate(date)).Times(2).WillRepeatedly(Return(vec));

  CoreAPI api(std::move(service));
  ASSERT_EQ(api.showDueDateByDate(date).size(), vec.size());
  ASSERT_EQ(api.showDueDateByDate(date)[0], dtos[0]);
}

