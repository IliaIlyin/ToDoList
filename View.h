//
// Created by Ilya on 7/20/2020.
//

#ifndef TODOLIST_VIEW_H
#define TODOLIST_VIEW_H

#include"TaskEntity.h"

class View {
public:
    void viewEntity(TaskEntity& entity);
    void viewTask(Task& task);
};


#endif //TODOLIST_VIEW_H
