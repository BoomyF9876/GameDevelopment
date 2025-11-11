#include "EngineCore.h"
#include "Transform.h"

IMPLEMENT_DYNAMIC_CLASS(Transform)

void Transform::Initialize()
{
	Component::Initialize();
}

void Transform::Update()
{
	Component::Update();
}

void Transform::Destroy()
{
	Component::Destroy();
}

void Transform::Load(json::JSON& jsonData)
{
	Component::Load(jsonData);
}