#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {
    char j[3] = "-j";
    char g[3] = "-g";
    char w[3] = "-w";
    char h[3] = "-h";

    char *hours[] = {" zwölf",    "eins", "zwei", "drei", "vier", "fünf", "sechs",
        "sieben", "acht", "neun", "zehn", "elf",  "zwölf"};
    char *whours[] = {" zwölf",    "eins", "zwei", "dry", "vier", "fünf", "sechs",
        "sieben", "acht", "neun", "zehn", "elf",  "zwölf"};
    char *htmlhours[] = {" ",         "eins",  "zwei",      "drei", "vier",
        "f&uuml;nf", "sechs", "sieben",    "acht", "neun",
        "zehn",      "elf",   "zw&ouml;lf"};
    char *guddaff[] = {" ",
        "uhr",
        "kurz nach",
        "viertel nach",
        "kurz vor halb",
        "halb",
        "kurz nach halb",
        "viertel vor",
        "kurz vor"};
    char *wucke[] = {" ",
        "uhr",
        "kurz nach",
        "viertel nach",
        "kurz vor halb",
        "halb",
        "kurz nach halb",
        "viertel vor",
        "kurz vor"};
    char *jessica[] = {" ",
        "um",
        "kurz nach",
        "viertel",
        "kurz vor halb",
        "halb",
        "kurz nach halb",
        "dreiviertel",
        "kurz vor"};
    int8_t midx = 0, hnow = 0, mnow = 0, hnext = 0;
    bool hrover = false;
    time_t now;
    struct tm *now_tm;
    now = time(NULL);
    now_tm = localtime(&now);
    hnow = now_tm->tm_hour;
    mnow = now_tm->tm_min;

    if (hnow >= 13) {
        hnow = hnow - 12;
    }

    if (hnow == 12) {
        hnext = 1;
    } else {
        hnext = hnow + 1;
    }

    if (mnow >= 0 && mnow <= 2) {
        midx = 1;
        hrover = false;
    } else if (mnow >= 3 && mnow <= 12) {
        midx = 2;
        hrover = false;
    } else if (mnow >= 13 && mnow <= 17) {
        midx = 3;
        hrover = false;
    } else if (mnow >= 18 && mnow <= 27) {
        midx = 4;
        hrover = false;
    } else if (mnow >= 28 && mnow <= 32) {
        midx = 5;
        hrover = false;
    } else if (mnow >= 33 && mnow <= 42) {
        midx = 6;
        hrover = false;
    } else if (mnow >= 43 && mnow <= 47) {
        midx = 7;
        hrover = false;
    } else if (mnow >= 48 && mnow <= 57) {
        midx = 8;
        hrover = false;
    } else if (mnow >= 58 && mnow <= 59) {
        midx = 1;
        hrover = true;
    } else {
        printf("\x1b[31m[ ERROR ] \x1b[0m so mach ich das immer mit die minuten\n");
    }

    // Debug ausgaben
    // printf("h: %s",h);
    // printf("m: %s",m);
    // printf("hnext: %d\n", hnext);
    // printf("hnow: %d\n", hnow);
    // printf("mnow: %d\n", mnow);
    // printf("midx: %d\n\n", midx);

    if (argc == 2) {
        if (strcmp(argv[1], j) == 0) {
            if ((midx <= 2) && (hrover == true)) {
                printf("%s %s\n", jessica[midx], hours[hnext]);
            } else if ((midx <= 2) && (hrover == false)) {
                printf("%s %s\n", jessica[midx], hours[hnow]);
            } else {
                printf("%s %s\n", jessica[midx], hours[hnext]);
            }
        } else if (strcmp(argv[1], g) == 0) {
            if ((midx == 1) && (hrover == true)) {
                printf("%s %s\n", hours[hnext], guddaff[midx]);
            } else if ((midx == 1) && (hrover == false)) {
                printf("%s %s\n", hours[hnow], guddaff[midx]);
            } else if (midx >= 1 && midx <= 3) {
                printf("%s %s\n", guddaff[midx], hours[hnow]);
            } else {
                printf("%s %s\n", guddaff[midx], hours[hnext]);
            }
        } else if (strcmp(argv[1], w) == 0) {
            if ((midx == 1) && (hrover == true)) {
                printf("%s %s\n", whours[hnext], wucke[midx]);
            } else if ((midx == 1) && (hrover == false)) {
                printf("%s %s\n", whours[hnow], wucke[midx]);
            } else if (midx >= 1 && midx <= 3) {
                printf("%s %s\n", wucke[midx], whours[hnow]);
            } else {
                printf("%s %s\n", wucke[midx], whours[hnext]);
            }
        } else if (strcmp(argv[1], h) == 0) {
            if ((midx <= 2) && (hrover == true)) {
                printf("%s %s\n", jessica[midx], htmlhours[hnext]);
            } else if ((midx <= 2) && (hrover == false)) {
                printf("%s %s\n", jessica[midx], htmlhours[hnow]);
            } else {
                printf("%s %s\n", jessica[midx], htmlhours[hnext]);
            }
        } else {
            printf("\x1b[31m[ ERROR ] \x1b[0m Not a supportet argument.\n");
        }
    } else if (argc > 2) {
        printf("\x1b[31m[ ERROR ] \x1b[0m Too many arguments supplied.\n");
    } else {
        printf("\x1b[31m[ ERROR ] \x1b[0m Too few arguments supplied.\n");
    }
    fflush(stdout);
}
