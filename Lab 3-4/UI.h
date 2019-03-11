#pragma once
#include "Controller.h"

typedef struct
{
	Controller* ctrl;
} UI;

UI createUI(Controller* p);

void startUI(UI* ui);
