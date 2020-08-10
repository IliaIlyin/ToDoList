//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_VIEWS_DATEVIEW_H_
#define TODOLIST_VIEWS_DATEVIEW_H_

#include "GeneralView.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <map>
#include <vector>
#include <memory>
#include <ctime>

class DateView : public GeneralView {
public:
    std::vector<std::weak_ptr<TaskEntity>> showAll() override;

    std::vector<std::weak_ptr<TaskEntity>> showToday() override;

    std::vector<std::weak_ptr<TaskEntity>> showDueDate(boost::gregorian::date date) override;

public:
    void clean() override;

    bool insert(std::shared_ptr<TaskEntity> taskEntity) override;

private:
    std::multimap<boost::gregorian::date, std::weak_ptr<TaskEntity> > dates;
};

#endif //TODOLIST_VIEWS_DATEVIEW_H_
