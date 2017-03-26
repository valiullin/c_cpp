#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 1024 /* MAX NUMBER OF LINES */
#define MAXC 1024 /* MAX NUMBER OF CHARS IN LINE */


int main(int argc, char *argv[]) {
	FILE *file;
	
	if (argc > 2) {
		printf("You should write only 1 filename\n"); 
		exit(1);
	}

	if ((file = fopen(argv[1], "r"))) {
		int i = 0;
		char line_prev[MAXC];
		char line_mid[MAXC];
		char line_next[MAXC];

		while (fgets(line_next, MAXC, file)) {
			if ((strchr(line_next, '\n') == NULL) || (strchr(line_next, EOF) != NULL)) {
				printf("Line #%d in file '%s' is longer than MAXC=%d\n", i+1, argv[1], MAXC);
				exit(1);
			}
			if (strchr(line_next, '\n') != NULL) {
				line_next[strlen(line_next) - 1] = '\0';
			}
			
			if (i == 0) {
				strcpy(line_mid, line_next);
			}

			if (i >= 1) {
				if (strcmp(line_mid, line_prev) && strcmp(line_mid, line_next)){
					printf("%s\n", line_mid);
				}
				strcpy(line_prev, line_mid);
				strcpy(line_mid, line_next);
			}

			if (i > MAXL) {
				printf("Number of lines in file '%s' is more than MAXL=%d\n", argv[1], MAXL);
				exit(1);
			}

			i++;

		}

		if (strcmp(line_prev, line_mid)) {
			printf("%s\n", line_mid);
		}

		return 0;
	}

	else {
		printf("Sorry, file '%s' does not exist.\n", argv[1]);
		exit(1);
	}

}
