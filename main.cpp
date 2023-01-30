#include <iostream>
#include "FlowEngine/src/Flow.h"

using namespace Flow;


struct DebugPoint : public Point, Normal{
    glm::dvec3 test;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Quad<DebugPoint> quad;
    debugVertexPosition<DebugPoint>(&quad.vertices[0]);
    debugVertexNormal<DebugPoint>(&quad.vertices[0]);
    return 0;
}
