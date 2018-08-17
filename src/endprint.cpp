#include <endprint.h>
#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <start_menu.h>

using namespace std;

int scan();
int lgame();

struct scores
{
    int score;
    char name[40];
};

void sortscore(scores nscore)
{
    scores s;
    ifstream iflow;
    iflow.open("scores.dat",ios::binary);
    ofstream oflow;
    oflow.open("temp.dat",ios::binary|ios::app);
    int flag = 0;
    while(!iflow.eof())
    {
        iflow.read((char*)&s,sizeof(s));
        if(nscore.score>=s.score)
        {
            oflow.write((char*)&nscore,sizeof(nscore));
            oflow.write((char*)&s,sizeof(s));
            flag = 1;
            break;
        }
        else
            oflow.write((char*)&s,sizeof(s));
    }
    if(flag == 0)
        oflow.write((char*)&nscore,sizeof(nscore));
    else
        if(!iflow.eof())
        {
            while(!iflow.eof())
            {
                iflow.read((char*)&s,sizeof(s));
                oflow.write((char*)&s,sizeof(s));
            }

        }
    oflow.close();
    iflow.close();
    remove("scores.dat");
    rename("temp.dat","scores.dat");
}

int endprint::ep(int &score, int &win_game)
{
    hit = ' ';
    int page;
    page = 0;
    cleardevice();
    strcpy(name,"");
    sprintf(points,"Your Score: %d",score);

    if(win_game == 0)
    {
        for(int i=0;i<31;i++)
        {
            delay(5);
            setcolor(COLOR(51, 204, 51));
            rectangle(10,10,830,660);

            setcolor(COLOR(255, 0, 102));
            settextstyle(10,HORIZ_DIR,6);
            outtextxy(300,70,"You Win!");

            setcolor(COLOR(153, 102, 255));
            outtextxy(130,190,points);

            settextstyle(10,HORIZ_DIR,4);
            outtextxy(130,270,"Enter Your Name:");

            settextstyle(10,HORIZ_DIR,4);

            setcolor(COLOR(0, 153, 255));

            outtextxy(180,535,"Main Menu");

            outtextxy(445,535,"Register Score!");

            setcolor(COLOR(51, 153, 255));

            if(GetAsyncKeyState(VK_LBUTTON))
            {

            }

            if(kbhit())
            {
                hit = getch();
                j = hit;
            }
                switch(j)
                {
                    case 97: name[i] = 'A';
                             break;
                    case 98: name[i] = 'B';
                             break;
                    case 99: name[i] = 'C';
                             break;
                    case 100: name[i] = 'D';
                              break;
                    case 101: name[i] = 'E';
                              break;
                    case 102: name[i] = 'F';
                              break;
                    case 103: name[i] = 'G';
                              break;
                    case 104: name[i] = 'H';
                              break;
                    case 105: name[i] = 'I';
                              break;
                    case 106: name[i] = 'J';
                              break;
                    case 107: name[i] = 'K';
                              break;
                    case 108: name[i] = 'L';
                              break;
                    case 109: name[i] = 'M';
                              break;
                    case 110: name[i] = 'N';
                              break;
                    case 111: name[i] = 'O';
                              break;
                    case 112: name[i] = 'P';
                              break;
                    case 113: name[i] = 'Q';
                              break;
                    case 114: name[i] = 'R';
                              break;
                    case 115: name[i] = 'S';
                              break;
                    case 116: name[i] = 'T';
                              break;
                    case 117: name[i] = 'U';
                              break;
                    case 118: name[i] = 'V';
                              break;
                    case 119: name[i] = 'W';
                              break;
                    case 120: name[i] = 'X';
                              break;
                    case 121: name[i] = 'Y';
                              break;
                    case 122: name[i] = 'Z';
                              break;
                    case 8: delay(10);
                            if(i > 0)
                            {
                                name[i-1] = '\0';
                                i-=1;
                            }
                            else
                                i=0;
                    default: --i;
                }

            settextstyle(10,HORIZ_DIR,4);
            outtextxy(440,270,name);
            hit = ' ';
            j = 0;

            k = scan();

            switch(k)
            {
                case 0:     return 2;
                case 320:  if(strcmp(name,"") != 0)
                            {
                                outtextxy(280,450,"Score Registered!");
                                scores s;
                                strcpy(s.name,name);
                                s.score = score;
                                sortscore(s);
                                i=31;
                                delay(200);
                            }
                            else
                            {
                                outtextxy(240,450,"Please Enter Your Name...");
                                setactivepage(page);
                                setvisualpage(1-page);
                            }
                            delay(250);
                            return 2;
            }

            setactivepage(page);
            setvisualpage(1-page);
            cleardevice();
            page=1-page;

        }
    }
    else
    {

        while(true)
        {
            if(GetAsyncKeyState(VK_LBUTTON))
            {
            }

            delay(1);
            setcolor(COLOR(51, 204, 51));
            rectangle(10,10,830,660);

            setcolor(COLOR(255, 0, 102));
            settextstyle(10,HORIZ_DIR,6);
            outtextxy(280,70,"You Lose!");

            setcolor(COLOR(153, 102, 255));
            outtextxy(130,190,points);

            settextstyle(10,HORIZ_DIR,4);

            setcolor(COLOR(0, 153, 255));
            outtextxy(180,535,"Main Menu");
            outtextxy(540,535,"Exit");

            ret = lgame();
            if(ret == 0 || ret == 2)
                return ret;

            setactivepage(page);
            setvisualpage(1-page);

            cleardevice();

            page=1-page;
        }

    }
}

int scan()
{
    for(int k=0;k<=320;k+=320)
        if(mousex() >=130+k && mousex() <=370+k && mousey() >= 530 && mousey() <= 570)
        {
            delay(1);
            setcolor(COLOR(255, 0, 0));
            switch(k)
            {
                case 0: outtextxy(180,535,"Main Menu");
                        break;

                case 320: outtextxy(445,535,"Register Score!");
                          break;
            }
            if(GetAsyncKeyState(VK_LBUTTON))
            {
              return k;
            }
        }
    return 321;
}

int lgame()
{
    for(int k=0,i=0;k<=370;k+=370,i+=280)
        if(mousex() >=130+k && mousex() <=370+i && mousey() >= 530 && mousey() <= 570)
        {
            delay(1);
            setcolor(COLOR(255, 0, 0));
            settextstyle(10,HORIZ_DIR,4);
            switch(k)
            {
                case 0: outtextxy(180,535,"Main Menu");
                        break;
                case 370: outtextxy(540,535,"Exit");
                          break;
            }
            if(GetAsyncKeyState(VK_LBUTTON))
            {
                switch(k)
                {
                    case 0: return 2;
                    case 370:  exit(0);
                }
            }

        }
    return 3;
}
