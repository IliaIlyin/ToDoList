//
// Created by ilya on 11.10.20.
//

#ifndef TODOLIST_TESTS_CORE_MOCKS_VIEWSERVICEMOCK_H_
#define TODOLIST_TESTS_CORE_MOCKS_VIEWSERVICEMOCK_H_
#include "Views/ViewServiceInterface.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class ViewServiceMock : public ViewServiceInterface {
 public:
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAllByPriority, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAllByLabel, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showAllByDate, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showTodayByPriority, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showTodayByLabel, (), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showDueDateByPriority, (boost::gregorian::date date), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showDueDateByLabel, (boost::gregorian::date date), (override));
  MOCK_METHOD(std::vector<std::weak_ptr<TaskEntity>>, showDueDateByDate, (boost::gregorian::date date), (override));
  MOCK_METHOD(void, clean, (), (override));
  MOCK_METHOD(bool, insert, (std::shared_ptr<TaskEntity> taskEntity), (override));
};

#endif //TODOLIST_TESTS_CORE_MOCKS_VIEWSERVICEMOCK_H_
