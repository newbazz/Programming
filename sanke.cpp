#include<bits/stdc++.h>
using namespace std;
bool gameOver;
int width=20,height=20,x,y,fruitX,fruitY,score;
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
int tailX[100],tailY[100],ntail;
void Setup(){
	gameOver=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitX=rand() %width;
	fruitY=rand() % height;
	score=0;
}
void Draw(){
	system("clear");
	int i;
	for(i=0;i<width+2;i++)cout<<"#";
	cout<<endl;
	for(i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if(!j)
				cout<<"#";
			if(i==y&&j==x)
				cout<<"O";
			else if(i==fruitY&&j==fruitX)
				cout<<"F";
			else{
				bool print=false;
				for(int k=0;k< ntail;i++){
					if(tailX[k]==j&&tailY[k]==i)
						cout<<"O";

				}
				if(!print)
						cout<<" ";
			}
			if(j==width-1)
				cout<<"#";
		}
		cout<<endl;
	}
	for(i=0;i<width+2;i++)cout<<"#";
	cout<<endl;
}


void Input(){
	char s;
	if(cin>>s){
		switch(s){
			case 'a':
				dir=LEFT;
				break;
			case 'd':
				dir=DOWN;
				break;
			case 's':
				dir=RIGHT;
				break;
			case 'w':
				dir=UP;
				break;
			case 'x':
				gameOver=true;
				break;
		}
	}
}

void Logic(){
	int preX=tailX[0],preY=tailY[0];
	int prev2X,prev2Y;
	tailY[0]=y;
	tailX[0]=x;
	for(int i=1;i<ntail;i++){
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=preX;
		tailY[i]=preY;
		preX=prev2X;
		preY=prev2Y;
		cout<<"0";
	}
	switch(dir){
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case 'UP':
			y++;
			break;
		case DOWN:
			y--;
			break;
		default:
			break;

	}
	if(x>width||x<0||y>height||y<0)gameOver=true;
	for(int i=0;i<ntail;i++){
		if(tailX[i]==x&&tailY[i]==y)
			gameOver=true;
	}
	if(x==fruitX&&y==fruitY){
		score+=10;
		fruitX=rand() %width;
		fruitY=rand() % height;
		ntail++;

	}
}
int main(){
	while(!gameOver){
		Draw();
		Input();
		Logic();
	}
	cout<<"your score is "<<score<<endl;
	return 0;

}
