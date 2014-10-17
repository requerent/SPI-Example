#pragma once
#include "AIE.h"

enum e_Event {
			   e_eventNone      = 0x0000,
			   e_eventAdvance   = 0x0001,
			   e_eventRespawn   = 0x0002,
			   e_eventGameOver  = 0x0004,
			   e_eventWaveClear = 0x0008,
			   e_eventExample4  = 0x0010,
			   e_eventExample5  = 0x0020,
			   e_eventCount     = 0x0040,
			};

enum e_Type { e_typeNone, e_typeBullet, e_typePlayer, e_typeEnemy };

extern const int g_ScreenWidth;
extern const int g_ScreenHeight;

class Entity;
class Bullet;
class Player;
class Enemy;