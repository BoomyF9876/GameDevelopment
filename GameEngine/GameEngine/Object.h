#pragma once

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include "json.hpp"

class Object
{
	DECLARE_ABSTRACT_BASE_CLASS(Object)
	//DECLARE_CLASS_DEFINITION(Object)
	//IS_A_BASE_DEFINITION(Object)
private:
	bool initialized = false;
	std::string name = "";
	int id = -1;

//protected:
//	Object() = default;
//	virtual ~Object() = default;

public:
	virtual void Initialize();
	virtual void Destroy();
	
	virtual void Load(json::JSON& jsonData);

	bool IsInitialized() { return initialized; }
	std::string& GetName() { return name; }
	int GetId() { return id; }

	void SetId(int _id) { id = _id; }
};

#endif	// _OBJECT_H_
