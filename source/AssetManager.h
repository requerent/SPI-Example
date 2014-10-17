#pragma once
#include <map>
#include <string>

class AssetManager
{
	struct TextureData { unsigned  m_handle, m_width, m_height; };
	
	static std::map<std::string, TextureData> s_textures;
	AssetManager() {}
public:
	static void Draw(const char *name, int x, int y);
	static void Load(const char *name, const char *path, int w, int h);

	static int GetHeight(const char *name);
	static int GetWidth(const char *name);

	static void FreeAll();
};