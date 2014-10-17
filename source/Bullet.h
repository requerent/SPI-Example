#pragma once
#include "Entity.h"


class Bullet : public Entity
{
	float m_speed;

	Bullet(float x, float y) : Entity(e_typeBullet, "bullet")
	{
		m_radius = 8;
		m_speed = 150;
		m_x = x;
		m_y = y;
	}
public:
	static void Spawn(float x, float y)
	{
		Entity::Add(new Bullet(x,y));		
	}

	void onUpdate(float dt) { m_y += m_speed * dt; }

	void onCollide(const Entity *e)
	{
		switch (e->getType())
		{
		case e_typeEnemy: m_active = false; break;
		}
	}
};