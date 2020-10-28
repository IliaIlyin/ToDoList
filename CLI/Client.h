//
// Created by ilya on 28.10.20.
//

#ifndef TODOLIST_CLI_CLIENT_H_
#define TODOLIST_CLI_CLIENT_H_

#include<iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "SerializationUtils.h"
#include "ClientInterface.h"
#include "CoreService.grpc.pb.h"
#include "CoreService.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class Client : public ClientInterface {
 public:
  Client(std::shared_ptr<Channel> channel)
      : stub_(coreService::CoreAPIInterface::NewStub(channel)) {}
 public:
  bool save(std::string fileName) override;
  bool load(std::string fileName) override;
 public:

  bool addTask(Task &task) override;

  bool addSubTaskToParent(const TaskID &parent, Task &task) override;

  std::optional<TaskDTO> getTask(const TaskID &id) override;

  std::optional<std::vector<TaskDTO>> getSubTasks(const TaskID &id) override;

 public:

  bool postponeTask(const TaskID &task,
                    boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  bool deleteTask(const TaskID &task) override;

  bool completeTask(const TaskID &task) override;

 public:

  std::vector<TaskDTO> showAllByPriority() override;

  std::vector<TaskDTO> showAllByLabel() override;

  std::vector<TaskDTO> showAllByDate() override;

  std::vector<TaskDTO> showTodayByPriority() override;

  std::vector<TaskDTO> showTodayByLabel() override;

  std::vector<TaskDTO>
  showDueDateByPriority(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  std::vector<TaskDTO>
  showDueDateByLabel(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

  std::vector<TaskDTO>
  showDueDateByDate(boost::gregorian::date = boost::gregorian::date(boost::gregorian::min_date_time)) override;

 private:
  std::unique_ptr<coreService::CoreAPIInterface::Stub> stub_;
};

#endif //TODOLIST_CLI_CLIENT_H_
