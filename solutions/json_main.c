#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "json_list.h"

void usage(const char *prog) {
	    fprintf(stderr, "Usage: %s -i <file.json>\n", prog);
	        exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
	    int opt;
	        char *filename = NULL;

		    while ((opt = getopt(argc, argv, "i:")) != -1) {
			            if (opt == 'i') {
					                filename = optarg;
							        } else {
									            usage(argv[0]);
										            }
				        }

		        if (!filename) {
				        usage(argv[0]);
					    }

			    JObject *head = parse_json(filename);
			        if (!head) {
					        fprintf(stderr, "Fehler beim Parsen der JSON-Datei.\n");
						        return EXIT_FAILURE;
							    }

				    print_list(head);
				        free_list(head);

					    return EXIT_SUCCESS;
}

