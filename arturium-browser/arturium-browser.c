#define browser
#include <stdio.h>

#ifdef __windows__
#include <Windows.h>

int main(void)
{
    char * const run[] = {"python C:/Program Files/Arturium Browser/resources/plugin.py"};

    return system(run[0]);
    exit(EXIT_SUCCESS);
}
#endif

#ifdef __linux__
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char * const run[] = {"python3 ./resources/plugin.py &> /tmp/arturium-browser.log || echo $(cat /tmp/arturium-browser.log). Exiting"};

    return system(run[0]);
    exit(EXIT_SUCCESS);
}
#endif
