//
// Created by ilya on 11.10.20.
//

#ifndef TODOLIST_CLI_COMMANDS_SERIALIZE_SAVECOMMAND_H_
#define TODOLIST_CLI_COMMANDS_SERIALIZE_SAVECOMMAND_H_

#include "API/CoreAPIInterface.h"
#include "Command.h"
#include "Visitor.h"
#include <memory>

class SaveCommand : public Command {

 public:
  SaveCommand(std::shared_ptr<CoreAPIInterface> service, std::string fileName);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

 public:
  bool getSaveResult() const;

 private:
  std::shared_ptr<CoreAPIInterface> service_;
  std::string fileName_;
  bool saveResult_;
};

#endif //TODOLIST_CLI_COMMANDS_SERIALIZE_SAVECOMMAND_H_
