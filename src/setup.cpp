#include <setup.h>
#include <graphics.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <start_game.h>
#include <properties.h>

using namespace std;

setup::setup(int &score, int &lives, int pcd[], int &pass, int &v, double &dif, int &rscore, int &gp)
{
        rscore = 0;

        delay(1);

        settextstyle(BOLD_FONT,HORIZ_DIR,2);

        setcolor(COLOR(0,0,255));

///Outer Matrix
        int out_matrix[10] = {10,10,650,10,650,650,10,650,10,10};
        drawpoly(5,out_matrix);

///Inner Matrix
        //Top-1
        int t_matrix1[12] = {50,50,230,50,230,130,310,130,310,50,350,50};
        drawpoly(6,t_matrix1);
        //Top-2
        int t_matrix2[10] = {350,50,350,130,430,130,430,50,610,50};
        drawpoly(5,t_matrix2);

        //Right-1
        int r_matrix1[12] = {610,50,610,230,530,230,530,310,610,310,610,350};
        drawpoly(6,r_matrix1);
        //Right-2
        int r_matrix2[10] = {610,350,530,350,530,430,610,430,610,610};
        drawpoly(5,r_matrix2);

        //Bottom-1
        int b_matrix1[12] = {610,610,430,610,430,530,350,530,350,610,310,610};
        drawpoly(6,b_matrix1);
        //Bottom-2
        int b_matrix2[10] = {310,610,310,530,230,530,230,610,50,610};
        drawpoly(5,b_matrix2);

        //Left-1
        int l_matrix1[12] = {50,610,50,430,130,430,130,350,50,350,50,310};
        drawpoly(6,l_matrix1);
        //Left-2
        int l_matrix2[10] = {50,310,130,310,130,230,50,230,50,50};
        drawpoly(5,l_matrix2);

        rectangle(250,250,410,410);

        //Square1
        rectangle(90,90,190,190);
        //Square2
        rectangle(470,90,570,190);
        //Square3
        rectangle(470,470,570,570);
        //Square4
        rectangle(90,470,190,570);
        //Rectangle1
        rectangle(250,450,410,490);
        //Rectangle2
        rectangle(250,170,410,210);
        //Rectangle3
        rectangle(170,230,210,430);
        //Rectangle4
        rectangle(450,230,490,430);

        int way[8] = {300,410,300,300,360,300,360,410};
            drawpoly(4,way);

        if(gp == 0)
        {
            setcolor(0);
            line(300,410,360,410);
        }
        else
        {
            setcolor(COLOR(255, 0, 0));
            line(300,410,360,410);
            line(300,406,360,406);
            line(300,402,360,402);
        }

///Matrix-2
        setcolor(COLOR(0,0,255));
        rectangle(660,10,830,650);
        setcolor(COLOR(51, 204, 51));
        if(dif != 0)
        if(score == 0)
            rscore =0;
        else
            rscore = (score*1000)/25;
        //Score-Text
        sprintf(text,"Score: %d",rscore);
        outtextxy(680,30,text);

        //lives
        int l=0;
        setcolor(COLOR(204, 0, 153));
        outtextxy(680,60,"Lives:");
        for(int v=1;v<lives+1;v++)
        {
            setcolor(RED);
            circle(765+l,72,10);
            setfillstyle(SOLID_FILL,COLOR(255, 26, 26));
            floodfill(765+l,72,RED);
            l+=25;
        }

        //Save State
        setcolor(COLOR(204, 102, 255));
        rectangle(680,590,810,630);
        strcpy(text,"Save State");
        outtextxy(685,600,text);



        if(v%2)
            setcolor(COLOR(255, 51, 0));
        else
            setcolor(14);
        circle(685,100,5);
        setcolor(14);
        sprintf(text,": %d ",score);
        outtextxy(700,89,text);

        //gem
        setcolor(12);
        int gem[10] = {330,310,350,330,330,350,310,330,330,310};
        fillpoly(5,gem);
        if(v%4)
        {
            setcolor(15);
            int gem_w[10] = {330,310,346,330,330,350,350,330,330,310};
            setfillstyle(SOLID_FILL,15);
            fillpoly(5,gem_w);
        }

        //player
        setcolor(10);
        circle(pcd[0],pcd[1],15);
        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(pcd[0],pcd[1],10);
        setcolor(0);
        if(pass == 0)
        {
            line(pcd[0],pcd[1],pcd[0]+12,pcd[1]+10);
                    line(pcd[0],pcd[1],pcd[0]+13,pcd[1]-9);
                    circle(pcd[0]-3,pcd[1]-5,4);
                    setfillstyle(SOLID_FILL,BLACK);
                    floodfill(pcd[0]+5,pcd[1],0);
                    floodfill(pcd[0]-3,pcd[1]-5,0);
        }
        else
            if(pass==3)
                if(v%2 !=0)
                {
                    line(pcd[0],pcd[1],pcd[0]+11,pcd[1]+11);
                    line(pcd[0],pcd[1],pcd[0]+11,pcd[1]-11);
                    circle(pcd[0]-3,pcd[1]-5,4);
                    setfillstyle(SOLID_FILL,BLACK);
                    floodfill(pcd[0]+5,pcd[1],0);
                    floodfill(pcd[0]-3,pcd[1]-5,0);
                }
                else
                {
                    setfillstyle(SOLID_FILL,BLACK);
                    circle(pcd[0]-3,pcd[1]-5,4);
                    floodfill(pcd[0]-3,pcd[1]-5,0);
                }
        if(pass==2)
            if(v%2 != 0)
            {
                line(pcd[0],pcd[1],pcd[0]+11,pcd[1]+11);
                line(pcd[0],pcd[1],pcd[0]-11,pcd[1]+11);
                circle(pcd[0]-5,pcd[1]-3,4);
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(pcd[0],pcd[1]+2,0);
                floodfill(pcd[0]-5,pcd[1]-3,0);
            }
            else
            {
                setfillstyle(SOLID_FILL,BLACK);
                circle(pcd[0]-5,pcd[1]-3,4);
                floodfill(pcd[0]-5,pcd[1]-3,0);
            }
        if(pass==4)
            if(v%2 != 0)
            {
                line(pcd[0],pcd[1],pcd[0]-11,pcd[1]-11);
                line(pcd[0],pcd[1],pcd[0]-11,pcd[1]+11);
                setfillstyle(SOLID_FILL,BLACK);
                circle(pcd[0]+5,pcd[1]-3,4);
                floodfill(pcd[0]+5,pcd[1]-3,0);
                floodfill(pcd[0]-2,pcd[1],0);
            }
            else
            {
                setfillstyle(SOLID_FILL,BLACK);
                circle(pcd[0]+5,pcd[1]-3,4);
                floodfill(pcd[0]+5,pcd[1]-3,0);
            }
        if(pass==1)
        {
            if(v%2 != 0)
            {
                line(pcd[0],pcd[1],pcd[0]-11,pcd[1]-11);
                line(pcd[0],pcd[1],pcd[0]+11,pcd[1]-11);
                setfillstyle(SOLID_FILL,BLACK);
                circle(pcd[0]+5,pcd[1]+3,4);
                floodfill(pcd[0]+5,pcd[1]+3,0);
                floodfill(pcd[0],pcd[1]-3,0);
            }
            else
            {
                setfillstyle(SOLID_FILL,BLACK);
                circle(pcd[0]+5,pcd[1]+3,4);
                floodfill(pcd[0]+5,pcd[1]+3,0);
            }
        }

}
