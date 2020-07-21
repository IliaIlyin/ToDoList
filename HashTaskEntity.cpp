//
// Created by Ilya on 5/20/2020.
//

#include "HashTaskEntity.h"

size_t HashTaskEntity::operator()(const std::shared_ptr<TaskEntity> &t) const {
    return std::hash<std::shared_ptr<TaskEntity>>()(t);
}

