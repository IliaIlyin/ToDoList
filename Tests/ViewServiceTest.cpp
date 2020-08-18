//
// Created by illia.ilin on 8/12/2020.
//

#include <gtest/gtest.h>
#include "Views/ViewService.h"
#include <gmock/gmock.h>
using testing::Eq;

class DateViewMock:public GeneralView {
 public:
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAll, (), (override));
  DateViewMock(DateViewMock& mock)=default;
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showToday, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showDueDate, (boost::gregorian::date), (override));
  MOCK_METHOD(void, clean, (), (override));
  MOCK_METHOD(bool, insert, (std::shared_ptr<TaskEntity>), (override));
};
class PriorityViewMock:public GeneralView {
 public:
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAll, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showToday, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showDueDate, (boost::gregorian::date), (override));
  MOCK_METHOD(void, clean, (), (override));
  MOCK_METHOD(bool, insert, (std::shared_ptr<TaskEntity>), (override));
};
class LabelViewMock:public GeneralView {
 public:
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAll, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showToday, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showDueDate, (boost::gregorian::date), (override));
  MOCK_METHOD(void, clean, (), (override));
  MOCK_METHOD(bool, insert, (std::shared_ptr<TaskEntity>), (override));
};

class ViewServiceTest : public ::testing::Test {

};

TEST_F(ViewServiceTest, shouldAddTask) {
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  DateViewMock obj = date.operator*();
  ViewService view_service(priority,label,date);
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  std::shared_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  EXPECT_CALL(date.operator*(),insert(entity)).Times(1);
  EXPECT_CALL(label.operator*(),insert(entity)).Times(1);
  EXPECT_CALL(priority.operator*(),insert(entity)).Times(1);
  view_service.insert(entity);
}

TEST_F(ViewServiceTest, shouldCleanTask) {
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  ViewService view_service(priority,label,date);
  Task task = Task::createTask("Lol", boost::gregorian::date{2000, 12, 9}, Task::Priority::FIRST, "label");
  IdGenerator idGenerator;
  TaskEntity taskEntity = TaskEntity::createTaskEntity(task, idGenerator);
  std::shared_ptr<TaskEntity> entity = std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task, idGenerator));
  EXPECT_CALL(date.operator*(),clean()).Times(1);
  EXPECT_CALL(label.operator*(),clean()).Times(1);
  EXPECT_CALL(priority.operator*(),clean()).Times(1);
  view_service.insert(entity);
  entity.reset();
  view_service.clean();
}
TEST_F(ViewServiceTest, shouldShowAllByPriority) {
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  ViewService view_service(priority,label,date);
  EXPECT_CALL(priority.operator*(),showAll()).Times(1);
  EXPECT_CALL(label.operator*(),showAll()).Times(0);
  EXPECT_CALL(date.operator*(),showAll()).Times(0);
  view_service.showAllByPriority();
}
TEST_F(ViewServiceTest, shouldShowAllByDate) {
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  ViewService view_service(priority,label,date);
  EXPECT_CALL(priority.operator*(),showAll()).Times(0);
  EXPECT_CALL(label.operator*(),showAll()).Times(0);
  EXPECT_CALL(date.operator*(),showAll()).Times(1);
  view_service.showAllByDate();
}
TEST_F(ViewServiceTest, shouldShowAllByLabel) {
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  ViewService view_service(priority,label,date);
  EXPECT_CALL(priority.operator*(),showAll()).Times(0);
  EXPECT_CALL(label.operator*(),showAll()).Times(1);
  EXPECT_CALL(date.operator*(),showAll()).Times(0);
  view_service.showAllByLabel();
}
TEST_F(ViewServiceTest, shouldTodayByPriority) {
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  ViewService view_service(priority,label,date);
  EXPECT_CALL(priority.operator*(),showToday()).Times(1);
  EXPECT_CALL(label.operator*(),showToday()).Times(0);
  EXPECT_CALL(date.operator*(),showToday()).Times(0);
  view_service.showTodayByPriority();
}

TEST_F(ViewServiceTest, shouldShowTodayByLabel) {
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  ViewService view_service(priority,label,date);
  EXPECT_CALL(priority.operator*(),showToday()).Times(0);
  EXPECT_CALL(label.operator*(),showToday()).Times(1);
  EXPECT_CALL(date.operator*(),showToday()).Times(0);
  view_service.showTodayByLabel();
}
TEST_F(ViewServiceTest, shouldShowDueDateByPriority) {
  boost::gregorian::date dat{2000,11,9};
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  ViewService view_service(priority,label,date);
  EXPECT_CALL(priority.operator*(),showDueDate(dat)).Times(1);
  EXPECT_CALL(label.operator*(),showDueDate(dat)).Times(0);
  EXPECT_CALL(date.operator*(),showDueDate(dat)).Times(0);
  view_service.showDueDateByPriority(dat);
}
TEST_F(ViewServiceTest, shouldShowDueDateByDate) {
  boost::gregorian::date dat{2000,11,9};
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  ViewService view_service(priority,label,date);
  EXPECT_CALL(priority.operator*(),showDueDate(dat)).Times(0);
  EXPECT_CALL(label.operator*(),showDueDate(dat)).Times(0);
  EXPECT_CALL(date.operator*(),showDueDate(dat)).Times(1);
  view_service.showDueDateByDate(dat);
}
TEST_F(ViewServiceTest, shouldShowDueDateByLabel) {
  boost::gregorian::date dat{2000,11,9};
  std::shared_ptr<DateViewMock> date;
  std::shared_ptr<LabelViewMock> label;
  std::shared_ptr<PriorityViewMock> priority;
  ViewService view_service(priority,label,date);
  EXPECT_CALL(priority.operator*(),showDueDate(dat)).Times(0);
  EXPECT_CALL(label.operator*(),showDueDate(dat)).Times(1);
  EXPECT_CALL(date.operator*(),showDueDate(dat)).Times(0);
  view_service.showDueDateByLabel(dat);
}