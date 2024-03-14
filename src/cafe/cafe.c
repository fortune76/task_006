#include "cafe.h"

#include "cafe_queue.h"

int main() {
    cafe();
    exit(EXIT_SUCCESS);
}

void cafe() {
    struct Queue *kitchen_queue = NULL;
    struct Queue *bar_queue = NULL;
    Stats statistics = {0, 0, 0, 0};
    Stats *statistics_ptr = &statistics;
    char kitchen_order[MAX_LEN_STR] = {0};
    char bar_order[MAX_LEN_STR] = {0};
    int menu_command = menu();
    while (menu_command != 0) {
        switch (menu_command) {
            case -1:
                printf("UNKNOWN COMMAND\n");
                break;
            case 1:
                /* Добавление нового заказа */
                kitchen_queue = new_kitchen_order(kitchen_queue, kitchen_order);
                bar_queue = new_bar_order(bar_queue, bar_order);
                break;
            case 2:
                /* Бар */
                if (bar_queue != NULL) {
                    bar_queue = bar_pop(bar_queue, statistics_ptr);
                } else {
                    printf("NO ORDERS\n");
                }
                break;
            case 3:
                /* Кухня */
                if (kitchen_queue != NULL) {
                    kitchen_queue = kitchen_pop(kitchen_queue, statistics_ptr);
                } else {
                    printf("NO ORDERS\n");
                }
                break;
            case 4:
                /* Статистика */
                show_statistics(statistics_ptr);
                break;
            default:
                destroy(kitchen_queue);
                destroy(bar_queue);
                break;
        }
        menu_command = menu();
    }
}

int menu() {
    char menu_command[MAX_LEN_STR];
    scanf("%1024s", menu_command);
    int result = -1;
    for (int i = 0; i < MENU; i++) {
        if (strcmp(menu_command, menu_commands[i]) == 0) {
            result = i;
        }
    }
    return result;
}

struct Queue *new_kitchen_order(struct Queue *kitchen_queue, char *kitchen_order) {
    int kitchen_price;
    /* ловим перенос строки */
    getchar();
    fgets(kitchen_order, MAX_LEN_STR - 1, stdin);
    scanf("%d\n", &kitchen_price);
    normalize_str(kitchen_order);
    Order kitchen = {"", kitchen_price};
    strcat(kitchen.order, kitchen_order);
    if (kitchen_queue == NULL) {
        kitchen_queue = init_queue(kitchen);
    } else {
        push(kitchen_queue, kitchen);
    }
    return kitchen_queue;
}

struct Queue *new_bar_order(struct Queue *bar_queue, char *bar_order) {
    int bar_price;
    fgets(bar_order, MAX_LEN_STR - 1, stdin);
    scanf("%d", &bar_price);
    normalize_str(bar_order);
    Order bar = {"", bar_price};
    strcat(bar.order, bar_order);
    if (bar_queue == NULL) {
        bar_queue = init_queue(bar);
    } else {
        push(bar_queue, bar);
    }
    return bar_queue;
}

void normalize_str(char *str) {
    int len = strlen(str);
    char tmp_str[MAX_LEN_STR] = {0};
    for (int i = 0; i < len; i++) {
        if (str[i] == '\n') {
            break;
        }
        tmp_str[i] = str[i];
    }
    for (int i = 0; i < len; i++) {
        str[i] = 0;
    }
    strcpy(str, tmp_str);
}

struct Queue *kitchen_pop(struct Queue *queue, Stats *statistics) {
    printf("%s\n", queue->order.order);
    statistics->kitchen_orders_count++;
    statistics->kitchen_orders_price += queue->order.price;
    queue = pop(queue);
    return queue;
}

struct Queue *bar_pop(struct Queue *queue, Stats *statistics) {
    printf("%s\n", queue->order.order);
    statistics->bar_orders_count++;
    statistics->bar_orders_price += queue->order.price;
    queue = pop(queue);
    return queue;
}

void show_statistics(Stats const *statistics) {
    printf("KITCHEN %d %d\nBAR %d %d\n", statistics->kitchen_orders_count, statistics->kitchen_orders_price,
           statistics->bar_orders_count, statistics->bar_orders_price);
}