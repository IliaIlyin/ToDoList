//
// Created by ilya on 11.10.20.
//

#ifndef TODOLIST_CLI_COMMANDS_SERIALIZE_LOADCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_SERIALIZE_LOADCOMMAND_H_

#include "ClientInterface.h"
#include "Command.h"
#include "Visitor.h"
#include <memory>

class LoadCommand : public Command {

 public:
  LoadCommand(std::shared_ptr<ClientInterface> service, std::string fileName);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

 public:
  bool getLoadResult() const;

 private:
  std::shared_ptr<ClientInterface> service_;
  std::string fileName_;
  bool loadResult_;
};

#endif //TODOLIST_CLI_COMMANDS_SERIALIZE_LOADCOMMAND_H_
