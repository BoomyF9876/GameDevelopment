#include "EngineCore.h"
#include "Component.h"

IMPLEMENT_ABSTRACT_CLASS(Component)

void Component::Initialize()
{
	Object::Initialize();
}

void Component::Update()
{
	// Do nothing, could be pure virtual?
}

void Component::Destroy()
{
	Object::Destroy();
}

void Component::Load(json::JSON& jsonData)
{
	Object::Load(jsonData);
}