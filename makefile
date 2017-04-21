# Variables :

ALL="$(IO) $(CARTE) $(MONSTRE) $(COMPETENCE) $(PERSONNAGE)"
IO="archives/io.a"
CARTE="archives/carte.a"
MONSTRE="archives/monstre.a"
COMPETENCE="archives/competence.a"
PERSONNAGE="archives/personnage.a"

# Cibles que l'on peut compiler directement :
all:
	@make -s io	# IO
	@make -s ca	# Carte
	@make -s co	# Compétences
	@make -s mo	# Monstre
	@make -s pe	# Personnage
	@make -s fj	# Fonctions jeu
	@make -s main.exe
ca:
	@make objects/carte.o
	@make archives/carte.a
mo:
	@make objects/monstre.o
	@make archives/monstre.a
co:
	@make objects/competence.o
	@make archives/competence.a
pe:
	@make objects/personnage.o
	@make archives/personnage.a
fj:
	@make objects/fonctionsjeu.o
	@make objects/fonctionsjeu_main.o
	@make archives/fonctionsjeu.a
	@make fonctionsjeu.exe
io:
	@make objects/io.o
	@make objects/io_main.o
	@make archives/io.a
	@make io_main.exe
in:
	@make objects/interface.o
doc:
	@cd documentation; doxygen documentation > doxygen_output.txt; cd latex; make;
main.exe: objects/fonctionsjeu.o objects/io.o objects/carte.o objects/personnage.o objects/competence.o objects/monstre.o objects/interface.o
	@g++ $^ tests/main.cpp -o $@ -std=c++11

# Archives des classes :

archives/io.a: objects/io.o
	@echo "Archiving $@ ..."
	@ar rvs $@ $<
archives/carte.a: objects/carte.o
	@echo "Archiving $@ ..."
	@ar rvs $@ $<
archives/monstre.a: objects/monstre.o
	@echo "Archiving $@ ..."
	@ar rvs $@ $<
archives/competence.a: objects/competence.o
	@echo "Archiving $@ ..."
	@ar rvs $@ $<
archives/personnage.a: objects/personnage.o
	@echo "Archiving $@ ..."
	@ar rvs $@ $<
archives/fonctionsjeu.a: objects/fonctionsjeu.o
	@echo "Archiving $@ ..."
	@ar rvs $@ $<

# Objets des classes :

objects/io.o: sources/io.cpp
	@echo "Compiling $@ ..."
	@g++ -c $< -o $@ -std=c++11
objects/carte.o: sources/carte.cpp
	@echo "Compiling $@ ..."
	@g++ -c $< -o $@ -std=c++11
objects/monstre.o: sources/monstre.cpp
	@echo "Compiling $@ ..."
	@g++ -c $< -o $@ -std=c++11
objects/interface.o: sources/interface.cpp
	@echo "Compiling $@ ..."
	@g++ -c $< -o $@ -std=c++11
objects/competence.o: sources/competence.cpp
	@echo "Compiling $@ ..."
	@g++ -c $< -o $@ -std=c++11
objects/personnage.o: sources/personnage.cpp
	@echo "Compiling $@ ..."
	@g++ -c $< -o $@ -std=c++11
objects/fonctionsjeu.o:	sources/fonctionsjeu.cpp
	@echo "Compiling $@ ..."
	@g++ -c $< -o $@ -std=c++11

# Objets (main) de test des classes :

objects/io_main.o: tests/io_main.cpp
	@echo "Compiling $@ ..."
	@g++ -c $< -o $@ -std=c++11
objects/fonctionsjeu_main.o: tests/fonctionsjeu_main.cpp
	@echo "Compiling $@ ..."
	@g++ -c $< -o $@ -std=c++11

# Exécutables de test des classes :

io_main.exe: objects/io_main.o objects/io.o
	@echo "Compiling $@ ..."
	@g++ $^ -o $@ -std=c++11
fonctionsjeu.exe: objects/fonctionsjeu.o objects/fonctionsjeu_main.o archives/io.a
	@echo "Compiling $@ ..."
	@g++ $^ $(IO) $(CARTE) $(COMPETENCE) $(MONSTRE) $(PERSONNAGE) -o $@ -std=c++11
