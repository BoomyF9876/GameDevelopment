#include "EngineCore.h"
#include "Object.h"
#include "Component.h"
#include "Sprite.h"
#include "Transform.h"
#include "Entity.h"

void Engine_Register()
{
	REGISTER_TYPECLASS(Object)
	REGISTER_TYPECLASS(Component)
	REGISTER_TYPECLASS(Sprite)
	REGISTER_TYPECLASS(Transform)
	REGISTER_TYPECLASS(Entity)
}
