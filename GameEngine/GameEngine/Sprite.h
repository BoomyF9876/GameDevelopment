#pragma once

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Component.h"
#include "IRenderable.h"
#include "SDL.h"

struct SDL_Texture;

class Sprite : public Component, public IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Sprite, Component)

private:
	std::string spriteName;
	SDL_Texture* texture;
	SDL_Point size;
	SDL_Texture* subTexture; // This is the new texture which is sub image

public:
	void Initialize() override;
	void Destroy() override;

	void Update() override;
	void Load(json::JSON& jsonData) override;

protected:
	void Render();
};

#endif	// _SPRITE_H_
