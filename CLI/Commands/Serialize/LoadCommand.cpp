//
// Created by ilya on 11.10.20.
//

#include "LoadCommand.h"
LoadCommand::LoadCommand(std::shared_ptr<CoreAPIInterface> service, std::string fileName)
    : service_(service), fileName_(fileName) {
}

void LoadCommand::execute() {
  loadResult_ = service_->load(fileName_);
}

bool LoadCommand::getLoadResult() const {
  return loadResult_;
}

void LoadCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitLoadCommand(*this);
}