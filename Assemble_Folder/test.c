// long arith(long x, long y, long z) {
//     long t1 = x ^ y;
//     long t2 = z * 48;
//     long t3 = t1 & 0x0F0F0F0F;
//     long t4 = t2 - t3;
//     return t4;
// }

// long arith2(long x, long y, long z) {
//     long t1 = x | y;
//     long t2 = t1 >> 3;
//     long t3 = ~t2;
//     long t4 = z - t3;
//     return t4;
// }

// #include <inttypes.h>

// typedef unsigned __int128 uint128_t;

// void store_uprod(uint128_t * dest, uint64_t x, uint64_t y) {
//     *dest = x * (uint128_t) y;
// }

// void remdiv(long x, long y, long * qp, long * rp) {
//     long q = x / y;
//     long r = x % y;
//     * qp = q;
//     * rp = r;
// }

// #include <stdio.h>

// int main(void) {
//     int i = 2;
//     printf("Hello, World! %d\n", 2 + i);
//     return 0;
// }

long test(long x, long y, long z) {
    long val = x + y + z;
    if (x < -3) {
        if (y < z) {
            val = x * y;
        }
        else {
            val = y * z;
        }
    } else if (x > 2) {
        val = x * z;
    }
    return val;
}