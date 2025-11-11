#include "EngineCore.h"
#include "Engine.h"
#include "EngineTime.h"
#include "RenderSystem.h"
#include "Sprite.h"
#include "Entity.h"

Engine* Engine::instance = nullptr;

extern void Engine_Register();

void Engine::Initialize()
{
    Engine_Register();
	Time::Instance().Initialize();
	RenderSystem::Instance().Initialize();
}

void Engine::Destroy()
{
	Time::Instance().Destroy();
	RenderSystem::Instance().Destroy();
}

void Engine::GameLoop()
{
    Component* component = (Component*)TypeClass::ConstructObject("Zombie");
    component->Initialize();

    // std::cout << component->GetDerivedTypeClassName() << std::endl;

    if (component->IsA(Sprite::GetTypeClassHashCode()))
    {
        // std::cout << "Something\n";
    }

	while (!quit)
	{
		GetInput();

		Time::Instance().Update();
		RenderSystem::Instance().Update();
	}
}

void Engine::GetInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                quit = true;
            }
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            std::cout << "Key Event" << std::endl;
            break;

        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEWHEEL:
            std::cout << "Mouse Event" << std::endl;
            break;
        }
    }
}