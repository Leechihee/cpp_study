#include "../header/tv.h"
#include <iostream>

int main()
{
    Tv t1;
    Remote tr1;
    t1.settings();
    std::cout << std::endl;
    tr1.chanup(t1);
    tr1.onoff(t1);
    t1.settings();
    std::cout << std::endl;
    for(int i = 0;i<50;i++)
    {
        tr1.volup(t1);
        tr1.chanup(t1);
    }
    t1.settings();
    std::cout << std::endl;
    for(int i = 0;i<35;i++)
    {
        tr1.voldown(t1);
        tr1.chandown(t1);
    }
    t1.settings();
    std::cout << std::endl;
    tr1.set_mode(t1);
    tr1.set_input(t1);
    tr1.set_chan(t1,200);
    t1.settings();
    
    tr1.ret_talkmode();
    tr1.set_talkmode();
    tr1.ret_talkmode();
    t1.set_talkmode(tr1);
    tr1.ret_talkmode();
    tr1.onoff(t1);
    t1.set_talkmode(tr1);
    return 0;
}
