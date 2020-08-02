//
// Created by Ilya on 7/31/2020.
//

#include "dtoConvertor.h"
TaskDTO dtoConvertor::convert(TaskEntity& task_entity) {
  std::vector<std::shared_ptr<TaskDTO> > vec;
  for(auto i=task_entity.getSubtasks().begin();i!=task_entity.getSubtasks().end();i++){
      vec.push_back(std::make_shared<TaskDTO>(convert(i->operator*())));
  }
  return TaskDTO(task_entity.getTask(),task_entity.getTaskId(),task_entity.checkStatus(),vec);
}
TaskEntity dtoConvertor::convert(TaskDTO& task_dto) {
  std::vector<std::shared_ptr<TaskEntity> > vec;
  for(auto i=task_dto.getSubtasks().begin();i!=task_dto.getSubtasks().end();i++){
    vec.push_back(std::make_shared<TaskEntity>(convert(i->operator*())));
  }
  return TaskEntity(task_dto.getTask(),task_dto.getTaskId(),task_dto.checkStatus(),vec);
}
