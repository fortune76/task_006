#ifndef CAFE_H
#define CAFE_H

#include <stdio.h>
#include <string.h>

#include "cafe_queue.h"
#define MENU 5

typedef struct {
    int kitchen_orders_count;
    int kitchen_orders_price;
    int bar_orders_count;
    int bar_orders_price;
} Stats;

static char *menu_commands[MENU] = {"EXIT", "ORDER", "BAR", "KITCHEN", "STATS"};

void cafe();
int menu();
void normalize_str(char *str);
struct Queue *new_kitchen_order(struct Queue *kitchen_queue, char *kitchen_order);
struct Queue *new_bar_order(struct Queue *bar_queue, char *bar_order);
struct Queue *kitchen_pop(struct Queue *queue, Stats *statistics);
struct Queue *bar_pop(struct Queue *queue, Stats *statistics);
void show_statistics(Stats const *statistics);

#endif