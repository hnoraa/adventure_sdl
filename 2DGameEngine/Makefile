# Build and clean

# compiler stuff
CC = g++
CFLAGS = -w

# linker
LINKERFLAGS = -lSDL2 -lSDL2_image

# objects
OBJS = main.cpp game.cpp gameObject.cpp textureManager.cpp tileMap.cpp ./math/vector2D.cpp

# output (target)
TARGET = engine

# commands
all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINKERFLAGS) -o $(TARGET)

clean:
	rm $(TARGET)
