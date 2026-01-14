#include <stdio.h>

#include "042_helper_fields.h"

int main() {
    packet_header_t header;
    header = (packet_header_t) {
        .tcp = (tcp_t) {
            .src_port = 8080,
            .dest_port = 80,
            .seq_num = 12345
        }
    };
    printf("source port: %u\n", header.tcp.src_port);
    printf("destination port: %u\n", header.tcp.dest_port);
    printf("sequence number: %u\n", header.tcp.seq_num);

    return 0;
}