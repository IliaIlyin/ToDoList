#include <iostream>
#include "TaskService.h"
int main() {
    TaskService taskService;
    taskService.addTask("Lol");
    taskService.showAllByPriority();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
