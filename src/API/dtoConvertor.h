//
// Created by Ilya on 7/31/2020.
//

#ifndef TODOLIST_MODEL_DTOCONVERTOR_H_
#define TODOLIST_MODEL_DTOCONVERTOR_H_
#include"Model/TaskEntity.h"
#include"TaskDTO.h"

#include<vector>

class dtoConvertor {
 public:
  TaskDTO              convert(TaskEntity &task_entity);
  TaskEntity           convert(TaskDTO &task_dto);
  std::vector<TaskDTO> convert(std::vector<std::weak_ptr<TaskEntity>> vec);
  std::vector<TaskDTO> convert(std::vector<std::shared_ptr<TaskEntity>> vec);

};

#endif //TODOLIST_MODEL_DTOCONVERTOR_H_
