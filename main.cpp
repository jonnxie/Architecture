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
    {
        auto viewPortSpec = makeViewPortSpec(0, 0, 500, 500, Camera{});
        auto firstViewPort = ViewPort::createViewPort(std::move(viewPortSpec));
        auto& firstCamera = firstViewPort->getCamera();
        firstCamera.setPos({0,0,10});
    }

    engine->setScene(std::move(scene));

    return 0;
}
