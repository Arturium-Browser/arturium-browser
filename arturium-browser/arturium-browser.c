#ifdef __linux__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	char *browser[] = {"python3 resources/plugin.py &> /tmp/arturium.log || echo $(cat /tmp/arturium.log). Exiting; rm -f /tmp/arturium.log"};
if (geteuid() == 0) {
	printf(" ERR: Cannot start %s with root user\n\r", argv[0]);
	exit(1);
}

if(argc<2) {
	system(browser[0]);
	exit(0);
}
if(argc>2) {
	printf(" WARN: Supported is only one argument\n\r");
}

if(!strcmp(argv[1], "--version")) {
	printf("  %s  v0.287.2\n\r", argv[0]);
	printf("License: GNU Generic Public License v3\n\r");
	exit(0);
}

if(!strcmp(argv[1], "--help")) {
	printf("Supported options:\n\r");
	printf("    --help					This help screen\n\r");
	printf("    --version				Show version and exit\n\r");
	printf("    --install-deps			Install dependencies\n\r");
	exit(0);
}

if(!strcmp(argv[1], "--install-deps")) {
	system("python3 -m pip install -r requirements.txt --user --no-warn-script-location");
	exit(0);
}

if(!strcmp(argv[1], argv[1])) {
	printf(" ERR: Unsupported argument: %s\n\r", argv[1]);
	exit(1);
}

}
#endif
#ifdef __windows__
#	error "Your system is not supported :("
#endif
