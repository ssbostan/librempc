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

#ifdef __cplusplus
  extern "C" {
#endif

#include "mpc.h"

int mpc_init(mpc_t *dst, char *src) {
    int i, slen;
    if(!src) return -1;
    if(!(dst->value=(char*) malloc((slen=strlen(src))))) return -1; // daryafte hafeze baraye adad dar heap.
    for(i=0; i<slen; i++)
        *(dst->value+i)=*(src+i) ^ 0x30; // tabdile code ascii be adad va zakhire dar struct.
    dst->len=slen; // zakhireye toole adad dar struct.
    return 0;
}

int mpc_destroy(mpc_t *ptr) {
    if(!ptr->value && !ptr->len)
        return 0;
    free(ptr->value); // azad kardane hafezeye gerefte shode az heap.
    ptr->value=NULL; // sefr kardane addresse adad.
    ptr->len=0; // sefr kardane toole adad.
    return 0;
}

int mpc_copy(mpc_t *dst, mpc_t *src) {
    int i;
    if(!src->value || src->len<=0) return -1;
    if(!(dst->value=(char*) malloc(src->len))) return -1; // daryafte hafezeye jadid dar heap.
    for(i=0; i<src->len; i++)
        *(dst->value+i)=*(src->value+i); // copy (src) dar (dst).
    dst->len=src->len; // toole adad.
    return 0;
}

int mpc_tostr(mpc_t *src, char **dst) {
    int i, ptr;
    if(!src->value || src->len<=0) return -1;
    for(ptr=0; !*(src->value+ptr); ptr++); // nadide gereftane sefr haye poshte adad.
    if(!(*dst=(char*) malloc(src->len-ptr+1))) return -1; // daryafte hafeze baraye zakhireye reshte dar heap.
    for(i=0; i<src->len-ptr; i++)
        *(*dst+i)=*(src->value+ptr+i) ^ 0x30; // tabdile adad be code ascii va zakhire dar (dst).
    *(*dst+src->len-ptr)=0x0; // akhare reshte.
    return 0;
}

int mpc_add(mpc_t *dst, mpc_t op1, mpc_t op2) {
    int i, mlen;
    mpc_t *less, *more;
    if(op1.len<=0 || op2.len<=0)
        return -1;
    less=op1.len>op2.len ? &op2 : &op1; // addresse adad ba toole kamtar.
    more=op1.len>op2.len ? &op1 : &op2; // addresse adad ba toole bishtar.
    mlen=op1.len>op2.len ? op1.len : op2.len; // toole adade bishtar.
    if(!(dst->value=(char*) calloc(mlen+1, 1))) return -1; // daryafte hafeze (mlen+1) baraye (dst) dar heap.
    for(i=0; i<less->len; i++)
        *(dst->value+mlen+1-less->len+i)=*(less->value+i); // copy adad haye (less) dar (dst).
    for(i=more->len-1; i>=0; i--) {
        *(dst->value+mlen+1-more->len+i) += *(more->value+i); // jame (dst) ba adad ba toole bishtar.
        *(dst->value+mlen-more->len+i)   += *(dst->value+mlen+1-more->len+i) / 10; // jame (dst-1) ba carry az jame (dst)+(more).
        *(dst->value+mlen+1-more->len+i) %= 10; // hazfe meghdare carry az (dst).
    }
    dst->len=mlen+1; // toole adade bedast amade.
    return 0;
}

int mpc_mul(mpc_t *dst, mpc_t op1, mpc_t op2) {
    int i, j, mlen;
    if(op1.len<=0 || op2.len<=0)
        return -1;
    mlen=op1.len+op2.len; // toole hafezeye morede niyaz.
    if(!(dst->value=(char*) calloc(mlen, 1))) return -1; // daryafte hafeze (mlen) baraye (dst) dar heap.
    for(i=op2.len-1; i>=0; i--) { // halghe baraye adad haye op2.
        for(j=op1.len-1; j>=0; j--) { // halghe baraye adad haye op1.
            *(dst->value+i+j+1) += *(op2.value+i) * *(op1.value+j); // jame (dst) ba op2*op1.
            *(dst->value+i+j)   += *(dst->value+i+j+1) / 10; // jame (dst-1) ba carry (dst)+op2*op1.
            *(dst->value+i+j+1) %= 10; // hazfe meghdare carry az (dst).
        }
        *(dst->value+i+j+1) += *(dst->value+i+j); // jame carry be vojood amade dar akharin amaliyat.
    }
    dst->len=mlen; // toole adade bedast amade.
    return 0;
}

// implementations goes here.

#ifdef __cplusplus
  }
#endif
