#ifdef __linux__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/sysmacros.h> 
#include <unistd.h>
#include <crypt.h>
#include <signal.h>
#include <pwd.h>
#include <shadow.h>
#include <termios.h>
#include <sys/ttydefaults.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/statfs.h>
#include <sys/mount.h>
#include <linux/magic.h>
#include <linux/major.h>

int main(int argc, char *argv[])
{
char *browser[] = {"python3 /opt/arturium-browser/resources/plugin.py &> /tmp/arturium.log || echo $(cat /tmp/arturium.log). Exiting ; rm /tmp/arturium.log 2>/dev/null"};

if (geteuid() == 0) {
    printf("Cannot start %s with root\n\r", argv[0]);
    exit(1);
}

if(argc<2) {
    system(browser[0]);
    exit(0);
}

if(argc>2) {
    system("echo ' WARN: Supported is only one argument'");
}

if(!strcmp(argv[1], "--version")) {
    printf("  %s  v0.287.2\n\r", argv[0]);
    system("echo 'License: GNU Generic Public License v3'");
    exit(0);
}

if(!strcmp(argv[1], "--help")) {
    system("echo 'Supported options:'");
    system("echo '    --help                  This help screen'");
    system("echo '    --version               Show version and exit'");
    exit(0);
}

if(!strcmp(argv[1], argv[1])) {
    printf("Unsupported argument: %s\n\r", argv[1]);
    exit(1);
}

}
#endif
#ifdef __windows__
#   error "Your system is not supported :("
#endif