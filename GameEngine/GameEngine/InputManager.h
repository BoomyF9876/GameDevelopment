#pragma once

#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

class InputManager
{
public:

	static InputManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new InputManager();
		}
		return *instance;
	}

	void Initialize();
	void Update();
	void Destroy();

private:
	static InputManager* instance;

private:
	inline explicit InputManager() = default;
	inline ~InputManager() = default;
	inline explicit InputManager(InputManager const&) = delete;
	inline InputManager& operator=(InputManager const&) = delete;
};

#endif //_INPUTMANAGER_H_