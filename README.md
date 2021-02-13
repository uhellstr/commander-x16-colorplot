# commander-x16-colorplot
Simple educational example on how to program in C with crosscospiler C65 for MOS6502 and Commander X16 emulator.

 Note: You need installed cc65 cross compiler with cx16 support.
 
    On Mac you can install with Homebrew (INCLUDING NEW M1 MACS) with brew install cc65.
    Or you can build ccc65 yourself directly from github repo.
    
    A very simple example demonstrating C-programming for the MOS6502 architecture.
    Target platform is the emulator for Commander X16 but could very easy be ported to C64.
 
 The program demonstrates:
 
    How to set PETSCII font.
    How to set videomode.
    Plot PETSCII character in random colors in 40x30 videmode.
 
 To compile and link use included Makefile.
 
 $ make
 
 
 To run program using Commander X16 emulator use  -prg flag like
 <path to commander x16 emulator> -prg COLORPLOT.PRG

