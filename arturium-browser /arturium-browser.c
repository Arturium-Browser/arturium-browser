#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//
#ifdef __windows__
#   error "Your system is not supported :("
#endif
#define browser
int main(void)
{
    char * const run[] = {"python3 ./plugin.py &> /tmp/arturium-browser.log || echo $(cat /tmp/arturium-browser.log). Exiting"};

    return system(run[0]);
    exit(EXIT_SUCCESS);
}
