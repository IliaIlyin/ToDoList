//
// Created by ilya on 16.10.20.
//

#ifndef TODOLIST_CLI_CONTEXTS_CONTEXTINTERFACE_H_
#define TODOLIST_CLI_CONTEXTS_CONTEXTINTERFACE_H_

#include <optional>
#include <vector>
#include <API/TaskDTO.h>

/*
 * class to represent the context of the StateMachine that operates commands
 *
 * @author Ilya Ilyin
 */
class ContextInterface {
 public:
  virtual const std::optional<TaskDTO> &GetDto() const =0;
  virtual const std::optional<std::vector<TaskDTO>> &GetDtos() const = 0;
  virtual void SetDto(const TaskDTO &dto) = 0 ;
  virtual void SetDtos(const std::vector<TaskDTO> &dtos) = 0 ;

};
#endif //TODOLIST_CLI_CONTEXTS_CONTEXTINTERFACE_H_
