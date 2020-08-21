//
// Created by illia.ilin on 8/19/2020.
//

#ifndef TODOLIST_CLI_CONTEXT_H_
#define TODOLIST_CLI_CONTEXT_H_

#include <memory>
#include "State.h"
#include "API/TaskDTO.h"

class Context {


 private:
    std::vector<std::shared_ptr<TaskDTO>> dtos;

};

#endif //TODOLIST_CLI_CONTEXT_H_
