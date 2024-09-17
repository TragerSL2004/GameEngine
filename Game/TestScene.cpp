#include "TestScene.h"
#include "Engine/Entity.h"
#include "Graphics/ShapeComponent.h"
#include "Engine/TransformComponent.h"
#include "Physics/RigidBodyComponent.h"
#include "Physics/CircleColliderComponent.h"
#include "Physics/AABBColliderComponent.h"
#include <chrono>

void TestScene::onStart()
{
	using namespace Graphics;

	//Set up circle 1
	m_circle1 = new GameEngine::Entity();
	m_circle1->getTransform()->setLocalScale({ 40, 40 });
	m_circle1->getTransform()->setLocalPosition({ 100, 100 });
	m_circle1->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::CIRCLE);
	m_circle1->addComponent(new GamePhysics::CircleColliderComponent(50));
	m_circle1->addComponent(new GamePhysics::RigidBodyComponent());
	addEntity(m_circle1);

	//Set up circle 2
	m_circle2 = new GameEngine::Entity();
	m_circle2->getTransform()->setLocalScale({ 40, 40 });
	m_circle2->getTransform()->setLocalPosition({ 600, 100 });
	m_circle2->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::CIRCLE);
	m_circle2->addComponent(new GamePhysics::CircleColliderComponent(50));
	m_circle2->addComponent(new GamePhysics::RigidBodyComponent());
	addEntity(m_circle2);

	//Set up floor
	m_floor = new GameEngine::Entity();
	m_floor->getTransform()->setLocalScale({ 1000, 100 });
	m_floor->getTransform()->setLocalPosition({ 400, 740 });
	m_floor->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::CIRCLE);
	m_floor->addComponent(new GamePhysics::CircleColliderComponent(210));
	m_floor->addComponent(new GamePhysics::RigidBodyComponent());
	m_floor->getComponent<GamePhysics::RigidBodyComponent>()->setGravity(0);

	addEntity(m_floor);

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
