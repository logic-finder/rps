rps: entry.o cdll.o rps.o
cdll.o: cdll.h
rps.o: rps.h

.PHONY: clean
clean:
	rm -f *.o