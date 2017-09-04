#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>
#define BIN_SH "/data/data/com.termux/files/usr/bin/sh";
#define USR_BIN_ENV "/data/data/com.termux/files/usr/bin/env";
int execve(const char *filename, char *const argv[], char *const envp[]) {
	FILE *fp;
	char buffer[1024], *buffer_p, *buffer_e, *fgets_ret;
	int (*real_execve)(const char *filename, char *const argv[], char *const envp[]) = NULL;
	const char *newFilename;
	char **newArgv;
	int argc;

	newFilename = filename;
	newArgv = (char **) argv;

	if (strcmp(filename, "/usr/bin/env") == 0) {
		newFilename = USR_BIN_ENV;
		goto final;
	}

	if (strcmp(filename, "/bin/sh") == 0) {
		newFilename = BIN_SH;
		goto final;
	}
	fp = fopen(filename, "r");
	if (fp == NULL) {
		goto final;
	}
	fgets_ret = fgets(buffer, sizeof(buffer), fp);
	fclose(fp);

	if (fgets_ret != buffer) {
		goto final;
	}

	if (strlen(buffer) < 3) {
		goto final;
	}

	if (buffer[strlen(buffer) - 1] != '\n') {
		goto final;
	}
	buffer[strlen(buffer) - 1] = '\0';

	if (buffer[0] != '#' || buffer[1] != '!') {
		goto final;
	}

	buffer_p = buffer;
	buffer_p += 2;

	while (buffer_p[0] == ' ') {
		buffer_p++;
	}

	buffer_e = strchr(buffer_p, ' ');
	if (buffer_e != NULL) {
		*buffer_e = '\0';
		buffer_e++;
	}

	if (strcmp(buffer_p, "/usr/bin/env") !=0  && strcmp(buffer_p, "/bin/sh") != 0)  {
		goto final;
	}
	
	if  (strcmp(buffer_p, "/bin/sh") ==0 ){
        newFilename = USR_BIN_ENV;
        for (argc = 0; argv[argc]; argc++) {}

        argc++;
        newArgv = malloc(sizeof(*newArgv) * (argc + 3));
        newArgv[0] = USR_BIN_ENV;
	newArgv[1] =  "sh"; 
	newArgv[2] = buffer_e;
        
	for (argc = 0; argv[argc]; argc++) {
                newArgv[argc + 2] = argv[argc];
        }
        newArgv[argc + 2] = NULL;
	}
	if  (strcmp(buffer_p, "/usr/bin/env") ==0 ){
        newFilename = USR_BIN_ENV;
        for (argc = 0; argv[argc]; argc++) {}

        argc++;
        newArgv = malloc(sizeof(*newArgv) * (argc + 3));
        newArgv[0] = USR_BIN_ENV;
        newArgv[1] = buffer_e;

        for (argc = 0; argv[argc]; argc++) {
                newArgv[argc + 2] = argv[argc];
        }
        newArgv[argc + 2] = NULL;
        }	
final:
        real_execve = dlsym(RTLD_NEXT, "execve");

        return(real_execve(newFilename, newArgv, envp));
}
