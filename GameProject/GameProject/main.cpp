#include "GameCore.h"

extern void Game_Register();

int main()
{
	try
	{
		Game_Register();
		Engine::Instance().Initialize();
		Engine::Instance().GameLoop();
		Engine::Instance().Destroy();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
}
