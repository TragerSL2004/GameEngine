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

	//Set up box 1
	m_box1 = new GameEngine::Entity();
	m_box1->getTransform()->setLocalScale({ 40, 40 });
	m_box1->getTransform()->setLocalPosition({130, 150 });
	m_box1->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::BOX);
	m_box1->addComponent(new GamePhysics::AABBColliderComponent(50, 50));
	m_box1->addComponent(new GamePhysics::RigidBodyComponent());
	addEntity(m_box1);

	//Set up floor
	m_floor = new GameEngine::Entity();
	m_floor->getTransform()->setLocalScale({ 2000, 100 });
	m_floor->getTransform()->setLocalPosition({ 100, 740 });
	m_floor->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::BOX);
	m_floor->addComponent(new GamePhysics::AABBColliderComponent(2020, 110));
	m_floor->addComponent(new GamePhysics::RigidBodyComponent());
	//Stop floor from bouncing on collisions
	m_floor->getComponent<GamePhysics::RigidBodyComponent>()->setMass(500);
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
