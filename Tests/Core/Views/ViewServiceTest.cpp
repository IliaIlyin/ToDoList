//
// Created by illia.ilin on 8/12/2020.
//

#include <gtest/gtest.h>
#include "Views/ViewService.h"
#include <gmock/gmock.h>
using testing::Eq;
using testing::Return;

class DateViewMock : public GeneralView {
 public:
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAll, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showToday, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showDueDate, (boost::gregorian::date), (override));
  MOCK_METHOD(void, clean, (), (override));
  MOCK_METHOD(bool, insert, (std::shared_ptr<TaskEntity>), (override));
};
class PriorityViewMock : public GeneralView {
 public:
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAll, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showToday, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showDueDate, (boost::gregorian::date), (override));
  MOCK_METHOD(void, clean, (), (override));
  MOCK_METHOD(bool, insert, (std::shared_ptr<TaskEntity>), (override));
};
class LabelViewMock : public GeneralView {
 public:
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAll, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showToday, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showDueDate, (boost::gregorian::date), (override));
  MOCK_METHOD(void, clean, (), (override));
  MOCK_METHOD(bool, insert, (std::shared_ptr<TaskEntity>), (override));
};

class ViewServiceTest : public ::testing::Test {

};

TEST_F(ViewServiceTest, shouldInsertTask) {
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  std::shared_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  EXPECT_CALL(date.operator*(), insert(entity)).Times(1);
  EXPECT_CALL(label.operator*(), insert(entity)).Times(1);
  EXPECT_CALL(priority.operator*(), insert(entity)).Times(1);
  ASSERT_EQ(view_service.insert(entity),true);
}

TEST_F(ViewServiceTest, shouldCleanTask) {
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  std::shared_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  EXPECT_CALL(date.operator*(), clean()).Times(1);
  EXPECT_CALL(label.operator*(), clean()).Times(1);
  EXPECT_CALL(priority.operator*(), clean()).Times(1);
  EXPECT_CALL(date.operator*(), insert(entity)).Times(1);
  EXPECT_CALL(label.operator*(), insert(entity)).Times(1);
  EXPECT_CALL(priority.operator*(), insert(entity)).Times(1);
  view_service.insert(entity);
  entity.reset();
  view_service.clean();
}
TEST_F(ViewServiceTest, shouldShowAllByPriority) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  EXPECT_CALL(priority.operator*(), showAll()).Times(1).WillOnce(Return(vec));
  EXPECT_CALL(label.operator*(), showAll()).Times(0);
  EXPECT_CALL(date.operator*(), showAll()).Times(0);
  ASSERT_EQ(view_service.showAllByPriority().empty(),vec.empty());
}
TEST_F(ViewServiceTest, shouldShowAllByDate) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  EXPECT_CALL(priority.operator*(), showAll()).Times(0);
  EXPECT_CALL(label.operator*(), showAll()).Times(0);
  EXPECT_CALL(date.operator*(), showAll()).Times(1).WillOnce(Return(vec));
  ASSERT_EQ(view_service.showAllByDate().empty(),vec.empty());
}
TEST_F(ViewServiceTest, shouldShowAllByLabel) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  EXPECT_CALL(priority.operator*(), showAll()).Times(0);
  EXPECT_CALL(label.operator*(), showAll()).Times(1).WillOnce(Return(vec));
  EXPECT_CALL(date.operator*(), showAll()).Times(0);
  ASSERT_EQ(view_service.showAllByLabel().empty(),vec.empty());
}
TEST_F(ViewServiceTest, shouldTodayByPriority) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  EXPECT_CALL(priority.operator*(), showToday()).Times(1).WillOnce(Return(vec));
  EXPECT_CALL(label.operator*(), showToday()).Times(0);
  EXPECT_CALL(date.operator*(), showToday()).Times(0);
  ASSERT_EQ(view_service.showTodayByPriority().empty(),vec.empty());
}

TEST_F(ViewServiceTest, shouldShowTodayByLabel) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  EXPECT_CALL(priority.operator*(), showToday()).Times(0);
  EXPECT_CALL(label.operator*(), showToday()).Times(1).WillOnce(Return(vec));
  EXPECT_CALL(date.operator*(), showToday()).Times(0);
  ASSERT_EQ(view_service.showTodayByLabel().empty(),vec.empty());
}
TEST_F(ViewServiceTest, shouldShowDueDateByPriority) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  boost::gregorian::date dat{2000, 11, 9};
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  EXPECT_CALL(priority.operator*(), showDueDate(dat)).Times(1).WillOnce(Return(vec));
  EXPECT_CALL(label.operator*(), showDueDate(dat)).Times(0);
  EXPECT_CALL(date.operator*(), showDueDate(dat)).Times(0);
  ASSERT_EQ(view_service.showDueDateByPriority(dat).empty(),vec.empty());
}
TEST_F(ViewServiceTest, shouldShowDueDateByDate) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  boost::gregorian::date dat{2000, 11, 9};
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  EXPECT_CALL(priority.operator*(), showDueDate(dat)).Times(0);
  EXPECT_CALL(label.operator*(), showDueDate(dat)).Times(0);
  EXPECT_CALL(date.operator*(), showDueDate(dat)).Times(1);
  ASSERT_EQ(view_service.showDueDateByDate(dat).empty(),vec.empty());
}
TEST_F(ViewServiceTest, shouldShowDueDateByLabel) {
  std::vector<std::weak_ptr<TaskEntity>> vec;
  boost::gregorian::date dat{2000, 11, 9};
  std::shared_ptr<DateViewMock> date = std::make_shared<DateViewMock>();
  std::shared_ptr<LabelViewMock> label = std::make_shared<LabelViewMock>();
  std::shared_ptr<PriorityViewMock> priority = std::make_shared<PriorityViewMock>();
  ViewService view_service(priority, label, date);
  EXPECT_CALL(priority.operator*(), showDueDate(dat)).Times(0);
  EXPECT_CALL(label.operator*(), showDueDate(dat)).Times(1).WillOnce(Return(vec));
  EXPECT_CALL(date.operator*(), showDueDate(dat)).Times(0);
  ASSERT_EQ(view_service.showDueDateByLabel(dat).empty(),vec.empty());
}