//
// Created by illia.ilin on 8/31/2020.
//

#include "PostponeTaskCommand.h"
PostponeTaskCommand::PostponeTaskCommand(std::shared_ptr<TaskService> service,
                                         const TaskID &id,
                                         const boost::gregorian::date &date) : service_(service), id_(id), date_(date) {

}
bool PostponeTaskCommand::execute() {
  return service_->postponeTask(id_, date_);
}
void PostponeTaskCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitPostponeTaskCommand(*this);
}
