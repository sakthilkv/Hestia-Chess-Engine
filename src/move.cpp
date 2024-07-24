#include "bitboard.h"
#include "chessboard.hpp"


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


//Sliding Pieces

U64 generateBishopAttacks(int square)
{
	U64 mask_attack = 0ULL;

	int rank, file, target_rank = square/8, target_file = square%8;


	/*When the rank increases, it goes down and when file increases, it goes right.    */
	//down-right
	for (rank = target_rank + 1, file = target_file + 1; rank <= 6 && file <= 6; rank++, file++)
		mask_attack |= (1ULL << ((rank * 8) + file));

	//up-right
	for (rank = target_rank - 1, file = target_file + 1; rank >= 1 && file <= 6; rank--, file++)
		mask_attack |= (1ULL << ((rank * 8) + file));

	//up-left
	for (rank = target_rank + 1, file = target_file - 1; rank <= 6 && file >= 1; rank++, file--)
		mask_attack |= (1ULL << ((rank * 8) + file));

	//down-left
	for (rank = target_rank - 1, file = target_file - 1; rank >= 1 && file >= 1; rank--, file--)
		mask_attack |= (1ULL << ((rank * 8) + file));

	return mask_attack;
}

U64 generateBishopAttacksWithBlockage(int square, U64 blockage)
{
	U64 mask_attack = 0ULL;

	int rank, file, target_rank = square/8, target_file = square%8;


	/*When the rank increases, it goes down and when file increases, it goes right.    */

	//down-right
	for (rank = target_rank + 1, file = target_file + 1; rank <= 7 && file <= 7; rank++, file++)
	{
		mask_attack |= (1ULL << ((rank * 8) + file));
		if ((1ULL << ((rank * 8) + file)) & blockage)
			break;
	}

	//up-right
	for (rank = target_rank - 1, file = target_file + 1; rank >= 0 && file <= 7; rank--, file++)
	{
		mask_attack |= (1ULL << ((rank * 8) + file));
		if ((1ULL << ((rank * 8) + file)) & blockage)
			break;
	}

	//up-left
	for (rank = target_rank + 1, file = target_file - 1; rank <= 7 && file >= 0; rank++, file--)
	{
		mask_attack |= (1ULL << ((rank * 8) + file));
		if ((1ULL << ((rank * 8) + file)) & blockage)
			break;
	}

	//down-left
	for (rank = target_rank - 1, file = target_file - 1; rank >= 0 && file >= 0; rank--, file--)
	{
		mask_attack |= (1ULL << ((rank * 8) + file));
		if ((1ULL << ((rank * 8) + file)) & blockage)
			break;
	}

	return mask_attack;
}


U64 generateRookAttacks(int square)
{
	U64 mask_attack = 0ULL;

	int rank, file, target_rank = square/8, target_file = square%8;


	/*When the rank increases, it goes down and when file increases, it goes right.    */
	//down
	for (rank = target_rank + 1; rank <= 6; rank++)
		mask_attack |= (1ULL << ((rank * 8) + target_file));

	//up
	for (rank = target_rank - 1; rank >= 1; rank--)
		mask_attack |= (1ULL << ((rank * 8) + target_file));

	//right
	for (file = target_file + 1; file <= 6; file++)
		mask_attack |= (1ULL << ((target_rank * 8) + file));

	//down-left
	for (file = target_file - 1; file >= 1; file--)
		mask_attack |= (1ULL << ((target_rank * 8) + file));

	return mask_attack;
}

U64 generateRookAttacksWithBlockage(int square, U64 blockage)
{
	U64 mask_attack = 0ULL;

	int rank, file, target_rank = square/8, target_file = square%8;


	/*When the rank increases, it goes down and when file increases, it goes right.    */
	//down
	for (rank = target_rank + 1; rank <= 7; rank++)
	{
		mask_attack |= (1ULL << ((rank * 8) + target_file));
		if ((1ULL << ((rank * 8) + target_file)) & blockage)
			break;
	}

	//up
	for (rank = target_rank - 1; rank >= 0; rank--)
	{
		mask_attack |= (1ULL << ((rank * 8) + target_file));
		if ((1ULL << ((rank * 8) + target_file)) & blockage)
			break;
	}

	//right
	for (file = target_file + 1; file <= 7; file++)
	{
		mask_attack |= (1ULL << ((target_rank * 8) + file));
		if ((1ULL << ((target_rank * 8) + file)) & blockage)
			break;
	}

	//left
	for (file = target_file - 1; file >= 0; file--)
	{
		mask_attack |= (1ULL << ((target_rank * 8) + file));
		if ((1ULL << ((target_rank * 8) + file)) & blockage)
			break;
	}

	return mask_attack;
}


U64 set_occupancy(int idx, int bits_in_mask, U64 mask_attack)
{
	U64 occupancy  = 0ULL;

	for (int count = 0; count < bits_in_mask; count++)
	{
		int square = get_lsbidx(attack_mask);

		pop_countbit(mask_attack, square);

		if (idx & (1 << count))
			occupancy |= (1ULL << square);
	}
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




int main(){
	//g++ move.cpp -o move && move.exe
	//g++ -o move move.cpp chessboard.cpp -I"C:/SFML/include" -L"C:/SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system
	//initLeapersAttacks();

	for (int idx = 0; idx < 4096; idx++)
	{
		
	}
	//int piece_pos = c7;
    //displayChessboard(blockage, generateKnightAttacks(piece_pos),piece_pos);
	return 0;
}