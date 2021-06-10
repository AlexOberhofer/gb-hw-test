#include <gb/gb.h>
#include <gb/drawing.h>

#include <stdio.h>
#include <time.h>

void main()
{
    NR50_REG = 0xFF;
    NR51_REG = 0xFF;
    NR52_REG = 0x80;
    
    gotogxy(1, 1);
    gprintf("= Hello Gameboy =");

    gotogxy(2, 4);
    gprintf("=== Uptime: ===");

    

    time_t t = 1;
    time_t prev = 0;

    for(;;) {
        gotogxy(9, 8);
        time(&t);

        if(t > prev) 
        {
            gprintf("%d", t);
            prev = t;
        }
        
    }

}