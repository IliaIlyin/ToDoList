//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_CONTEXTS_INPUTCONTEXT_H_
#define TODOLIST_CLI_CONTEXTS_INPUTCONTEXT_H_
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "API/TaskID.h"
#include "API/Task.h"
#include "InputContextInterface.h"
/*
 * class that contains the information needed to create task
 * Context for InputStateMachine
 * @see InputStateMachine
 *
 * @see Task
 *
 * @author Ilya Ilyin
 */
class InputContext : public InputContextInterface {

 public:
  void setId(const TaskID &id) override;
  void setName(const std::string &name) override;
  void setDate(const boost::gregorian::date &date) override;
  void setPriority(Task::Priority priority) override;
  void setLabel(const std::string &label) override;

 public:
  const std::string &getName() const override;
  const boost::gregorian::date &getDate() const override;
  Task::Priority getPriority() const override;
  const std::string &getLabel() const override;
  const TaskID &getId() const override;

 private:
  std::string name_;
  boost::gregorian::date date_;
  Task::Priority priority_;
  std::string label_;
  TaskID id_;
};
bool operator==(const InputContext context1, const InputContext context2);
#endif //TODOLIST_CLI_CONTEXTS_INPUTCONTEXT_H_
