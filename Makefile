CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors `sdl-config --cflags`
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image -lcmocka -lm -lSDL_ttf
VPATH=model:view:controller

OBJS=main.o

TEST_OBJS=

all: aoe_like

aoe4: $(OBJS) $(TEST_OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)
	@mkdir ./obj
	@mv *.o ./obj

main.o :


%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	@rm -f aoe4
	@rm -f *.o *.gcno *.gcda *.save
	@rm -r ./obj
	
