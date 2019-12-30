//
// Created by root on 12/28/19.
//
#include <python3.5/Python.h>
#include "Cryptosystem.hh"
void Cryptosystem::get_random_prime(int num_bits) {
    // create the storage number
    mpz_t p;
    mpz_init(p);

    // get a random n-bit number
    pbc_mpz_randomb(p, num_bits);

    // get the next prime
    mpz_nextprime(p, p);

    char *s = mpz_get_str(NULL, 10, p);

    cout << s << endl;



    free(s);

    // get the mpz as a string
//    PyObject *rand_prime = mpz_to_pynum(p);

    // clean up the mpz's
    mpz_clear(p);

//    return rand_prime;
}