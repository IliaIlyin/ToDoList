//
// Created by ilya on 04.10.20.
//

#ifndef TODOLIST_CORE_COREAPI_H_
#define TODOLIST_CORE_COREAPI_H_
#include "Model/TaskServiceInterface.h"
#include "Model/TaskService.h"
#include "TaskDTO.h"
#include "CoreAPIInterface.h"
#include "Model/dtoConvertor.h"
#include "TaskID.h"

class CoreAPI : public CoreAPIInterface {
 public:
  static CoreAPI create();
  CoreAPI(std::unique_ptr<TaskServiceInterface> service);
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

  std::optional<TaskDTO> getTask(const TaskID &id) override;

  std::optional<std::vector<TaskDTO>> getSubTasks(const TaskID &id) override;

 public:

  bool postponeTask(const TaskID &task,
                    boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  bool deleteTask(const TaskID &task) override;

  bool completeTask(const TaskID &task) override;

 public:

  std::vector<TaskDTO> showAllByPriority() override;

  std::vector<TaskDTO> showAllByLabel() override;

  std::vector<TaskDTO> showAllByDate() override;

  std::vector<TaskDTO> showTodayByPriority() override;

  std::vector<TaskDTO> showTodayByLabel() override;

  std::vector<TaskDTO>
  showDueDateByPriority(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  std::vector<TaskDTO>
  showDueDateByLabel(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  std::vector<TaskDTO>
  showDueDateByDate(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

 private:
  std::unique_ptr<TaskServiceInterface> service_;
};

#endif //TODOLIST_CORE_COREAPI_H_
