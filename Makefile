CC=g++
CFLAGS=-Wall -Wextra -pedantic-errors `sdl-config --cflags`
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image -lcmocka -lm -lSDL_ttf
VPATH=model:view:controller

OBJS=main.o characterType.o resourceType.o resource.o character.o math_utils.o 

TEST_OBJS=

all: aoe_like

aoe_like: $(OBJS) $(TEST_OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)
	@mkdir ./obj
	@mv *.o ./obj

main.o:characterType.o resourceType.o
characterType.o: character.o
resourceType.o:resource.o
character.o: math_utils.o


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	@rm -f aoe_like
	@rm -f *.o *.gcno *.gcda *.save
	@rm -r ./obj
	
