#pragma once

#ifndef _IRENDERABLE_H_
#define _IRENDERABLE_H_

class IRenderable 
{
protected:
	IRenderable();
	virtual ~IRenderable();

	virtual void Render() = 0;

private:
	friend class RenderSystem;
};

#endif	// _IRENDERABLE_H_
