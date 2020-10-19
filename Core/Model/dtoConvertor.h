//
// Created by Ilya on 7/31/2020.
//

#ifndef TODOLIST_MODEL_DTOCONVERTOR_H_
#define TODOLIST_MODEL_DTOCONVERTOR_H_

#include "Model/TaskEntity.h"
#include "API/TaskDTO.h"

#include <vector>

/*
 * static class to convert TaskEntities to TaskDTOs
 */
class dtoConvertor {

public:

    static TaskDTO convert(const TaskEntity &task_entity);

    static TaskEntity convert(const TaskDTO &task_dto);

    static std::vector<TaskDTO> convert(const std::vector<std::weak_ptr<TaskEntity>>& vec);

    static std::vector<TaskDTO> convert(const std::vector<std::shared_ptr<TaskEntity>>& vec);

};

#endif //TODOLIST_MODEL_DTOCONVERTOR_H_
