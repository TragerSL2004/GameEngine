#include "CircleColliderComponent.h"
#include "AABBColliderComponent.h"
#include "Engine/TransformComponent.h"
#include "Math/Vector2.h"
#include "Engine/Entity.h"
#include <raylib.h>

GamePhysics::Collision* GamePhysics::CircleColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
    GameMath::Vector2 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 direction = otherPosition - position;
    float distance = direction.getMagnitude();

    if (distance > other->m_radius + m_radius)
        return nullptr;

    GamePhysics::Collision* collisionData = new Collision();
    collisionData->collider = other;
    collisionData->normal = direction.getNormalized();
    collisionData->contactPoint = position + direction.getNormalized() * getRadius();
    collisionData->penetrationDistance = other->m_radius + m_radius - distance;

    return collisionData;
}

GamePhysics::Collision* GamePhysics::CircleColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
    GameMath::Vector2 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    int BoxMaxX = other->getWidth() / 2;
    int BoxMaxY = other->getHeight() / 2;
    GameMath::Vector2 direction = otherPosition - position;
    float distance = direction.getMagnitude();

    if (distance < BoxMaxX || distance < BoxMaxY)
    {
        GamePhysics::Collision* collisionData = new Collision();
        collisionData->collider = other;
        collisionData->normal = direction.getNormalized();
        return collisionData;
    }

    return nullptr;
}

void GamePhysics::CircleColliderComponent::draw()
{
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();

    RAYLIB_H::DrawCircleLines(position.x, position.y, getRadius(), GetColor(getColor()));
}
