//
// Created by Ilya on 5/20/2020.
//

#include "HashTaskEntity.h"

size_t HashTaskEntity::operator()(const TaskEntity &t) const {
    return (std::hash<int>{}(t.getTaskId().getId()));
}
