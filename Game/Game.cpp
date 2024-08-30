#include "Engine/Engine.h"
#include "TestScene.h"

int main()
{
    GameEngine::Engine engine = GameEngine::Engine();

    TestScene* scene = new TestScene();

    engine.setCurrentScene(scene);
    engine.run();

    return 0;
}

