#include <start_menu.h>
#include <graphics.h>
#include <windows.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <start_game.h>
#include <locale>

using namespace std;

int menu_choice(int k);

struct scores
{
    int score;
    char name[40];
};

void optscan(char menu1[],string menu[],int &check, int &choice)
{
    for(int k=0;k<=320;k+=80)
        if( mousex() >= 130 && mousex() <= 330 && mousey() >= 190+k && mousey() <= 230+k)
        {
              setcolor(COLOR(255,51,0));
              switch(k)
              {
                    case 0: strcpy(menu1,menu[0].c_str());
                            outtextxy(120,195,menu1);
                            break;

                    case 80:  strcpy(menu1,menu[1].c_str());
                              outtextxy(120,275,menu1);
                              break;
                    case 160: strcpy(menu1,menu[2].c_str());
                              outtextxy(120,355,menu1);
                              break;
                    case 240: strcpy(menu1,menu[3].c_str());
                              outtextxy(120,435,menu1);
                              break;
                    case 320: strcpy(menu1,menu[4].c_str());
                              outtextxy(120,515,menu1);
                }
              if(GetAsyncKeyState(VK_LBUTTON))
               {
                   choice = menu_choice(k);
                   check = k;
                   delay(5);
               }
        }
}
void my_scores()
{
    setcolor(COLOR(255,51,0));

    scores s;

    ifstream iflow;
    iflow.open("scores.dat",ios::binary);

    int add=0,i=0;

    char score[8];

    settextstyle(BOLD_FONT,HORIZ_DIR,3);

    floodfill(530,210,COLOR(51, 187, 255));

    outtextxy(550,170,"High Score");

    while(iflow.read((char*)&s,sizeof(s)) && i<10)
    {
        setcolor(COLOR(255, 0, 102));
        outtextxy(480,210+add,s.name);
        sprintf(score,"%d",s.score);
        outtextxy(640,210+add,score);
        add+=35;
        i++;
    }
    iflow.close();

}

int start_menu::sm()
{
    int page=0;
    int choice = 1;

     string menu[5] = {"Start Game","Instructions","Credits","Scores","Load Save"};

     char menu1[20];

     scores s;

     int check = -1;
     char score[20];

     ifstream iflow;
     iflow.open("scores.dat",ios::binary);


    if(!iflow)
    {
        ofstream oflow;
        oflow.open("scores.dat",ios::binary|ios::app);
        s.score = 1000;
        strcpy(s.name,"Player");

        for(int i=0;i<10;i++)
        {
            oflow.write((char*)&s,sizeof(s));
        }
        oflow.close();
    }

    iflow.close();

    while(true)
    {
        cleardevice();

        setcolor(COLOR(51, 187, 255));

        rectangle(10,10,830,660);

        rectangle(90,150,370,590);

        rectangle(450,150,770,590);

        settextstyle(BOLD_FONT,HORIZ_DIR,5);

        setcolor(COLOR(255, 0, 102));
        outtextxy(300,60,"PACMAN!");

        setcolor(COLOR(255, 255, 0));

        settextstyle(BOLD_FONT,HORIZ_DIR,4);

        for(int i=0,j=0;i<=320,j<5;i+=80,j++)
        {
            strcpy(menu1,menu[j].c_str());
            outtextxy(120,195+i,menu1);
        }

        if(GetAsyncKeyState(VK_LBUTTON))
        {}
        delay(5);

        optscan(menu1,menu,check,choice);

        menu_choice(check);

        if(choice == 0)
        {
            return 1;
        }
        else
            if(choice == 2)
                return 0;

        setactivepage(page);

        setvisualpage(1-page);

        page = 1-page;

    }
    cleardevice();
}

int menu_choice(int k)
{
    setcolor(12);

    ifstream scores,names;

    int score[100],i=0,temp,check;

    char n[30],sch[8];

    string name[45],temps;

    string instruct[8] = {"The game is very simple","collect all the coins","to unlock the door","to the JEM!!","Collect all the objects","in minimum time","to make more score..","HAPPY GAMING!!"};

    string credits[5] = {"The game is designed","and written by","SAURABH KUMAR SURYAN...","CONCEPT FROM THE GAME","       PACMAN.."};

    setfillstyle(SOLID_FILL,BLACK);

    switch(k)
    {
        case 0: return 0;

        case 80:    settextstyle(BOLD_FONT,HORIZ_DIR,3);
                    floodfill(530,230,COLOR(51, 187, 255));
                    setcolor(COLOR(255, 51, 0));
                    outtextxy(530,170,"Instructions");
                    for(int j =0,y=0; j<8;j++,y+=30)
                    {
                        settextstyle(BOLD_FONT,HORIZ_DIR,2);
                        setcolor(COLOR(210, 77, 255));
                        strcpy(n,instruct[j].c_str());
                        if(j == 7)
                            y+=20;
                        outtextxy(470,210+y,n);
                    }
                    break;

        case 160:   settextstyle(BOLD_FONT,HORIZ_DIR,3);
                    floodfill(530,230,COLOR(51, 187, 255));
                    setcolor(COLOR(255, 51, 0));
                    outtextxy(555,170,"Credits");
                    for(int j =0,y=0; j<5;j++,y+=30)
                    {
                        settextstyle(BOLD_FONT,HORIZ_DIR,2);
                        setcolor(COLOR(77, 121, 255));
                        strcpy(n,credits[j].c_str());

                        if(j == 3)
                            y+=20;
                        outtextxy(470,210+y,n);
                    }
                    break;

        case 240: my_scores();
                    break;

        case 320: return 2;

    }
}

