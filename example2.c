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
    mpc_t a, b, c, result;
    char *str;
    mpc_init(&a, "973237146278946812938743753465782356783465783467823678564378653478346378");
    mpc_init(&b, "28472389473289472389473289047023894032974823");
    mpc_mul(&c, a, b);
    mpc_copy(&result, &c);
    mpc_tostr(&result, &str);
    printf("a*b: %s\n", str);
    mpc_destroy(&result);
    mpc_destroy(&c);
    mpc_destroy(&b);
    mpc_destroy(&a);
    return 0;
}
