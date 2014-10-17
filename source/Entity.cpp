#include "Entity.h"
#include "AssetManager.h"
#include <cmath>
#include <iostream>
using namespace std;

const int Entity::s_MaxEntities = 128;
Entity *Entity::s_entities[s_MaxEntities];
unsigned int Entity::s_Events;

void Entity::Destroy(Entity *e) { e->m_active = false; }

void Entity::DestroyAll()
{
	for (int i = 0; i < s_MaxEntities; ++i)
		if (s_entities[i])
		{
			delete s_entities[i];
			s_entities[i] = nullptr;
		}
}

void Entity::Add(Entity *e)
{
	for (int i = 0; i < s_MaxEntities; ++i)
		if (!s_entities[i] || !s_entities[i]->isActive())
		{
			if (s_entities[i]) delete s_entities[i];
			s_entities[i] = e;
			return;
		}


}

void Entity::Update(float dt)
{
	for (int i = 0; i < s_MaxEntities; ++i)
		if (s_entities[i] && s_entities[i]->isActive())
			s_entities[i]->onUpdate(dt);

	for (int i = 0; i < s_MaxEntities-1; ++i)
		for (int j = i + 1; j < s_MaxEntities; ++j)
		if (s_entities[i] && s_entities[i]->isActive() && s_entities[j] && s_entities[j]->isActive())
			if (s_entities[i]->collides(s_entities[j]))
			{
				s_entities[i]->onCollide(s_entities[j]);
				s_entities[j]->onCollide(s_entities[i]);
			}




	for (int i = 0; i < s_MaxEntities; ++i)
		if (s_entities[i] && !s_entities[i]->isActive())
		{
			s_entities[i] = nullptr;
			delete s_entities[i];
		}


	for (unsigned e = e_eventNone; e < e_eventCount; ++e)
		for (int i = 0; i < s_MaxEntities; ++i)
			if (s_entities[i] && s_entities[i]->isActive())
				if (e & s_Events)
					s_entities[i]->onEvent(e);

		s_Events = 0;
}

void Entity::Draw()
{
	for (int i = 0; i < s_MaxEntities; ++i)
	if (s_entities[i] && s_entities[i]->isActive())
		s_entities[i]->onDraw();
}


void Entity::Event(e_Event e) { s_Events |= e; }