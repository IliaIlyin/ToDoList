//
// Created by Ilya on 8/3/2020.
//

#ifndef TODOLIST_VIEWS_VIEWSERVICE_H_
#define TODOLIST_VIEWS_VIEWSERVICE_H_

#include "GeneralView.h"
#include "LabelView.h"
#include "PriorityView.h"
#include "DateView.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <vector>
#include <memory>
/*
 * class to operate views
 */
class ViewService {

 public:
  ViewService()=default;

  ViewService(std::shared_ptr<GeneralView> priority_view_,
              std::shared_ptr<GeneralView> label_view_,
              std::shared_ptr<GeneralView> date_view_);
 public:
  /*
   * @return container of tasks that satisfy the request
   */
  std::vector<std::weak_ptr<TaskEntity>> showAllByPriority();
  /*
    * @return container of tasks that satisfy the request
    */
  std::vector<std::weak_ptr<TaskEntity>> showAllByLabel();
  /*
    * @return container of tasks that satisfy the request
    */
  std::vector<std::weak_ptr<TaskEntity>> showAllByDate();
  /*
    * @return container of tasks that satisfy the request
    */
  std::vector<std::weak_ptr<TaskEntity>> showTodayByPriority();
  /*
    * @return container of tasks that satisfy the request
    */
  std::vector<std::weak_ptr<TaskEntity>> showTodayByLabel();
  /*
    * @return container of tasks that satisfy the request
    */
  std::vector<std::weak_ptr<TaskEntity>> showDueDateByPriority(boost::gregorian::date date);
  /*
    * @return container of tasks that satisfy the request
    */
  std::vector<std::weak_ptr<TaskEntity>> showDueDateByLabel(boost::gregorian::date date);
  /*
    * @return container of tasks that satisfy the request
    */
  std::vector<std::weak_ptr<TaskEntity>> showDueDateByDate(boost::gregorian::date date);

 public:
/*
 * cleans general_view_
 */
  void clean();
/*
 * insert task in the general_view_
 *
 * @return true,if the insertion was completed. False, otherwise.
 */
  bool insert(std::shared_ptr<TaskEntity> taskEntity);

 private:
  std::shared_ptr<GeneralView> priority_view_;
  std::shared_ptr<GeneralView> label_view_;
  std::shared_ptr<GeneralView> date_view_;
};

#endif //TODOLIST_VIEWS_VIEWSERVICE_H_
