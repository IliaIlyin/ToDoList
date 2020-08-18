//
// Created by Ilya on 8/2/2020.
//

#ifndef TODOLIST_VIEWS_GENERALVIEW_H_
#define TODOLIST_VIEWS_GENERALVIEW_H_

#include "Model/TaskEntity.h"

#include <memory>
#include <vector>
#include "boost/date_time/gregorian/gregorian.hpp"
/*
 * view interface
 */
class GeneralView {

public:
  /*
   * shows all views
   */
    virtual std::vector<std::weak_ptr<TaskEntity>> showAll() = 0;
/*
   * shows all today views
   */
    virtual std::vector<std::weak_ptr<TaskEntity>> showToday() = 0;
/*
   * shows views due date
   */
    virtual std::vector<std::weak_ptr<TaskEntity>> showDueDate(boost::gregorian::date date) = 0;
/*
 cleans the view. Deletes all nullptr objects
 */
    virtual void clean() = 0;

    virtual ~GeneralView()=default;
/*
 inserts the object to the view. Deletes all nullptr objects
 */
    virtual bool insert(std::shared_ptr<TaskEntity> taskEntity) = 0;
};

#endif //TODOLIST_VIEWS_GENERALVIEW_H_
