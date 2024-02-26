#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define yukari 10
#define asagi 20
void gotoxy(int x,int y);
void harita();
void hareket();
void hidecursor();
void taslar();
int skor;
int x=5 ,y=9;
int random,random1=2;
int bitti=3;
int main(){
	random=rand()%19+2;
while(bitti>0){
    skor=skor+1;
    gotoxy(11,11);
    printf("skor:%d",skor);
    gotoxy(3,11);
    printf("can:%d",bitti);
	harita();
	hareket();
	taslar();
	hidecursor();
	
	if (x < 2 || x > asagi - 1){
	bitti = 0;
	}
	if(random==x&&random1==y){
	bitti = bitti - 1;

	}
	if(bitti==0){
	 gotoxy(3,12);
	 printf("\n kaybettin");
	 getch();
	 exit(0);
	}
}
	getch();
	return(0);
}   	
void hidecursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);	
}
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void hareket(){
	gotoxy(x,y);
	printf("o");
		if (kbhit()) {
		switch (getch()) {
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		default:
			break;
		}
	}
}
void harita(){
	int i,j;
    gotoxy(1,1);
    for (i = 0; i < yukari; i++) {
    for (j = 0; j < asagi; j++) {
    if (i == 0 || i == yukari - 1 || j == 0 || j == asagi - 1) {
    printf("v");
    }
    else
	printf(" ");
    }
    printf("\n");
    }
}
void taslar(){
    enum {SECS_TO_SLEEP = 0, NSEC_TO_SLEEP = 90000000};
    struct timespec surec, istenen = {SECS_TO_SLEEP, NSEC_TO_SLEEP};
    gotoxy(random,random1);
	printf("v");
	random1++;
    nanosleep(&istenen,&surec);
	if(random1==11){
	random1=2;
	random=rand()%19+2;
	                  }
}
