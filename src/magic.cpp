#include "magic.hpp"
#include "bitboard.h"
#include <string.h>
const int bishop_relevant_bits[64] = {
    6, 5, 5, 5, 5, 5, 5, 6,
    5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 7, 7, 7, 7, 5, 5,
    5, 5, 7, 9, 9, 7, 5, 5,
    5, 5, 7, 9, 9, 7, 5, 5,
    5, 5, 7, 7, 7, 7, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5,
    6, 5, 5, 5, 5, 5, 5, 6,
};


const int rook_relevant_bits[64] = {
    12, 11, 11, 11, 11, 11, 11, 12,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    12, 11, 11, 11, 11, 11, 11, 12,
};


U64 rook_magic_numbers[64] = {
    0x8001810200420ULL,
    0x4000440621811200ULL,
    0x100e400a8048002ULL,
    0x200520402014140ULL,
    0x80200840a001808ULL,
    0x4090808148101ULL,
    0x2000e022004000a4ULL,
    0x810011009200010ULL,
    0x150040010045101ULL,
    0x41401320091008ULL,
    0x22808288031ULL,
    0x840048102080000ULL,
    0x1a02002820002020ULL,
    0x510000894120410ULL,
    0x4812001860831201ULL,
    0x2400400200b010ULL,
    0x2000112094809242ULL,
    0x2820021b4000980ULL,
    0x1024880040040ULL,
    0x10808020d0200200ULL,
    0x8000440403006402ULL,
    0x1000062080080ULL,
    0x2002460004008c00ULL,
    0x300650236408022ULL,
    0x2288008090600ULL,
    0x1001014220040110ULL,
    0x202a010208000820ULL,
    0x21a0c04000840022ULL,
    0x2002020020101000ULL,
    0x91100100710ULL,
    0x203000824400800ULL,
    0x6408c208100404ULL,
    0x4008020300008820ULL,
    0x800190040051e02ULL,
    0x40405008109ULL,
    0x6040100002002ULL,
    0x1090808200040200ULL,
    0x40120040400906ULL,
    0x4802002621042800ULL,
    0x1018a009229214ULL,
    0x220101008210490ULL,
    0x60000b58200000b0ULL,
    0x450022020000c2ULL,
    0x32003184800040ULL,
    0x80501041410a0402ULL,
    0x52c0008080ae0056ULL,
    0x5000218308100901ULL,
    0x415000410d020ULL,
    0x10821080232250ULL,
    0x3000d0088040000ULL,
    0x10000204220022ULL,
    0x1100580008580002ULL,
    0x8501308020484000ULL,
    0x808c020014c4200ULL,
    0x821001302001100ULL,
    0x9401080310420048ULL,
    0x20018040404420ULL,
    0x1000010400210100ULL,
    0x2300082803104008ULL,
    0x42040ac04004d026ULL,
    0x200b0020028086ULL,
    0x2010300a048100ULL,
    0x280044496401080ULL,
    0x1200406303012206ULL

};

U64 bishop_magic_numbers[64] = {
    0x8a1002060c00e0ULL,
    0x2010024214082000ULL,
    0xa44081220410800ULL,
    0x244400802d4010ULL,
    0x184042000000054ULL,
    0x160202a2440003ULL,
    0x202442258401012ULL,
    0x4202110101085ULL,
    0x1060213890408288ULL,
    0xb8202809350820ULL,
    0x404100112002400ULL,
    0x4600404008a0002ULL,
    0x4c01040422221021ULL,
    0x8824120600509ULL,
    0x244c008210022002ULL,
    0x84002a0049180820ULL,
    0x920101142900900ULL,
    0x2404006028220841ULL,
    0x1000120382000dULL,
    0x8001041404011ULL,
    0x8803400a02000ULL,
    0x1810048044002ULL,
    0x6008808044100808ULL,
    0x202000109010104ULL,
    0x3182400022180240ULL,
    0x8201043660041401ULL,
    0x18004804010e0402ULL,
    0x480a040008010820ULL,
    0x2194082044002002ULL,
    0x2008a20001004200ULL,
    0x40908041041004ULL,
    0x881002200540404ULL,
    0x4001082002082101ULL,
    0x8110408880880ULL,
    0x8000404040080200ULL,
    0x200020082180080ULL,
    0x1184440400114100ULL,
    0xc220008020110412ULL,
    0x4088084040090100ULL,
    0x8822104100121080ULL,
    0x100111884008200aULL,
    0x2844040288820200ULL,
    0x90901088003010ULL,
    0x1000a218000400ULL,
    0x1102010420204ULL,
    0x8414a3483000200ULL,
    0x6410849901420400ULL,
    0x201080200901040ULL,
    0x204880808050002ULL,
    0x1001008201210000ULL,
    0x16a6300a890040aULL,
    0x8049000441108600ULL,
    0x2212002060410044ULL,
    0x100086308020020ULL,
    0x484241408020421ULL,
    0x105084028429c085ULL,
    0x4282480801080cULL,
    0x81c098488088240ULL,
    0x1400000090480820ULL,
    0x4444000030208810ULL,
    0x1020142010820200ULL,
    0x2234802004018200ULL,
    0xc2040450820a00ULL,
    0x2101021090020ULL

};





static unsigned int state = 1804289383;

unsigned int generate_rand_U32()
{
    unsigned int number = state;

    number ^= number << 13;
    number ^= number >> 17;
    number ^= number << 5;

    state = number;

    return number;
}

U64 generate_rand_U64()
{
    U64 r1, r2, r3, r4;
    r1 = (U64)(generate_rand_U32() & 0xFFFF);
    r2 = (U64)(generate_rand_U32() & 0xFFFF);
    r3 = (U64)(generate_rand_U32() & 0xFFFF);
    r4 = (U64)(generate_rand_U32() & 0xFFFF);

    return r1 | (r2 << 16) | (r3 << 32) | (r4 << 48);
}

U64 generate_magic_number()
{
    return generate_rand_U64() & generate_rand_U64() & generate_rand_U64();
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
        int square = get_lsbidx(mask_attack);

        pop_bit(mask_attack, square);

        if (idx & (1 << count))
            occupancy |= (1ULL << square);

    }

    return occupancy;
}


U64 find_magic_number(int square, int relevant_bits, int slider)
{
    U64 occupancies[4096];

    U64 attacks[4096];

    U64 used_attacks[4096];

    U64 mask_attack = bishop ? generateBishopAttacks(square) : generateBishopAttacks(square);

    int occupancy_indicies = 1 << relevant_bits;

    for (int idx = 0; idx < occupancy_indicies; idx++)
    {
        occupancies[idx] = set_occupancy(idx, relevant_bits, mask_attack);

        attacks[idx] = bishop ? generateBishopAttacksWithBlockage(square, occupancies[idx]) : generateRookAttacksWithBlockage(square, occupancies[idx]);

    }

    for (int rc = 0; rc < 100000000; rc++)
    {
        U64 magic_number = generate_magic_number();

        if (count_bit((mask_attack * magic_number) & 0xFF00000000000000) < 6)
            continue;
        memset(used_attacks, 0ULL, sizeof(used_attacks));
    
        int idx, flag;

        for (idx = 0, flag = 0; !flag && idx < occupancy_indicies; idx++)
        {
            int magic_idx = (int) ((occupancies[idx] * magic_number) >> (64 - relevant_bits));
        
            if (used_attacks[magic_idx] == 0ULL)
                used_attacks[magic_idx] = attacks[idx]; 

            else if (used_attacks[magic_idx] != attacks[idx])
                flag = 1;

        }


        if (!flag)
            return magic_number;
    }

    return 0ULL;
}


void init_magic_numbers()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    for (int square = 0; square < 64; square++)
    {
        //printf("0x%llxULL,\n", find_magic_number(square, rook_relevant_bits[square], rook));
        rook_magic_numbers[square] = find_magic_number(square, rook_relevant_bits[square], rook);
    }
    for (int square = 0; square < 64; square++)
        printf("0x%llxULL,\n", find_magic_number(square, bishop_relevant_bits[square], bishop));
}