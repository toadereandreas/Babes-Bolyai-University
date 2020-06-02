#include "Lab10.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include "UI.h"
#include <fstream>
#include "GUIm.h"
#include "Bussines.h"

int GUI(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Repository repo;
	repo.readFromFile();

	Controller ctrl{ repo };

	GUIByHand main_widget{ ctrl, 0 };

	main_widget.initGUI();
	main_widget.connectSignalsAndSlots();

	main_widget.show();
	//main_widget.setFixedHeight(main_widget.sizeHint().height());

	return a.exec();
}

int main(int argc, char* argv[])
{
	return GUI(argc, argv);
}