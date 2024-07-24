#ifndef MOVE_HPP
#define MOVE_HPP

#include "bitboard.h"
#include "chessboard.hpp"
#include "magic.hpp"
#include <iostream>

using namespace std;

extern U64 pawnAttackTable[2][64];
extern U64 knightAttackTable[64];
extern U64 kingAttackTable[64];

U64 generatePawnAttacks(int side, int square);

U64 generateKnightAttacks(int square);

U64 generateKingAttacks(int square);

void initLeapersAttacks();

#endif // MOVE_HPP
