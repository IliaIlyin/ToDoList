//
// Created by ilya on 30.09.20.
//

#ifndef TODOLIST_SERIALIZER_H
#define TODOLIST_SERIALIZER_H

class Serializer{
public:
    virtual bool Save()=0;
    virtual bool Load()=0;
};

#endif //TODOLIST_SERIALIZER_H
