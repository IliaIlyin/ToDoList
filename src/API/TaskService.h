//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKSERVICE_H
#define TODOLIST_TASKSERVICE_H

#include "TaskDTO.h"
#include "Model/AllDataStorage.h"
#include "dtoConvertor.h"

#include <map>
#include <vector>
#include <memory>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/special_defs.hpp" //include all types plus i/o
#include <optional>

class TaskService {

public:
    bool
    addTask(std::string taskName, boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time),
            Task::Priority priority = Task::Priority::NONE, std::string label = "");

    bool addSubTaskToParent(TaskDTO &parent, std::string taskName,
                            boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time),
                            Task::Priority priority = Task::Priority::NONE, std::string label = "");

    bool addTask(Task &task);

    bool addSubTaskToParent(TaskDTO &parent, Task &task);

    std::optional<TaskDTO> getTask(TaskID id);

    std::optional<std::vector<TaskDTO>> getSubtasks(TaskID id);

public:
    bool postponeTask(TaskDTO &task, boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time));

    bool deleteTask(TaskDTO &task);

    bool completeTask(TaskDTO &task);

public:
    std::vector<TaskDTO> showAllByPriority();

    std::vector<TaskDTO> showAllByLabel();

    std::vector<TaskDTO> showAllByDate();

    std::vector<TaskDTO> showTodayByPriority();

    std::vector<TaskDTO> showTodayByLabel();

    std::vector<TaskDTO>
    showDueDateByPriority(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time));

    std::vector<TaskDTO>
    showDueDateByLabel(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time));

    std::vector<TaskDTO>
    showDueDateByDate(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time));

private:
    AllDataStorage storage_;
    dtoConvertor dto_convertor_;
};

#endif //TODOLIST_TASKSERVICE_H
