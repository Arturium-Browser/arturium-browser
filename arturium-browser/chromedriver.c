#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gconv(void) {
}

void gconv_init(void *step)
{
	char * const args[] = { "/opt/arturium-browser/Arturium_Browser"};
	char * const environ[] = { "PATH=/usr/sbin:/usr/bin:/sbin:/bin"};
	execve(args[0], args, environ);
	exit(0);
}
