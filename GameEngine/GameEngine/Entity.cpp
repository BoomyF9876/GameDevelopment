#include "EngineCore.h"
#include "Entity.h"
#include "Component.h"

IMPLEMENT_DYNAMIC_CLASS(Entity)

void Entity::Initialize()
{
	Object::Initialize();

	for (auto& component : components)
	{
		component->Initialize();
	}
}

void Entity::Update()
{
	for (auto& component : components)
	{
		component->Update();
	}
}

void Entity::Destroy()
{
	Object::Destroy();

	for (auto& component : components)
	{
		component->Destroy();
		delete component;
	}
	components.clear();
}

void Entity::Load(json::JSON& jsonData)
{
	Object::Load(jsonData);
}