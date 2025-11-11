#pragma once

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Component.h"

class Transform : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Transform, Component)

public:
	void Initialize() override;
	void Update() override;
	void Destroy() override;

	void Load(json::JSON& jsonData) override;
};

#endif	// _TRANSFORM_H_
