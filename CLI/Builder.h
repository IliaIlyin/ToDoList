//
// Created by Ilya on 9/13/2020.
//

#ifndef TODOLIST_CLI_BUILDER_H_
#define TODOLIST_CLI_BUILDER_H_
#include <memory>
#include "Command.h"
#include "ClientInterface.h"
#include "CoreService.pb.h"

/*
 * interface for classes that build users commands.
 *
 * @author Ilya Ilyin
 */

class Builder {
 public:
  /*
   * method that builds users command
   *
   * @input API that command is bounded to
   *
   * @return pointer to the built command
   */
  virtual std::shared_ptr<Command> buildCommand(std::shared_ptr<ClientInterface> service) = 0;
  virtual ~Builder() = default;
};

#endif //TODOLIST_CLI_BUILDER_H_
