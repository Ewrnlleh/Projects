hepsi: derle test calistir
derle:
	g++ -I ./include/ -o ./lib/AgacDugum.o -c ./src/AgacDugum.cpp
	g++ -I ./include/ -o ./lib/IkiliAramaAgaci.o -c ./src/IkiliAramaAgaci.cpp
	g++ -I ./include/ -o ./lib/Karsilasma.o -c ./src/Karsilasma.cpp
test:
	g++ -I ./include/ -o ./bin/Program ./lib/AgacDugum.o ./lib/Karsilasma.o ./lib/IkiliAramaAgaci.o ./src/Program.cpp
calistir:
	./bin/Program