#include<iostream>
#include<algorithm>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *q, Rect *w){
	double L1,L2;
	double minx , miny, maxx , maxy , LT = 0;
    minx = min(q->x+q->w,w->x+w->w);
    maxx = max(q->x,w->x);
	L1 = minx - maxx;
	miny = min(q->y,w->y);
    maxy = max(q->y-q->h,w->y-w->h);
	L2 = miny - maxy;
	if(L1 < 0){
		L1 = 0;
	}
	if(L2 <0){
		L2 = 0;
	}
	LT = L1*L2;
	return LT; 
}

int main(){
	Rect R1 = {1,1,5,5};
Rect R2 = {7,2,3,3};
cout << overlap(&R1,&R2);
	return 0;	
}