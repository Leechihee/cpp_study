#include "stonewt.h"

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn*Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt(){}

std::ostream & operator<<(std::ostream & os, const Stonewt & s, const char form)
{
    if(form == 'l')
    {
        os << pounds << "pounds";
        return os;
    }
    else if(form == 's')
    {
        os << stone << "stone, " << lbs_left << "pounds";
        return os;
    }
    else
    {
        cout << "출력값의 형태오류 출력 하지 않습니다.\n";
        return os;
    }
}
