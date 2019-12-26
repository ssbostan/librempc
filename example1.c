/*
 *  libreMPC is Multiple Precision Arithmetic
 *
 *  Copyright (c) 2014 Saeid Bostandoust <ssbostan@gmail.com>
 *
 *  BSD 3-Clause "New" or "Revised" License.
 *
 *  @link http://bostandoust.ir/
 *  @link http://github.com/ssbostan/libreMPC/
 *
 */

#include <stdio.h>
#include <mpc.h>

int main(int argc, char *argv[]) {
    mpc_t a, b, result;
    char *str;
    mpc_init(&a, "98765432123432777664998989880098512738");
    mpc_init(&b, "9929376103284789101034214807236201092843287127236017540403");
    mpc_add(&result, a, b);
    mpc_tostr(&result, &str);
    printf("a+b: %s\n", str);
    mpc_destroy(&result);
    mpc_destroy(&b);
    mpc_destroy(&a);
    return 0;
}
