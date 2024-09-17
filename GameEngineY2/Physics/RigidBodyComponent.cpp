#include "RigidBodyComponent.h"
#include "Engine/TransformComponent.h"
#include "Physics/ColliderComponent.h"
#include "Engine/Entity.h"

void GamePhysics::RigidBodyComponent::applyForce(GameMath::Vector2 force)
{
	m_velocity = m_velocity + force / getMass();
}

void GamePhysics::RigidBodyComponent::applyForceToEntity(RigidBodyComponent* rigidBody, GameMath::Vector2 force)
{
	applyForce(force * -1);
	rigidBody->applyForce(force);
}

void GamePhysics::RigidBodyComponent::fixedUpdate(float fixedDeltaTime)
{
	GameMath::Vector2 position = getOwner()->getTransform()->getLocalPosition();
	getOwner()->getTransform()->setLocalPosition(position + m_velocity * fixedDeltaTime);

	GameMath::Vector2 gravity = { 0, getGravity() };
	applyForce(gravity * getMass());
}

void GamePhysics::RigidBodyComponent::resolveCollision(GamePhysics::Collision* collisionData)
{
	RigidBodyComponent* rigidBody = collisionData->collider->getRigidBody();
	GameMath::Vector2 velocity1 = getVelocity();
	GameMath::Vector2 velocity2 = collisionData->collider->getRigidBody()->getVelocity();
	float mass1 = getMass();
	float mass2 = collisionData->collider->getRigidBody()->getMass();
	GameMath::Vector2 normal = collisionData->normal;

	float j = 2 * GameMath::Vector2::dotProduct(velocity1 - velocity2, normal) 
		/GameMath::Vector2::dotProduct(normal, normal) * (1/mass1 + 1/mass2);

	GameMath::Vector2 impulse = normal * j;

	applyForceToEntity(rigidBody, impulse);
}
