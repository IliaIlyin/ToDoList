//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_ADDSUBTASKCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_ADDSUBTASKCOMMAND_H_

#include "Command.h"
#include "Visitor.h"
#include "ClientInterface.h"
#include "API/TaskID.h"
#include "API/Task.h"
#include "API/CoreAPI.h"
#include <memory>
class AddSubTaskCommand : public Command {

 public:
  AddSubTaskCommand(std::shared_ptr<ClientInterface> service, const TaskID &parent, const Task &child);

 public:
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

  bool getAddSubTaskResult() const;
 private:
  std::shared_ptr<ClientInterface> service_;
  TaskID parent_;
  Task child_;

 private:
  bool addSubTaskResult_;
};

#endif //TODOLIST_CLI_COMMANDS_ADDSUBTASKCOMMAND_H_
