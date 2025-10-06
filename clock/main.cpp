#include "clock.h"
#include <iostream>

int main() {
    Clock clock;
    Clock::clock_t clock_time1 = clock.init(7, 35, 0);
    clock.print_clock(clock_time1);
}