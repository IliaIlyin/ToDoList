//
// Created by Ilya on 7/20/2020.
//

#ifndef TODOLIST_DISPLAY_H
#define TODOLIST_DISPLAY_H

#include"Model/TaskEntity.h"

class Display {

public:

    void viewEntity(TaskEntity &entity);

    void viewTask(Task &task);
};


#endif //TODOLIST_DISPLAY_H
