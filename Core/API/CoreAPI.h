//
// Created by ilya on 04.10.20.
//

#ifndef TODOLIST_CORE_COREAPI_H_
#define TODOLIST_CORE_COREAPI_H_
#include "Model/TaskServiceInterface.h"
#include "Model/TaskService.h"
#include "TaskDTO.h"
#include "CoreAPIInterface.h"
#include "Model/dtoConvertor.h"
#include "TaskID.h"

class CoreAPI : public CoreAPIInterface {
 public:
  static CoreAPI create();
  CoreAPI(std::unique_ptr<TaskServiceInterface> service);
 public:
  bool save(std::string fileName) override;
  bool load(std::string fileName) override;
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
          Task::Priority priority = Task::Priority::NONE, std::string label = "") override;

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
  bool addSubTaskToParent(const TaskID &parent, std::string taskName,
                          boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time),
                          Task::Priority priority = Task::Priority::NONE, std::string label = "") override;
/*
 * adds task to the model
 * @param task Task to Add
 * @return true, if adding was completed succesfully.
* @return false, otherwise.
 */
  bool addTask(Task &task) override;
/*
 * adds one task as a SubTask to another.
 * @param parent Parent task to Add SubTask to
 * @param task SubTask to Add to parent
 *
 * @return true, if adding was completed succesfully.
* @return false, otherwise.
 */
  bool addSubTaskToParent(const TaskID &parent, Task &task) override;

  /*
   * gets task by TaskID
   * @param task id to look for
   * @return TaskDTO if task was found.
   * @return nullopt,otherwise.
   */
  std::optional<TaskDTO> getTask(const TaskID &id) override;

  /*
   * gets SubTasks of the task by const TaskID &
   * @param task id to look for
   * @return container of TaskDTO if task was found.
   * @return nullopt,otherwise.
   */
  std::optional<std::vector<TaskDTO>> getSubTasks(const TaskID &id) override;

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
  bool postponeTask(const TaskID &task,
                    boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  /*
  * sets task date to the new value
  *
  * @param task TaskDTO to delete
  *
* @return true, if deleting was completed succesfully.
* @return false, otherwise.
  */
  bool deleteTask(const TaskID &task) override;
  /*
   * sets task status to true
   *
   * @param task task to complete
   *
  * @return true, if completing was completed succesfully.
* @return false, otherwise.
   */
  bool completeTask(const TaskID &task) override;

 public:
  /*
   * shows all tasks sorted by priority
   * @return container of tasks sorted by priority (ascending)
   */
  std::vector<TaskDTO> showAllByPriority() override;
  /*
    * shows all tasks sorted by date
    * @return container of tasks sorted by date (ascending)
    */
  std::vector<TaskDTO> showAllByLabel() override;
  /*
    * shows all tasks sorted by label in LEX order
    * @return container of tasks sorted by label (ascending)
    */
  std::vector<TaskDTO> showAllByDate() override;
  /*
    * shows all today tasks sorted by priority
    * @return container of tasks sorted by priority where the date value is today (ascending)
    */
  std::vector<TaskDTO> showTodayByPriority() override;
  /*
     * shows all today tasks sorted by label in LEX order
     * @return container of tasks sorted by label where the date value is today (ascending)
     */
  std::vector<TaskDTO> showTodayByLabel() override;
/*
     * shows all tasks due date sorted by priority
     *
     * @param date date until which we search for
     * @return container of tasks sorted by priority where the date value is less than date
     */
  std::vector<TaskDTO>
  showDueDateByPriority(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;
/*
     * shows all tasks due date sorted by label
     *
     * @param date date until which we search for
     * @return container of tasks sorted by label where the date value is less than date
     */
  std::vector<TaskDTO>
  showDueDateByLabel(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;
/*
     * shows all tasks due date sorted by date
     *
     * @param date date until which we search for
     * @return container of tasks sorted by date where the date value is less than date
     */
  std::vector<TaskDTO>
  showDueDateByDate(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

 private:
  std::unique_ptr<TaskServiceInterface> service_;
};

#endif //TODOLIST_CORE_COREAPI_H_
