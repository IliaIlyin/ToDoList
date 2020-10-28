//
// Created by ilya on 28.10.20.
//

#include "Client.h"
bool Client::save(std::string fileName) {
  coreService::Name name;
  name.set_name(fileName);
  ClientContext context;
  coreService::Result result;
  Status status = stub_->save(&context, name, &result);
  return result.result();

}
bool Client::load(std::string fileName) {
  coreService::Name name;
  name.set_name(fileName);
  ClientContext context;
  coreService::Result result;
  Status status = stub_->load(&context, name, &result);
  return result.result();

}
bool Client::addTask(Task &task) {
  protoStorage::Task request;
  request.CopyFrom(convertTask(task));
  ClientContext context;
  coreService::Result result;
  Status status = stub_->addTask(&context, request, &result);
  return result.result();
}

bool Client::addSubTaskToParent(const TaskID &parent, Task &task) {
  coreService::SubTask request;
  request.set_allocated_child(new protoStorage::Task(convertTask(task)));
  request.set_allocated_parent(new coreService::TaskID(convertTaskID(parent)));
  ClientContext context;
  coreService::Result result;
  Status status = stub_->addSubTask(&context, request, &result);
  return result.result();
}

std::optional<TaskDTO> Client::getTask(const TaskID &id) {
  coreService::TaskID request(convertTaskID(id));
  ClientContext context;
  coreService::GetTaskResult result;
  Status status = stub_->getTask(&context, request, &result);
  return convertGetTaskResult(result);
}
std::optional<std::vector<TaskDTO>> Client::getSubTasks(const TaskID &id) {
  coreService::TaskID request(convertTaskID(id));
  ClientContext context;
  coreService::TasksContainer result;
  Status status = stub_->getSubTasks(&context, request, &result);
  return convertTasksContainer(result);
}
bool Client::postponeTask(const TaskID &task, boost::gregorian::date date) {
  coreService::PostponeTaskRequest request = convertPostponeTaskRequest(task, date);
  coreService::Result result;
  ClientContext context;
  Status status = stub_->postponeTask(&context, request, &result);
  return result.result();
}
bool Client::deleteTask(const TaskID &task) {
  coreService::TaskID request(convertTaskID(task));
  ClientContext context;
  coreService::Result result;
  Status status = stub_->deleteTask(&context, request, &result);
  return result.result();
}
bool Client::completeTask(const TaskID &task) {
  coreService::TaskID request(convertTaskID(task));
  ClientContext context;
  coreService::Result result;
  Status status = stub_->completeTask(&context, request, &result);
  return result.result();
}
std::vector<TaskDTO> Client::showAllByPriority() {
  coreService::showRequest request;
  ClientContext context;
  coreService::TasksContainer result;
  Status status = stub_->showAllByPriority(&context, request, &result);
  return convertTasksContainer(result).value();
}
std::vector<TaskDTO> Client::showAllByLabel() {
  coreService::showRequest request;
  ClientContext context;
  coreService::TasksContainer result;
  Status status = stub_->showAllByLabel(&context, request, &result);
  return convertTasksContainer(result).value();
}
std::vector<TaskDTO> Client::showAllByDate() {
  coreService::showRequest request;
  ClientContext context;
  coreService::TasksContainer result;
  Status status = stub_->showAllDate(&context, request, &result);
  return convertTasksContainer(result).value();
}
std::vector<TaskDTO> Client::showTodayByPriority() {
  coreService::showRequest request;
  ClientContext context;
  coreService::TasksContainer result;
  Status status = stub_->showTodayByPriority(&context, request, &result);
  return convertTasksContainer(result).value();
}
std::vector<TaskDTO> Client::showTodayByLabel() {
  coreService::showRequest request;
  ClientContext context;
  coreService::TasksContainer result;
  Status status = stub_->showTodayByPriority(&context, request, &result);
  return convertTasksContainer(result).value();
}
std::vector<TaskDTO> Client::showDueDateByLabel(boost::gregorian::date date) {
  protoStorage::TaskDate request(convertDate(date));
  ClientContext context;
  coreService::TasksContainer result;
  Status status = stub_->showDueDateByLabel(&context, request, &result);
  return convertTasksContainer(result).value();
}
std::vector<TaskDTO> Client::showDueDateByDate(boost::gregorian::date date) {
  protoStorage::TaskDate request(convertDate(date));
  ClientContext context;
  coreService::TasksContainer result;
  Status status = stub_->showDueDateByDate(&context, request, &result);
  return convertTasksContainer(result).value();
}
std::vector<TaskDTO> Client::showDueDateByPriority(boost::gregorian::date date) {
  protoStorage::TaskDate request(convertDate(date));
  ClientContext context;
  coreService::TasksContainer result;
  Status status = stub_->showDueDateByPriority(&context, request, &result);
  return convertTasksContainer(result).value();
}

