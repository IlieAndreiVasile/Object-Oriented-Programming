#include "UndoController.h"
#include <string.h>
#include <stdlib.h>

undoController* createUndoController()
{
	undoController* p = (undoController*)malloc(sizeof(undoController));
	p->repoList = (CountryRepo*)malloc(100 * sizeof(CountryRepo));
	p->index = -1;
	p->n = 0;
	return p;
}

void destroyUndoController(undoController* undoCtrl)
{
	for (int i = 0; i < undoCtrl->n; i++)
		destroyRepo(undoCtrl->repoList[i]);

	free(undoCtrl->repoList);
	free(undoCtrl);
}

void newOperation(undoController* undoCtrl)
{
	for (int i = undoCtrl->index + 1; i < undoCtrl->n; i++)
		destroyRepo(undoCtrl->repoList[i]);

	undoCtrl->n = undoCtrl->index + 2;
	undoCtrl->index = undoCtrl->index + 1;
}

void addList(undoController* undoCtrl, CountryRepo* repo)
{
	Country* cou;

	undoCtrl->repoList[undoCtrl->index] = createRepo();

	for (int i = 0; i < repo->length; i++)
	{
		cou = createCountry(repo->countries[i]->name, repo->countries[i]->continent, repo->countries[i]->population);

		add(undoCtrl->repoList[undoCtrl->index], cou);
	}

}

int checkUndo(undoController* undoCtrl)
{
	return undoCtrl->index > 0;
}

int checkRedo(undoController* undoCtrl)
{
	return undoCtrl->index + 1 < undoCtrl->n;
}

int undo(undoController* undoCtrl, CountryRepo* repo)
{
	if (checkUndo(undoCtrl))
	{

		Country* cou;
		destroyRepo(repo);
		repo = createRepo();
		undoCtrl->index = undoCtrl->index - 1;
		for (int i = 0; i < undoCtrl->repoList[undoCtrl->index]->length; i++)
		{
			cou = createCountry(undoCtrl->repoList[undoCtrl->index]->countries[i]->name, undoCtrl->repoList[undoCtrl->index]->countries[i]->continent, \
				undoCtrl->repoList[undoCtrl->index]->countries[i]->population);

			add(repo, cou);
		}

		return repo;
	}
	return repo;
}

int redo(undoController* undoCtrl, CountryRepo* repo)
{
	if (checkRedo(undoCtrl))
	{

		Country* cou;
		destroyRepo(repo);
		repo = createRepo();
		undoCtrl->index = undoCtrl->index + 1;
		for (int i = 0; i < undoCtrl->repoList[undoCtrl->index]->length; i++)
		{
			cou = createCountry(undoCtrl->repoList[undoCtrl->index]->countries[i]->name, undoCtrl->repoList[undoCtrl->index]->countries[i]->continent, \
				undoCtrl->repoList[undoCtrl->index]->countries[i]->population);

			add(repo, cou);
		}
		return repo;
	}
	return repo;
}