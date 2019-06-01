Obj=server.o main.o

serv:$(Obj)
	g++ -g -o serv $(Obj)
	rm $(Obj)

server.o=server.h
main.o=main.cpp

clean:
	serv $(Obj)
