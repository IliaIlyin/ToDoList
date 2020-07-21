//
// Created by Ilya on 7/20/2020.
//

#include "View.h"

void View::viewEntity(TaskEntity& entity) {
    viewTask(entity.getTask().operator*());
    std::cout<<"status"<<entity.checkStatus()<<" ; "<<std::endl;
    auto vec=entity.getSubtasks();
    for(auto i=vec.begin();i!=vec.end();i++)
        viewEntity(i->operator*());
}


void View::viewTask(Task& task) {
std::cout<<"task "<<task.getName()<<" with date: "<<task.getDate()<<std::endl;
std::cout<<"Priority "<<task.getPriority()<<" label "<<task.getLabel()<<std::endl;
}

View::View() {}
