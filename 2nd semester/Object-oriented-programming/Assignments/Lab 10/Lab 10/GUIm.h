#pragma once

#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <qformlayout.h>
#include "Bussines.h"

class GUIByHand : public QWidget
{
	Q_OBJECT

private:
	QLabel* songs_label, * addMovieInWatchlist;
	QRadioButton* sorted_button, * shuffled_button;
	QPlainTextEdit* repository, * genre_list, * watchlist;
	QLineEdit* name_textbox, * year_textbox, * artist_textbox, * link_textbox, * generate_textbox, * remove_textbox;
	QPushButton* add_button, * update_button, * remove_button, * play_button, * next_button, * add_genre_button, * generate_button, * remove_good_button, * remove_bad_button, * addToWatchlist_button;
	Controller& ctrl;
	QHBoxLayout* main_layout;
	QGridLayout* repository_layout{}, * genre_list_layout{}, * watchlist_layout{};

	void initGUIRepository();
	void initGUIGenreList();
	void initGUIWatchlist();

public:
	GUIByHand(Controller& ctrl_, QWidget* parent);
	~GUIByHand();

	void initGUI();
	void connectSignalsAndSlots();

public slots:
	void sortedList();
	void shuffledList();
	void addAction();
	void updateAction();
	void removeAction();
	void addToWatchlist();
	void refreshWatchlist();
	void gerenateGenre();
};