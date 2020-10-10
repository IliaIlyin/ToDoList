//
// Created by ilya on 06.10.20.
//

#ifndef TODOLIST_CORE_COREAPIINTERFACE_H_
#define TODOLIST_CORE_COREAPIINTERFACE_H_
#include "TaskDTO.h"
#include "TaskID.h"
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
class CoreAPIInterface {
 public:
  ~CoreAPIInterface()=default;
  virtual bool save(std::string fileName)=0;
  virtual bool load(std::string fileName)=0;
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
  virtual bool
  addTask(std::string taskName, boost::gregorian::date date = boost::gregorian::date(boost::gregorian::min_date_time),
          Task::Priority priority = Task::Priority::NONE, std::string label = "")=0;

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
  virtual bool addSubTaskToParent(const TaskID &parent, std::string taskName,
                          boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time),
                          Task::Priority priority = Task::Priority::NONE, std::string label = "")=0;
/*
 * adds task to the model
 * @param task Task to Add
 * @return true, if adding was completed succesfully.
* @return false, otherwise.
 */
  virtual bool addTask(Task &task)=0;
/*
 * adds one task as a SubTask to another.
 * @param parent Parent task to Add SubTask to
 * @param task SubTask to Add to parent
 *
 * @return true, if adding was completed succesfully.
* @return false, otherwise.
 */
  virtual bool addSubTaskToParent(const TaskID &parent, Task &task)=0;

/*
 * gets task by TaskID
 * @param task id to look for
 * @return TaskDTO if task was found.
 * @return nullopt,otherwise.
 */
  virtual std::optional<TaskDTO> getTask(const TaskID &id)=0;

/*
 * gets SubTasks of the task by const TaskID &
 * @param task id to look for
 * @return container of TaskDTO if task was found.
 * @return nullopt,otherwise.
 */
  virtual std::optional<std::vector<TaskDTO>> getSubTasks(const TaskID &id)=0;

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
  virtual bool postponeTask(const TaskID &task,
                    boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time))=0;

/*
* sets task date to the new value
*
* @param task TaskDTO to delete
*
* @return true, if deleting was completed succesfully.
* @return false, otherwise.
*/
  virtual bool deleteTask(const TaskID &task)=0;
/*
 * sets task status to true
 *
 * @param task task to complete
 *
* @return true, if completing was completed succesfully.
* @return false, otherwise.
 */
  virtual bool completeTask(const TaskID &task)=0;

 public:
/*
 * shows all tasks sorted by priority
 * @return container of tasks sorted by priority (ascending)
 */
  virtual std::vector<TaskDTO> showAllByPriority()=0;
/*
  * shows all tasks sorted by date
  * @return container of tasks sorted by date (ascending)
  */
  virtual std::vector<TaskDTO> showAllByLabel()=0;
/*
  * shows all tasks sorted by label in LEX order
  * @return container of tasks sorted by label (ascending)
  */
  virtual std::vector<TaskDTO> showAllByDate()=0;
/*
  * shows all today tasks sorted by priority
  * @return container of tasks sorted by priority where the date value is today (ascending)
  */
  virtual std::vector<TaskDTO> showTodayByPriority()=0;
/*
   * shows all today tasks sorted by label in LEX order
   * @return container of tasks sorted by label where the date value is today (ascending)
   */
  virtual std::vector<TaskDTO> showTodayByLabel()=0;
/*
     * shows all tasks due date sorted by priority
     *
     * @param date date until which we search for
     * @return container of tasks sorted by priority where the date value is less than date
     */
  virtual std::vector<TaskDTO>
  showDueDateByPriority(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time))=0;
/*
     * shows all tasks due date sorted by label
     *
     * @param date date until which we search for
     * @return container of tasks sorted by label where the date value is less than date
     */
  virtual std::vector<TaskDTO>
  showDueDateByLabel(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time))=0;
/*
     * shows all tasks due date sorted by date
     *
     * @param date date until which we search for
     * @return container of tasks sorted by date where the date value is less than date
     */
  virtual std::vector<TaskDTO>
  showDueDateByDate(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time))=0;
};
#endif //TODOLIST_CORE_COREAPIINTERFACE_H_
