#ifndef _CLOCK_H
#define _CLOCK_H

#include <iostream>

class Clock
{
private:
    /* data */
public:
    typedef struct clock_t
    {
        u_int8_t hh;
        u_int8_t mm;
        u_int8_t ss;
    };

    Clock();
    ~Clock();
    clock_t init(int hh, int mm, int ss);
    bool is_valid(int hh, int mm, int ss);

    //Selector
    u_int8_t get_hour(clock_t c);
    u_int8_t get_minute(clock_t c);
    u_int8_t get_second(clock_t c);

    //Value changer
    void set_hour(clock_t *c, int new_HH);
    void set_minute(clock_t *c, int new_MM);
    void set_second(clock_t *c, int new_SS);

    //Relation Operation
    bool is_equal(clock_t c1, clock_t c2);

    //Arithmetic Operation
    clock_t add_clock(clock_t c1, clock_t c2);

    //output
    void print_clock(clock_t c);
};

#endif