#include "main.h"
#include "helper.h"
#include <iostream>

void greet() {
    std::cout << "Hello from main!" << std::endl;
}

void run() {
    greet();
    Helper helper;
    helper.greet();
}

int main() {
    run();
    return 0;
}
