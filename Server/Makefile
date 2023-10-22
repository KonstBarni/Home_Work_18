TARGET = ServerChat
PATHHIST = history_files/

all: $(TARGET)

$(TARGET):	Main.cpp User.o Massage.o Chat.o WorkWithFiles.o
	g++ -o $(TARGET) Main.cpp User.o Massage.o Chat.o WorkWithFiles.o

Main.o:	Main.cpp
	g++ -c Main.cpp

User.o:	User.cpp User.h
	g++ -c User.cpp

Massage.o:	Massage.cpp Massage.h
	g++ -c Massage.cpp

Chat.o:	Chat.cpp Chat.h
	g++ -c Chat.cpp

WorkWithFiles.o:	$(PATHHIST)WorkWithFiles.cpp WorkWithFiles.o
	g++ -c $(PATHHIST)WorkWithFiles.cpp

clean:
	rm -rf *.o