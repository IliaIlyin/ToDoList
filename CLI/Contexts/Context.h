//
// Created by illia.ilin on 8/19/2020.
//

#ifndef TODOLIST_CLI_CONTEXT_H_
#define TODOLIST_CLI_CONTEXT_H_

#include <memory>
#include "State.h"
#include "API/TaskDTO.h"
#include "API/TaskService.h"

class Context {

 public:
  Context(std::shared_ptr<TaskService> service);

 public:
  const std::vector<std::shared_ptr<TaskDTO>> &getDtos() const;
  std::shared_ptr<TaskService> &getService();

 private:
  std::shared_ptr<TaskService> service_;
  std::vector<std::shared_ptr<TaskDTO>> dtos;

};

#endif //TODOLIST_CLI_CONTEXT_H_
