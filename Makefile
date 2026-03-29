all: pcap-test

pcap-test: main.o pprint.o
	g++ -std=c++20 -o pcap-test main.o pprint.o -lpcap

main.o: pprint.h main.cpp
	g++ -std=c++20 -c -o main.o main.cpp

pprint.o: hdr.h pprint.cpp
	g++ -std=c++20 -c -o pprint.o pprint.cpp

clean:
	rm -f pcap-test
	rm -f *o

