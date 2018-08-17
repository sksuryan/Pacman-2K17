#include <daemons.h>
#include <graphics.h>
#include <iostream>
#include <stdio.h>

void move1(int daemon[6],int &j, int &k)
{
	if(daemon[k] == 70 && daemon[j] >=70 && daemon[j]<210)
    daemon[j] +=10;
    else
    if(daemon[j] == 210 && daemon[k]<210)
    daemon[k] +=10;
    else
    if(daemon[k] == 210 && daemon[j]>70)
    daemon[j] -=10;
    else
    if(daemon[j] == 70 && daemon[k]>70)
    daemon[k] -=10;
}

void move2(int daemon[6], int &j, int &k)
{
	if(daemon[k] == 70 && daemon[j] >=450 && daemon[j]<590)
    daemon[j] +=10;
    else
    if(daemon[j] == 590 && daemon[k]<210)
    daemon[k] +=10;
    else
    if(daemon[k] == 210 && daemon[j]>450)
    daemon[j] -=10;
    else
    if(daemon[j] == 450 && daemon[k]>70)
    daemon[k] -=10;
}

void move3(int daemon[6],int &j,int &k)
{
	if(daemon[k] == 450 && daemon[j] >=450 && daemon[j]<590)
    daemon[j] +=10;
    else
    if(daemon[j] == 590 && daemon[k]<590)
    daemon[k] +=10;
    else
    if(daemon[k] == 590 && daemon[j]>450)
    daemon[j] -=10;
    else
    if(daemon[j] == 450 && daemon[k]>450)
    daemon[k] -=10;
}

void move4(int daemon[6], int &j,int &k)
{
	if(daemon[k] == 450 && daemon[j] >=70 && daemon[j]<210)
    daemon[j] +=10;
    else
    if(daemon[j] == 210 && daemon[k]<590)
    daemon[k] +=10;
    else
    if(daemon[k] == 590 && daemon[j]>70)
    daemon[j] -=10;
    else
    if(daemon[j] == 70 && daemon[k]>450)
    daemon[k] -=10;
}

void move5(int daemon[6], int &j ,int &k)
{
	if(daemon[k] == 230 && daemon[j] >=230 && daemon[j]<430)
    daemon[j] +=10;
    else
    if(daemon[j] == 430 && daemon[k]<430)
    daemon[k] +=10;
    else
    if(daemon[k] == 430 && daemon[j]>230)
    daemon[j] -=10;
    else
    if(daemon[j] == 230 && daemon[k]>230)
    daemon[k] -=10;
}

void find_player(int pcd[], int &part)
{
    if(pcd[0]>=70 && pcd[0] <= 210 && pcd[1]>=70 && pcd[1]<=210 || pcd[0]>=210 && pcd[0] <= 250 && pcd[1]>=130 && pcd[1]<=220)
        part = 1;
    else
    if(pcd[0]>=450 && pcd[0] <= 590 && pcd[1]>=70 && pcd[1]<=210 || pcd[0]>=410 && pcd[0] <= 450 && pcd[1]>=130 && pcd[1]<=220)
        part = 2;
    else
    if(pcd[0]>=450 && pcd[0] <= 590 && pcd[1]>=450 && pcd[1]<=590 || pcd[0]>=410 && pcd[0] <= 450 && pcd[1]>=440 && pcd[1]<=530)
        part = 3;
    else
    if(pcd[0]>=70 && pcd[0] <= 210 && pcd[1]>=450 && pcd[1]<=590 || pcd[0]>=210 && pcd[0] <= 250 && pcd[1]>=440 && pcd[1]<=530)
        part = 4;
    else
    if(pcd[0]>=230 && pcd[0]<=430 && pcd[1] >=230 && pcd[1]<=430)
        part = 5;
    else
    if(pcd[0] == 150 && pcd[1] >= 220 && pcd[1] <= 440 || pcd[0] >= 50 && pcd[0] <=140 && pcd[1] >= 310 && pcd[1] <= 350)
        part = 6;
    else
    if(pcd[0] == 510 && pcd[1] >= 220 && pcd[1] <= 440 || pcd[0] >= 520 && pcd[0] <=610 && pcd[1] >= 310 && pcd[1] <= 350)
        part = 7;
    else
    if(pcd[1] == 150 && pcd[0] >= 220 && pcd[0] <= 440 || pcd[1] >= 50 && pcd[1] <=140 && pcd[0] >= 310 && pcd[0] <= 350)
        part = 8;
    else
    if(pcd[1] == 510 && pcd[0] >= 220 && pcd[0] <= 440 || pcd[1] >= 520 && pcd[1] <=610 && pcd[0] >= 310 && pcd[0] <= 350)
        part = 9;
}

void daemon_ground(int daemon[], int &j,int &k, int &dpart)
{
    if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
        dpart = 1;
    else
    if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
        dpart = 2;
    else
    if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
        dpart = 3;
    else
    if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
        dpart = 4;
    else
    if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
        dpart = 5;
}

void elses(int daemon[],int &j, int &k)
{
    if(daemon[j] == 150 && daemon[k] >= 220 && daemon[k] <= 440)
        daemon[k] += 10;
    else
    if(daemon[j] == 510 && daemon[k] >= 220 && daemon[k] <= 440)
        daemon[k] -= 10;
    else
    if(daemon[k] == 510 && daemon[j] >= 220 && daemon[j] <= 440)
        daemon[j] -= 10;
    else
    if(daemon[k] == 150 && daemon[j] >= 220 && daemon[j] <= 440)
        daemon[j] += 10;
    else
    if(daemon[j]>210 && daemon[j] <= 250 && daemon[k]>=160 && daemon[k] <= 220 || daemon[j]>410 && daemon[j] < 450 && daemon[k]>=160 && daemon[k] <= 220)
       daemon[k] -=10;
    else
    if(daemon[j]>210 && daemon[j] <= 250 && daemon[k]>=440 && daemon[k] <= 500 || daemon[j]>410 && daemon[j] < 450 && daemon[k]>=440 && daemon[k] <= 500)
       daemon[k] +=10;
}

void daemons::dmns(int daemon[], int pcd[], int &v, int dpart[])
{
    setcolor(COLOR(242,242,242));
    part=0;
    for(int j=0,k=1;j<8 && k<7;j+=2,k+=2)
    {
        circle(daemon[j], daemon[k],10);
        circle(daemon[j]-3,daemon[k]-2,2);
        circle(daemon[j]+3,daemon[k]-2,2);
        arc(daemon[j], daemon[k]+2,220,330,4);
    }
    int r[4] = {163,0,102},g[4]={102,204,153},b[4]={255,102,255},c=0;

    for(int j=0,k=1;j<8 && k<7;j+=2,k+=2,c++)
    {
        setfillstyle(SOLID_FILL,COLOR(r[c],g[c],b[c]));
        floodfill(daemon[j], daemon[k],COLOR(242,242,242));
        if(v%2 == 1)
            setfillstyle(SOLID_FILL,WHITE);
        else
            setfillstyle(SOLID_FILL,BLACK);
        floodfill(daemon[j]-3,daemon[k]-2,COLOR(242,242,242));
        floodfill(daemon[j]+3,daemon[k]-2,COLOR(242,242,242));
    }

    find_player(pcd,part);

    for(int j=0,k=1,c=0;c<3;j+=2,k+=2,c++)
    {
        daemon_ground(daemon,j,k,dpart[c]);
        //For 1
        if(part == 1)
        {
            //From 1
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
            {
                move1(daemon,j,k);
            }
            else
            //From 2
            if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 150)
                daemon[j] -=10;
            else
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 450 && daemon[k] == 150)
                    daemon[j] -= 10;
                else
                {
                    move2(daemon,j,k);
                }
            }
            else
            //From 3
            if(daemon[j] == 440 && daemon[k] == 450)
                daemon[j] -= 10;
            else
            if(daemon[k]>430 && daemon[k] <= 510 && daemon[j] == 430)
                daemon[k] -=10;
            else
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 450 && daemon[k] == 450)
                    daemon[j] -= 10;
                else
                {
                    move3(daemon,j,k);
                }
            }
            else
            //From 4
            if(daemon[k]>=220 && daemon[k] < 450 && daemon[j] == 150)
                daemon[k] -=10;
            else
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 150 && daemon[k] == 450)
                    daemon[k] -=10;
                else
                {
                    move4(daemon,j,k);
                }
            }
            else
            //From 5
            if(daemon[j] == 230 && daemon[k] > 150 && daemon[k] <230)
                daemon[k] -= 10;
            else
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                if(daemon[j] == 230 && daemon[k] == 230)
                    daemon[k]-=10;
                else
                {
                    move5(daemon,j,k);
                }
            }
            else
                elses(daemon,j,k);

        }
        //For 2
        else
        if(part == 2 && dpart[c] > 0 && dpart[c] < 6)
        {
            //From 1
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 210 && daemon[k] == 150)
                    daemon[j] += 10;
                else
                {
                    move1(daemon,j,k);
                }
            }
            else
            if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 150)
                daemon[j] +=10;
            else
            //From 2
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                move2(daemon,j,k);
            }
            else
            //From 3
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 510 && daemon[k] == 450)
                    daemon[k] -= 10;
                else
                {
                    move3(daemon,j,k);
                }
            }
            else
            if(daemon[k]>=220 && daemon[k] <= 440 && daemon[j] == 510)
                daemon[k] -=10;
            else
            //From 4
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
            {

                if(daemon[j] == 210 && daemon[k] == 510)
                    daemon[j] +=10;
                else
                {
                    move4(daemon,j,k);
                }
            }
            else
            if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 510)
                daemon[j] +=10;
            else
            //From 5
            if(daemon[j] == 430 && daemon[k]>150 && daemon[k] <= 220)
                daemon[k]-=10;
            else
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                if(daemon[j] == 430 && daemon[k] == 230)
                    daemon[k]-=10;
                else
                {
                    move5(daemon,j,k);
                }
            }
            else
                elses(daemon,j,k);
        }
        //For 3
        else
        if(part == 3 && dpart[c] > 0 && dpart[c] < 6)
        {
            //From 1
            if(daemon[j] == 220 && daemon[k] == 150)
                daemon[j] += 10;
            else
            if(daemon[j] == 230 && daemon[k] >= 150 && daemon[k] <230)
                daemon[k] += 10;
            else
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 210 && daemon[k] == 150)
                    daemon[j] += 10;
                else
                {
                    move1(daemon,j,k);
                }
            }
            else
            //From 2
            if(daemon[k]>=220 && daemon[k] <= 440 && daemon[j] == 510)
                daemon[k] +=10;
            else
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 510 && daemon[k] == 210)
                    daemon[k]+=10;
                else
                {
                    move2(daemon,j,k);
                }
            }
            else
            //From 3
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
            {
                move3(daemon,j,k);
            }
            //From 4
            else
            if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 510)
                daemon[j] +=10;
            else
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 210 && daemon[k] == 510)
                    daemon[j] +=10;
                else
                {
                    move4(daemon,j,k);
                }
            }
            else
            //From 5
            if(daemon[j] == 430 && daemon[k]<510 && daemon[k] >= 430)
                daemon[k]+=10;
            else
            if(daemon[j] == 430 && daemon[k]<510 && daemon[k] >= 430)
                daemon[k]+=10;
            else
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                if(daemon[j] == 430 && daemon[k] == 430)
                    daemon[k]+=10;
                else
                {
                    move5(daemon,j,k);
                }
            }
            else
                elses(daemon,j,k);
        }
        //For 4
        else
        if(part == 4 && dpart[c] > 0 && dpart[c] < 6)
        {
            //From 1
            if(daemon[k]>=220 && daemon[k] < 450 && daemon[j] == 150)
                daemon[k] +=10;
            else
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 150 && daemon[k] == 210)
                    daemon[k] += 10;
                else
                {
                    move1(daemon,j,k);
                }
            }
            else
            //From 2
            if(daemon[j] == 440 && daemon[k] == 210)
                daemon[j] -= 10;
            else
            if(daemon[j] == 430 && daemon[k] >= 150 && daemon[k] <230)
                daemon[k] += 10;
            else
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 450 && daemon[k] == 210)
                    daemon[j] -=10;
                else
                {
                    move2(daemon,j,k);
                }
            }
            else
            //From 3
            if(daemon[j]>=220 && daemon[j] <= 440 && daemon[k] == 510)
                daemon[j] -=10;
            else
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 450 && daemon[k] == 510)
                    daemon[j] -= 10;
                else
                {
                    move3(daemon,j,k);
                }
            }
            else
            //From 4
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
            {
                move4(daemon,j,k);
            }
            else
            //From 5
            if(daemon[j] == 230 && daemon[k]>=440 && daemon[k] < 510)
                daemon[k]+=10;
            else
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                if(daemon[j] == 230 && daemon[k] == 430)
                    daemon[k]+=10;
                else
                {
                    move5(daemon,j,k);
                }
            }
            else
                elses(daemon,j,k);
        }
        //For 5
        else
        if(part == 5 && dpart[c] > 0 && dpart[c] < 6)
        {
            //From 1
            if(daemon[j] == 220 && daemon[k] == 150)
                daemon[j] += 10;
            else
            if(daemon[j] == 230 && daemon[k] >= 150 && daemon[k] <230)
                daemon[k] += 10;
            else
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 210 && daemon[k] == 150)
                    daemon[j] += 10;
                else
                {
                    move1(daemon,j,k);
                }
            }
            else
            //From 2
            if(daemon[j] == 440 && daemon[k] == 210)
                daemon[j] -= 10;
            else
            if(daemon[j] == 430 && daemon[k] >= 150 && daemon[k] <230)
                daemon[k] += 10;
            else
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 450 && daemon[k] == 210)
                    daemon[j] -=10;
                else
                {
                    move2(daemon,j,k);
                }
            }
            else
            //From 3
            if(daemon[j] == 440 && daemon[k] == 450)
                    daemon[j] -= 10;
            else
            if(daemon[k]>430 && daemon[k] <= 510 && daemon[j] == 430)
                daemon[k] -=10;
            else
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 450 && daemon[k] == 450)
                    daemon[j] -= 10;
                else
                {
                    move3(daemon,j,k);
                }
            }
            else
            //From 4
            if(daemon[j] == 220 && daemon[k] == 450)
                daemon[j] +=10;
            else
            if(daemon[j] == 230 && daemon[k] <= 510 && daemon[k] >430)
                daemon[k] -= 10;
            else
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 210 && daemon[k] == 450)
                    daemon[j] +=10;
                else
                {
                    move4(daemon,j,k);
                }
            }
            else
            //From 5
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                move5(daemon,j,k);
            }
            else
                elses(daemon,j,k);
        }
        else
        // Left Vertical
        if(part == 6)
        {
            if(dpart[c] == 1)
            {
                if(daemon[j] == 150 && daemon[k] == 210)
                    daemon[k] += 10;
                else
                if(daemon[j] == 150 && daemon[k] >= 220 && daemon[k] <= 440)
                    daemon[k] += 10;
                else
                if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
                {
                    move1(daemon,j,k);
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 4)
            {
                if(daemon[j] == 150 && daemon[k] == 450)
                    daemon[k] -= 10;
                else
                if(daemon[j] == 150 && daemon[k] >= 220 && daemon[k] <= 440)
                    daemon[k] -= 10;
                else
                if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
                {
                    move4(daemon,j,k);
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 5)
            {
                if(daemon[j] == 230 && daemon[k] > 150 && daemon[k] <230)
                    daemon[k] -= 10;
                else
                if(daemon[j] == 230 && daemon[k]>=440 && daemon[k] < 510)
                    daemon[k]+=10;
                else
                if(daemon[k] == 510 && daemon[j] >= 220 && daemon[j] <= 440)
                    daemon[j] -= 10;
                else
                if(daemon[k] == 150 && daemon[j] >= 220 && daemon[j] <= 440)
                    daemon[j] -= 10;
                else
                if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
                {
                    if(daemon[j] == 230 && daemon[k] == 230)
                        daemon[k]-=10;
                    else
                        if(daemon[j] == 230 && daemon[k] == 430)
                            daemon[k]+=10;
                        else
                        {
                            move5(daemon,j,k);
                        }
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 2)
            {
             	if(daemon[j] == 440 && daemon[k] == 210)
                daemon[j] -= 10;
	            else
	            if(daemon[j] == 430 && daemon[k] >= 150 && daemon[k] <230)
	                daemon[k] += 10;
	            else
	            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
	            {
	                if(daemon[j] == 450 && daemon[k] == 210)
	                    daemon[j] -=10;
	                else
	                {
	                    move2(daemon,j,k);
	                }
	            }
	            else
            	elses(daemon,j,k);
            }
            else
            if(dpart[c] == 3)
            {
            	if(daemon[j] == 440 && daemon[k] == 450)
                daemon[j] -= 10;
	            else
	            if(daemon[k]>430 && daemon[k] <= 510 && daemon[j] == 430)
	                daemon[k] -=10;
	            else
	            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
	            {
	                if(daemon[j] == 450 && daemon[k] == 450)
	                    daemon[j] -= 10;
	                else
	                {
	                    move3(daemon,j,k);
	                }
	            }
	            else
            	elses(daemon,j,k);
            }
        }
        else
        //Right Vertical
        if(part == 7)
        {
            if(dpart[c] == 2)
            {
                if(daemon[j] == 510 && daemon[k] == 210)
                    daemon[k]+=10;
                else
                if(daemon[k]>=220 && daemon[k] <= 440 && daemon[j] == 510)
                    daemon[k] +=10;
                else
                    if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
                    {
                        move2(daemon,j,k);
                    }
            }
            else
            if(dpart[c] == 3)
            {
                if(daemon[k]>=220 && daemon[k] <= 440 && daemon[j] == 510)
                    daemon[k] -=10;
                else
                if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
                {
                    if(daemon[j] == 510 && daemon[k] == 450)
                        daemon[k] -= 10;
                    else
                    {
                        move3(daemon,j,k);
                    }
                }
            }
            else
            if(dpart[c] == 5)
            {
                if(daemon[j] == 430 && daemon[k]<510 && daemon[k] >= 430)
                    daemon[k]+=10;
                else
                if(daemon[k] == 510 && daemon[j] >= 220 && daemon[j] <= 440)
                    daemon[j] += 10;
                else
                if(daemon[k] == 150 && daemon[j] >= 220 && daemon[j] <= 440)
                    daemon[j] += 10;
                else
                if(daemon[j] == 430 && daemon[k]>150 && daemon[k] <= 220)
                    daemon[k]-=10;
                else
                if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
                {
                    if(daemon[j] == 430 && daemon[k] == 430)
                        daemon[k]+=10;
                    else
                        if(daemon[j] == 430 && daemon[k] == 230)
                            daemon[k]-=10;
                        else
                        {
                            move5(daemon,j,k);
                        }
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 1)
            {
            	if(daemon[j] == 220 && daemon[k] == 150)
                daemon[j] += 10;
	            else
	            if(daemon[j] == 230 && daemon[k] >= 150 && daemon[k] <230)
	                daemon[k] += 10;
	            else
	            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
	            {
	                if(daemon[j] == 210 && daemon[k] == 150)
	                    daemon[j] += 10;
	                else
	                {
	                    move1(daemon,j,k);
	                }
	            }
	            else
            	elses(daemon,j,k);
            }
            else
            if(dpart[c] == 4)
            {
            	if(daemon[j] == 220 && daemon[k] == 450)
                daemon[j] +=10;
	            else
	            if(daemon[j] == 230 && daemon[k] <= 510 && daemon[k] >430)
	                daemon[k] -= 10;
	            else
	            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
	            {
	                if(daemon[j] == 210 && daemon[k] == 450)
	                    daemon[j] +=10;
	                else
	                {
	                    move4(daemon,j,k);
	                }
	            }
	            else
            	elses(daemon,j,k);
            }
        }
        else
        //Top Horizontal
        if(part == 8)
        {
            if(dpart[c] == 1)
            {
                if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 150)
                    daemon[j] +=10;
                else
                if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
                {
                    if(daemon[j] == 210 && daemon[k] == 150)
                        daemon[j] += 10;
                    else
                    {
                        move1(daemon,j,k);
                    }
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 2)
            {
                if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 150)
                    daemon[j] -=10;
                else
                if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
                {
                    if(daemon[j] == 450 && daemon[k] == 150)
                        daemon[j] -= 10;
                    else
                    {
                        move2(daemon,j,k);
                    }
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 5)
            {
                if(daemon[j] == 430 && daemon[k]>150 && daemon[k] <= 220)
                {
                    daemon[k]-=10;
                    if(daemon[k] == 150)
                        dpart[c] = 2;
                }
                else
                if(daemon[j] == 230 && daemon[k] > 150 && daemon[k] <230)
                {
                    daemon[k] -= 10;
                    if(daemon[k] == 150)
                        dpart[c] = 1;
                }
                else
                if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
                {
                    if(daemon[j] == 430 && daemon[k] == 230)
                        daemon[k]-=10;
                    else
                        if(daemon[j] == 230 && daemon[k] == 230)
                            daemon[k]-=10;
                        else
                        {
                            move5(daemon,j,k);
                        }
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 3)
            {
            	if(daemon[j] == 440 && daemon[k] == 450)
                    daemon[j] -= 10;
	            else
	            if(daemon[k]>430 && daemon[k] <= 510 && daemon[j] == 430)
	                daemon[k] -=10;
	            else
	            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
	            {
	                if(daemon[j] == 450 && daemon[k] == 450)
	                    daemon[j] -= 10;
	                else
	                {
	                    move3(daemon,j,k);
	                }
	            }
	            else
            	elses(daemon,j,k);
            }
            else
            if(dpart[c] == 4)
            {
            	if(daemon[j] == 220 && daemon[k] == 450)
                daemon[j] +=10;
	            else
	            if(daemon[j] == 230 && daemon[k] <= 510 && daemon[k] >430)
	                daemon[k] -= 10;
	            else
	            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
	            {
	                if(daemon[j] == 210 && daemon[k] == 450)
	                    daemon[j] +=10;
	                else
	                {
	                    move4(daemon,j,k);
	                }
	            }
	            else
            	elses(daemon,j,k);
            }
        }
        else
        //Bottom Horizontal
        if(part == 9)
        {
            if(dpart[c] == 4)
            {
                if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 510)
                    daemon[j] +=10;
                else
                if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
                {
                    if(daemon[j] == 210 && daemon[k] == 510)
                        daemon[j] +=10;
                    else
                    {
                        move4(daemon,j,k);
                    }
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 3)
            {
                if(daemon[j]>=220 && daemon[j] <= 440 && daemon[k] == 510)
                daemon[j] -=10;
                else
                if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
                {
                    if(daemon[j] == 450 && daemon[k] == 510)
                        daemon[j] -= 10;
                    else
                    {
                        move3(daemon,j,k);
                    }
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 5)
            {
                if(daemon[j] == 230 && daemon[k]>=440 && daemon[k] < 510)
                {
                    daemon[k]+=10;
                    if(daemon[k] == 510)
                        dpart[c] = 4;
                }
                else
                if(daemon[j] == 430 && daemon[k]<510 && daemon[k] >= 430)
                {
                    daemon[k]+=10;
                    if(daemon[k] == 510)
                        dpart[c] = 3;
                }
                else
                if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
                {
                    if(daemon[j] == 230 && daemon[k] == 430)
                        daemon[k]+=10;
                    else
                        if(daemon[j] == 430 && daemon[k] == 430)
                            daemon[k]+=10;
                        else
                        {
                            move5(daemon,j,k);
                        }
                }
                else
                elses(daemon,j,k);
            }
            else
            if(dpart[c] == 1)
            {
            	if(daemon[j] == 220 && daemon[k] == 150)
                daemon[j] += 10;
	            else
	            if(daemon[j] == 230 && daemon[k] >= 150 && daemon[k] <230)
	                daemon[k] += 10;
	            else
	            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
	            {
	                if(daemon[j] == 210 && daemon[k] == 150)
	                    daemon[j] += 10;
	                else
	                {
	                    move1(daemon,j,k);
	                }
	            }
	            else
            	elses(daemon,j,k);
            }
            else
            if(dpart[c] == 2)
            {
            	if(daemon[j] == 440 && daemon[k] == 210)
                daemon[j] -= 10;
	            else
	            if(daemon[j] == 430 && daemon[k] >= 150 && daemon[k] <230)
	                daemon[k] += 10;
	            else
	            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
	            {
	                if(daemon[j] == 450 && daemon[k] == 210)
	                    daemon[j] -=10;
	                else
	                {
	                    move2(daemon,j,k);
	                }
	            }
	            else
            	elses(daemon,j,k);
            }
        }
        else
        elses(daemon,j,k);
    }

    if((daemon[0] == daemon[2] && daemon[1] == daemon[3]) || (daemon[0] == daemon[2]+10 && daemon[1] == daemon[3]) || (daemon[0] == daemon[2]-10 && daemon[1] == daemon[3]) || (daemon[0] == daemon[2] && daemon[1] == daemon[3]+10) || (daemon[0] == daemon[2] && daemon[1] == daemon[3]-10))
    {
        daemon[0] = 70;
        daemon[1] = 70;
    }
    else
    if((daemon[4] == daemon[2] && daemon[5] == daemon[3]) || (daemon[4] == daemon[2]+10 && daemon[5] == daemon[3]) || (daemon[4] == daemon[2]-10 && daemon[5] == daemon[3]) || (daemon[4] == daemon[2] && daemon[5] == daemon[3]+10) || (daemon[4] == daemon[2] && daemon[5] == daemon[3]-10))
    {
        daemon[2] = 590;
        daemon[3] = 70;
    }
    else
    if((daemon[0] == daemon[4] && daemon[1] == daemon[5]) || (daemon[0] == daemon[4]+10 && daemon[1] == daemon[5]) || (daemon[0] == daemon[4]-10 && daemon[1] == daemon[5]) || (daemon[0] == daemon[4] && daemon[1] == daemon[5]+10) || (daemon[0] == daemon[4] && daemon[1] == daemon[5]-10))
    {
        daemon[4] = 590;
        daemon[5] = 590;
    }
}
