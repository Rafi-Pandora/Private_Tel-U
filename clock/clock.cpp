#include <iostream>
#include "clock.h"

Clock::Clock() {}
Clock::~Clock() {
    //ksosng
}

Clock::clock_t Clock::init(int hh, int mm, int ss) {
    if (is_valid(hh, mm, ss))
    {
        clock_t clock = {
            clock.hh = (u_int8_t)hh,
            clock.mm = (u_int8_t)mm,
            clock.ss = (u_int8_t)ss,
        };
        return clock;
    } else {
        std::cout << "tidak dapat diinisialisasi" << std::endl;
        return {0,0,0};
    }
}

bool Clock::is_valid(int hh, int mm, int ss) {
    bool Hour = (hh < 24) && (hh >= 0);
    bool Minute = (mm <= 60) && (mm >= 0);
    bool Second = (ss <= 60) && (ss >= 0);

    return Hour && Minute && Second;
} 

u_int8_t Clock::get_hour(clock_t c) { return c.hh; }

u_int8_t Clock::get_minute(clock_t c) { return c.mm; }

u_int8_t Clock::get_second(clock_t c) { return c.ss; }

void Clock::set_hour(clock_t *c, int new_HH) { c->hh = new_HH; }

void Clock::set_minute(clock_t *c, int new_MM) { c->mm = new_MM; }

void Clock::set_second(clock_t *c, int new_SS) { c->ss = new_SS; }

bool Clock::is_equal(clock_t c1, clock_t c2) {
    return (c1.hh ==  c2.hh) && (c1.mm == c2.mm) && (c1.ss == c2.ss);
}

void Clock::print_clock(clock_t c) {
    std::cout << "Jam : " << (int)c.hh << std::endl;
    std::cout << "Menit : " << (int)c.mm << std::endl;
    std::cout << "Detik : " << (int)c.ss << std::endl;
}