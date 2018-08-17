#include <start_game.h>
#include <iostream>
#include <graphics.h>
#include <setup.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <controls.h>

using namespace std;

void checklives(int pcd[], int daemon[], int &lives, int &pass, int &i);

start_game::start_game()
{
    rscore =0;

    pcd[0] = 110;
    pcd[1] = 330;

    lives = 3;
    daemon[0] = 70;
    daemon[1] = 70;
    daemon[2] = 590;
    daemon[3] = 70;
    daemon[4] = 450;
    daemon[5] = 590;
    page=0;

    i = 0,score=0,v=0;

    pass = 0;

    gp = 1;

    dif = 1;

    win_game = 1;

    dpart[0] = 0;
    dpart[1] = 0;
    dpart[2] = 0;
}

int start_game::sg(int saved)
{
    if(saved == 1)
    {
        load();
    }

    controls *play;
    play = new controls;

    while(true)
    {
        if(i==1)
            time(&start);

        //settextstyle(BOLD_FONT,HORIZ_DIR,2);
        //call for coin function
        cs(i,score,xc,yc,pcd,check,ux,uy,oz);

        //Setup
        setup(score,lives,pcd,pass,v,dif,rscore,gp);

        //Save-State
        if(mousex()>= 680 && mousex() <=810 && mousey()>=590 && mousey()<=630)
        {
            char text[50];
            setcolor(COLOR(255,0,0));
            strcpy(text,"Save State");
            outtextxy(685,600,text);
            if(GetAsyncKeyState(VK_LBUTTON) != 0)
                save();
        }

        //daemon function
        dmns(daemon,pcd,v,dpart);

        if(check == 0)
            checklives(pcd,daemon,lives,pass,i);

        delay(25);

        //double buffering
        setactivepage(page);
        setvisualpage(1-page);

        //controls
        play->cntrl(pcd,i,score,daemon,pass,gp);
        cleardevice();

        v++;

        m = pcd[0]-10;
        n = pcd[1]-10;
        if(m%20 == 0 && n%20==0)
            ++i;

        delay(15);

        checklives(pcd,daemon,lives,pass,i);
        page = 1-page;

        if(i < 220 && i !=0)
        {
            time (&end);
            dif = difftime (end,start);
        }

        if(lives == 0)
        {
           break;
        }
         if(i == 221)
         {
             gp = 0;
         }
         if(pcd[0] == 330 && pcd[1] == 330)
        {
                win_game = 0;
                rscore += 1000;
                break;
        }
    }
    int x = ep(rscore,win_game);
    delete play;
    return x;
}

void checklives(int pcd[], int daemon[], int &lives, int &pass,int &i )
{
    for(int j=0, k=1; j<6 && k<7; j+=2, k+=2)
        if((daemon[j] == pcd[0] && daemon[k] == pcd[1]) || (daemon[j] == pcd[0]+10 && daemon[k] == pcd[1]) || (daemon[j] == pcd[0]-10 && daemon[k] == pcd[1]) || (daemon[j] == pcd[0] && daemon[k] == pcd[1]+10) || (daemon[j] == pcd[0] && daemon[k] == pcd[1] -10))
        {
            --lives;
            i++;
            pass = 0;
            pcd[0] = 110;
            pcd[1] = 330;
            break;
        }
}
