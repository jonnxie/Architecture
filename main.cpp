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

    auto engine {makeEngine()};
    auto window{std::make_shared<GLFWWindow>(640, 640, "FlowEngine")};
    engine->setWindow(window);
    auto renderer {Renderer::createRender()};
    engine->setRenderer(renderer);
    auto computer{createMultipleComputer()};
    engine->setComputer(computer);
    auto firstScene = makeScene();
    {
        auto viewPortSpec {makeViewPortSpec(0, 0, 500, 500, Camera{})};
        auto firstViewPort {ViewPort::createViewPort(std::move(viewPortSpec))};
        auto& firstCamera {firstViewPort->getCamera()};
        firstCamera.setPos({0,0,10});
        firstScene->addViewPort("FirstViewPort",firstViewPort);
    }

    auto firstObject {firstScene->createObject("firstObject")};
    auto material {Material::creatMaterial({{"", VertexShader}, {"", FragmentShader}})};
    std::function<void(RenderComponent*)> renderFunction {
        [](RenderComponent* _component) {
            _component->bindMaterial(_component->getMaterial().get());
            _component->drawIndex(4, 0);
        }
    };
    firstObject.addComponent<RenderComponentMiddle>(renderFunction);
    firstObject.getComponent<RenderComponentMiddle>()()->setMaterial(material);
    engine->setScene(std::move(firstScene));
    engine->update();
    return 0;
}
