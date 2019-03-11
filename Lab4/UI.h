#pragma once
#include "Controller.h"

typedef struct
{
	Controller* ctrl;
} UI;

UI* createUI(Controller* p);
void destroyUI(UI* ui);

void startUI(UI* ui);
