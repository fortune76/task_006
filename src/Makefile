GC=gcc
FLAGS=-Wall -Wextra -Werror
BIN=../bin/
AIR_TRAFFIC=air_traffic_task/
CAFE=cafe_task/

all: air_traffic cafe

air_traffic: $(AIR_TRAFFIC)air_traffic.c
	$(GC) $(FLAGS) $(AIR_TRAFFIC)air_traffic.c -o $(BIN)air_traffic

cafe: $(CAFE)cafe_queue.c $(CAFE)cafe.c 
	$(GC) $(FLAGS) $(CAFE)cafe_queue.c $(CAFE)cafe.c -o $(BIN)cafe

clean:
	rm -f $(BIN)*

rebuild:
	clean all