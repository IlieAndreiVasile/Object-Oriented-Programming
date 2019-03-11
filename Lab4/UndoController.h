#pragma once
#include "Repository.h"

typedef struct
{
	CountryRepo** repoList;
	int n;
	int index;
} undoController;

undoController* createUndoController();
/*
Creates a new controller for the undo/redo operation.
*/

void destroyUndoController(undoController* undoCtrl);
/*
Destroys the undoController.
Input:  undoCtrl - pointer for the undoController
*/

int checkUndo(undoController* undoCtrl);
/*
The function checks if we can make undo operations
Input:  undoCtrl - pointer of the controller
Output: 1 - If there can be made an undo operation
		0 - If there can't be made an undo operation
*/

int checkRedo(undoController* undoCtrl);
/*
The function checks if we can make redo operations
Input:  undoCtrl - pointer of the controller
Output: 1 - If there can be made an redo operation
		0 - If there can't be made an redo operation
*/

int undo(undoController* undoCtrl);
/*
The function makes the undo operation
Input:  undoCtrl - pointer of the controller
Output: 1 - If the undo operation has been made
		0 - If the undo operation hasn't been made
*/

int redo(undoController* undoCtrl);
/*
The function makes the redo operation
Input:  undoCtrl - pointer of the controller
Output: 1 - If the redo operation has been made
		0 - If the redo operation hasn't been made
*/