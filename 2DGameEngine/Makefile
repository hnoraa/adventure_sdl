# Build and clean

# compiler stuff
CC = g++
CFLAGS = -w

# linker
LINKERFLAGS = -lSDL2 -lSDL2_image

# objects
BASEDIR = ./game/
MATHDIR = math/
OBJS = main.cpp $(BASEDIR)game.cpp $(BASEDIR)textureManager.cpp $(BASEDIR)tileMap.cpp $(BASEDIR)$(MATHDIR)vector2D.cpp

# output (target)
TARGET = engine

# commands
all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINKERFLAGS) -o $(TARGET)

clean:
	rm $(TARGET)
