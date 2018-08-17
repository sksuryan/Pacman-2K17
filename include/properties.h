#include <time.h>

#ifndef PROPERTIES_H
#define PROPERTIES_H


class properties
{
    public:
        void save();
        void load();
        int pcd[2];
        int xc[300],yc[300];
        int daemon[6];
        int dpart[3];
        int rscore;
        int lives;
        int page;
        int i,score,pass,check,ux[2],uy[2],v;
        int gp;
        double dif;
        int oz;
        int win_game;

    protected:

    private:

};

#endif // PROPERTIES_H
