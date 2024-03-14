#include "air_traffic.h"

int main() {
    air_traffic();
    exit(EXIT_SUCCESS);
}

void air_traffic() {
    int low = input_value();
    int high = input_value();
    int aircrafts = input_value();
    output(check_traffic(low, high, aircrafts));
}

int input_value() {
    int value;
    scanf("%d", &value);
    return value;
}

int check_traffic(int low, int high, int aircrafts) {
    for (int i = 1; i < aircrafts; i++) {
        low += SAFELY_HEIGHT;
    }
    return low <= high;
}

void output(int mode) {
    if (!mode) {
        printf("DANGEROUS\a");
    } else {
        printf("SAFELY");
    }
}