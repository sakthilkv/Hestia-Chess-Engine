#ifndef MAGIC_HPP
#define MAGIC_HPP

typedef unsigned long long U64;

unsigned int generate_rand_U32();
U64 generate_rand_U64();
U64 generate_magic_number();
U64 generateBishopAttacks(int square);
U64 generateBishopAttacksWithBlockage(int square, U64 blockage);
U64 generateRookAttacks(int square);
U64 generateRookAttacksWithBlockage(int square, U64 blockage);
U64 set_occupancy(int idx, int bits_in_mask, U64 mask_attack);
U64 find_magic_number(int square, int relevant_bits, int slider);
void init_magic_numbers();
static inline U64 get_bishop_attacks(int square, U64 occupancy);
static inline U64 get_rook_attacks(int square, U64 occupancy);
void init_sliders_attack(int slider);
#endif // MAGIC_HPP