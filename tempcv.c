#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float toCelcius(float tempIn, char mode) {
    float tempOut = 0;
    switch (mode) {
        case 'c':
            return tempIn;
        case 'f': 
            tempOut = tempIn - 32;
            tempOut = tempOut * 5 / 9;
            return tempOut;
        case 'k':
            tempOut = tempIn - 273.15;
            return tempOut;
        case 'r':
            tempOut = tempIn * 5 / 9 - 273.15;
            return tempOut;
        case 'e':
            tempOut = tempIn * 5 / 4;
            return tempOut;
        case 'o':
            tempOut = tempIn - 7.5;
            tempOut = tempOut * 40 / 21;
            return tempOut;
        case 'd':
            tempOut = 100 - tempIn * 2 / 3;
            return tempOut;
    }
}
float toKelvin(float tempIn, char mode) {
    float tempOut = toCelcius(tempIn, mode) + 273.15;
    return tempOut;
}
float toFehrenheit(float tempIn, char mode) {
    float tempOut = toCelcius(tempIn, mode) * 9 / 5 + 32;
    return tempOut;
}
float toRankine(float tempIn, char mode) {
    float tempOut = toFehrenheit(tempIn, mode) + 459.67;
    return tempOut;
}
float toRomer(float tempIn, char mode) {
    float tempOut = toCelcius(tempIn, mode) * 21 / 40 + 7.5;
    return tempOut;
}
float toReaumur(float tempIn, char mode) {
    float tempOut = toCelcius(tempIn, mode) * 4 / 5;
    return tempOut;
}
float toDelisle(float tempIn, char mode) {
    float tempOut = 100 - toCelcius(tempIn, mode);
    tempOut = tempOut * 3/2;
    return tempOut;
}
int main (int argc, char** argv) {
    if (argc > 1 && !strcmp(argv[1], "--help")) {
        printf("Usage: tempcv [TEMPERATURE] [SCALE]\nOutput a temperature converted to many different scales.\nSupported units are [k]elvin, [c]elcius, [f]ehrenheit, [r]ankine, R[o]mer, R[e]aumur, [d]elisle.\n\n  --help        Print this help dialog and exit.\n");
        return 0;
    }
    if (argc == 3) {
        printf("%.2fK\n%.2fC\n%.2fF\n%.2fRa\n%.2fRo\n%.2fRe\n%.2fD\n", toKelvin(atof(argv[1]), argv[2][0]), toCelcius(atof(argv[1]), argv[2][0]), toFehrenheit(atof(argv[1]), argv[2][0]), toRankine(atof(argv[1]), argv[2][0]), toRomer(atof(argv[1]), argv[2][0]), toReaumur(atof(argv[1]), argv[2][0]), toDelisle(atof(argv[1]), argv[2][0]));
    } else {
        printf("invalid args\n");
        return -1;
    }
    return 0;
}
