//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_DELETETASKCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_DELETETASKCOMMAND_H_

#include "API/CoreAPIInterface.h"
#include "Command.h"
#include "Visitor.h"
#include <memory>

class DeleteTaskCommand : public Command {
 public:
  DeleteTaskCommand(std::shared_ptr<CoreAPIInterface> service,const TaskID& id);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

  bool IsDeleteTaskCommandResult() const;
 private:
  std::shared_ptr<CoreAPIInterface> service_;
  TaskID id_;

 private:
  bool deleteTaskCommandResult_;
};

#endif //TODOLIST_CLI_COMMANDS_DELETETASKCOMMAND_H_
