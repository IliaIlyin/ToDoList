//
// Created by ilya on 16.10.20.
//

#ifndef TODOLIST_CLI_CONTEXTS_INPUTCONTEXTINTERFACE_H_
#define TODOLIST_CLI_CONTEXTS_INPUTCONTEXTINTERFACE_H_
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "API/TaskID.h"
#include "API/Task.h"
/*
 * class that contains the information needed to create task
 * Context for InputStateMachine
 * @see InputStateMachine
 *
 * @see Task
 *
 * @author Ilya Ilyin
 */
class InputContextInterface {

 public:
  virtual void setId(const TaskID &id)=0;
  virtual void setName(const std::string &name)=0;
  virtual void setDate(const boost::gregorian::date &date)=0;
  virtual void setPriority(Task::Priority priority)=0;
  virtual void setLabel(const std::string &label)=0;

 public:
  virtual  const std::string &getName() const=0;
  virtual  const boost::gregorian::date &getDate() const=0;
  virtual  Task::Priority getPriority() const=0;
  virtual const std::string &getLabel() const=0;
  virtual const TaskID &getId() const=0;
  
};
#endif //TODOLIST_CLI_CONTEXTS_INPUTCONTEXTINTERFACE_H_
