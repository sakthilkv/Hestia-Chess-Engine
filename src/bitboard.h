#ifndef BITBOARD_H
#define BITBOARD_H

#include <iostream>

using namespace std;

#define U64 unsigned long long
#define get_bit(bitboard,square) ((bitboard & (1ULL << square)))
#define set_bit(bitboard,square) (bitboard |= (1ULL << square))
#define pop_bit(bitboard,square) (get_bit(bitboard,square) ? bitboard ^= (1ULL << square) : 0)

enum {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};


enum { white, black };

const U64 FileA = 72340172838076673ULL;
const U64 FileB = 144680345676153346ULL;
const U64 FileC = 289360691352306692ULL;
const U64 FileD = 578721382704613384ULL;
const U64 FileE = 1157442765409226768ULL;
const U64 FileF = 2314885530818453536ULL;
const U64 FileG = 4629771061636907072ULL;
const U64 FileH = 9259542123273814144ULL;

//For Debugging
void print_bitboard(U64 bitboard)
{
    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file++)
        {
            int square = (rank * 8) + file;

            if (!file)
                cout << " " << 8 - rank << " ";

            cout << " " <<  (get_bit(bitboard,square) ? 1 : 0);
        }

        cout << "\n";
    }

    cout << "\n    a b c d e f g h\n\n";

    cout << "    Bitboard: " << bitboard << '\n';
}

#endif //Hestia
