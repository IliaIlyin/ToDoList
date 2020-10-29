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
#include "dtoConvertor.h"
#include "API/TaskID.h"
#include "StorageModel.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

/*
 * Server Implementation for adding tasks to the Model,adding SubTasks to tasks, getting tasks, getting SubTasks.
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
 * @param request name of file to save to
 *
 * sets response to true, if saving was successful
 * sets response to  false, otherwise
   * 
   *@return Status::OK
 */
  Status save(ServerContext *context, const coreService::Name *request, coreService::Result *response) override;
  /*
* loads tasks from file
*
* @param request name of file to load from
*
* sets response to true, if loading was successful
* sets response to false, otherwise
   *
  *@return Status::OK

*/
  Status load(ServerContext *context, const coreService::Name *request, coreService::Result *response) override;
  /*
 * adds task to the model
 * @param task Task to Add
 * sets response to true, if adding was completed succesfully.
* sets response to false, otherwise.
  *
   * @return Status::OK
 */
  Status addTask(ServerContext *context, const protoStorage::Task *request, coreService::Result *response) override;
  /*
 * adds one task as a SubTask to another.
 * @param request SubTask to add
 *
 * sets response to true, if adding was completed succesfully.
* sets response to false, otherwise.
   *
   * @return Status::OK
 */
  Status addSubTask(ServerContext *context,
                    const coreService::SubTask *request,
                    coreService::Result *response) override;
  /*
 * gets task by TaskID
 * @param task id to look for
 * sets response isFound to true and result to found task if task was found.
 * sets response isFound to false,otherwise.
   *
   * @return Status::OK
 */
  Status getTask(ServerContext *context,
                 const coreService::TaskID *request,
                 coreService::GetTaskResult *response) override;
/*
 * gets SubTasks of the task by TaskID
 * @param task id to look for
 *
 * sets response isFound to true and container of TaskDTO if task was found.
 * sets response isFound to false,otherwise.
 *
 * @return Status::OK
 */
  Status getSubTasks(ServerContext *context,
                     const coreService::TaskID *request,
                     coreService::TasksContainer *response) override;
  /*
  * sets task date to the new value
  *
  * @param request info for postponing
  *
 * sets response to true, if postponing was completed succesfully.
 * sets response to false, otherwise.
   *
   * @return Status::OK
  */
  Status postponeTask(ServerContext *context,
                      const coreService::PostponeTaskRequest *request,
                      coreService::Result *response) override;
/*
 * completes task
 *
 * @param task id for task to complete
 *
* sets response to true, if completing was completed succesfully.
* sets response to false, otherwise.
 *
 * @return Status::OK
 */
  Status completeTask(ServerContext *context,
                      const coreService::TaskID *request,
                      coreService::Result *response) override;
  /*
* deletes task
*
* @param task TaskDTO to delete
*
* sets response to true, if deleting was completed succesfully.
* sets response to false, otherwise.
   *
   * @return Status::OK
*/
  Status deleteTask(ServerContext *context, const coreService::TaskID *request, coreService::Result *response) override;
  /*
  * shows all tasks sorted by priority
  * sets response to container of tasks sorted by priority (ascending)
   *
   * @return Status::OK
  */
  Status showAllByPriority(ServerContext *context,
                           const coreService::showRequest *request,
                           coreService::TasksContainer *response) override;
  /*
  * shows all tasks sorted by date
  * sets response to container of tasks sorted by date (ascending)
   *
   * @return Status::OK
  */
  Status showAllDate(ServerContext *context,
                     const coreService::showRequest *request,
                     coreService::TasksContainer *response) override;
  /*
  * shows all tasks sorted by label in LEX order
  * sets response to container of tasks sorted by label (ascending)
   *
   * @return Status::OK
  */
  Status showAllByLabel(ServerContext *context,
                        const coreService::showRequest *request,
                        coreService::TasksContainer *response) override;
  /*
     * shows all tasks due date sorted by priority
     *
     * @param date date until which we search for
     * sets response to container of tasks sorted by priority where the date value is less than date
    *
    * @return Status::OK
     */
  Status showDueDateByPriority(ServerContext *context,
                               const protoStorage::TaskDate *request,
                               coreService::TasksContainer *response) override;
  /*
     * shows all tasks due date sorted by date
     *
     * @param date date until which we search for
     * sets response to container of tasks sorted by date where the date value is less than date
     *
     * @return Status::OK
     */
  Status showDueDateByDate(ServerContext *context,
                           const protoStorage::TaskDate *request,
                           coreService::TasksContainer *response) override;
  /*
     * shows all tasks due date sorted by label
     *
     * @param date date until which we search for
     * sets response to container of tasks sorted by label where the date value is less than date
     *
     * @return Status::OK
     */
  Status showDueDateByLabel(ServerContext *context,
                            const protoStorage::TaskDate *request,
                            coreService::TasksContainer *response) override;
  /*
  * shows all today tasks sorted by priority
  * sets response to container of tasks sorted by priority where the date value is today (ascending)
   *
   * @return Status::OK
  */
  Status showTodayByPriority(ServerContext *context,
                             const coreService::showRequest *request,
                             coreService::TasksContainer *response) override;
  /*
  * shows all today tasks sorted by priority
  * sets response to container of tasks sorted by priority where the date value is today (ascending)
   *
   * @return Status::OK
  */
  Status showTodayByLabel(ServerContext *context,
                          const coreService::showRequest *request,
                          coreService::TasksContainer *response) override;

 private:
  std::unique_ptr<TaskServiceInterface> service_;
};
/*runs server*/
void RunServer();
#endif //TODOLIST_CORE_CORESERVERIMPL_H_
