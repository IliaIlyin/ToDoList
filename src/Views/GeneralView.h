//
// Created by Ilya on 8/2/2020.
//

#ifndef TODOLIST_VIEWS_GENERALVIEW_H_
#define TODOLIST_VIEWS_GENERALVIEW_H_

#include "Model/TaskEntity.h"

#include <memory>
#include <vector>
#include "boost/date_time/gregorian/gregorian.hpp"

class GeneralView {

public:
    virtual std::vector<std::weak_ptr<TaskEntity>> showAll() = 0;

    virtual std::vector<std::weak_ptr<TaskEntity>> showToday() = 0;

    virtual std::vector<std::weak_ptr<TaskEntity>> showDueDate(boost::gregorian::date date) = 0;

    virtual void clean() = 0;

    virtual ~GeneralView()=default;

    virtual bool insert(std::shared_ptr<TaskEntity> taskEntity) = 0;
};

#endif //TODOLIST_VIEWS_GENERALVIEW_H_
