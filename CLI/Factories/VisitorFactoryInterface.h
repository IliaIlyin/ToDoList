//
// Created by ilya on 25.10.20.
//

#ifndef TODOLIST_CLI_FACTORIES_VALIDATORS_VISITORFACTORYINTERFACE_H_
#define TODOLIST_CLI_FACTORIES_VALIDATORS_VISITORFACTORYINTERFACE_H_
#include "Visitor.h"
#include "Factories/Validators/GeneralCommandsValidator.h"

#include <memory>
/*
 * factory that creates commands visitors
 *
 * @see Visitor
 *
 * @author Ilya Ilyin
 */
class VisitorFactoryInterface {
 public:
  virtual ~VisitorFactoryInterface() = default;
  /*
   * method that creates visitors
   *
   * @input token corresponding to the command
   * @input pointer to the Context to change
   *
   * @return pointer to the visitor
   */
  virtual std::shared_ptr<Visitor> createVisitor(const GeneralCommandsValidator::CommandToken &token,
                                                 std::shared_ptr<Context> context,
                                                 std::shared_ptr<IOStreamInterface> outputer) = 0;
};
#endif //TODOLIST_CLI_FACTORIES_VALIDATORS_VISITORFACTORYINTERFACE_H_
