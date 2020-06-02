#pragma once
#include"Song.h"
#include "Repository.h"

class UndoAction {
private:
public:
	virtual ~UndoAction() {}
	virtual void executeUndo() = 0;
};

class UndoAdd :public UndoAction {
private:
	Song addedSong;
	Repository* repo;
public:
	UndoAdd(const Song& _addedSong, Repository* _repo) : addedSong{ _addedSong }, repo{_repo } {} 
	void executeUndo() override;
	~UndoAdd() {}
};

class UndoRemove :public UndoAction {
private:
	Song deletedSong;
	Repository* repo;
public:
	UndoRemove(const Song& _deletedSong, Repository* _repo) : deletedSong{ _deletedSong }, repo{ _repo } {}
	void executeUndo() override;
	~UndoRemove() {}
};