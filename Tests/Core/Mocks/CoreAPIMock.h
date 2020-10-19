//
// Created by ilya on 18.10.20.
//

#ifndef TODOLIST_TESTS_CORE_MOCKS_COREAPIMOCK_H_
#define TODOLIST_TESTS_CORE_MOCKS_COREAPIMOCK_H_
#include "API/CoreAPIInterface.h"
class CoreAPIMock : public CoreAPIInterface {
 public:
  MOCK_METHOD(bool, save, (std::string fileName), (override));
  MOCK_METHOD(bool, load, (std::string fileName), (override));
 public:
  MOCK_METHOD(bool,
              addTask, (std::string taskName, boost::gregorian::date date,
                        Task::Priority priority, std::string label ), (override));

  MOCK_METHOD(bool, addSubTaskToParent, (const TaskID &parent, std::string taskName,
                                         boost::gregorian::date,
                                         Task::Priority priority, std::string label ), (override));

  MOCK_METHOD(bool, addTask, (Task & task), (override));

  MOCK_METHOD(bool, addSubTaskToParent, (const TaskID &parent, Task &task), (override));

  MOCK_METHOD(std::optional<TaskDTO>, getTask, (const TaskID &id), (override));

  MOCK_METHOD(std::optional<std::vector<TaskDTO>>, getSubTasks, (const TaskID &id), (override));

 public:

  MOCK_METHOD(bool, postponeTask, (const TaskID &task,
                                   boost::gregorian::date), (override));

  MOCK_METHOD(bool, deleteTask, (const TaskID &task), (override));

  MOCK_METHOD(bool, completeTask, (const TaskID &task), (override));

 public:

  MOCK_METHOD(std::vector<TaskDTO>, showAllByPriority, (), (override));

  MOCK_METHOD(std::vector<TaskDTO>, showAllByLabel, (), (override));

  MOCK_METHOD(std::vector<TaskDTO>, showAllByDate, (), (override));

  MOCK_METHOD(std::vector<TaskDTO>, showTodayByPriority, (), (override));

  MOCK_METHOD(std::vector<TaskDTO>, showTodayByLabel, (), (override));

  MOCK_METHOD(std::vector<TaskDTO>,
      showDueDateByPriority,(boost::gregorian::date),
  (override));

  MOCK_METHOD(std::vector<TaskDTO>,
      showDueDateByLabel,
  (boost::gregorian::date),
  (override));

  MOCK_METHOD(std::vector<TaskDTO>,
      showDueDateByDate,
  (boost::gregorian::date),
  (override));
};
#endif //TODOLIST_TESTS_CORE_MOCKS_COREAPIMOCK_H_
