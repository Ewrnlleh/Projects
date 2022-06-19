hepsi: derle test calistir
derle:	
	g++ -I ./include/ -o ./lib/Kova.o -c ./src/Kova.cpp
	g++ -I ./include/ -o ./lib/KovaKontrol.o -c ./src/KovaKontrol.cpp
	g++ -I ./include/ -o ./lib/Top.o -c ./src/Top.cpp
test:
	g++ -I ./include/ -o ./bin/Test ./lib/Kova.o ./lib/KovaKontrol.o ./lib/Top.o ./src/Test.cpp
calistir:
	./bin/Test