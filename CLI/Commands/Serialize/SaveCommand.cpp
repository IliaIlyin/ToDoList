//
// Created by ilya on 11.10.20.
//

#include "SaveCommand.h"

SaveCommand::SaveCommand(std::shared_ptr<ClientInterface> service, std::string fileName)
    : service_(service), fileName_(fileName) {
}

void SaveCommand::execute() {
  saveResult_ = service_->save(fileName_);
}

bool SaveCommand::getSaveResult() const {
  return saveResult_;
}

void SaveCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitSaveCommand(*this);
}