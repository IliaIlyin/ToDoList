//
// Created by ilya on 01.10.20.
//

#ifndef TODOLIST_CORE_SERIALIZATION_PERSISTORUTILS_H_
#define TODOLIST_CORE_SERIALIZATION_PERSISTORUTILS_H_

#include "StorageModel.pb.h"
#include "API/Task.h"
#include "Model/TaskEntity.h"
#include <memory>
#include <vector>

serializer::Task_Priority convertPriority(Task::Priority priority);
Task::Priority convertPriority(serializer::Task_Priority priority);
std::shared_ptr<serializer::Task> serializeToTask(const Task &task);
std::shared_ptr<serializer::TaskEntity> serializeToTaskEntity(TaskEntity &entity);
serializer::Storage serializeToStorage(std::vector<std::shared_ptr<TaskEntity>> vec);
Task deserializeFromTask(const serializer::Task &task);

#endif //TODOLIST_CORE_SERIALIZATION_PERSISTORUTILS_H_
