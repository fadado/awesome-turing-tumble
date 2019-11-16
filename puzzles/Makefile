# TODO: all!

#.SILENT:

CPP=cpp -P

PUZZLES=\
	puzzle01.gv	\
	puzzle03.gv	\
	puzzle04.gv	\
	puzzle05.gv	\

all:
	$(CPP) puzzle01.gv | dot -Tsvg > puzzle01.svg
	$(CPP) puzzle03.gv | dot -Tsvg > puzzle03.svg
	$(CPP) puzzle04.gv | dot -Tsvg > puzzle04.svg
	$(CPP) puzzle05.gv | dot -Tsvg > puzzle05.svg

clean:
	rm -f *.svg *.png
