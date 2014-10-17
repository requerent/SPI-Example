#pragma once
#include "decl.h"
#include "AssetManager.h"
#include <string>

class Entity
{
	/// Static Treatment
public:
	static void Update(float dt);
	static void Draw();
	static void Event(e_Event e);
	static void Destroy(Entity *e);
	static void Add(Entity *e);
	static void DestroyAll();
	static unsigned isEvent(e_Event e) { return s_Events&e; }

	static const int s_MaxEntities;

	e_Type getType() const { return m_type; }

protected:

	static unsigned s_Events;

	static Entity *s_entities[];
	
	Entity(e_Type a_type = e_typeNone, const char *a_AssetName = "")
		: m_type(a_type), m_AssetName(a_AssetName),m_active(true) { }

	/// Member functions
	e_Type m_type;
	bool m_active;
	float m_radius, m_x, m_y;
	int m_w, m_h;
	std::string m_AssetName;
	


	virtual void onEvent(unsigned e)		{}
	virtual void onUpdate(float dt)			{}
	virtual void onCollide(const Entity *e)	{}
	virtual void onDraw() { AssetManager::Draw(m_AssetName.c_str(), m_x, m_y); }
	
	bool isActive()	const	{ return m_active && m_type != e_typeNone; }
	
	bool collides(const Entity *e) const
	{
		return distance(e) < (m_radius + e->m_radius);
	}
	float distance(const Entity *e) const
	{
		return sqrt((m_x - e->m_x) * (m_x - e->m_x) + (m_y - e->m_y) * (m_y - e->m_y));
	}

	
};