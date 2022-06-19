hepsi: derle test calistir
derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/IkiYonluBagliListe.o -c ./src/IkiYonluBagliListe.cpp
test:
	g++ -I ./include/ -o ./bin/Program ./lib/Dugum.o ./lib/IkiYonluBagliListe.o ./src/Program.cpp
calistir:
	./bin/Program