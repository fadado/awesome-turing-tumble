#

#.SILENT:

CPP=cpp -P

all:
	$(CPP) puzzle01.gv | dot -Tsvg > puzzle01.svg
	$(CPP) puzzle03.gv | dot -Tsvg > puzzle03.svg
	$(CPP) puzzle05.gv | dot -Tsvg > puzzle05.svg

clean:
	rm -f *.svg *.png
