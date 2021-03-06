/*
 * main.cpp
 *
 *  Created on: Jul 5, 2011
 *      Author: admin
 */

#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "jsonencoder.cpp"
#include <libgearman/gearman.h>
#include "grammar.h"
#include "lexglobal.h"

#define BUFS 1024
int state = 0;

extern FILE *yyin;
typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern "C" {
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *);
void yy_delete_buffer(YY_BUFFER_STATE);
}

int getState() {
	return state;
}

void switchOn(int type) {
	state = type;
}

void *do_parse(gearman_job_st *job, void *context, size_t *result_size,
		gearman_return_t *ret_ptr) {

	int yv;
	char *buf;
	JSONEncoder json = JSONEncoder();
	buf = strdup((char *) gearman_job_workload(job));

	yy_scan_string(buf);

	// on EOF yylex will return 0
	while ((yv = yylex()) != 0) {

		int token = yv;
		char *value = (char*) yysval.sval;

		switch (token) {
		case LIKES:
			switchOn(LIKES);
			break;
		case HATES:
			switchOn(HATES);
			break;
		case FROM:
			switchOn(FROM);
			break;
		case MOODS:
			switchOn(MOODS);
			break;
		case INFO:
			switchOn(INFO);
			break;

		case VALUE:
			Data *data = Data::getInstance();

			switch (getState()) {
			case LIKES:
				data->likes.push_back(value);
				break;
			case HATES:
				data->hates.push_back(value);
				break;
			case INFO:
				data->info.push_back(value);
				break;
			case MOODS:
				data->moods.push_back(value);
				break;
			case FROM:
				data->from.push_back(value);
				break;

			default:
				data->vals.push_back(value); //push all the vals to a list if no identifier is present
				break;

			}
		}

	}

	char* result = strdup(json.encodeParsed());
	*result_size = strlen(result);
	*ret_ptr = GEARMAN_SUCCESS;

	Data::getInstance()->free();
	state=0;

	return result;

}

int main() {

	gearman_worker_st worker;
	gearman_worker_create(&worker);
	gearman_worker_add_server(&worker, "localhost", 0);

	gearman_worker_add_function(&worker, "parser", 0, do_parse, NULL);

	while (1) {
		gearman_worker_work(&worker);
	}

}

