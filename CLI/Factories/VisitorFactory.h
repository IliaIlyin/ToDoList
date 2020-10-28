//
// Created by Ilya on 9/14/2020.
//

#ifndef TODOLIST_CLI_FACTORIES_VISITORFACTORY_H_
#define TODOLIST_CLI_FACTORIES_VISITORFACTORY_H_
#include "Visitor.h"
#include "Factories/Validators/GeneralCommandsValidator.h"

#include "Visitors/Add/AddTaskCommandVisitor.h"
#include "Visitors/Add/AddSubTaskCommandVisitor.h"

#include "Visitors/Get/GetSubTaskCommandVisitor.h"
#include "Visitors/Get/GetTaskCommandVisitor.h"

#include "Visitors/Other/DeleteTaskCommandVisitor.h"
#include "Visitors/Other/CompleteTaskCommandVisitor.h"
#include "Visitors/Other/PostponeTaskCommandVisitor.h"

#include "Visitors/Show/ShowAll/ShowAllByDateCommandVisitor.h"
#include "Visitors/Show/ShowAll/ShowAllByLabelCommandVisitor.h"
#include "Visitors/Show/ShowAll/ShowAllByPriorityCommandVisitor.h"

#include "Visitors/Show/ShowToday/ShowTodayByLabelCommandVisitor.h"
#include "Visitors/Show/ShowToday/ShowTodayByPriorityCommandVisitor.h"

#include "Visitors/Show/ShowDueDate/ShowDueDateByDateCommandVisitor.h"
#include "Visitors/Show/ShowDueDate/ShowDueDateByLabelCommandVisitor.h"
#include "Visitors/Show/ShowDueDate/ShowDueDateByPriorityCommandVisitor.h"

#include "Visitors/Serialize/SaveCommandVisitor.h"
#include "Visitors/Serialize/LoadCommandVisitor.h"
#include <memory>
#include "VisitorFactoryInterface.h"
/*
 * factory that creates commands visitors
 *
 * @see Visitor
 *
 * @author Ilya Ilyin
 */
class VisitorFactory : public VisitorFactoryInterface {
 public:
  /*
   * method that creates visitors
   *
   * @input token corresponding to the command
   * @input pointer to the Context to change
   *
   * @return pointer to the visitor
   */
  std::shared_ptr<Visitor> createVisitor(const GeneralCommandsValidator::CommandToken &token,
                                         std::shared_ptr<Context> context,
                                         std::shared_ptr<IOStreamInterface> outputer) override;
};

#endif //TODOLIST_CLI_FACTORIES_VISITORFACTORY_H_
