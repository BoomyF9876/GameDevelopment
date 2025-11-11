#include "EngineCore.h"
#include "Sprite.h"
#include "RenderSystem.h"
#include <exception>
#include <iostream>
#include <stdio.h>
#include <sstream>

IMPLEMENT_DYNAMIC_CLASS(Sprite)

void Sprite::Initialize()
{
	Component::Initialize();

	SDL_Surface* surface = IMG_Load("../Assets/Tacos.jpg");
	THROW_RUNTIME_ERROR(surface == nullptr, "Cannot find Tacos.jpg");
	//if (surface == nullptr)	
	//{
	//	std::stringstream msg_s;
	//	msg_s << "Cannot find Tacos.jpg : " << __FILE__ << ", " << __LINE__;
	//	throw std::exception(msg_s.str().c_str());
	//}

	texture = SDL_CreateTextureFromSurface(RenderSystem::Instance().GetRenderer(), surface);
	SDL_FreeSurface(surface); // we got the texture now free surface
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);


	SDL_Rect rect{ 0, 0, 250, 250 };
	subTexture = SDL_CreateTexture(RenderSystem::Instance().GetRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
	SDL_SetRenderTarget(RenderSystem::Instance().GetRenderer(), subTexture);
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), texture, &rect, NULL);
	SDL_SetRenderTarget(RenderSystem::Instance().GetRenderer(), NULL); // the folowing line should reset the target to default(the screen)
}

void Sprite::Render()
{
	SDL_Rect dstrect = { 100, 100, size.x, size.y };
	SDL_SetTextureColorMod(texture, 0, 255, 0);
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), texture, NULL, &dstrect);

	SDL_Rect subRect = { 0, 00, 250, 250 };
	//SDL_SetTextureColorMod(texture, 0, 255, 0);
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), subTexture, NULL, &subRect);
}

void Sprite::Destroy()
{
	Component::Destroy();
	SDL_DestroyTexture(texture);
}

void Sprite::Load(json::JSON& jsonData)
{
	Component::Load(jsonData);
}

void Sprite::Update()
{
	Component::Update();
}