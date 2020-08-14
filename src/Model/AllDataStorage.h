//
// Created by Ilya on 8/3/2020.
//

#ifndef TODOLIST_MODEL_ALLDATASTORAGE_H_
#define TODOLIST_MODEL_ALLDATASTORAGE_H_

#include "Views/ViewService.h"
#include "StorageService.h"
#include "boost/date_time/gregorian/gregorian.hpp"

class AllDataStorage {

 public:

  bool addTask(Task &task);

  std::optional<std::shared_ptr<TaskEntity>> addSubTaskToParent(const TaskID  &parent, Task &task);

  std::optional<std::shared_ptr<TaskEntity>> getTask(const TaskID & id);

  std::optional<std::vector<std::shared_ptr<TaskEntity>>> getSubTasks(const TaskID & id);

 public:
  bool postponeTask(const TaskID & task, boost::gregorian::date dueDate);

  bool deleteTask(const TaskID & task);

  bool completeTask(const TaskID &task);

 public:
  const ViewService &getViewService() const;

 private:
  ViewService view_service_;
  StorageService storage_service_;
};

#endif //TODOLIST_MODEL_ALLDATASTORAGE_H_
