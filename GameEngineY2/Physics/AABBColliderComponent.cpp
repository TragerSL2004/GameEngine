#include "AABBColliderComponent.h"
#include "CircleColliderComponent.h"
#include "Engine/TransformComponent.h"
#include "Math/Vector2.h"
#include "Engine/Entity.h"
#include <raylib.h>

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
    GameMath::Vector2 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 direction = otherPosition - position;

    if (position.x < otherPosition.x + other->getRadius() && position.x + getWidth() > otherPosition.x
        && position.y < otherPosition.y + other->getRadius() && position.y + getHeight() > otherPosition.y)
    {
        GamePhysics::Collision* collisionData = new Collision();
        collisionData->collider = other;
        collisionData->normal = direction.getNormalized();
        collisionData->penetrationDistance = getWidth() + getHeight() + other->getRadius() - direction.getMagnitude();
        return collisionData;
    }

    else
        return nullptr;
}

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
    GameMath::Vector2 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 direction = otherPosition - position;

    if (position.x < otherPosition.x + other->getWidth() && position.x + getWidth() > otherPosition.x
        && position.y < otherPosition.y + other->getHeight() && position.y + getHeight() > otherPosition.y)
    {
        GamePhysics::Collision* collisionData = new Collision();
        collisionData->collider = other;
        collisionData->normal = direction.getNormalized();
        return collisionData;
    }

    else
        return nullptr;
}

void GamePhysics::AABBColliderComponent::draw()
{
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 scale = getOwner()->getTransform()->getLocalScale();

    RAYLIB_H::DrawRectangleLines(position.x - m_width / 2, position.y - m_height / 2, m_width, m_height, GetColor(getColor()));
}
