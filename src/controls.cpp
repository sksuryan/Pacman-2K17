#include "controls.h"
#include <windows.h>
#include <graphics.h>

int controls::cntrl(int pcd[], int &i, int &score, int daemon[], int &pass, int &gp)
{
//Up-Key
    if(GetAsyncKeyState(VK_UP) !=0 || pass==1)
    {
        if(pcd[1]==70 && pcd[0] >= 70 && pcd[0]<=210 || pcd[1]==150 && pcd[0] >= 220 && pcd[0]<=320 || pcd[1]==150 && pcd[0] >= 340 && pcd[0]<=440 || pcd[1]==70 && pcd[0] >= 450 && pcd[0]<=610 )
        {
            cleardevice();
            pass = 0;
        }
        else
          if(pcd[1]==210 && pcd[0] >= 80 && pcd[0]<=200 || pcd[1]==210 && pcd[0] >= 460 && pcd[0]<=580)
          {
                cleardevice();
                pass = 0;
          }
          else
            if(pcd[1]==230 && pcd[0] >= 240 && pcd[0]<=420)
            {
                cleardevice();
                pass = 0;
            }
            else
                if(pcd[1]==330 && pcd[0] >= 50 && pcd[0]<=140 || pcd[1]==330 && pcd[0] >= 520 && pcd[0]<=610)
                {
                    cleardevice();
                    pass = 0;
                }
                else
                    if(pcd[1]==430 && pcd[0] >= 240 && pcd[0]<=420 ||pcd[1]==450 && pcd[0] >= 50 && pcd[0]<=140 || pcd[1]==450 && pcd[0] >= 520 && pcd[0]<=610)
                    {
                        if(gp == 0 && pcd [0] == 330 && pcd[1] == 430)
                        {
                            pcd[1] -= 20;
                                pass = 1;
                        }
                        else
                        {
                            cleardevice();
                            pass = 0;
                        }
                    }
                    else
                        if(pcd[1]==510 && pcd[0] >= 240 && pcd[0]<=420 || pcd[1]==590 && pcd[0] >= 80 && pcd[0]<= 200 || pcd[1]==590 && pcd[0] >= 460 && pcd[0]<=580)
                        {
                            cleardevice();
                            pass = 0;
                        }
                        else
                            if(pcd[1]==450 && pcd[0] >= 160 && pcd[0]<=220 || pcd[1]==450 && pcd[0] >= 440 && pcd[0]<=500)
                            {
                                cleardevice();
                                pass = 0;
                            }
                            else
                            {
                                pcd[1] -= 10;
                                pass = 1;
                                cleardevice();
                                if(pcd[0] == 330 && pcd[1] == 60)
                                {
                                    pcd[1] = 590;

                                }
                            }

    }

    //Down-Key
    if(GetAsyncKeyState(VK_DOWN) !=0 || pass == 2)
    {
        if(pcd[1]==70 && pcd[0] >= 80 && pcd[0]<=200 || pcd[1]==150 && pcd[0] >= 240 && pcd[0]<=420 || pcd[1]==70 && pcd[0] >= 460 && pcd[0]<=580 )
        {
            cleardevice();
            pass = 0;
        }
        else
            if(pcd[1]==210 && pcd[0] >= 50 && pcd[0]<=140 || pcd[1]==210 && pcd[0] >= 160 && pcd[0]<=220 || pcd[1]==210 && pcd[0] >= 440 && pcd[0]<=500 || pcd[1]==210 && pcd[0] >= 520 && pcd[0]<=610)
            {
                cleardevice();
                pass = 0;
            }
            else
                if(pcd[1]==230 && pcd[0] >= 240 && pcd[0]<=420 || pcd[1]==330 && pcd[0] >= 50 && pcd[0]<=140 || pcd[1]==330 && pcd[0] >= 520 && pcd[0]<=610)
                {
                    cleardevice();
                    pass = 0;
                }
                else
                    if(pcd[1]==430 && pcd[0] >= 240 && pcd[0]<=420 || pcd[1]==450 && pcd[0] >= 80 && pcd[0]<=200 || pcd[1]==450 && pcd[0] >= 460 && pcd[0]<=580)
                    {
                        cleardevice();
                        pass = 0;
                    }
                    else
                        if(pcd[1]==590 && pcd[0] >= 50 && pcd[0]<=230 || pcd[1]==510 && pcd[0] >= 220 && pcd[0]<= 320 || pcd[1]==510 && pcd[0] >= 340 && pcd[0]<=440 || pcd[1]==590 && pcd[0] >= 430 && pcd[0]<=610)
                        {
                            cleardevice();
                            pass = 0;
                        }

                        else
                        {
                            pcd[1] += 10;
                            pass=2;
                            cleardevice();
                            if(pcd[0] == 330 && pcd[1] == 600)
                            {
                                    pcd[1] = 70;
                            }
                        }
    }

    //Left-Key
    if(GetAsyncKeyState(VK_LEFT) !=0 || pass == 4)
    {
        if(pcd[0]==70 && pcd[1] >= 50 && pcd[1]<=230 || pcd[0]==150 && pcd[1] >= 220 && pcd[1]<=320 || pcd[0]==150 && pcd[1] >= 340 && pcd[1]<=440 || pcd[0]==70 && pcd[1] >= 430 && pcd[1]<=610)
        {
            cleardevice();
            pass = 0;
        }
        else
            if(pcd[0]==210 && pcd[1] >= 80 && pcd[1]<=200 || pcd[0]==210 && pcd[1] >= 460 && pcd[1] <= 580 || pcd[0]==230 && pcd[1] >= 220 && pcd[1]<=440)
            {
                cleardevice();
                pass = 0;
            }
            else
                if(pcd[0]==330 && pcd[1] >= 50 && pcd[1]<=140 || pcd[0]==330 && pcd[1] >= 520 && pcd[1]<=610 )
                {
                    cleardevice();
                    pass = 0;
                }
                else
                    if(pcd[0]==430 && pcd[1] >= 160 && pcd[1]<=220 || pcd[0]==430 && pcd[1] >= 240 && pcd[1]<=420 || pcd[0]==430 && pcd[1] >= 440 && pcd[1]<=500)
                    {
                            cleardevice();
                            pass = 0;
                    }
                    else
                        if(pcd[0]==450 && pcd[1] >= 50 && pcd[1]<=140 || pcd[0]==450 && pcd[1] >= 520 && pcd[1]<=610 || pcd[0]==510 && pcd[1] >= 220 && pcd[1]<= 440)
                        {
                            cleardevice();
                            pass = 0;
                        }
                        else
                            if(pcd[0]==590 && pcd[1] >= 80 && pcd[1]<=200 || pcd[0]==590 && pcd[1] >= 460 && pcd[1]<=580)
                            {
                                cleardevice();
                                pass = 0;
                            }
                            else
                                if(pcd[0] == 330 && pcd[1]<430 && pcd[1]>=290)
                                {
                                    cleardevice();
                                    pass = 0;
                                }
                                else
                                {
                                    pcd[0] -= 10;
                                    pass = 4;
                                    cleardevice();
                                    if(pcd[0] == 60 && pcd[1] == 330)
                                    {
                                        pcd[0] = 590;
                                    }
                                }
    }

    //Right-Key
    if(GetAsyncKeyState(VK_RIGHT) !=0 || pass == 3)
    {
        if(pcd[0]==70 && pcd[1] >= 80 && pcd[1]<=200 || pcd[0]==70 && pcd[1] >= 460 && pcd[1]<=580)
        {
            cleardevice();
            pass = 0;
        }
        else
            if(pcd[0]==150 && pcd[1] >= 220 && pcd[1]<=440 || pcd[0]==210 && pcd[1] >= 50  && pcd[1]<=140 || pcd[0]==210 && pcd[1] >= 520 && pcd[1]<=610)
            {
                cleardevice();
                pass = 0;
            }
            else
                if(pcd[0]==230 && pcd[1] >= 160 && pcd[1]<=220 || pcd[0]==230 && pcd[1] >= 240 && pcd[1]<= 420 || pcd[0]==230 && pcd[1] >= 440 && pcd[1]<=500)
                {
                    pass=0;
                    cleardevice();

                }
                else
                    if(pcd[0]==330 && pcd[1] >= 50 && pcd[1]<=140 || pcd[0]==330 && pcd[1] >= 520 && pcd[1]<=610)
                    {
                        cleardevice();
                        pass = 0;
                    }
                    else
                        if(pcd[0]==450 && pcd[1] >= 80 && pcd[1]<=200 || pcd[0]==450 && pcd[1] >= 460 && pcd[1]<=580 || pcd[0]==430 && pcd[1] >= 220 && pcd[1]<=440)
                        {
                            cleardevice();
                            pass = 0;
                        }
                        else
                            if(pcd[0]==590 && pcd[1] >= 70 && pcd[1]<=210 || pcd[0]==510 && pcd[1] >= 220 && pcd[1]<=320 || pcd[0]==510 && pcd[1] >= 340 && pcd[1]<=440 || pcd[0]==590 && pcd[1] >= 430 && pcd[1]<=610)
                            {
                                cleardevice();
                                pass = 0;
                            }
                            else
                                if(pcd[0] == 330 && pcd[1]<430 && pcd[1]>=290)
                                {
                                    cleardevice();
                                    pass = 0;
                                }
                                else
                                {
                                    pcd[0] += 10;
                                    pass =3;

                                    cleardevice();
                                    if(pcd[0] == 600 && pcd[1] == 330)
                                    {
                                        pcd[0] = 70;
                                    }
                                }
    }

    //Escape-Key
    if(GetAsyncKeyState(VK_ESCAPE) !=0)
    {
        exit(0);
    }
}
