/*
    Program:        ColorPlot.c
    Architecture:   Commander 16x Emulator , MOS 6502
    Author:         Ulf Hellstrom, oramininute@gmail.com, Februari 2021
    Puropse:        Educational
    
    Note: You need installed cc65 cross compiler with cx16 support.

    On Mac you can install with Homebrew (INCLUDING NEW M1 MACS) with brew install cc65
    Or you can build ccc65 yourself directly from github repo.

    A very simple example demonstrating C-programming for the MOS6502 architecture
    Target platform is the emulator for Commander X16 but could very easy be ported to C64

    The program demonstrates
    How to set PETSCII font
    How to set videomode
    Plot PETSCII character in random colors in 40x30 videmode.

    To compile and link use included Makefile
    To run program using Commander X16 emulator use  -prg flag like

    <path to commander x16 emulator> -prg COLORPLOT.PRG

*/

#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <conio.h>

unsigned char XSize, YSize;

/*
    setupvideomode
        We need the PETSCII characterset not the standard ISO-8859 charset that CC65 supports
        so we use the conio.h and cx§6.h that defines a function to let us setup UPPERCASE PETSCII
        We also go to 40x30 mode to be more retro! And finally we read th screensize.
        Like using ncurses with normal C.
*/
void setupvideomode(void) 
{

    // User petscii fonts 
    cbm_k_bsout(CH_FONT_UPPER);
    videomode(VIDEOMODE_40x30);
    //get screensize
    screensize(&XSize, &YSize);

}

/*
    setdefaultvidemode
    This function "resets" to the normal colorbackground and default 80x60 charactermode
*/
void setdefaultvideomode(void) 
{

    videomode(VIDEOMODE_80x60);
    bgcolor(COLOR_BLUE);
    bordercolor(COLOR_BLUE);
    textcolor(COLOR_WHITE);
    clrscr();
    cursor(1);

}

/*
    introscreen
        This just introduce a very simple introscreen or setup or whatever...
        We are setting textcolor, border and backgroundcolors.
        We clear the screeen and turn of the cursor.
        And we use a very simple "Plot" function for characters.
*/
void introscreen(void) 
{

    textcolor(COLOR_WHITE);
    bordercolor(COLOR_BLACK);
    bgcolor(COLOR_BLACK);
    cursor (0);
    clrscr();
    gotoxy(XSize/4,YSize/2);
    cprintf("hello c65 compiled code.\n");
    gotoxy(XSize/4,(YSize/2)+1);
    cprintf("press any key to continue..");
    getchar();

}

/*
    randomcolor
        This is a real C-function introduce rand in C
        and we use this to get a raandom Color for
        our character output and returns a number
        in a given range we send as inparameters 
        to the function.
*/
int randomcolor(int lower, int upper) 
{ 

    int num = (rand() % (upper - lower + 1)) + lower; 
    
    return num;  
} 

/*
    plotter is where the magic occurs and here we
    use for loop functions to loop over all
    possible positions on our 40x30 screen and
    print out a PETSCII character in a a ramdon
    color on each position.
*/
void plotter(void) 
{
   
   int x, y, lower=1 , upper=16, color;

   for ( x = 0; x < XSize; x++ ) {
       for ( y = 0; y < YSize; y++) {
           color = randomcolor(lower,upper);
           gotoxy(x,y);  // Set hidden cursor at x,y
           textcolor(color);
           cprintf("%c",113); //petscii character
       }
   }

}

/*
    main: Every C-program that is not a library
    and should execute something must have a main
    functions. THis is what actually is called
    when we run the program in a Commander X16 emulator
    and in the futurure possible on the real hardware.
*/
int main(void) 
{
    int quit = 0;
    char c;
    _randomize();
    setupvideomode();
    introscreen();
    // loop until we press q and enter
    while (quit < 1) {

        clrscr();
        plotter();
        c = getchar();
        if (c == 'q')
            quit = 1;

    }
    setdefaultvideomode();
    
    return 0;
}