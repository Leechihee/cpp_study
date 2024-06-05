#include "tv.h"
#include <iostream>

namespace
{
    using namespace std;
    
}
//Tv public method
bool Tv::volup()
{
    if(!ison())
        return false;
    if(volume > MaxVal)
        return false;
    else
    {
        volume++;
        return true;
    }
}

bool Tv::voldown()
{
    if(!ison())
        return false;
    if(volume < MinVal)
        return false;
    else
    {
        volume--;
        return true;
    }
}


void Tv::chanup()
{
    if(!ison())
    {
        cout << "Power Off." << endl;
        return;
    }
    if(channel > maxchannel)
        channel = 1;
    else
        channel++;
}

void Tv::chandown()
{
    if(!ison())
    {
        cout << "Power Off." << endl;
        return;
    }
    if(channel < 1)
        channel = maxchannel;
    else
        channel--;
}

void Tv::set_talkmode(Remote & r)
{
    if(!ison())
    {
        cout << "Power Off." << endl;
        return;
    }
    else
        r.rmode = (r.rmode == Remote::Nomal) ? Remote::Talk : Remote::Nomal;
}

void Tv::settings() const
{
    cout << "Tv = " << (state == Off ? "Off" : "On") << endl;
    if(ison())
    {
        cout << "Volume : " << volume << endl;
        cout << "Channel : " << channel << endl;
        cout << "Mode : " << (mode == Antenna ? "Antenna" : "Cable") << endl;
        cout << "Input : " << (input == DVD ? "DVD" : "TV") << endl;
    }
}

//Remote public method
bool Remote::volup(Tv & t) { return t.volup(); }

bool Remote::voldown(Tv & t) { return t.voldown(); }

void Remote::onoff(Tv & t) { t.onoff(); }

void Remote::chanup(Tv & t) { t.chanup(); }

void Remote::chandown(Tv & t) { t.chandown(); }

void Remote::set_mode(Tv & t) { t.set_mode(); }

void Remote::set_input(Tv & t) { t.set_input(); }

void Remote::set_chan(Tv & t, int n)
{
    if(n > t.maxchannel)
    {
        t.channel = t.maxchannel;
        return;
    }
    else if(n < 1)
    {
        t.channel = 1;
        return;
    }
    else
        t.channel = n;
}

void Remote::ret_talkmode() const
{
    cout << "Remote Mode : " << (rmode == Nomal ? "Nomal" : "Talk") << endl;
}
