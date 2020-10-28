//
// Created by ilya on 26.10.20.
//

#include "CoreAPI.h"

Status CoreAPI::save(ServerContext *context, const coreService::Name *request, coreService::Result *response) {
  response->set_result(service_->save(request->name()));
  return Status::OK;
}
Status CoreAPI::load(ServerContext *context, const coreService::Name *request, coreService::Result *response) {
  response->set_result(service_->load(request->name()));
  return Status::OK;
}
Status CoreAPI::addTask(ServerContext *context,
                        const protoStorage::Task *request,
                        coreService::Result *response) {
  Task t = convertTask(*request);
  response->set_result(service_->addTask(t));
  return Status::OK;
}
Status CoreAPI::postponeTask(ServerContext *context,
                             const coreService::PostponeTaskRequest *request,
                             coreService::Result *response) {
  auto date = convertDate(request->date());
  TaskID id = convertTaskID(request->id());
  response->set_result(service_->postponeTask(id, date));
  return Status::OK;
}
Status CoreAPI::addSubTask(ServerContext *context,
                           const coreService::SubTask *request,
                           coreService::Result *response) {
  Task t = convertTask(request->child());
  TaskID id = convertTaskID(request->parent());
  response->set_result(service_->addSubTaskToParent(id, t));
  return Status::OK;
}
Status CoreAPI::getTask(ServerContext *context,
                        const coreService::TaskID *request,
                        coreService::GetTaskResult *response) {
  TaskID id = convertTaskID(*request);
  response->CopyFrom(convertGetTaskResult(service_->getTask(id)));
  return Status::OK;
}
Status CoreAPI::getSubTasks(ServerContext *context,
                            const coreService::TaskID *request,
                            coreService::TasksContainer *response) {
  TaskID id = convertTaskID(*request);
  response->CopyFrom(convertTasksContainer(service_->getSubTasks(id)));
  return Status::OK;
}
Status CoreAPI::completeTask(ServerContext *context,
                             const coreService::TaskID *request,
                             coreService::Result *response) {
  TaskID id = convertTaskID(*request);
  response->set_result(service_->completeTask(id));
  return Status::OK;
}
Status CoreAPI::deleteTask(ServerContext *context,
                           const coreService::TaskID *request,
                           coreService::Result *response) {
  TaskID id = convertTaskID(*request);
  response->set_result(service_->deleteTask(id));
  return Status::OK;
}
Status CoreAPI::showAllByPriority(ServerContext *context,
                                  const coreService::showRequest *request,
                                  coreService::TasksContainer *response) {
  response->CopyFrom(convertTasksContainer(service_->showAllByPriority()));
  return Status::OK;
}
Status CoreAPI::showAllDate(ServerContext *context,
                            const coreService::showRequest *request,
                            coreService::TasksContainer *response) {
  response->CopyFrom(convertTasksContainer(service_->showAllByDate()));
  return Status::OK;
}
Status CoreAPI::showAllByLabel(ServerContext *context,
                               const coreService::showRequest *request,
                               coreService::TasksContainer *response) {
  response->CopyFrom(convertTasksContainer(service_->showAllByLabel()));
  return Status::OK;
}
Status CoreAPI::showDueDateByPriority(ServerContext *context,
                                      const protoStorage::TaskDate *request,
                                      coreService::TasksContainer *response) {
  auto date = convertDate(*request);
  response->CopyFrom(convertTasksContainer(service_->showDueDateByPriority(date)));
  return Status::OK;
}
Status CoreAPI::showDueDateByDate(ServerContext *context,
                                  const protoStorage::TaskDate *request,
                                  coreService::TasksContainer *response) {
  auto date = convertDate(*request);
  response->CopyFrom(convertTasksContainer(service_->showDueDateByDate(date)));
  return Status::OK;
}
Status CoreAPI::showDueDateByLabel(ServerContext *context,
                                   const protoStorage::TaskDate *request,
                                   coreService::TasksContainer *response) {
  auto date = convertDate(*request);
  response->CopyFrom(convertTasksContainer(service_->showDueDateByLabel(date)));
  return Status::OK;
}
Status CoreAPI::showTodayByPriority(ServerContext *context,
                                    const coreService::showRequest *request,
                                    coreService::TasksContainer *response) {
  response->CopyFrom(convertTasksContainer(service_->showTodayByPriority()));
  return Status::OK;
}
Status CoreAPI::showTodayByLabel(ServerContext *context,
                                 const coreService::showRequest *request,
                                 coreService::TasksContainer *response) {
  response->CopyFrom(convertTasksContainer(service_->showTodayByLabel()));
  return Status::OK;
}
CoreAPI CoreAPI::create() {
  auto factory = std::make_shared<AllDataStorageFactory>();
  return CoreAPI(std::make_unique<TaskService>(factory));
}
CoreAPI::CoreAPI(std::unique_ptr<TaskServiceInterface> service) : service_(std::move(service)) {
}
void RunServer() {
  std::string server_address("0.0.0.0:50051");
  CoreAPI service = CoreAPI::create();
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}