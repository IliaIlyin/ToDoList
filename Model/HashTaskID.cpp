//
// Created by Ilya on 5/20/2020.
//

#include "HashTaskID.h"

size_t HashTaskID::operator()(const std::shared_ptr<TaskEntity> &t) const {
    return std::hash<std::shared_ptr<TaskEntity>>()(t);
}

