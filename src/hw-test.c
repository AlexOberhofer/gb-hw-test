#include <gb/gb.h>
#include <gb/drawing.h>

#include <stdio.h>
#include <time.h>

#define CLR_LINE "                      "

void keypress() 
{
    gotogxy(0, 15);
    
    UBYTE state = joypad();
    
    switch(state) 
    {
        case J_LEFT:
            gprintf(CLR_LINE);
            gotogxy(3, 15);
            gprintf("Pressed: Left");
            break;
        case J_RIGHT:
            gprintf(CLR_LINE);
            gotogxy(3, 15);
            gprintf("Pressed: Right");
            break;
        case J_UP:
            gprintf(CLR_LINE);
            gotogxy(3, 15);
            gprintf("Pressed: Up");
            break;
        case J_DOWN:
            gprintf(CLR_LINE);
            gotogxy(3, 15);
            gprintf("Pressed: Down");
            break;
        case J_START:
            gprintf(CLR_LINE);
            gotogxy(3, 15);
            gprintf("Pressed: Start");
            break;
        case J_SELECT:
            gprintf(CLR_LINE);
            gotogxy(3, 15);
            gprintf("Pressed: Select");
            break;
        case J_A:
            gprintf(CLR_LINE);
            gotogxy(3, 15);
            gprintf("Pressed: A");
            break;
        case J_B:
            gprintf(CLR_LINE);
            gotogxy(3, 15);
            gprintf("Pressed: B");
            break;
        }

        if(state) 
        {
            NR10_REG = 0x38U;
            NR11_REG = 0x70U;
            NR12_REG = 0xE0U;
            NR13_REG = 0x0AU;
            NR14_REG = 0xC6U;
            NR51_REG |= 0x11;
            
            delay(200);
        }
           
}

void main()
{
    NR50_REG = 0xFF;
    NR51_REG = 0xFF;
    NR52_REG = 0x80;
    
    gotogxy(1, 1);
    gprintf("== SDL2 GNUBoy ==");

    gotogxy(1, 4);
    gprintf("##################");
    gotogxy(1, 5);
    gprintf("#      Timer     #");
    gotogxy(1, 6);
    gprintf("##################");

    time_t t = 1;
    time_t prev = 0;

    gotogxy(1, 10);
    gprintf("##################");
    gotogxy(1, 11);
    gprintf("# Input + Sound  #");
    gotogxy(1, 12);
    gprintf("##################");

    gotogxy(1, 15);
    gprintf("= Press a button =");

    for(;;) {
        gotogxy(9, 8);
        time(&t);

        if(t > prev) 
        {
            gprintf("%d", t);
            prev = t;
        }
        
        keypress();
    }

}