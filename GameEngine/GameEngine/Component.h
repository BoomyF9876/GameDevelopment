#pragma once

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "Object.h"

class Component : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Component, Object)
	//IS_A_BASE_DEFINITION(Component)
//protected:
//	Component() = default;
//	~Component() override = default;

public:
	void Initialize() override;
	virtual void Update();
	void Destroy() override;

	void Load(json::JSON& jsonData) override;

	friend class Entity;
};

#endif	// _COMPONENT_H_
