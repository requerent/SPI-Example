#pragma once
#include "Entity.h"


class Enemy : public Entity
{
	float m_speed;
	bool advance;

	Enemy(float x, float y) : Entity(e_typeEnemy, "enemy")
	{
		m_radius = 12;
		m_speed = 150;
		m_x = x;
		m_y = y;
	}
public:
	static void Spawn(float x, float y)
	{
		Entity::Add(new Enemy(x, y));
	}

	

	static void SpawnFleet()
	{
		for (int i = 0; i < 48; ++i)
		{
			Enemy::Spawn(40 * (i % 6), 500 + 40 * (i / 6));
		}
	}

	void onUpdate(float dt)
	{
		m_x += m_speed * dt;
		if (m_x > g_ScreenWidth || m_x < 0)
			Entity::Event(e_eventAdvance);
	}

	void onEvent(unsigned e)
	{
		switch (e)
		{
		case e_eventAdvance: Advance(); break;
		}
	}

	void onCollide(const Entity *e)
	{
		switch (e->getType())
		{
		case e_typeBullet: m_active = false; break;
		}
	}

	void Advance() { m_y -= 40; m_speed *= -1; }
};