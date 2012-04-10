#VARIABLES
cc=g++
options=-Wall
exec=verif
include=inc
template=tpp
src=src
obj=obj

#CIBLES

all: verif_noeud verif_arbre
	rm -f $(obj)/verif_noeud.o

box:
	$(cc) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(obj)/$@.o -o $@.out

listei:
	$(cc) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(obj)/$@.o -o $@.out

node:
	$(cc) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(obj)/$@.o -o $@.out

filei:
	$(cc) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(obj)/$@.o -o $@.out

tree:
	$(cc) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(obj)/$@.o -o $@.out

cleantemp:
	rm -f *~
	cd $(src); rm -f *~
	cd $(include); rm -f *~
	cd $(template); rm -f *~

clean: cleantemp
	cd $(obj); rm -f *.o

cleanall: clean
	rm -f *.out