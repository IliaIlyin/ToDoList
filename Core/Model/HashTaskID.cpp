//
// Created by Ilya on 5/20/2020.
//

#include "HashTaskID.h"

size_t HashTaskID::operator()(TaskID task_id) const {
    return std::hash<int>()(task_id.getId());
}
