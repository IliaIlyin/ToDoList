//
// Created by ilya on 30.09.20.
//

#include "Persistor.h"

bool Persistor::Save() {
  auto tasks = storage_->getAllTasks();
  if (tasks.empty()) {
    std::cout << "No tasks in storage. System is not changed";
    return false;
  }
  protoStorage::Storage storage(serializeToStorage(tasks));
  if (!storage.SerializeToOstream(stream_.get())) {
    std::cout << "Failed to serialize" << std::endl;
    return false;
  }
  return true;
}

bool Persistor::Load() {
  protoStorage::Storage storage;
  if (!storage.ParseFromIstream(stream_.get())) {
    std::cout << "Could not parse the file" << std::endl;
    return false;
  }
  auto new_storage = factory_.operator*().create();
  serializeTaskEntities(storage, new_storage);
  storage_ = new_storage;
  return true;
}

Persistor::Persistor(std::shared_ptr<std::iostream> stream,
                     std::shared_ptr<AllDataStorageInterface> storage,
                     std::shared_ptr<AllDataStorageFactoryInterface> factory) :
    stream_(stream),
    storage_(storage),
    factory_(factory) {
}

