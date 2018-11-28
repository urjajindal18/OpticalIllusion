
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
union REGS in,o;
void rocket();
void text();
int gd=DETECT,gm,i,j,k;
void circ()
{
	int i;
	for(i=0;i<15;i++)
		circle(320,240,i*10);
	rectangle(240,160,400,320);
}

void text()
{
initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
settextstyle(0,EMPTY_FILL,1);
settextstyle(0,EMPTY_FILL,2);
setcolor(BLUE);
outtextxy(100,50,"I I I T");
outtextxy(100,70,"UNA");
settextstyle(0,EMPTY_FILL,1);
setcolor(WHITE);
outtextxy(50,120,"We present you our project on OPTICAL ILLUSION");
delay(150);
outtextxy(50,150,"An Optical Illusion is an illusion caused by");
delay(150);
outtextxy(50,180," the visual system and characterized by a visual");
delay(150);
outtextxy(50,210,"persept that appears to differ from reality.");
delay(150);
setcolor(RED);
outtextxy(50,240,"Lets LAUNCH the project ");
delay(150);
outtextxy(50,420,"SO... COUNTDOWN  BEGIN");
delay(150);
outtextxy(50,450,"ENTER TO CONTINUE");
delay(150);
}

void rocket()
{
setcolor(BLUE);
 //earth
    for(i=30;i<=400;i++)
    {
setcolor(BLUE);

arc(500-i,200+i,0,120,200);
arc(500-i,200+i,0,120,300);
arc(500-i,200+i,0,120,400);
arc(500-i,200+i,0,120,500);
setcolor(GREEN);
outtextxy(318,330-i,"I");
outtextxy(318,340-i,"I");
outtextxy(318,350-i,"I");
outtextxy(318,360-i,"T");
outtextxy(310,385-i,"UNA");
//rocket
setcolor(WHITE );
outtextxy(10,400+i,"GRAPHICS");
for(j=0;j<=7;j++)
{
setcolor(RED);
circle(320,300-i,0+j);
}
for(k=0;k<=15;k++)
{
setcolor(YELLOW);
circle(300,410-i,0+k);
circle(340,410-i,0+k);
circle(320,410-i,0+k);
circle(280,410-i,0+k);
circle(360,410-i,0+k);
}
setcolor(WHITE);
line(0,420+i,620,420+i);
line(340,400-i,340,320-i);
line(300,400-i,300,320-i);
line(330,370-i,330,330-i);
line(310,370-i,310,330-i);
line(310,330-i,330,330-i);
line(310,370-i,330,370-i);
line(300,380-i,340,380-i);
line(270,400-i,370,400-i);
line(270,400-i,300,380-i);
line(340,380-i,370,400-i);
line(300,320-i,340,320-i);
line(300,320-i,320,300-i);
line(340,320-i,320,300-i);
delay(50);
cleardevice();
}
getch();
}


void bulb()
{
	int i=1,c=1;
	randomize();
	while(!kbhit())
	{
		if((i%2)==0)
			setcolor(c++);
		setfillstyle(1,getcolor());
		circle(320,240,i*20);
		putpixel(320-i+2,240-i+2,1);
		floodfill(320-i+2,240-i+2,getcolor());
		delay(1000);
		i++;
		if(i>=5)
			i=1;
	}
}

void dot()
{
	int i,j,of=40,wid=5;
	setcolor(8);
	setfillstyle(1,getcolor());
	for(i=of;i<getmaxx();i+=of)
		bar(i,0,i+wid,getmaxy());

	for(i=of;i<getmaxy();i+=of)
		bar(0,i,getmaxx(),i+wid);

	for(i=of;i<getmaxx();i+=of)
		for(j=of;j<getmaxy();j+=of)
		{
			setcolor(15);
			setfillstyle(1,getcolor());
			circle(i+2,j+2,4);
			floodfill(i+2,j+2,getcolor());
		}

}

void main()
{
         text();
         getch();
         cleardevice();
	rocket();
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	setcolor(YELLOW);
	settextstyle(1,0,6);
	outtextxy(0,240,"Count the black dots.....");
	sleep(4);
	cleardevice();
	dot();
	getch();
	cleardevice();
	setcolor(YELLOW);
	settextstyle(1,0,4);
	outtextxy(0,240,"I bet the lines of rectangle are straight.....");
	sleep(4);
	getch();
	cleardevice();
	circ();
	sleep(4);
	getch();
	cleardevice();
	setcolor(YELLOW);
	settextstyle(1,0,4);
	outtextxy(0,240,"THANK YOU");
	getch();
	closegraph();
}
