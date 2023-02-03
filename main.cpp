#include <iostream>
#include "FlowEngine/src/Flow.h"

using namespace Flow;


struct DebugPoint : public Point, Normal{
    glm::dvec3 test;
};

int main() {
    Quad<DebugPoint> quad;
    debugVertexPosition<DebugPoint>(&quad.vertices[0]);
    debugVertexNormal<DebugPoint>(&quad.vertices[0]);

    auto engine = makeEngine();
    auto scene = makeScene();

    engine->setScene(std::move(scene));

    return 0;
}
