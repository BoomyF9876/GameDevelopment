#include "EngineCore.h"
#include "RenderSystem.h"
#include "EngineTime.h"
#include "IRenderable.h"

RenderSystem* RenderSystem::instance = nullptr;

void RenderSystem::Initialize()
{
	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderSystem::Update()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	for (auto& renderable : renderables)
	{
		renderable->Render();
	}

	SDL_RenderPresent(renderer);
}

void RenderSystem::Destroy()
{
	renderables.clear();
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void RenderSystem::AddRenderable(IRenderable* _renderable)
{
	renderables.push_back(_renderable);
}

void RenderSystem::RemoveRenderable(IRenderable* _renderable)
{
	renderables.remove(_renderable);
}
