#include "cafe_queue.h"

struct Queue *init_queue(Order new_order) {
    struct Queue *queue = (struct Queue *)calloc(sizeof(struct Queue), sizeof(struct Queue));
    queue->next = NULL;
    queue->order = new_order;
    return queue;
}

void push(struct Queue *queue, Order new_order) {
    struct Queue *new_item = (struct Queue *)calloc(sizeof(struct Queue), sizeof(struct Queue));
    while (queue->next != NULL) {
        queue = queue->next;
    }
    queue->next = new_item;
    new_item->order = new_order;
    new_item->next = NULL;
}

struct Queue *pop(struct Queue *queue) {
    struct Queue *tmp = queue->next;
    free(queue);
    return tmp;
}

void destroy(struct Queue *queue) {
    struct Queue *tmp = queue;
    while (tmp != NULL) {
        tmp = pop(queue);
    }
}