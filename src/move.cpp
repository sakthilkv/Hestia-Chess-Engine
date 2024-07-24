#include "bitboard.h"
#include "chessboard.hpp"
#include "magic.hpp"
#include <iostream>

using namespace std;
U64 pawnAttackTable[2][64];
U64 knightAttackTable[64];
U64 kingAttackTable[64];


U64 generatePawnAttacks(int side, int square)
{
	U64 mask_attack = 0ULL;

	U64 bitboard = 0ULL;

	set_bit(bitboard,square);

	if (!side)
	{
		if ((bitboard >> 7) & ~FileA)
			mask_attack |= (bitboard >> 7);

		if ((bitboard >> 9) & ~FileH)
			mask_attack |= (bitboard >> 9);
	}
	else
	{
		if ((bitboard << 7) & ~FileH)
			mask_attack |= (bitboard << 7);

		if ((bitboard << 9) & ~FileA)
			mask_attack |= (bitboard << 9);
	}

	return mask_attack;
}

U64 generateKnightAttacks(int square)
{
	U64 mask_attack = 0ULL;

	U64 bitboard = 0ULL;

	set_bit(bitboard,square);

	if ((bitboard >> 17) & ~FileH)
		mask_attack |= (bitboard >> 17);

	if ((bitboard >> 15) & ~FileA)
		mask_attack |= (bitboard >> 15);

	if ((bitboard >> 10) & ~(FileG | FileH))
		mask_attack |= (bitboard >> 10);

	if ((bitboard >> 6) & ~(FileA | FileB))
		mask_attack |= (bitboard >> 6);

	//downside

	if ((bitboard << 17) & ~FileA)
		mask_attack |= (bitboard << 17);

	if ((bitboard << 15) & ~FileH)
		mask_attack |= (bitboard << 15);

	if ((bitboard << 10) & (~FileA & ~FileB))
		mask_attack |= (bitboard << 10);

	if ((bitboard << 6) & (~FileG & ~FileH))
		mask_attack |= (bitboard << 6);

	return mask_attack;
}

U64 generateKingAttacks(int square)
{
	U64 mask_attack = 0ULL;

	U64 bitboard = 0ULL;

	set_bit(bitboard,square);

	if ((bitboard >> 8))
		mask_attack |= (bitboard >> 8);

	if ((bitboard >> 7) & ~FileA)
		mask_attack |= (bitboard >> 7);

	if ((bitboard >> 9) & ~FileH)
		mask_attack |= (bitboard >> 9);
	
	if ((bitboard >> 1) & ~FileH)
		mask_attack |= (bitboard >> 1);


	if ((bitboard << 8))
		mask_attack |= (bitboard << 8);

	if ((bitboard << 7) & ~FileH)
		mask_attack |= (bitboard << 7);

	if ((bitboard << 9) & ~FileA)
		mask_attack |= (bitboard << 9);

	if ((bitboard << 1) & ~FileA)
		mask_attack |= (bitboard << 1);

	return mask_attack;
}




void initLeapersAttacks()
{
	for (int square = 0; square < 64; square++)
	{
		pawnAttackTable[white][square] = generatePawnAttacks(white,square);
		pawnAttackTable[black][square] = generatePawnAttacks(black,square);

		knightAttackTable[square] = generateKnightAttacks(square);

		kingAttackTable[square] = generateKingAttacks(square);
	}
}





