#include "AABBColliderComponent.h"
#include "CircleColliderComponent.h"
#include "Engine/TransformComponent.h"
#include "Math/Vector2.h"
#include "Engine/Entity.h"
#include <raylib.h>

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{

    return nullptr;
}

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
    
    return nullptr;
}

void GamePhysics::AABBColliderComponent::draw()
{
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 scale = getOwner()->getTransform()->getLocalScale();

    RAYLIB_H::DrawRectangleLines(position.x - m_width / 2, position.y - m_height / 2, m_width, m_height, GetColor(getColor()));
}
