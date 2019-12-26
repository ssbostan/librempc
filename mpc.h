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

#ifndef __MPC_H__
#define __MPC_H__

#ifdef __cplusplus
  extern "C" {
#endif

#include <malloc.h>
#include <string.h>

struct mpc_struct // struct baraye negahdariye adad.
{
    char *value; // addresse adad dar heap.
    int len; // toole adad.
};

typedef struct mpc_struct mpc_t; // datatype az rooye struct adad.

int mpc_init(mpc_t *, char *); // tabdile reshteye adadi be struct.
int mpc_destroy(mpc_t *); // free kardane heap va sefr kardane struct.
int mpc_copy(mpc_t *, mpc_t *); // copy kardane struct dar struct digar.
int mpc_tostr(mpc_t *, char **); // tabdile struct be reshte.
int mpc_add(mpc_t *, mpc_t, mpc_t); // jame 2 structe init shode va zakhire dar struct aval.
int mpc_mul(mpc_t *, mpc_t, mpc_t); // zarb 2 structe init shode va zakhire dar struct aval.

// implementations goes here.

#ifdef __cplusplus
  }
#endif

#endif
