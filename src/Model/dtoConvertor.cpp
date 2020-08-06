//
// Created by Ilya on 7/31/2020.
//

#include "dtoConvertor.h"

TaskDTO dtoConvertor::convert(TaskEntity &task_entity) {
  return TaskDTO(task_entity.getTask(), task_entity.getTaskId(), task_entity.checkStatus());
}

TaskEntity dtoConvertor::convert(TaskDTO &task_dto) {
  return TaskEntity(task_dto.getTask(),
                    task_dto.getTaskId(),
                    task_dto.checkStatus(),
                    std::vector<std::shared_ptr<TaskEntity>>());
}

std::vector<TaskDTO> dtoConvertor::convert(std::vector<std::weak_ptr<TaskEntity>> vec) {
  std::vector<TaskDTO> result;
  for (auto i = vec.begin(); i != vec.end(); i++) {
    result.push_back(this->convert(i->lock().operator*()));
  }
  return result;
}
