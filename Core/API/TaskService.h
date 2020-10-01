//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_TASKSERVICE_H
#define TODOLIST_TASKSERVICE_H

#include "TaskDTO.h"
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

/*
 * public API for adding tasks to the Model,adding SubTasks to tasks, getting tasks, getting SubTasks.
 * API can postpone tasks, delete and complete them.
 * Also it provides the capability of representing information in the sorted way. Current sorting options:
 * sort tasks by label, priority, date
 * @see GeneralView
 * @see Task
 *
 * @author Ilya Ilyin
 */
class TaskService {
 public:
  TaskService();
  TaskService(std::shared_ptr<AllDataStorageFactory> factory,std::shared_ptr<Persistor>);
 public:
  bool save(std::string fileName);
  bool load(std::string fileName);
 public:
  /*
   * adds task to the model. All params are params to construct task
   * @see Task
   *
   * @param taskName representing task name
   * @param date representing date to complete task. Set to boost::gregorian::min_date_time by default
   * @param priority Task Priority. Set to NONE by default
   * @param label Task label. Set empty by default
   *
   * @return true, if adding was completed succesfully.
   * @return false, otherwise.
   */
  bool
  addTask(std::string taskName, boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time),
          Task::Priority priority = Task::Priority::NONE, std::string label = "");

  /*
* adds task to the model. All params are params to construct task
* @see Task
*
   * @param parent TaskDTO to Add SubTask to
* @param taskName representing task name
* @param date representing date to complete task. Set to boost::gregorian::min_date_time by default
* @param priority Task Priority. Set to NONE by default
* @param label Task label. Set empty by default
*
* @return true, if adding was completed succesfully.
* @return false, otherwise.
*/
  bool addSubTaskToParent(const TaskID & parent, std::string taskName,
                          boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time),
                          Task::Priority priority = Task::Priority::NONE, std::string label = "");
/*
 * adds task to the model
 * @param task Task to Add
 * @return true, if adding was completed succesfully.
* @return false, otherwise.
 */
  bool addTask(Task &task);
/*
 * adds one task as a SubTask to another.
 * @param parent Parent task to Add SubTask to
 * @param task SubTask to Add to parent
 *
 * @return true, if adding was completed succesfully.
* @return false, otherwise.
 */
  bool addSubTaskToParent(const TaskID &parent, Task &task);

  /*
   * gets task by TaskID
   * @param task id to look for
   * @return TaskDTO if task was found.
   * @return nullopt,otherwise.
   */
  std::optional<TaskDTO> getTask(const TaskID & id);

  /*
   * gets SubTasks of the task by const TaskID &
   * @param task id to look for
   * @return container of TaskDTO if task was found.
   * @return nullopt,otherwise.
   */
  std::optional<std::vector<TaskDTO>> getSubTasks(const TaskID & id);

 public:
  /*
   * sets task date to the new value
   *
   * @param task TaskDTO which to change
   * @param date new date to set
   *
 * @return true, if postponing was completed succesfully.
* @return false, otherwise.
   */
  bool postponeTask(const TaskID & task, boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time));

  /*
  * sets task date to the new value
  *
  * @param task TaskDTO to delete
  *
* @return true, if deleting was completed succesfully.
* @return false, otherwise.
  */
  bool deleteTask(const TaskID & task);
  /*
   * sets task status to true
   *
   * @param task task to complete
   *
  * @return true, if completing was completed succesfully.
* @return false, otherwise.
   */
  bool completeTask(const TaskID & task);

 public:
  /*
   * shows all tasks sorted by priority
   * @return container of tasks sorted by priority (ascending)
   */
  std::vector<TaskDTO> showAllByPriority();
  /*
    * shows all tasks sorted by date
    * @return container of tasks sorted by date (ascending)
    */
  std::vector<TaskDTO> showAllByLabel();
  /*
    * shows all tasks sorted by label in LEX order
    * @return container of tasks sorted by label (ascending)
    */
  std::vector<TaskDTO> showAllByDate();
  /*
    * shows all today tasks sorted by priority
    * @return container of tasks sorted by priority where the date value is today (ascending)
    */
  std::vector<TaskDTO> showTodayByPriority();
  /*
     * shows all today tasks sorted by label in LEX order
     * @return container of tasks sorted by label where the date value is today (ascending)
     */
  std::vector<TaskDTO> showTodayByLabel();
/*
     * shows all tasks due date sorted by priority
     *
     * @param date date until which we search for
     * @return container of tasks sorted by priority where the date value is less than date
     */
  std::vector<TaskDTO>
  showDueDateByPriority(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time));
/*
     * shows all tasks due date sorted by label
     *
     * @param date date until which we search for
     * @return container of tasks sorted by label where the date value is less than date
     */
  std::vector<TaskDTO>
  showDueDateByLabel(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time));
/*
     * shows all tasks due date sorted by date
     *
     * @param date date until which we search for
     * @return container of tasks sorted by date where the date value is less than date
     */
  std::vector<TaskDTO>
  showDueDateByDate(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time));

 private:
  std::shared_ptr<AllDataStorageInterface> storage_;
  std::shared_ptr<AllDataStorageFactory> factory_;
  std::shared_ptr<Persistor> persistor_;
};

#endif //TODOLIST_TASKSERVICE_H
