#include "pointplotter.h"

PointPlotter::PointPlotter(char *path){


//Get in the data
        std::ifstream infile(path);
        infile>>number;
        Point *pp;
        int tmpX, tmpY;
        for(int i = 0; i < number ; i++){
                infile >> tmpX >> tmpY;
                pp = new Point(tmpX,tmpY);
                points.push_back(*pp);

        }
        sort(points.begin(),points.end(),presort);



//Set layout 
        fastButton = new QPushButton("&Fast");
        bruteButton = new QPushButton("&Brute");
        img.load("Drawing.png");
        background.setPixmap(QPixmap::fromImage(img));

//set slots
        QObject::connect(fastButton, SIGNAL(clicked()), this , SLOT(useFast()) );
	QObject::connect(bruteButton, SIGNAL(clicked()), this , SLOT(useBrute()));

//draw points   
        for (int i= 0; i <points.size(); i++ ){
                paintPoint(points[i]);
        }




//still set layout
	
        paintLine(Point(0,0),Point(0,32676));
        paintLine(Point(0,0),Point(32676,0));
        layout.addWidget(&background);
	layout.addWidget(&runtime);
        layout.addWidget(bruteButton);
        layout.addWidget(fastButton);
        setLayout(&layout);

        background.show();
}

void PointPlotter::paintPoint(Point p){
        QPainter painter(&img);
        painter.setBrush(Qt::SolidPattern);
        painter.setBrush(Qt::red);
        painter.setPen(Qt::darkRed);
        painter.drawEllipse( 100+ (p.x/37-5),880-(p.y/37-5),10,10);
        background.setPixmap(QPixmap::fromImage(img));
        background.show();
}

void PointPlotter::paintLine(Point p, Point q){
        QPainter painter(&img);
        painter.setPen(Qt::black);
        painter.drawLine(100+p.x/37,890 -p.y/37, 100+q.x/37, 890-q.y/37);
        background.setPixmap(QPixmap::fromImage(img));
        background.show();

}

void PointPlotter::useFast(){
	clock_t begin = clock();
        fastlines = new Fast(points);
	clock_t end = clock();
	double run= ((double) end - (double)begin)/CLOCKS_PER_SEC*1000  ;
        for(int i = 0 ;i < fastlines->lines.size(); i++){
                std::cout<< fastlines->lines[i].size()<<": ";
		for(int j = 0 ; j < fastlines-> lines[i].size(); j++){
			std::cout << " ->  (" << fastlines->lines[i][j].x << "," << fastlines->lines[i][j].y << ")";
		}
		std::cout<<std::endl;	

        }



        for(int i = 0 ;i < fastlines->lines.size(); i++){
                paintLine(fastlines->lines[i].front(), fastlines->lines[i].back());
        	background.setPixmap(QPixmap::fromImage(img));

        }

	sprintf( time, "%.10f", run);
	runtime.setText( time );
	runtime.show();
}


void PointPlotter::useBrute(){
	clock_t begin = clock();
        brutelines = new Brute(points);
	clock_t end = clock();
	double run= ((double) end - (double)begin)/CLOCKS_PER_SEC *1000 ;

        for(int i = 0 ;i < brutelines->lines.size(); i++){
                std::cout<< brutelines->lines[i].size()<<": ";
		for(int j = 0 ; j < brutelines-> lines[i].size(); j++){
			std::cout << " ->  (" << brutelines->lines[i][j].x << "," << brutelines->lines[i][j].y << ")";
		}
		
		std::cout<<std::endl;	

        }

        for(int i = 0 ;i < brutelines->lines.size(); i++){
        paintLine(brutelines->lines[i][1], brutelines->lines[i][2]);
        paintLine(brutelines->lines[i][2], brutelines->lines[i][3]);
        paintLine(brutelines->lines[i][3], brutelines->lines[i][0]);
        paintLine(brutelines->lines[i][0], brutelines->lines[i][1]);
        background.setPixmap(QPixmap::fromImage(img));
	}


	sprintf( time, "%.10f", run);
	runtime.setText( time );
	runtime.show();
}













