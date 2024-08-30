#include "TestScene.h"
#include "Engine/Entity.h"
#include "Graphics/ShapeComponent.h"
#include "Engine/TransformComponent.h"
#include <chrono>

void TestScene::onStart()
{
	using namespace Graphics;

	//Initialize Entity
	m_entity = new GameEngine::Entity();
	m_entity->getTransform()->setLocalScale({ 100, 100 });
	m_entity->getTransform()->setLocalPosition({ 400, 400 });

	//Initialize Shape Component
	ShapeComponent* shapeComponent = new ShapeComponent();
	shapeComponent->setShapeType(ShapeType::CIRCLE);
	shapeComponent->setColor(0x00FFFFFF);

	m_entity->addComponent(shapeComponent);

	addEntity(m_entity);
}

void TestScene::onUpdate(double deltaTime)
{
	float currentTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}
