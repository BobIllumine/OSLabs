//
// Created by hered on 03.11.2021.
//
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

static const char *const evval[3] = {
        "RELEASED",
        "PRESSED",
        "REPEATED"
};

int main(int argc, char **argv) {
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event ev;
    ssize_t n;
    int fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }
    while(1) {
        n = read(fd, &ev, sizeof ev);
        if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2)
            printf("%s 0x%04x (%d)\n", evval[ev.value], (int)ev.code, (int)ev.code);
    }
    fflush(stdout);
    return 0;
}

