#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Object.h"
#include <list>

class Component;

class Entity final : public Object
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Entity, Object)

private:
	std::list<Component*> components;

//protected:
//	Entity() = default;
//	~Entity() override = default;

public:
	void Initialize() override;
	void Update();
	void Destroy() override;
	void Load(json::JSON& jsonData) override;
};

#endif	// _ENTITY_H_
