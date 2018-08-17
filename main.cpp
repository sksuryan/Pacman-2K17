#include <iostream>
#include <graphics.h>
#include <start_menu.h>
#include <start_game.h>
#include <process.h>
#include <fstream>
#include <properties.h>

using namespace std;

void loading();
void splash();

int main()
{
    int for_return = 2,saved = 0;
    ifstream fin;
    start_game *s;
    start_menu *start;
    initwindow(850,680,"Pacman",50,50);
    splash();
    while(true)
    {
        saved = 0;
        if(for_return == 2)
        {
            start = new start_menu;
            for_return = start->sm();
        }
        if(for_return == 1)
        {
            s = new start_game;
            for_return = s->sg(saved);
            delete s;
        }
        if(for_return == 0)
        {
            saved = 1;
            s = new start_game;
            for_return = s->sg(saved);
            delete s;
        }
        loading();
    }
    system("PAUSE");
    closegraph();
    return 0;
}

void loading()
{
    cleardevice();
    char load[11] = "Loading";
    settextstyle(9,HORIZ_DIR,2);
    int page = 0;
    outtextxy(350,340,load);
    setactivepage(page);
    for(int i = 0,k=7; i<3;i++,k++)
    {
        cleardevice();
        load[k] = '.';
        load[k+1] = '\0';
        setvisualpage(page);

        outtextxy(350,340,load);
        setactivepage(1-page);

        delay(1500);
        page = 1 - page;
    }
    cleardevice();
}

void splash()
{

    int page =0;

    for(int i=0,j=0;i<610;i+=20,j++)
    {
         setcolor(COLOR(0, 204, 0));
         rectangle(10,10,830,660);

         setcolor(COLOR(255, 51, 153));
         settextstyle(10,HORIZ_DIR,6);
         outtextxy(315,70,"Pacman!");

         setcolor(14);

         circle(90+i,470,40);

         setfillstyle(SOLID_FILL,COLOR(255, 255, 0));

         floodfill(85+i,470,14);

         circle(170+i,470,20);

         setfillstyle(SOLID_FILL,COLOR(255, 51, 0));

         floodfill(165+i,470,14);


         if(j%2 == 0)
         {
             setcolor(0);
             line(90+i,470,90+i+41,470+41);
             line(90+i,470,90+i+41,470-41);
             setfillstyle(SOLID_FILL,BLACK);
             floodfill(90+i+5,470,0);
         }
         delay(100);

        if(90+i==690)
        {
            setcolor(COLOR(102, 153, 255));
            settextstyle(10,HORIZ_DIR,3);
            outtextxy(250,570,"PRESS SPACE TO CONTINUE!!!");
        }

        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        page = 1-page;
    }

    getch();
    cleardevice();
    setactivepage(page);
    setvisualpage(1-page);
}
