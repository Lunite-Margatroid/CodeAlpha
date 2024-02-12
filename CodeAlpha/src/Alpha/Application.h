#pragma once
#include "Core.h"
#include <stdio.h>
namespace Alpha
{

class ALPHA_API Application
{
public:
	Application();
	virtual ~Application();

	virtual void Run();

};

Application* CreateApplaction();

}