#ifndef CAFE_QUEUE_H
#define CAFE_QUEUE_H

#include <stdlib.h>

#define MAX_LEN_STR 1025

typedef struct {
    char order[MAX_LEN_STR];
    int price;
} Order;

struct Queue {
    struct Queue *next;
    Order order;
};

struct Queue *init_queue(Order new_order);
void push(struct Queue *queue, Order new_order);
struct Queue *pop(struct Queue *queue);
void destroy(struct Queue *queue);

#endif