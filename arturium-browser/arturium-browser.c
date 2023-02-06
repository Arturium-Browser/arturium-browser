#ifdef __linux__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
char *browser[] = {"python3 /opt/arturium-browser/resources/plugin.py &> /tmp/arturium.log || echo $(cat /tmp/arturium.log). Exiting ; rm /tmp/arturium.log 2>/dev/null"};
char *id = {"id -u"};
if(id=0) {
    printf("Cannot start %s with root", argv[0]);
    return 1;
}

if(argc<2) {
    system(browser[0]);
    return 0;
}

if(argc>2) {
    system("echo ' WARN: Supported is only one argument'");
}

if(!strcmp(argv[1], "--version")) {
    printf("  %s  v0.287.2", argv[0]);
    system("echo 'License: GNU Generic Public License v3'");
    return 0;
}

if(!strcmp(argv[1], "--help")) {
    system("echo 'Supported options:'");
    system("echo '    --help                  This help screen'");
    system("echo '    --version               Show version and exit'");
    return 0;
}

if(!strcmp(argv[1], argv[1])) {
    printf("Unsupported argument: %s", argv[1]);
    return 1;
}

}
#endif
#ifdef __windows__
#   error "Your system is not supported :("
#endif
