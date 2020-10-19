//
// Created by ilya on 01.10.20.
//

#ifndef TODOLIST_CORE_SERIALIZATION_PERSISTORUTILS_H_
#define TODOLIST_CORE_SERIALIZATION_PERSISTORUTILS_H_

#include "StorageModel.pb.h"
#include "API/Task.h"
#include "Model/AllDataStorageInterface.h"
#include "Model/TaskEntity.h"
#include <memory>
#include <vector>

protoStorage::Task_Priority convertPriority(Task::Priority priority);
Task::Priority convertPriority(protoStorage::Task_Priority priority);

protoStorage::Task serializeToTask(const Task &task);
protoStorage::TaskEntity serializeToTaskEntity(TaskEntity &entity);

protoStorage::Storage serializeToStorage(std::vector<std::shared_ptr<TaskEntity>> vec);
Task deserializeFromTask(const protoStorage::Task &entity);

void serializeSubTasks(const protoStorage::TaskEntity &entity,
                       const TaskID &id,
                       std::shared_ptr<AllDataStorageInterface> ptr);
void serializeTaskEntities(const protoStorage::Storage &storage, std::shared_ptr<AllDataStorageInterface> ptr);

#endif //TODOLIST_CORE_SERIALIZATION_PERSISTORUTILS_H_
