#ifndef TV_H_
#define TV_H_

class Tv;

class Remote{
    friend class Tv;
    int mode;
    int rmode;
public:
    enum State{Off, On};
    enum {MinVal,MaxVal};
    enum {Antenna, Cable};
    enum {TV,VCR};
    enum {Nomal, Talk};
    
    Remote(int m = TV, int rm = Nomal) : mode(m), rmode(rm) {}
    bool volup(Tv & t);
    bool voldown(Tv & t);
    void onoff(Tv & t);
    void chanup(Tv & t);
    void chandown(Tv & t);
    void set_mode(Tv & t);
    void set_input(Tv & t);
    void set_chan(Tv & t, int n);
    void set_talkmode()  { rmode = (rmode == Nomal) ? Talk : Nomal; }
    void ret_talkmode() const;
};

class Tv{
    friend class Remote;
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
public:
    enum State{Off,On};
    enum {MinVal,MaxVal=201};
    enum {Antenna, Cable};
    enum {TV, DVD};
    enum {Nomal, Talk};
    
    Tv(int s = Off, int mc = 215) : state(s), volume(5), maxchannel(mc), channel(mc), mode(Cable), input(TV) {}
    void onoff() { state = (state == On) ? Off : On;}
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antenna) ? Cable:Antenna;}
    void set_input() {input = (input == TV) ? DVD : TV;}
    void set_talkmode(Remote & r); 
    void settings() const;
};

#endif
