//
// Created by ilya on 26.10.20.
//

#ifndef TODOLIST_CORE_CORESERVERIMPL_H_
#define TODOLIST_CORE_CORESERVERIMPL_H_
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "CoreService.pb.h"

#include "CoreService.grpc.pb.h"

#include "SerializationUtils.h"
#include "Model/TaskService.h"
#include "API/TaskDTO.h"
#include "Model/dtoConvertor.h"
#include "API/TaskID.h"
#include "StorageModel.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

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

class CoreAPI final : public coreService::CoreAPIInterface::Service {
 public:
  static CoreAPI create();
  CoreAPI(std::unique_ptr<TaskServiceInterface> service);
  /*
 * saves all tasks to the file
 *
 * @input fileName name of file to save to
 *
 * @return true, if saving was successful
 * @return false, otherwise
 */
  Status save(ServerContext *context, const coreService::Name *request, coreService::Result *response) override;
  /*
* loads tasks from file
*
* @input fileName name of file to load from
*
* @return true, if loading was successful
* @return false, otherwise
*/
  Status load(ServerContext *context, const coreService::Name *request, coreService::Result *response) override;
  /*
 * adds task to the model
 * @param task Task to Add
 * @return true, if adding was completed succesfully.
* @return false, otherwise.
 */
  Status addTask(ServerContext *context, const protoStorage::Task *request, coreService::Result *response) override;
  /*
 * adds one task as a SubTask to another.
 * @param parent Parent task to Add SubTask to
 * @param task SubTask to Add to parent
 *
 * @return true, if adding was completed succesfully.
* @return false, otherwise.
 */
  Status addSubTask(ServerContext *context,
                    const coreService::SubTask *request,
                    coreService::Result *response) override;
  /*
 * gets task by TaskID
 * @param task id to look for
 * @return TaskDTO if task was found.
 * @return nullopt,otherwise.
 */
  Status getTask(ServerContext *context,
                 const coreService::TaskID *request,
                 coreService::GetTaskResult *response) override;
/*
 * gets SubTasks of the task by const TaskID &
 * @param task id to look for
 * @return container of TaskDTO if task was found.
 * @return nullopt,otherwise.
 */
  Status getSubTasks(ServerContext *context,
                     const coreService::TaskID *request,
                     coreService::TasksContainer *response) override;
  /*
  * sets task date to the new value
  *
  * @param task TaskDTO which to change
  * @param date new date to set
  *
 * @return true, if postponing was completed succesfully.
 * @return false, otherwise.
  */
  Status postponeTask(ServerContext *context,
                      const coreService::PostponeTaskRequest *request,
                      coreService::Result *response) override;
/*
 * completes task
 *
 * @param task task to complete
 *
* @return true, if completing was completed succesfully.
* @return false, otherwise.
 */
  Status completeTask(ServerContext *context,
                      const coreService::TaskID *request,
                      coreService::Result *response) override;
  /*
* deletes task
*
* @param task TaskDTO to delete
*
* @return true, if deleting was completed succesfully.
* @return false, otherwise.
*/
  Status deleteTask(ServerContext *context, const coreService::TaskID *request, coreService::Result *response) override;
  /*
  * shows all tasks sorted by priority
  * @return container of tasks sorted by priority (ascending)
  */
  Status showAllByPriority(ServerContext *context,
                           const coreService::showRequest *request,
                           coreService::TasksContainer *response) override;
  /*
  * shows all tasks sorted by date
  * @return container of tasks sorted by date (ascending)
  */
  Status showAllDate(ServerContext *context,
                     const coreService::showRequest *request,
                     coreService::TasksContainer *response) override;
  /*
  * shows all tasks sorted by label in LEX order
  * @return container of tasks sorted by label (ascending)
  */
  Status showAllByLabel(ServerContext *context,
                        const coreService::showRequest *request,
                        coreService::TasksContainer *response) override;
  /*
     * shows all tasks due date sorted by priority
     *
     * @param date date until which we search for
     * @return container of tasks sorted by priority where the date value is less than date
     */
  Status showDueDateByPriority(ServerContext *context,
                               const protoStorage::TaskDate *request,
                               coreService::TasksContainer *response) override;
  /*
     * shows all tasks due date sorted by date
     *
     * @param date date until which we search for
     * @return container of tasks sorted by date where the date value is less than date
     */
  Status showDueDateByDate(ServerContext *context,
                           const protoStorage::TaskDate *request,
                           coreService::TasksContainer *response) override;
  /*
     * shows all tasks due date sorted by label
     *
     * @param date date until which we search for
     * @return container of tasks sorted by label where the date value is less than date
     */
  Status showDueDateByLabel(ServerContext *context,
                            const protoStorage::TaskDate *request,
                            coreService::TasksContainer *response) override;
  /*
  * shows all today tasks sorted by priority
  * @return container of tasks sorted by priority where the date value is today (ascending)
  */
  Status showTodayByPriority(ServerContext *context,
                             const coreService::showRequest *request,
                             coreService::TasksContainer *response) override;
  /*
  * shows all today tasks sorted by priority
  * @return container of tasks sorted by priority where the date value is today (ascending)
  */
  Status showTodayByLabel(ServerContext *context,
                          const coreService::showRequest *request,
                          coreService::TasksContainer *response) override;

 private:
  std::unique_ptr<TaskServiceInterface> service_;
};
void RunServer();
#endif //TODOLIST_CORE_CORESERVERIMPL_H_
