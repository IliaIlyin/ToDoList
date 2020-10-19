//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKSERVICE_H
#define TODOLIST_TASKSERVICE_H

#include "TaskServiceInterface.h"
#include "Model/TaskEntity.h"
#include "Model/AllDataStorage.h"
#include "Model/dtoConvertor.h"
#include "Model/AllDataStorageFactory.h"
#include "Serialization/Persistor.h"

#include <map>
#include <vector>
#include <memory>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/special_defs.hpp" //include all types plus i/o
#include <optional>
#include <future>
#include <mutex>

/*
 * Task service
 *
 * @author Ilya Ilyin
 */
class TaskService : public TaskServiceInterface {
 public:
  TaskService(std::shared_ptr<AllDataStorageFactoryInterface> factory);
 public:
  bool save(std::string fileName) override;
  bool load(std::string fileName) override;
 public:
  bool
  addTask(std::string taskName, boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time),
          Task::Priority priority = Task::Priority::NONE, std::string label = "") override;

  bool addSubTaskToParent(const TaskID &parent, std::string taskName,
                          boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time),
                          Task::Priority priority = Task::Priority::NONE, std::string label = "") override;

  bool addTask(Task &task) override;

  bool addSubTaskToParent(const TaskID &parent, Task &task) override;

  std::optional<TaskEntity> getTask(const TaskID &id) override;

  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID &id) override;

 public:

  bool postponeTask(const TaskID &task,
                    boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  bool deleteTask(const TaskID &task) override;

  bool completeTask(const TaskID &task) override;

 public:

  std::vector<std::weak_ptr<TaskEntity>> showAllByPriority() override;

  std::vector<std::weak_ptr<TaskEntity>> showAllByLabel() override;

  std::vector<std::weak_ptr<TaskEntity>> showAllByDate() override;

  std::vector<std::weak_ptr<TaskEntity>> showTodayByPriority() override;

  std::vector<std::weak_ptr<TaskEntity>> showTodayByLabel() override;

  std::vector<std::weak_ptr<TaskEntity>>
  showDueDateByPriority(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  std::vector<std::weak_ptr<TaskEntity>>
  showDueDateByLabel(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  std::vector<std::weak_ptr<TaskEntity>>
  showDueDateByDate(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

 private:
  std::shared_ptr<AllDataStorageInterface> storage_;
  std::shared_ptr<AllDataStorageFactoryInterface> factory_;
  std::mutex mutex_;
};

#endif //TODOLIST_TASKSERVICE_H
