#include<iostream> 
#include<graphics.h>

using namespace std;

void circled(int x,int y,int xc ,int yc)
{
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc+y,yc+x,WHITE);
    putpixel(xc-y,yc+x,WHITE);
    putpixel(xc-y,yc-x,WHITE);
    putpixel(xc+y,yc-x,WHITE);
}

void midpoint(int xc,int yc,int r)
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C://TC//BGI");

    int x=0;
    int y=r;
    int P=1-r;
    circled(x,y,xc,yc);
    while (y>x)
    {
        x++;
        if (P <= 0) 
            P = P + 2*x + 1; 
        else
        { 
            y--; 
            P = P + 2*x - 2*y + 1; 
        } 

        circled(x,y,xc,yc);

    }
    getch();
    closegraph();
    
}

void cbresenhams(int xc,int yc, int r)
{
    int x=0,y=r;
    int dp=3-2*r;
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");
    circled(x,y,xc,yc);
    while (x<y)
    {
        x++;
        if(dp<=0)
        {
            dp=dp+4*x+6;
        }
        else
        {
            y--;
            dp=dp+4*x-4*y+10;
        }
        circled(x,y,xc,yc);
    }
    getch();
    closegraph();
    
}

int main(int argc, char const *argv[])
{
    //midpoint(200,200,50);
    cbresenhams(200,200,50);
    return 0;
}
