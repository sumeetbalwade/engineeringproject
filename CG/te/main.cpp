#include<graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, "C:\\tc\\bgi");
    circle(300,300,50);
    getch();
    closegraph();
    
    return 0;
    //getch();
}
