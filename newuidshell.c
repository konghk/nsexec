#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
        if (argc < 2) exit(1);
        int id = atoi(argv[1]);
        int ret = setgid(id);
        if (ret) {
                perror("setgid");
                exit(1);
        }
        ret = setuid(id);
        if (ret) {
                perror("setuid");
                exit(1);
        }
        execl("/bin/bash", "/bin/bash", NULL);
	return -1;  // notreached
}
