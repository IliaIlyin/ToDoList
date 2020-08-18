//
// Created by Ilya on 8/9/2020.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "API/TaskService.h"

using testing::Eq;
using testing::Return;

class AllDataStorageMock : public AllDataStorageInterface {

 public:
  MOCK_METHOD(bool, addTask, (Task &task), (override));
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>,
              addSubTaskToParent,
              (const TaskID  &parent, Task &task),
              (override));
  MOCK_METHOD(std::optional<std::shared_ptr<TaskEntity>>, getTask, (const TaskID & id), (override));
  MOCK_METHOD(std::optional<std::vector<std::shared_ptr<TaskEntity>>>, getSubTasks, (const TaskID & id), (override));
  MOCK_METHOD(bool, postponeTask, (const TaskID & task, boost::gregorian::date dueDate), (override));
  MOCK_METHOD(bool, deleteTask, (const TaskID & task), (override));
  MOCK_METHOD(bool, completeTask, (const TaskID &task), (override));
  MOCK_METHOD(const ViewService &, getViewService, (), (const, override));

};
class TaskServiceTest : public ::testing::Test {

};
TEST_F(TaskServiceTest, shouldAddTaskInputTask) {
  auto mock = std::make_unique<AllDataStorageMock>();
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");

  EXPECT_CALL(mock.operator*(),addTask(task)).Times(1);
  TaskService service(std::move(mock));
  service.addTask(task);
}
TEST_F(TaskServiceTest, shouldAddTaskInputParams) {
  auto mock = std::make_unique<AllDataStorageMock>();
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");

  EXPECT_CALL(mock.operator*(),addTask(task)).Times(1);
  TaskService service(std::move(mock));
  service.addTask("Lol",
      boost::gregorian::date{2000, 12, 9},
      Task::Priority::FIRST,
      "labelgfd");
}
TEST_F(TaskServiceTest, shouldAddSubTaskInputParams) {
  auto mock = std::make_unique<AllDataStorageMock>();
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(1);
  EXPECT_CALL(mock.operator*(),addSubTaskToParent(id,task)).Times(1);
  TaskService service(std::move(mock));
  service.addSubTaskToParent(id,"Lol",
                  boost::gregorian::date{2000, 12, 9},
                  Task::Priority::FIRST,
                  "labelgfd");
}
TEST_F(TaskServiceTest, shouldAddSubTaskInputTask) {
  auto mock = std::make_unique<AllDataStorageMock>();
  Task task = Task::createTask("Lol",
                               boost::gregorian::date{2000, 12, 9},
                               Task::Priority::FIRST,
                               "labelgfd");
  TaskID id(1);
  EXPECT_CALL(mock.operator*(),addSubTaskToParent(id,task)).Times(1);
  TaskService service(std::move(mock));
  service.addSubTaskToParent(id,task);
}
TEST_F(TaskServiceTest, getTask) {
  auto mock = std::make_unique<AllDataStorageMock>();
  TaskID id(1);
  EXPECT_CALL(mock.operator*(),getTask(id));
  TaskService service(std::move(mock));
  service.getTask(id);
}
TEST_F(TaskServiceTest, getSubTasks) {
  auto mock = std::make_unique<AllDataStorageMock>();
  TaskID id(1);
  EXPECT_CALL(mock.operator*(),getSubTasks(id));
  TaskService service(std::move(mock));
  service.getSubTasks(id);
}
TEST_F(TaskServiceTest, postponeTasks) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  TaskID id(1);
  EXPECT_CALL(mock.operator*(),postponeTask(id,date));
  TaskService service(std::move(mock));
  service.postponeTask(id,date);
}
TEST_F(TaskServiceTest, deleteTask) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  TaskID id(1);
  EXPECT_CALL(mock.operator*(),deleteTask(id));
  TaskService service(std::move(mock));
  service.deleteTask(id);
}
TEST_F(TaskServiceTest, completeTask) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  TaskID id(1);
  EXPECT_CALL(mock.operator*(),completeTask(id));
  TaskService service(std::move(mock));
  service.completeTask(id);
}
TEST_F(TaskServiceTest, showAllByDate) {
  auto mock = std::make_unique<AllDataStorageMock>();
  ON_CALL(mock.operator*(), getViewService).WillByDefault(Return(ViewService()));
  boost::gregorian::date date{2000,11,8};
  EXPECT_CALL(mock.operator*(),getViewService());
  TaskService service(std::move(mock));
  service.showAllByDate();
}
TEST_F(TaskServiceTest, showAllByLabel) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  EXPECT_CALL(mock.operator*(),getViewService());
  TaskService service(std::move(mock));
  service.showAllByLabel();
}
TEST_F(TaskServiceTest, showAllByPriority) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  EXPECT_CALL(mock.operator*(),getViewService());
  TaskService service(std::move(mock));
  service.showAllByPriority();
}
TEST_F(TaskServiceTest, showTodayByLabel) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  EXPECT_CALL(mock.operator*(),getViewService());
  TaskService service(std::move(mock));
  service.showTodayByLabel();
}
TEST_F(TaskServiceTest, showTodayByPriority) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  EXPECT_CALL(mock.operator*(),getViewService());
  TaskService service(std::move(mock));
  service.showTodayByPriority();
}
TEST_F(TaskServiceTest, showDueDateByPriority) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  EXPECT_CALL(mock.operator*(),getViewService());
  TaskService service(std::move(mock));
  service.showDueDateByPriority(date);
}
TEST_F(TaskServiceTest, showDueDateByLabel) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  EXPECT_CALL(mock.operator*(),getViewService());
  TaskService service(std::move(mock));
  service.showDueDateByLabel(date);
}
TEST_F(TaskServiceTest, showDueDateByDate) {
  auto mock = std::make_unique<AllDataStorageMock>();
  boost::gregorian::date date{2000,11,8};
  EXPECT_CALL(mock.operator*(),getViewService());
  TaskService service(std::move(mock));
  service.showDueDateByDate(date);
}