//
// Created by ilya on 01.10.20.
//

#ifndef TODOLIST_CORE_SERIALIZATION_SERIALIZATIONUTILS_H_
#define TODOLIST_CORE_SERIALIZATION_SERIALIZATIONUTILS_H_

#include "StorageModel.pb.h"
#include "CoreService.pb.h"

#include "API/TaskDTO.h"
#include "API/Task.h"
#include "Model/AllDataStorageInterface.h"
#include "Model/TaskEntity.h"
#include <memory>
#include <vector>

boost::gregorian::date convertDate(protoStorage::TaskDate);
protoStorage::TaskDate convertDate(boost::gregorian::date);

coreService::TaskID convertTaskID(TaskID id);
TaskID convertTaskID(coreService::TaskID id);

TaskDTO convertTaskDTO(coreService::TaskDTO);
coreService::TaskDTO convertTaskDTO(TaskDTO);

coreService::TasksContainer convertTasksContainer(std::optional<std::vector<std::shared_ptr<TaskEntity>>> result);
coreService::TasksContainer convertTasksContainer(std::vector<std::weak_ptr<TaskEntity>> result);
std::optional<std::vector<TaskDTO>> convertTasksContainer(coreService::TasksContainer result);

coreService::GetTaskResult convertGetTaskResult(std::optional<TaskEntity> result);
std::optional<TaskDTO> convertGetTaskResult(coreService::GetTaskResult result);

coreService::SubTask convertSubTask(TaskID id, Task child);

coreService::PostponeTaskRequest convertPostponeTaskRequest(TaskID, boost::gregorian::date date);

protoStorage::Task_Priority convertPriority(Task::Priority priority);
Task::Priority convertPriority(protoStorage::Task_Priority priority);

protoStorage::Task convertTask(const Task &task);
Task convertTask(const protoStorage::Task &proto_task);

protoStorage::TaskEntity serializeToTaskEntity(TaskEntity &entity);

protoStorage::Storage serializeToStorage(std::vector<std::shared_ptr<TaskEntity>> vec);

void serializeSubTasks(const protoStorage::TaskEntity &entity,
                       const TaskID &id,
                       std::shared_ptr<AllDataStorageInterface> ptr);
void serializeTaskEntities(const protoStorage::Storage &storage, std::shared_ptr<AllDataStorageInterface> ptr);

#endif //TODOLIST_CORE_SERIALIZATION_SERIALIZATIONUTILS_H_
