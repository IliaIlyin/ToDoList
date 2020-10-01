//
// Created by Ilya on 7/30/2020.
//

#ifndef TODOLIST_VIEWS_LABELVIEW_H_
#define TODOLIST_VIEWS_LABELVIEW_H_

#include "GeneralView.h"
#include <map>
#include <vector>
#include <memory>
#include <ctime>
/*
 * class to represent views sorted by label
 */
class LabelView : public GeneralView {
public:
    std::vector<std::weak_ptr<TaskEntity>> showAll() override;

    std::vector<std::weak_ptr<TaskEntity>> showToday() override;

    std::vector<std::weak_ptr<TaskEntity>> showDueDate(boost::gregorian::date date) override;

    ~LabelView()=default;

public:
    void clean() override;

    bool insert(std::shared_ptr<TaskEntity> taskEntity) override;

private:
    std::multimap<std::string, std::weak_ptr<TaskEntity> > labels;
};

#endif //TODOLIST_VIEWS_LABELVIEW_H_
