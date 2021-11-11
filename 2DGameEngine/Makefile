TARGET = runner
BASEDIR = engine
ECSDIR = $(BASEDIR)/ECS
GLOBALDIR = $(BASEDIR)/global
MATHDIR = $(BASEDIR)/math
OBJS = main.cpp $(BASEDIR)/*.cpp $(MATHDIR)/*.cpp
OUTDIR = ./bin
CC = g++
CLFAGS = -w
LINKERFLAGS = -lSDL2 -lSDL2_image

# main target build (runs when make is typed)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINKERFLAGS) -o $(OUTDIR)/$(TARGET)

# run the executable
test:
	clear
	./$(OUTDIR)/$(TARGET)	

# clean up the directory
clean: 
	clear
	rm $(OUTDIR)/$(TARGET)