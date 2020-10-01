//
// Created by ilya on 30.09.20.
//

#include "Persistor.h"

bool Persistor::Save() {
  auto tasks = storage_->getAllTasks();
  serializer::Storage storage(serializeToStorage(tasks));
  if (!storage.SerializeToOstream(stream_.get())) {
    std::cout << "Failed to serialize" << std::endl;
    return false;
  }
  return true;
}

bool Persistor::Load() {

  serializer::Storage storage;
  if (!storage.ParseFromIstream(stream_.get())) {
    std::cout << "Could not read the file" << std::endl;
    return false;
  }
  auto new_storage = factory_.operator*().create();
  serializeTaskEntities(storage, new_storage);
  storage_=new_storage;
  return true;
}

void Persistor::serializeTaskEntities(const serializer::Storage &storage,
                                      std::shared_ptr<AllDataStorageInterface> ptr) {
  for (int i = 0; i < storage.tasks_size(); i++) {
    auto entity = storage.tasks(i);
    Task t = deserializeFromTask(entity.task());
    TaskID id = ptr->addTask(t, entity.complete());
    serializeSubTasks(entity, id, ptr);
  }
}

void Persistor::serializeSubTasks(const serializer::TaskEntity &entity,
                                  const TaskID &id,
                                  std::shared_ptr<AllDataStorageInterface> ptr) {
  for (int i = 0; i < entity.subtasks_size(); i++) {
    auto subTask = entity.subtasks(i);
    Task t2 = deserializeFromTask(subTask.task());
    auto subTaskId = ptr->addSubTaskToParent(id, t2, subTask.complete());
    serializeSubTasks(subTask, subTaskId.value(),ptr);
  }
}

Persistor::Persistor(std::shared_ptr<std::iostream> stream,
                     std::shared_ptr<AllDataStorageInterface> storage,
                     std::shared_ptr<AllDataStorageFactory> factory) :
    stream_(stream),
    storage_(storage),
    factory_(factory) {
}

