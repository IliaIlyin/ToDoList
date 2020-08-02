//
// Created by Ilya on 7/31/2020.
//

#ifndef TODOLIST_MODEL_DTOCONVERTOR_H_
#define TODOLIST_MODEL_DTOCONVERTOR_H_
#include"TaskEntity.h"
#include"TaskDTO.h"
class dtoConvertor {
 public:
  TaskDTO convert(TaskEntity& task_entity);
  TaskEntity convert(TaskDTO& task_dto);
};

#endif //TODOLIST_MODEL_DTOCONVERTOR_H_
