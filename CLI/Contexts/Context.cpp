//
// Created by illia.ilin on 8/19/2020.
//

#include "Contexts/Context.h"

const std::optional<TaskDTO> &Context::GetDto() const {
  return dto_;
}
const std::optional<std::vector<TaskDTO>> &Context::GetDtos() const {
  return dtos_;
}
void Context::SetDto(const TaskDTO &dto) {
  dto_.emplace(dto);
  dtos_ = std::nullopt;
}
void Context::SetDtos(const std::vector<TaskDTO> &dtos) {
  dtos_.emplace(dtos);
  dto_ = std::nullopt;
}
Context::Context() {
  dto_ = std::nullopt;
  dtos_ = std::nullopt;
}
