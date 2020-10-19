//
// Created by ilya on 10.10.20.
//

#ifndef TODOLIST_CORE_VIEWS_VIEWSERVICEINTERFACE_H_
#define TODOLIST_CORE_VIEWS_VIEWSERVICEINTERFACE_H_
/*
 * class that operates views
 *
 * @author ilya ilyin
 */
class ViewServiceInterface {
 public:
  /*
   * @return container of tasks that satisfy the request
   */
  virtual std::vector<std::weak_ptr<TaskEntity>> showAllByPriority() = 0;
  /*
    * @return container of tasks that satisfy the request
    */
  virtual std::vector<std::weak_ptr<TaskEntity>> showAllByLabel() = 0;
  /*
    * @return container of tasks that satisfy the request
    */
  virtual std::vector<std::weak_ptr<TaskEntity>> showAllByDate() = 0;
  /*
    * @return container of tasks that satisfy the request
    */
  virtual std::vector<std::weak_ptr<TaskEntity>> showTodayByPriority() = 0;
  /*
    * @return container of tasks that satisfy the request
    */
  virtual std::vector<std::weak_ptr<TaskEntity>> showTodayByLabel() = 0;
  /*
    * @return container of tasks that satisfy the request
    */
  virtual std::vector<std::weak_ptr<TaskEntity>> showDueDateByPriority(boost::gregorian::date date) = 0;
  /*
    * @return container of tasks that satisfy the request
    */
  virtual std::vector<std::weak_ptr<TaskEntity>> showDueDateByLabel(boost::gregorian::date date) = 0;
  /*
    * @return container of tasks that satisfy the request
    */
  virtual std::vector<std::weak_ptr<TaskEntity>> showDueDateByDate(boost::gregorian::date date) = 0;

 public:
/*
 * cleans empty tasks in views
 */
  virtual void clean() = 0;
/*
 * insert task in the views
 *
 * @return true,if the insertion was completed. False, otherwise.
 */
  virtual bool insert(std::shared_ptr<TaskEntity> taskEntity) = 0;

  virtual ~ViewServiceInterface() = default;
};
#endif //TODOLIST_CORE_VIEWS_VIEWSERVICEINTERFACE_H_
