ALL_C = $(wildcard *.c) $(wildcard *.h)

all: $(ALL_C)
	cl65 -Oi -t cx16 -o COLORPLOT.PRG -l colorplot.list ColorPlot.c

clean:
	rm -f *.PRG *.list *.o
