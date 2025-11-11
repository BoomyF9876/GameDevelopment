#pragma once

#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_

#include <list>
#include "SDL.h"
#include "SDL_image.h"

class IRenderable;

class RenderSystem
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

public:
	static RenderSystem& Instance()
	{
		if (instance == nullptr)
		{
			instance = new RenderSystem();
		}
		return *instance;
	}

	SDL_Renderer* GetRenderer() { return renderer; }

	void AddRenderable(IRenderable* _renderable);
	void RemoveRenderable(IRenderable* _renderable);

private:
	void Initialize();
	void Update();
	void Destroy();

private:
	static RenderSystem* instance;
	std::list<IRenderable*> renderables;

private:
	inline explicit RenderSystem() = default;
	inline ~RenderSystem() = default;
	inline explicit RenderSystem(RenderSystem const&) = delete;
	inline RenderSystem& operator=(RenderSystem const&) = delete;

	friend class Engine;
};

#endif