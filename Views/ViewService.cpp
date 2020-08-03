//
// Created by Ilya on 8/3/2020.
//

#include "ViewService.h"

ViewService::ViewService() {
    general_view_.push_back(std::unique_ptr<LabelView>());
    general_view_.push_back(std::unique_ptr<PriorityView>());
    general_view_.push_back(std::unique_ptr<DateView>());
}

bool ViewService::cleanPrioritiesWithCertainPriority(Task::Priority priority) {
  for(auto i=general_view_.begin();i!=general_view_.end();i++) {
    if(dynamic_cast<std::unique_ptr<LabelView>&>(i->operator*())){
      i->operator*().cleanNullptr(Task::Priority);
    }
  }
}

bool ViewService::cleanDatesWithCertainDate(time_t date) {

}

bool ViewService::cleanLabelsWithCertainLabel(std::string label) {

}
