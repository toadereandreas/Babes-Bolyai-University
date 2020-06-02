#include "GUIm.h"

void GUIByHand::initGUI()
{
	this->setWindowTitle("My app");
	this->main_layout = new QHBoxLayout{ this };

	this->initGUIRepository();
	this->initGUIGenreList();
	this->initGUIWatchlist();

	this->main_layout->addLayout(this->repository_layout);
	this->main_layout->addLayout(this->genre_list_layout);
	this->main_layout->addLayout(this->watchlist_layout);

	this->connectSignalsAndSlots();

}

void GUIByHand::connectSignalsAndSlots()
{
	QObject::connect(this->sorted_button, &QRadioButton::clicked, this, &GUIByHand::sortedList);
	QObject::connect(this->shuffled_button, &QRadioButton::clicked, this, &GUIByHand::shuffledList);
	QObject::connect(this->add_button, &QPushButton::clicked, this, &GUIByHand::addAction);
	QObject::connect(this->update_button, &QPushButton::clicked, this, &GUIByHand::updateAction);
	QObject::connect(this->remove_button, &QPushButton::clicked, this, &GUIByHand::removeAction);

	QObject::connect(this->addToWatchlist_button, &QPushButton::clicked, this, &GUIByHand::addToWatchlist);

	QObject::connect(this->generate_button, &QPushButton::clicked, this, &GUIByHand::gerenateGenre);
}

void GUIByHand::gerenateGenre() {
	std::string genre = this->generate_textbox->text().toStdString();
	std::string string_vector;
	std::vector<Movie> movies = this->ctrl.getGenre(genre);
	for (auto it = movies.begin(); it != movies.end(); ++it)
	{
		string_vector += (*it).toString() + '\n';
	}
	this->genre_list->clear();
	this->genre_list->insertPlainText(QString::fromStdString(string_vector));

}

void GUIByHand::addToWatchlist() {
	std::string s = this->remove_textbox->text().toStdString();
	Movie x = this->ctrl.returnMovieWithTitle(s);
	this->ctrl.addMovieToWatchlist(x);
	this->watchlist->clear();
	this->refreshWatchlist();
}

void GUIByHand::refreshWatchlist() {
	this->watchlist->clear();
	QString qst = QString::fromStdString(this->ctrl.getWatchlistAsString());
	this->watchlist->insertPlainText(qst);
}

void GUIByHand::removeAction() {
	this->ctrl.deleteMovie(this->name_textbox->text().toStdString());
	this->ctrl.updateRepo();
	this->shuffledList();
}

void GUIByHand::updateAction() {

	this->ctrl.updateMovie(this->name_textbox->text().toStdString(), this->artist_textbox->text().toStdString(),
		std::stoi(this->year_textbox->text().toStdString()), this->link_textbox->text().toStdString());
	this->ctrl.updateRepo();
	this->shuffledList();
}

void GUIByHand::addAction() {
	QString name_Str = this->name_textbox->text();
	this->ctrl.addMovieToRepository(name_Str.toStdString(), this->artist_textbox->text().toStdString(), 
		std::stoi(this->year_textbox->text().toStdString()), 0, this->link_textbox->text().toStdString());
	this->ctrl.updateRepo();
	this->shuffledList();
}

void GUIByHand::shuffledList()
{
	this->repository->clear();
	QString str = QString::fromStdString(this->ctrl.getMoviesAsString());
	this->repository->insertPlainText(str);
}

void GUIByHand::sortedList()
{
	this->repository->clear();
	QString str = QString::fromStdString(this->ctrl.getMoviesSortedAsString());
	this->repository->insertPlainText(str);
}


void GUIByHand::initGUIRepository()
{
	this->repository_layout = new QGridLayout;

	this->songs_label = new QLabel{ "List of movies: " };
	this->repository_layout->addWidget(this->songs_label, 0, 0, 1, 1);

	QHBoxLayout* radio_buttons = new QHBoxLayout;
	this->shuffled_button = new QRadioButton("Shuffled");
	this->sorted_button = new QRadioButton("Sorted");
	radio_buttons->addWidget(sorted_button);
	radio_buttons->addWidget(shuffled_button);
	this->repository_layout->addItem(radio_buttons, 2, 0, 2, 1);

	QString songs_string_qt = QString::fromStdString(this->ctrl.getMoviesAsString());
	this->repository = new QPlainTextEdit{ songs_string_qt };
	this->repository->setFont(QFont("Courier", 10, 10, true));
	this->repository_layout->addWidget(this->repository, 4, 0, 12, 1);

	QFormLayout* interactions = new QFormLayout{};
	//...
	this->name_textbox = new QLineEdit{};
	QLabel* nameLabel = new QLabel{ "&Title:" };
	nameLabel->setBuddy(this->name_textbox);
	//...
	this->artist_textbox = new QLineEdit{};
	QLabel* artistLabel = new QLabel{ "&Genre:" };
	artistLabel->setBuddy(this->artist_textbox);
	//...
	this->year_textbox = new QLineEdit{};
	QLabel* yearLabel = new QLabel{ "&Year:" };
	yearLabel->setBuddy(this->year_textbox);
	//...
	this->link_textbox = new QLineEdit{};
	QLabel* linkLabel = new QLabel{ "&Link:" };
	linkLabel->setBuddy(this->link_textbox);
	//...
	interactions->addRow(nameLabel, this->name_textbox);
	interactions->addRow(artistLabel, this->artist_textbox);
	interactions->addRow(yearLabel, this->year_textbox);
	interactions->addRow(linkLabel, this->link_textbox);
	//...
	this->repository_layout->addLayout(interactions, 16, 0, 6, 1);

	QVBoxLayout* first_buttons = new QVBoxLayout;

	/*
	QLinearGradient buttonGradient(0, 0, 100, 100);
	buttonGradient.setColorAt(0, QColor(0, 0, 0));
	buttonGradient.setColorAt(1, QColor(100, 100, 100));

	QPalette palette = this->palette();
	palette.setBrush(QPalette::Base, buttonGradient);
	palette.setBrush(QPalette::Highlight, buttonGradient);
	palette.setBrush(QPalette::HighlightedText, Qt::white);
	palette.setBrush(QPalette::Text, Qt::white);
	*/

	this->add_button = new QPushButton{ "Add" };

	QLinearGradient linearGradient(0, 0, 500, 500);
	linearGradient.setColorAt(0, QColor(200, 200, 0));
	linearGradient.setColorAt(1, QColor(0, 12, 199));
	QBrush brush{ linearGradient };

	QPalette palette;
	palette.setBrush(QPalette::Base, brush);
	this->repository->setPalette(palette);

	this->update_button = new QPushButton{ "Update" };
	this->remove_button = new QPushButton{ "Remove" };
	first_buttons->addWidget(this->add_button);
	first_buttons->addWidget(this->update_button);
	first_buttons->addWidget(this->remove_button);
	this->repository_layout->addLayout(first_buttons, 23, 0, 2, 1);


}

void GUIByHand::initGUIGenreList()
{
	this->genre_list_layout = new QGridLayout;

	QLabel* songs = new QLabel{ "Genre List" };
	this->genre_list_layout->addWidget(songs, 0, 0, 1, 1);

	this->genre_list = new QPlainTextEdit{ "" };
	this->genre_list->setFont(QFont("Courier", 10, 10, true));
	this->genre_list_layout->addWidget(this->genre_list, 2, 0, 14, 1);

	QVBoxLayout* first_buttons = new QVBoxLayout;
	this->play_button = new QPushButton{ "Play" };
	this->next_button = new QPushButton{ "Next" };
	this->add_genre_button = new QPushButton{ "Add" };
	first_buttons->addWidget(this->play_button);
	first_buttons->addWidget(this->next_button);
	first_buttons->addWidget(this->add_genre_button);

	QHBoxLayout* genre_layout = new QHBoxLayout;
	this->generate_button = new QPushButton{ "Generate" };
	this->generate_textbox = new QLineEdit;
	genre_layout->addWidget(this->generate_button);
	genre_layout->addWidget(this->generate_textbox);
	first_buttons->addLayout(genre_layout);

	this->genre_list_layout->addLayout(first_buttons, 16, 0, 2, 1);

	QLinearGradient linearGradient(0, 0, 500, 500);
	linearGradient.setColorAt(0, QColor(0, 204, 0));
	linearGradient.setColorAt(1, QColor(255, 0, 0));
	QBrush brush{ linearGradient };

	QPalette palette;
	palette.setBrush(QPalette::Base, brush);
	this->genre_list->setPalette(palette);
}

void GUIByHand::initGUIWatchlist()
{
	this->watchlist_layout = new QGridLayout;

	QLabel* songs = new QLabel{ "Watchlist" };
	this->watchlist_layout->addWidget(songs, 0, 0, 1, 1);

	this->watchlist = new QPlainTextEdit{ "" };
	this->watchlist->setFont(QFont("Courier", 10, 10, true));
	this->watchlist_layout->addWidget(this->watchlist, 2, 0, 10, 1);

	QHBoxLayout* buttons = new QHBoxLayout;
	QPushButton* remove_good_button = new QPushButton{ "Like" };
	QPushButton* remove_bad_button = new QPushButton{ "Dislike" };
	buttons->addWidget(remove_good_button);
	buttons->addWidget(remove_bad_button);

	this->watchlist_layout->addItem(buttons, 12, 0, 2, 1);

	QLabel* addMovieInWatchlist = new QLabel{ "Enter title to add to watchlist: " };
	this->addToWatchlist_button = new QPushButton{ "Add" };
	this->remove_textbox = new QLineEdit{ "" };

	
	QLinearGradient linearGradient(0, 0, 500, 500);
	linearGradient.setColorAt(0, QColor(239, 204, 0));
	linearGradient.setColorAt(1, QColor(255, 0, 0));
	QBrush brush{linearGradient};

	QPalette palette;
	palette.setBrush(QPalette::Base, brush);
	this->watchlist->setPalette(palette);
	
	

	this->watchlist_layout->addWidget(addMovieInWatchlist, 14, 0, 1, 1);
	this->watchlist_layout->addWidget(remove_textbox, 15, 0, 1, 1);
	this->watchlist_layout->addWidget(addToWatchlist_button, 16, 0, 1, 1);


	QString x = QString::fromStdString(this->ctrl.getWatchlistAsString());
	this->watchlist->insertPlainText(x);
}

GUIByHand::GUIByHand(Controller& ctrl_, QWidget* parent = 0) : QWidget{ parent }, ctrl{ ctrl_ }
{
}

GUIByHand::~GUIByHand()
{
}