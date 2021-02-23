#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *q, Rect *w){
	double L1,L2;
	double minx , miny, maxx , maxy , LT;
	if(q->x+q->w < w->x+w->w){
		minx = q->x+q->w;
	}else{
		minx = w->x+w->w;
	}
	if(q->x < w->x){
		maxx = w->y;
	}else{
		maxx = q->y;
	}
	L1 = minx - maxx;
	if(q->y < w->y){
		miny = q->y;
	}else{
		miny = w->y;
	}
	if(q->y-q->h > w->y-w->h){
		maxy = q->y-q->h;
	}else{
		maxy = w->y-w->h;
	}
	L2 = miny - maxy;
	if(L1 < 0){
		LT = 0;
	}
	if(L2 <0){
		LT = 0;
	}
	cout << minx << " " << maxx << endl;
	cout << miny << " " << maxy << endl;

	cout << L1 << " " << L2;
	cout << "LT before multiply = " << LT;
	LT = L1*L2;
	return LT;
}

int main(){
	Rect R1 = {1,1,5,5};
Rect R2 = {7,2,3,3};
cout << overlap(&R1,&R2);
	return 0;	
}