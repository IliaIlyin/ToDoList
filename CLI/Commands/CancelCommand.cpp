//
// Created by Ilya on 9/15/2020.
//

#include "CancelCommand.h"
void CancelCommand::execute() {
  std::cout<<"Command was cancelled"<<std::endl;
}
void CancelCommand::accept(std::shared_ptr<Visitor> v) {

}
