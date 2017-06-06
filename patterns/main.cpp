#include<QtGui>
#include"pointplotter.h"
using namespace std;
int main(int argc, char** argv){
	QApplication app(argc, argv);
	PointPlotter* p = new PointPlotter(argv[1]); 
	p->show();

	return app.exec();
}
