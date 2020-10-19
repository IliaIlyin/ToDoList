//
// Created by ilya on 01.10.20.
//

#include "AllDataStorageFactory.h"
std::shared_ptr<AllDataStorageInterface> AllDataStorageFactory::create() {
  std::unique_ptr<Storage> storage=std::make_unique<Storage>();
  std::unique_ptr<StorageService> service = std::make_unique<StorageService>(std::move(storage));
  return std::make_shared<AllDataStorage>(std::move(service));
}
