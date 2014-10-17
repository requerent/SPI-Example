#pragma once
#include "Entity.h"
#include "Bullet.h"

class Player : public Entity
{
	float m_speed;
	float m_rof;
	float m_timer;

	Player(float x, float y) : Entity(e_typePlayer, "player")
	{
		m_x = x; m_y = y; m_speed = 150; m_timer = 0; m_rof = .25f;
		m_radius = 32;
	}
public:	
	static void Spawn(float x, float y) { Entity::Add(new Player(x,y)); }

	void onUpdate(float dt)
	{
		m_timer += dt;
		if (IsKeyDown('A'))
		{
			m_x -= m_speed * dt;
		}
		if (IsKeyDown('D'))
		{
			m_x += m_speed * dt;
		}
		if (IsKeyDown('F') && m_timer > m_rof)
		{
			m_timer = 0;
			Bullet::Spawn(m_x,m_y+48);
		}
	}
};