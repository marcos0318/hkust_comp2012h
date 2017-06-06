#include "fast.h"
Fast::Fast(std::vector<Point> vec)
        :points(vec)
{
//Time start
	using namespace std;

        int count = 1; 
        for(int i = 0; i < points.size(); i++){
                for (int j = 0; j < points.size();j++){
                        points[j].setAngle(points[j].angleFromPoint(points[i]));
                }
                copy = points;

//cut the points considered
                for(int j =0; j<i; j++)copy.erase(copy.begin());


                sort(copy.begin(),copy.end());


                std::vector<Point> tmp;


                for (int j = 1; j < copy.size(); j++){
                        if (copy[j].getAngle() == copy[j-1].getAngle()){
                                if (j == copy.size()-1 && count > 1 ){
                                        tmp.push_back(points[i]);
                                        for(int p=j-count;p<=j;p++){
                                                tmp.push_back(copy[p]);
                                        }
                                        if (!IsIncluded(tmp) ){
                                                //check if is included
                                                lines.push_back(tmp);
                                        }
                                        tmp.clear();

                                }
                                count++;
                         
                        }
                        else {  
                                if(count>2){
                                        tmp.push_back(points[i]);
                                        for(int p=j-count;p<j;p++){
                                                tmp.push_back(copy[p]);
                                        }
                                        count = 1;
                                        if (! IsIncluded(tmp)){
                                                //check if is included  
                                                lines.push_back(tmp);
                                        }
                                        tmp.clear();
                                }
                                else count = 1;
                        }               
                }        
        }
	
}
bool Fast::IsIncluded(std::vector<Point> tmp){
        for (int i = 0; i< lines.size(); i++){
                int counter = 0;
                for (int j = 0 ; j < tmp.size(); j++){
                        if (std::find(lines[i].begin(), lines[i].end(), tmp[j])!=lines[i].end()) counter++;

                }
                if (counter > 1)return 1;
        }
        return 0;
}

