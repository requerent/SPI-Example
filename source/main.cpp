
#include "AIE.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

const int g_ScreenWidth = 800;
const int g_ScreenHeight = 600;

int main(int argc, char* argv[])
{

	Initialise(g_ScreenWidth, g_ScreenHeight, false, "Space Invaders");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));
	AssetManager::Load("player","./images/cannon.png" , 64, 32);
	AssetManager::Load("enemy", "./images/invaders/invaders_1_00.png", 32, 32);
	AssetManager::Load("bullet", "./images/invaders/invaders_5_00.png", 24, 24);

	Player::Spawn(400, 100);

	Enemy::SpawnFleet();

	do
	{
		ClearScreen();
		float dt = GetDeltaTime();

		Entity::Update(dt);
		Entity::Draw();

	} while (FrameworkUpdate() == false);


	Shutdown();

	return 0;
}
