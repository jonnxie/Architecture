#include <iostream>
#include "FlowEngine/src/Flow.h"

using namespace Flow;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Quad<Point> quad;
    debugVertex<Point>(&quad.vertices[0]);
    return 0;
}
