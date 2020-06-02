#include "Undo.h"


void UndoAdd::executeUndo()
{
	this->repo->removeSong(this->addedSong);
}

void UndoRemove::executeUndo()
{
	this->repo->addSong(this->deletedSong);
}