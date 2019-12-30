#include <iostream>
#include "/usr/local/include/pbc/pbc.h"
#include "Cryptosystem.hh"
using namespace std;

int main() {
    // define variables
//    pairing_t pairing;
//    pbc_param_t par;
//    element_t g, h;
//
//    // initialization
//    pbc_param_init_a_gen(par, 160, 512);
//    pairing_init_pbc_param(pairing, par);
//
//
//    element_init_G2(g, pairing);
//    element_init_G1(h, pairing);
//
//    // get value
//    element_random(g);
//    element_random(h);
//
//    // print test
//    cout << "g=" << g << endl;
//    cout << "h=" << h << endl;

    Cryptosystem cryptosystem;
    cryptosystem.get_random_prime(256);

    return 0;
}