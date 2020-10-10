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
#include "ViewServiceInterface.h"
/*
 * class to operate views
 */
class ViewService : public ViewServiceInterface {

 public:
  ViewService() = default;

  ViewService(std::shared_ptr<GeneralView> priority_view_,
              std::shared_ptr<GeneralView> label_view_,
              std::shared_ptr<GeneralView> date_view_);
 public:

  std::vector<std::weak_ptr<TaskEntity>> showAllByPriority() override;

  std::vector<std::weak_ptr<TaskEntity>> showAllByLabel() override;

  std::vector<std::weak_ptr<TaskEntity>> showAllByDate() override;

  std::vector<std::weak_ptr<TaskEntity>> showTodayByPriority() override;

  std::vector<std::weak_ptr<TaskEntity>> showTodayByLabel() override;

  std::vector<std::weak_ptr<TaskEntity>> showDueDateByPriority(boost::gregorian::date date) override;

  std::vector<std::weak_ptr<TaskEntity>> showDueDateByLabel(boost::gregorian::date date) override;

  std::vector<std::weak_ptr<TaskEntity>> showDueDateByDate(boost::gregorian::date date) override;

 public:

  void clean() override;

  bool insert(std::shared_ptr<TaskEntity> taskEntity) override;

 private:
  std::shared_ptr<GeneralView> priority_view_;
  std::shared_ptr<GeneralView> label_view_;
  std::shared_ptr<GeneralView> date_view_;
};

#endif //TODOLIST_VIEWS_VIEWSERVICE_H_
