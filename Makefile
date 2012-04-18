#VARIABLES
cc=g++
flags=-Wall -g
exec=verif
include=inc
template=tpp
src=src
obj=obj

#CIBLES

all: tree

box:
	$(cc) $(flags) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(flags) $(obj)/$@.o -o $@.out

listei: box
	$(cc) $(flags) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(flags) $(obj)/$@.o -o $@.out

node:
	$(cc) $(flags) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(flags) $(obj)/$@.o -o $@.out

filei: listei
	$(cc) $(flags) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(flags) $(obj)/$@.o -o $@.out

tree: node listei filei
	$(cc) $(flags) -I$(include) -I$(template) -c $(src)/$@.cpp
	mv $@.o $(obj)
	$(cc) $(flags) $(obj)/$@.o -o $@.out

cleantemp:
	rm -f *~
	cd $(src); rm -f *~
	cd $(include); rm -f *~
	cd $(template); rm -f *~

clean: cleantemp
	cd $(obj); rm -f *.o

cleanall: clean
	rm -f *.out