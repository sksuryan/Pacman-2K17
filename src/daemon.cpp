#include <daemons.h>
#include <graphics.h>
#include <iostream>

void move1(int daemon[6],int j, int k)
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

void move2(int daemon[6], int j, int k)
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

void move3(int daemon[6],int j,int k)
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

void move4(int daemon[6], int j,int k)
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

void move5(int daemon[6], int j ,int k)
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

void blankcheck(int pcd[],int daemon[],int j,int k,int &finder)
{
	if(pcd[0] == 150 && pcd[1] >= 220 && pcd[1] <= 440 && daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
		finder = 1;
	else
	if(finder == 0 && pcd[0] == 150 && pcd[1] >= 220 && pcd[1] <= 440 && daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
		finder = 2;
	else
	if(pcd[0] == 510 && pcd[1] >= 220 && pcd[1] <= 440 && daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
		finder = 3;
	else
	if(finder == 0 && pcd[0] == 510 && pcd[1] >= 220 && pcd[1] <= 440 && daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
		finder = 4;
	else
	if(pcd[1] == 150 && pcd[0] >= 220 && pcd[0] <= 440 && daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
		finder = 5;
	else
	if(finder == 0 && pcd[1] == 150 && pcd[0] >= 220 && pcd[0] <= 440 && daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
		finder = 6;
	else
	if(pcd[1] == 510 && pcd[0] >= 220 && pcd[0] <= 440 && daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[j]<=590)
		finder = 7;
	else
	if(finder == 0 && pcd[1] == 510 && pcd[0] >= 220 && pcd[0] <= 440 && daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
		finder = 8;
	else
	if(finder == 0 && pcd[0] == 150 && pcd[1] >= 220 && pcd[1] <= 440 && daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
		finder = 9;
	else
	if(finder == 0 && pcd[0] == 510 && pcd[1] >= 220 && pcd[1] <= 440 && daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
		finder = 10;
}

daemons::daemons(int daemon[], int &i, int pcd[], int v, int dpart[])
{

	setcolor(WHITE);
	part=0;
	for(int j=0,k=1;j<8 && k<7;j+=2,k+=2)
	{
		circle(daemon[j], daemon[k],10);
        circle(daemon[j]-3,daemon[k]-2,2);
        circle(daemon[j]+3,daemon[k]-2,2);
        arc(daemon[j], daemon[k]+2,220,330,4);
	}
	int r[4] = {163,204,0},g[4]={102,0,51},b[4]={255,102,102},c=0;

	for(int j=0,k=1;j<8 && k<7;j+=2,k+=2,c++)
    {
        setfillstyle(SOLID_FILL,COLOR(r[c],g[c],b[c]));
        floodfill(daemon[j], daemon[k],WHITE);
        if(v%2 == 1)
            setfillstyle(SOLID_FILL,WHITE);
        else
            setfillstyle(SOLID_FILL,BLACK);
        floodfill(daemon[j]-3,daemon[k]-2,WHITE);
        floodfill(daemon[j]+3,daemon[k]-2,WHITE);
    }



    if(pcd[0]>=70 && pcd[0] <= 210 && pcd[1]>=70 && pcd[1]<=210)
    	part = 1;
    else
    	if(pcd[0]>=450 && pcd[0] <= 590 && pcd[1]>=70 && pcd[1]<=210)
    		part = 2;
    	else
    		if(pcd[0]>=450 && pcd[0] <= 590 && pcd[1]>=450 && pcd[1]<=590)
    			part = 3;
    		else
    			if(pcd[0]>=70 && pcd[0] <= 210 && pcd[1]>=450 && pcd[1]<=590)
    				part = 4;
    			else
    				if(pcd[0]>=230 && pcd[0]<=430 && pcd[1] >=230 && pcd[1]<=430)
    					part = 5;


    for(int j=0,k=1;j<8 && k<7;j+=2,k+=2)
    {
    	blankcheck(pcd,daemon,j,k,finder);
    	//std::cout<<finder;
        //For 1
        if(part == 1)
        {
            finder = 0;
            //From 1
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
            {
                move1(daemon,j,k);
            }
            //From 2
            if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 150)
                daemon[j] -=10;
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 450 && daemon[k] == 150)
                    daemon[j] -= 10;
                else
                {
                    move2(daemon,j,k);
                }
            }
            //From 3
            if(daemon[j] == 440 && daemon[k] == 450)
                daemon[j] -= 10;
            if(daemon[k]>430 && daemon[k] <= 510 && daemon[j] == 430)
                daemon[k] -=10;
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 450 && daemon[k] == 450)
                    daemon[j] -= 10;
                else
                {
                    move3(daemon,j,k);
                }
            }
            //From 4
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 150 && daemon[k] == 450)
                    daemon[k] -=10;
                else
                {
                    move4(daemon,j,k);
                }
            }
            if(daemon[k]>=220 && daemon[k] < 450 && daemon[j] == 150)
                daemon[k] -=10;
            //From 5
            if(daemon[j] == 230 && daemon[k] > 150 && daemon[k] <230)
                daemon[k] -= 10;
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                if(daemon[j] == 230 && daemon[k] == 230)
                    daemon[k]-=10;
                else
                {
	                move5(daemon,j,k);
                }
            }

        }
        //For 2
        else
        if(part == 2)
        {
            finder = 0;
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
            if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 150)
                daemon[j] +=10;
            //From 2
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                move2(daemon,j,k);
            }
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
            if(daemon[k]>=220 && daemon[k] <= 440 && daemon[j] == 510)
                daemon[k] -=10;
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
            if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 510)
                daemon[j] +=10;
            //From 5
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                if(daemon[j] == 430 && daemon[k] == 230)
                    daemon[k]-=10;
                else
                {
                	move5(daemon,j,k);
                }
            }
            if(daemon[j] == 430 && daemon[k]>150 && daemon[k] <= 220)
                daemon[k]-=10;
        }
        //For 3
        else
        if(part == 3)
        {
            finder =0;
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
            if(daemon[j] == 220 && daemon[k] == 150)
                daemon[j] += 10;
            if(daemon[j] == 230 && daemon[k] >= 150 && daemon[k] <230)
                daemon[k] += 10;
            //From 2
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 510 && daemon[k] == 210)
                    daemon[k]+=10;
                else
                {
                    move2(daemon,j,k);
                }
            }
            if(daemon[k]>=220 && daemon[k] <= 440 && daemon[j] == 510)
                daemon[k] +=10;
            //From 3
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
            {
                move3(daemon,j,k);
            }
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
            if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 510)
                daemon[j] +=10;
            //From 5
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                if(daemon[j] == 430 && daemon[k] == 430)
                    daemon[k]+=10;
                else
                {
                	move5(daemon,j,k);
                }
            }
            if(daemon[j] == 430 && daemon[k]<510 && daemon[k] >= 430)
                daemon[k]+=10;
        }
        //For 4
        else
        if(part == 4)
        {
            finder = 0;
            //From 1
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 150 && daemon[k] == 210)
                    daemon[k] += 10;
                else
                {
                    move1(daemon,j,k);
                }
            }
            if(daemon[k]>=220 && daemon[k] < 450 && daemon[j] == 150)
                daemon[k] +=10;
            //From 2
            if(daemon[j] == 440 && daemon[k] == 210)
                daemon[j] -= 10;
            if(daemon[j] == 430 && daemon[k] >= 150 && daemon[k] <230)
                daemon[k] += 10;
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 450 && daemon[k] == 210)
                    daemon[j] -=10;
                else
                {
                    move2(daemon,j,k);
                }
            }

            //From 3
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 450 && daemon[k] == 510)
                    daemon[j] -= 10;
                else
                {
                    move3(daemon,j,k);
                }
            }
            if(daemon[j]>=220 && daemon[j] <= 440 && daemon[k] == 510)
                daemon[j] -=10;
            //From 4
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
            {
            	move4(daemon,j,k);
            }
            //From 5
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                if(daemon[j] == 230 && daemon[k] == 430)
                    daemon[k]+=10;
                else
                {
                	move5(daemon,j,k);
                }
            }
            if(daemon[j] == 230 && daemon[k]>=440 && daemon[k] < 510)
                daemon[k]+=10;
        }
        //For 5
        else
        if(part == 5)
        {
            finder =0;
            //From 1
            if(daemon[j] == 220 && daemon[k] == 150)
                daemon[j] += 10;
            if(daemon[j] == 230 && daemon[k] >= 150 && daemon[k] <230)
                daemon[k] += 10;
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 210 && daemon[k] == 150)
                    daemon[j] += 10;
                else
                {
                    move1(daemon,j,k);
                }
            }

            //From 2
            if(daemon[j] == 440 && daemon[k] == 210)
                daemon[j] -= 10;
            if(daemon[j] == 430 && daemon[k] >= 150 && daemon[k] <230)
                daemon[k] += 10;
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
            {
                if(daemon[j] == 450 && daemon[k] == 210)
                    daemon[j] -=10;
                else
                {
                    move2(daemon,j,k);
                }
            }

            //From 3
            if(daemon[j] == 440 && daemon[k] == 450)
                    daemon[j] -= 10;
            if(daemon[k]>430 && daemon[k] <= 510 && daemon[j] == 430)
                daemon[k] -=10;
            if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 450 && daemon[k] == 450)
                    daemon[j] -= 10;
                else
                {
                    move3(daemon,j,k);
                }
            }

            //From 4
            if(daemon[j] == 220 && daemon[k] == 450)
                daemon[j] +=10;
            if(daemon[j] == 230 && daemon[k] <= 510 && daemon[k] >430)
                daemon[k] -= 10;
            if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
            {
                if(daemon[j] == 210 && daemon[k] == 450)
                    daemon[j] +=10;
                else
                {
                    move4(daemon,j,k);
                }
            }

            //From 5
            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
            {
                move5(daemon,j,k);
            }
        }
        else
        	// Left Vertical
            if(pcd[0] == 150 && pcd[1] >= 220 && pcd[1] <= 440 && (finder == 1 || finder == 2 || finder == 9))
            {
            	std::cout<<finder;
                if(finder == 1)
                {
                    if(daemon[j] == 150 && daemon[k] == 210)
                    daemon[k] += 10;
                    else
                    if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
                    {
                        move1(daemon,j,k);
                    }
                    else
                    	if(daemon[j] == 150 && daemon[k] >= 220 && daemon[k] <= 440)
                    		daemon[k] += 10;
                }
               else
               if(finder == 2)
               {
                   if(daemon[j] == 150 && daemon[k] == 450)
                    daemon[k] -= 10;
                    else
                        if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
                        {
                            move4(daemon,j,k);
                        }
                        else
	                        if(daemon[j] == 150 && daemon[k] >= 220 && daemon[k] <= 440)
	                        {
	                            daemon[k] -= 10;
	                        }
               }
               /*if(finder == 1 || finder == 2 || finder == 9)
		        {
					if(daemon[j] == 230 && daemon[k] > 150 && daemon[k] <230)
						daemon[k] -= 10;
					if(daemon[j] == 230 && daemon[k]>=440 && daemon[k] < 510)
		        		daemon[k]+=10;
		        	if(daemon[k] == 510 && daemon[j] >= 220 && daemon[j] <= 440)
		                daemon[j] -= 10;
		            if(daemon[k] == 150 && daemon[j] >= 220 && daemon[j] <= 440)
		                daemon[j] -= 10;
		            if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
		            {
		                if(daemon[j] == 230 && daemon[k] == 230)
		                    daemon[k]-=10;
		                else
		                	if(daemon[j] == 230 && daemon[k]>=440 && daemon[k] < 510)
		        				daemon[k]+=10;
			                else
			                {
				                move5(daemon,j,k);
			                }
		            }
		        }*/
		        finder = 0;
            }
        else
        	//Right Vertical
            if(pcd[0] == 510 && pcd[1] >= 220 && pcd[1] <= 440 && (finder == 3 || finder == 4 || finder == 10))
            {
                if(finder == 3)
                {
                    if(daemon[j] == 510 && daemon[k] == 210)
                        daemon[k]+=10;
                    else
                        if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
	                    {
	                        move2(daemon,j,k);
	                    }
	                    else
		                    if(daemon[k]>=220 && daemon[k] <= 440 && daemon[j] == 510)
		                        daemon[k] +=10;
                }

                if(finder == 4)
                {
                    if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
                    {
                        if(daemon[j] == 510 && daemon[k] == 210)
                            daemon[k]-=10;
                        else
                        {
                            move3(daemon,j,k);
                        }
                    }
                        if(daemon[k]>=220 && daemon[k] <= 440 && daemon[j] == 510)
                        daemon[k] -=10;
                }
                if(finder == 3 || finder == 4 || finder == 10)
                {
                    if(daemon[j]>=230 && daemon[j] <= 430 && daemon[k]>=230 && daemon[k]<=430)
		            {
		                if(daemon[j] == 430 && daemon[k] == 430)
		                    daemon[k]+=10;
		                else
		                {
		                	move5(daemon,j,k);
		                }
		            }
		            if(daemon[j] == 430 && daemon[k]<510 && daemon[k] >= 430)
		                daemon[k]+=10;
		            if(daemon[k] == 510 && daemon[j] >= 220 && daemon[j] <= 440)
                		daemon[j] += 10;
                }
                finder = 0;
            }
    	else
    		//Top Horizontal
            if(pcd[1] == 150 && pcd[0] >= 220 && pcd[0] <= 440 && (finder == 5 || finder == 6))
            {
                if(finder == 5)
                {
                    if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=70 && daemon[k]<=210)
                    {
                        if(daemon[j] == 210 && daemon[k] == 150)
                            daemon[j] += 10;
                        else
                        {
                            move1(daemon,j,k);
                        }
                    }
                    if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 150)
                        daemon[j] +=10;
                }
                if(finder == 6)
                {
                    if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 150)
                        daemon[j] -=10;
                    if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=70 && daemon[k]<=210)
                    {
                        if(daemon[j] == 450 && daemon[k] == 150)
                            daemon[j] -= 10;
                        else
                        {
                            move2(daemon,j,k);
                        }
                    }
                }
                finder = 0;
            }
        else
            //Bottom Horizontal
            if(pcd[1] == 510 && pcd[0] >= 220 && pcd[0] <= 440 && (finder == 7 || finder == 8))
            {
                if(finder == 7)
                {
                    if(daemon[j]>=70 && daemon[j] <= 210 && daemon[k]>=450 && daemon[k]<=590)
                    {
                        if(daemon[j] == 210 && daemon[k] == 510)
                            daemon[j] +=10;
                        else
                        {
                            move4(daemon,j,k);
                        }
                    }
                    if(daemon[j]>=220 && daemon[j] < 450 && daemon[k] == 510)
                        daemon[j] +=10;
                }
                if(finder == 8)
                {
                    if(daemon[j]>=450 && daemon[j] <= 590 && daemon[k]>=450 && daemon[k]<=590)
                    {
                        if(daemon[j] == 450 && daemon[k] == 510)
                            daemon[j] -= 10;
                        else
                        {
                            move3(daemon,j,k);
                        }
                    }
                    if(daemon[j]>=220 && daemon[j] <= 440 && daemon[k] == 510)
                    daemon[j] -=10;
                }
                finder = 0;
            }
            //Stop Stucking in Middle
            else
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
            if(daemon[j] == 230 && daemon[k]>=160 && daemon[k] <= 220 || daemon[j] == 430 && daemon[k]>=160 && daemon[k] <= 220)
               daemon[k] -=10;
           	else
            if(daemon[j] == 220)
                daemon[j] -= 10;
            else
            if(daemon[j] == 440)
                daemon[j] += 10;

    }
    if(daemon[0] == daemon[2] && daemon[1] == daemon[3])
    {
    	daemon[0] = 70;
    	daemon[1] = 70;
    }
    else
    	if(daemon[2] == daemon[4] && daemon[3] == daemon[5])
    	{
	    	daemon[2] = 590;
	    	daemon[3] = 70;
    	}
    	else
	    	if(daemon[4] == daemon[0] && daemon[5] == daemon[1])
	    	{
		    	daemon[4] = 590;
		    	daemon[5] = 590;
	    	}
}
