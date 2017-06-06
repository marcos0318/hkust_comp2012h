#include <QtGui>
#include <qtimer.h>
#include <QKeyEvent>
#include "game.h"

int main(int argc, char* argv[]){
	QApplication app(argc, argv);
	Game* c = new Game();
	c->show();

	return app.exec();
}
