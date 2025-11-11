#pragma once

#ifndef _ASSETMANAGER_H_
#define _ASSETMANAGER_H_

class AssetManager
{
public:

	static AssetManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new AssetManager();
		}
		return *instance;
	}

	void Initialize();
	void Update();
	void Destroy();

private:
	static AssetManager* instance;

private:
	inline explicit AssetManager() = default;
	inline ~AssetManager() = default;
	inline explicit AssetManager(AssetManager const&) = delete;
	inline AssetManager& operator=(AssetManager const&) = delete;
};

#endif //_ASSETMANAGER_H_