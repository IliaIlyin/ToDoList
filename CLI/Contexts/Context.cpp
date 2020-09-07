//
// Created by illia.ilin on 8/19/2020.
//

#include "Contexts/Context.h"
const std::vector<std::shared_ptr<TaskDTO>> &Context::getDtos() const {
  return dtos;
}
std::shared_ptr<TaskService> &Context::getService(){
  return service_;
}
Context::Context(std::shared_ptr<TaskService> service) : service_(std::move(service)){
}
