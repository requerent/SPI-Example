#include "AssetManager.h"
#include "Aie.h"


std::map<std::string, AssetManager::TextureData> AssetManager::s_textures;


void AssetManager::Draw(const char *name, int x, int y)
{
	if (s_textures.count(name) > 0)
	{
		MoveSprite(s_textures[name].m_handle, x, y);
		DrawSprite(s_textures[name].m_handle);
	}
}

void AssetManager::Load(const char *name, const char *path, int w, int h)
{
	if (s_textures.count(name) > 0)
		DestroySprite(s_textures[name].m_handle);

	TextureData t;
	t.m_handle = CreateSprite(path,w,h,true);
	t.m_width = w;
	t.m_height = h;
	s_textures[name] = t;
}

int AssetManager::GetHeight(const char *name)
{
	if (s_textures.count(name) > 0)
		return s_textures[name].m_height;
	else return -1;
}

int AssetManager::GetWidth(const char *name)
{
	if (s_textures.count(name) > 0)
		return s_textures[name].m_width;
	else return -1;
}

void AssetManager::FreeAll()
{
	for each(auto t in s_textures)
		DestroySprite(t.second.m_handle);
}