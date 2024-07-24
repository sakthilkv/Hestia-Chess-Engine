#include "bitboard.h"

using namespace std;


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

