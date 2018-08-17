#ifndef START_GAME_H
#define START_GAME_H

#include <endprint.h>
#include <coins_sc.h>
#include <daemons.h>
#include <properties.h>
#include <controls.h>

class start_game: public endprint, public coins_sc, public daemons,public properties
{
    public:
        int sg(int saved);
        start_game();
    protected:

    private:
         time_t start,end;

};

#endif
