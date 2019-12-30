//
// Created by root on 12/28/19.
//

#ifndef CPPSSWIMPL_CRYPTOSYSTEM_HH
#define CPPSSWIMPL_CRYPTOSYSTEM_HH

#include <iostream>
#include "/usr/local/include/pbc/pbc.h"
using namespace std;

class Cryptosystem {
    public:
        void get_random_prime(int num_bits);

};


//class QueryRewrite {
//public:
//    QueryRewrite(bool wasRes, ReturnMeta rmeta, const KillZone &kill_zone,
//                 AbstractQueryExecutor *const executor)
//            : rmeta(rmeta), kill_zone(kill_zone),
//              executor(std::unique_ptr<AbstractQueryExecutor>(executor)) {}
//    QueryRewrite(QueryRewrite &&other_qr) : rmeta(other_qr.rmeta),
//                                            executor(std::move(other_qr.executor)) {}
//    const ReturnMeta rmeta;
//    const KillZone kill_zone;
//    std::unique_ptr<AbstractQueryExecutor> executor;
//};
#endif //CPPSSWIMPL_CRYPTOSYSTEM_HH
