#include <jansson.h>
typedef struct JObject {
	    char *name;
	        int age;
		    struct JObject *next;
} JObject;

JObject* parse_json(const char *filename);
void     print_list(JObject *head);
void     free_list(JObject *head);
