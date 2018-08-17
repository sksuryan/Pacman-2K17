#include <coins_sc.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>

int coins_sc::cs(int &i, int &score, int xc[],int yc[],int pcd[], int &check, int ux[], int uy[],int &oz)
{
    ch = 1;
    m = pcd[0]-10;
    n= pcd[1]-10;
    if(m%20 == 0 && n%20==0)
    {
        xc[i] = pcd[0];
        yc[i] = pcd [1];

    }
    ux[1] = pcd[0];
    uy[1] = pcd [1];

    setcolor(15);
    setfillstyle(SOLID_FILL,WHITE);
    for(int k=70;k<610;k+=20)
        for(int j=70;j<610;j+=20)
        {
            if(j==70 && k >= 70 && k<=210 || j==150 && k >= 230 && k<=430 || j==70 && k >= 450 && k<=590 )
            {
                circle(k,j,3);
            }
            else
            if(j==210 && k >= 90 && k<=230 || j==210 && k >= 430 && k<=590)
            {
                circle(k,j,3);
            }
            else
            if(j==230 && k >= 250 && k<=410 || j==330 && k >= 530 && k<=590)
            {
                circle(k,j,3);
            }
            else
            if(j==430 && k >= 250 && k<=410 ||j==450 && k >= 50 && k<=230 || j==450 && k >= 430 && k<=590)
            {
                    circle(k,j,3);
            }
            else
            if(j==510 && k >= 230 && k<=430 || j==590 && k >= 70 && k<= 210 || j==590 && k >= 450 && k<=590)
            {
                circle(k,j,3);
            }
            else
            if(k==70 && j >= 90 && j<=210 || k==150 && j >= 230 && j<=430 || k==70 && j >= 450 && j<=610)
            {
                circle(k,j,3);
            }
            else
            if(k==210 && j >= 90 && j<=190 || k==210 && j >= 470 && j <= 570 || k==230 && j >= 150 && j<=510)
            {
                circle(k,j,3);
            }
            else
            if(k==330 && j >= 50 && j<=130 || k==330 && j >= 530 && j<=610 )
            {
                circle(k,j,3);
            }
            else
            if(k==430 && j >= 150 && j<=510)
            {
                circle(k,j,3);
            }
            else
            if(k==450 && j >= 70 && j<=210 || k==450 && j >= 450 && j<=590 || k==510 && j >= 230 && j<= 430)
            {
                circle(k,j,3);
            }
            else
            if(k==590 && j >= 70 && j<=210 || k==590 && j >= 470 && j<=570)
            {
                circle(k,j,3);
            }
            else
                ch = 0;
            if(ch == 1)
            {
                floodfill(k,j,15);
            }
            else
                ch = 1;
        }

        setfillstyle(SOLID_FILL,BLACK);
        for(int j = 0; j<=i;j++)
        {
            setcolor(BLACK);
            circle(xc[j], yc[j],3);
            floodfill(xc[j], yc[j],0);
        }

        check = 0;

        if(pcd[0] == ux[0] && pcd[1] == uy[0])
            check = 1;

        m = ux[0];
        n = uy[0];
        ux[0] = ux[1];
        uy[0] = uy[1];
        ux[1] = m;
        uy[1] = n;


        for(int j=0;j<i;j++)
        {
            if(xc[j] == xc[i] && yc[j] == yc[i])
            {
                --i;
            }
            else
            if(yc[i] == 330 && xc[i] >=50 && xc[i]<=130 || xc[i] == 330 && yc[i]<430 && yc[i]>=290)
                --i;
        }
        score = i;
}
