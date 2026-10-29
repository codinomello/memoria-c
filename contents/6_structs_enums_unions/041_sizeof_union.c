#include <stdio.h>

#include "041_sizeof_union.h"

int main() {
    printf("size of int_or_err_message_t: %zu bytes\n", sizeof(int_or_err_message_t));
    printf("size of sensor data union: %zu bytes\n", sizeof(union SensorData));
    printf("size of packet payload union: %zu bytes\n", sizeof(union PacketPayload));
    printf("size of item union: %zu bytes\n", sizeof(union Item));
    
    return 0;
}