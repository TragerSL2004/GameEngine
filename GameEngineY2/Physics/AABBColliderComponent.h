#pragma once
#include "ColliderComponent.h"

namespace GamePhysics
{
	class AABBColliderComponent : public ColliderComponent
	{
	public:
		AABBColliderComponent(int width, int height) : ColliderComponent() { m_width = width, m_height = height, setColliderType(AABB); }

		GamePhysics::Collision* checkCollisionCircle(CircleColliderComponent* other) override;
		GamePhysics::Collision* checkCollisionAABB(AABBColliderComponent* other) override;

		void draw() override;

		int getWidth() { return m_width; }
		int getHeight() { return m_height; }

	private:
		int m_width;
		int m_height;
	};
}