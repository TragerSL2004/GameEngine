#include "Component.h"
#include "Entity.h"

void GameEngine::Component::setEnabled(bool enabled)
{
	if (!m_enabled && enabled)
		onEnabled();
	else if (m_enabled && !enabled)
		onDisbale();

	m_enabled = enabled;
}

GameEngine::Entity* GameEngine::Component::getOwner()
{
	return m_owner;
}

void GameEngine::Component::setOwner(Entity* entity)
{
	m_owner = entity;
}
