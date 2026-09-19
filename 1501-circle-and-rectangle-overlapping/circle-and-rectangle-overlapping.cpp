class Solution {
public:
    double distance(double x1, double y1, double x2, double y2){
        double val1=x2-x1;
        double val2=y2-y1;
        double sq1=val1*val1;
        double sq2=val2*val2;
        double rootval=sq1+sq2;
        return sqrt(rootval);
    }
    bool checkOverlap(int radius, int xcenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xi,yi;
        if(x1>xcenter)xi=x1;
        else if(xcenter>x2)xi=x2;
        else xi=xcenter;
        if(y1>yCenter)yi=y1;
        else if(yCenter>y2)yi=y2;
        else yi=yCenter;

        double dist=distance(xi,yi,xcenter,yCenter);
        return dist<=radius;
    }
};