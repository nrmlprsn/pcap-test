all: pcap-test

pcap-test: main.o pprint.o
	g++ -o pcap-test main.o pprint.o

main.o: hdr.h pprint.h main.cpp
	g++ -c -o main.o main.cpp

pprint.o: hdr.h pprint.cpp
	g++ -c -o pprint.o pprint.cpp

clean:
	rm -f pcap-test
	rm -f *o

