#define browser
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//
#ifdef __windows__
#   error "Your system is not supported :("
#endif
int main(void)
{
    char * const run[] = {"python3 ../../opt/arturium-browser/resources/plugin.py &> /tmp/arturium-browser.log || echo $(cat /tmp/arturium-browser.log). Exiting"};

    return system(run[0]);
    exit(EXIT_SUCCESS);

}
