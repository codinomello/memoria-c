#pragma once

#include <stdint.h>

typedef struct TCP {
    uint16_t src_port;
    uint16_t dest_port;
    uint16_t seq_num;
} tcp_t;

typedef union PacketHeader {
    tcp_t tcp;
    uint8_t raw[sizeof(tcp_t)];
} packet_header_t;