//
// Created by illia.ilin on 8/19/2020.
//

#ifndef TODOLIST_CLI_CONTEXT_H_
#define TODOLIST_CLI_CONTEXT_H_

#include <memory>
#include <optional>
#include <map>
#include "API/TaskDTO.h"
#include "API/CoreAPIInterface.h"
/*
 * class to represent the context of the StateMachine that operates commands
 *
 * @author Ilya Ilyin
 */
class Context {
 public:
  const std::optional<TaskDTO> &GetDto() const;
  const std::optional<std::vector<TaskDTO>> &GetDtos() const;
  void SetDto(const TaskDTO &dto);
  void SetDtos(const std::vector<TaskDTO> &dtos);

 public:
  Context();
 private:
  /*
   * class member to save concrete task
   */
  std::optional<TaskDTO> dto_;
  /*
 * class member to save container of tasks
 */
  std::optional<std::vector<TaskDTO>> dtos_;
};

#endif //TODOLIST_CLI_CONTEXT_H_
