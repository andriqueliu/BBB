#include <stdio.h>
// #include <time.h>
#include <unistd.h>

#define GPIO_PIN 20

// Test
// Code...
int main()
{
    FILE *sys, *dir, *val;
    
    //
    sys = fopen("/sys/class/gpio/export", "w");
    
    fprintf(sys, "%d", GPIO_PIN);
    fflush(sys);

    dir = fopen("/sys/class/gpio/gpio20/direction", "w");

    fprintf(dir, "%s", "out");
    fflush(dir);

    val = fopen("/sys/class/gpio/gpio20/value", "w");
    int value = 0;

    while (1) {
        value = ~value;
        fprintf(val, "%d", value);
        fflush(val);
        usleep(500000);
    }

    fclose(sys);
    fclose(dir);
    fclose(val);
}


