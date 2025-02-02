#include "io_data.h"
#include "string.h"

int get_input_data_tst(const char *__restrict, ...) {
    return 0;
}

static IO_TEST_CONFIG_INPUT_DATA st_default_config;

void reset_put_data(void) {
    memset(&st_default_config, 0, sizeof(st_default_config));
}

void config_put_data(IO_TEST_CONFIG_INPUT_DATA *st_config) {
    memcpy(&st_default_config, st_config, sizeof(st_default_config));
}

int put_output_data_tst(const char *__restrict, ...) {
    return 0;
}
