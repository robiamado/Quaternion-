#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "Quaternione++.h"
using namespace std;

ostream& operator<<(ostream& o, quaternione q)
{
	if (q.coeff_rif[1] < 0)	// {-i , -i-j , -i-k, -i-j-k}
	{
		if (q.coeff_rif[2] < 0)	// {-i-j , -i-j-k}
		{
			if (q.coeff_rif[3] < 0)	// -i-j-k
			{
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // i+j+k
					return o << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // j+k
					return o << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) // i+k
					return o << q.coeff_rif[1] << "i" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) // i+j
					return o << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << "\n";

				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0) 	// n
					return o << q.coeff_rif[0] << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// i
					return o << q.coeff_rif[1] << "i" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// j
					return o << q.coeff_rif[2] << "j" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) 	// k
					return o << q.coeff_rif[3] << "k" << "\n";

				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) 	// n+j+k
					return o << q.coeff_rif[0] << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+i+k
					return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) 	// n+i+j
					return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << "\n";

				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// n+i
					return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << "\n";
				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// n+j
					return o << q.coeff_rif[0] << q.coeff_rif[2] << "j" << "\n";
				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+k
					return o << q.coeff_rif[0] << q.coeff_rif[3] << "k" << "\n";

				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// 0
					return o << "0";

				else
					return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
			}
			else	// -i-j
			{
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // i+j+k
					return o << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // j+k
					return o << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) // i+k
					return o << q.coeff_rif[1] << "i+" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) // i+j
					return o << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << "\n";

				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0) 	// n
					return o << q.coeff_rif[0] << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// i
					return o << q.coeff_rif[1] << "i" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// j
					return o << q.coeff_rif[2] << "j" << "\n";
				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) 	// k
					return o << q.coeff_rif[3] << "k" << "\n";

				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) 	// n+j+k
					return o << q.coeff_rif[0] << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+i+k
					return o << q.coeff_rif[0] << q.coeff_rif[1] << "i+" << q.coeff_rif[3] << "k" << "\n";
				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) 	// n+i+j
					return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << "\n";

				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// n+i
					return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << "\n";
				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// n+j
					return o << q.coeff_rif[0] << q.coeff_rif[2] << "j" << "\n";
				if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+k
					return o << q.coeff_rif[0] << "+" << q.coeff_rif[3] << "k" << "\n";

				if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// 0
					return o << "0";

				else
					return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
			}
		}
		if (q.coeff_rif[3] < 0)	// -i-k
		{
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // i+j+k
				return o << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // j+k
				return o << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) // i+k
				return o << q.coeff_rif[1] << "i" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) // i+j
				return o << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0) 	// n
				return o << q.coeff_rif[0] << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// i
				return o << q.coeff_rif[1] << "i" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// j
				return o << q.coeff_rif[2] << "j" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) 	// k
				return o << q.coeff_rif[3] << "k" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) 	// n+j+k
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+i+k
				return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) 	// n+i+j
				return o << q.coeff_rif[0] << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// n+i
				return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// n+j
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[2] << "j" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+k
				return o << q.coeff_rif[0] << q.coeff_rif[3] << "k" << "\n";

			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// 0
				return o << "0";

			else
				return o << q.coeff_rif[0] << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
		}
		else	// -i
		{
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // i+j+k
				return o << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // j+k
				return o << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) // i+k
				return o << q.coeff_rif[1] << "i+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) // i+j
				return o << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0) 	// n
				return o << q.coeff_rif[0] << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// i
				return o << q.coeff_rif[1] << "i" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// j
				return o << q.coeff_rif[2] << "j" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) 	// k
				return o << q.coeff_rif[3] << "k" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) 	// n+j+k
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+i+k
				return o << q.coeff_rif[0] << q.coeff_rif[1] << "i+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) 	// n+i+j
				return o << q.coeff_rif[0] << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// n+i
				return o << q.coeff_rif[0] << q.coeff_rif[1] << "i" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// n+j
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[2] << "j" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+k
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[3] << "k" << "\n";

			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// 0
				return o << "0";

			else
				return o << q.coeff_rif[0] << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
		}
	};
	if (q.coeff_rif[2] < 0)	// {-j, -j-k}
	{
		if (q.coeff_rif[3] < 0) // -j-k
		{
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // i+j+k
				return o << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // j+k
				return o << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) // i+k
				return o << q.coeff_rif[1] << "i" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) // i+j
				return o << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0) 	// n
				return o << q.coeff_rif[0] << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// i
				return o << q.coeff_rif[1] << "i" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// j
				return o << q.coeff_rif[2] << "j" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) 	// k
				return o << q.coeff_rif[3] << "k" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) 	// n+j+k
				return o << q.coeff_rif[0] << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+i+k
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) 	// n+i+j
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// n+i
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// n+j
				return o << q.coeff_rif[0] << q.coeff_rif[2] << "j" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+k
				return o << q.coeff_rif[0] << q.coeff_rif[3] << "k" << "\n";

			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// 0
				return o << "0";

			else
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
		}
		else	// -j
		{
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // i+j+k
				return o << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // j+k
				return o << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) // i+k
				return o << q.coeff_rif[1] << "i+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) // i+j
				return o << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0) 	// n
				return o << q.coeff_rif[0] << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// i
				return o << q.coeff_rif[1] << "i" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// j
				return o << q.coeff_rif[2] << "j" << "\n";
			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) 	// k
				return o << q.coeff_rif[3] << "k" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) 	// n+j+k
				return o << q.coeff_rif[0] << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+i+k
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i+" << q.coeff_rif[3] << "k" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) 	// n+i+j
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j" << "\n";

			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// n+i
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// n+j
				return o << q.coeff_rif[0] << q.coeff_rif[2] << "j" << "\n";
			if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+k
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[3] << "k" << "\n";

			if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// 0
				return o << "0";

			else
				return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
		}
	};
	if (q.coeff_rif[3] < 0)	// -k
	{
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // i+j+k
			return o << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // j+k
			return o << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) // i+k
			return o << q.coeff_rif[1] << "i" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) // i+j
			return o << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << "\n";

		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0) 	// n
			return o << q.coeff_rif[0] << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// i
			return o << q.coeff_rif[1] << "i" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// j
			return o << q.coeff_rif[2] << "j" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) 	// k
			return o << q.coeff_rif[3] << "k" << "\n";

		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) 	// n+j+k
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+i+k
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) 	// n+i+j
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << "\n";

		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// n+i
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << "\n";
		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// n+j
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[2] << "j" << "\n";
		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+k
			return o << q.coeff_rif[0] << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// 0
			return o << "0";

		else
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << q.coeff_rif[3] << "k" << "\n";
	}
	else	// i+j+k
	{
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // i+j+k
			return o << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) // j+k
			return o << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) // i+k
			return o << q.coeff_rif[1] << "i+" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) // i+j
			return o << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << "\n";

		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0) 	// n
			return o << q.coeff_rif[0] << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// i
			return o << q.coeff_rif[1] << "i" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// j
			return o << q.coeff_rif[2] << "j" << "\n";
		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0) 	// k
			return o << q.coeff_rif[3] << "k" << "\n";

		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] != 0) 	// n+j+k
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+i+k
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i+" << q.coeff_rif[3] << "k" << "\n";
		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0) 	// n+i+j
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j" << "\n";

		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] != 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// n+i
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i" << "\n";
		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] != 0 && q.coeff_rif[3] == 0)	// n+j
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[2] << "j" << "\n";
		if (q.coeff_rif[0] != 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] != 0)	// n+k
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[3] << "k" << "\n";

		if (q.coeff_rif[0] == 0 && q.coeff_rif[1] == 0 && q.coeff_rif[2] == 0 && q.coeff_rif[3] == 0)	// 0
			return o << "0";

		else
			return o << q.coeff_rif[0] << "+" << q.coeff_rif[1] << "i+" << q.coeff_rif[2] << "j+" << q.coeff_rif[3] << "k" << "\n";
	}
};

const string esci = "quit", somma = "q+p", moltiplica = "q*p", 
moltiplica_1 = "p*q", cambia_q = "q=", cambia_p = "p=", h = "h", 
con_q = "q'", con_p = "p'", mod_q = "modq", mod_p = "modp", mostra = "show",
qugp = "q=p", pugq = "p=q", minq = "-q", minp = "-p", matrq = "matrq", 
matrp = "matrp",mod1_q = "qmod1", mod1_p = "pmod1", somma_1 = "p+q", 
matcq = "matcq", matcp = "matcp", sottra = "q-p", sottra_1 = "p-q",
cambia_v = "rotq", cambia_v2 = "rotp", invertiq = "invq", invertip = "invp", 
qdivp = "q/p", pdivq = "p/q", kutta = "euler";

double genera(double coeff_gen[4])
{
	bool var = false;

	do
	{
		cout << "\nEnter the real part \n\n";
		cin >> coeff_gen[0]; cout << "\n\n";
		if (cin.fail()) cin.clear(), 
			throw "\nError you did not type a number.\n";
		cout << "Insert the imaginary parts i,j,k \n\n";
		for (int i = 1; i <= 3; ++i) cin >> coeff_gen[i];
		if (cin.fail()) cin.clear(), 
			throw "Error you did not type a number.\n";
		if (coeff_gen[0] == 0 && coeff_gen[1] == 0 && coeff_gen[2] == 0 && 
			coeff_gen[3] == 0)
			cout << "\nInvalid values.Enter at least"
					"one value other than 0.\n";
		else var = true;
	} while (var == false);
	for (int i = 0; i <= 3;) return coeff_gen[i];
}

double genera_V(double coeff_gen[4])
{
	bool var = false;

	coeff_gen[0] = 0;
	do
	{
		cout << "Enter the three components i, j, k of the vector\n\n";
		for (int i = 1; i <= 3; ++i) cin >> coeff_gen[i];
		if (cin.fail()) cin.clear(), throw "\nError you did not type"
											"a number.\n";
		else var = true;
	} while (var == false);
	for (int i = 0; i <= 3;) return coeff_gen[i];
}

double genera_I(double coeff_gen[9])
{
	bool var = false;

	do
	{
		for (int i = 0; i < 9; ++i) coeff_gen[i] = 0;
		cout << "Enter the three main moments of inertia in ascending "
				"order \n\n";
		cin >> coeff_gen[0]; cin >> coeff_gen[4]; cin >> coeff_gen[8];
		if (cin.fail()) cin.clear(), throw "\nError you did not type a"
											"number.\n";
		if (coeff_gen[0] <= coeff_gen[4] && coeff_gen[4] <= coeff_gen[8] 
			&& coeff_gen[0] > 0 && coeff_gen[4] > 0 && coeff_gen[8] > 0)
			var = true;
		else cout << "\nEnter three increasing values," 
					"positive and non-null\n\n";
	} while (var == false);
	for (int i = 0; i < 9; ++i) return coeff_gen[i];
};

void aiuto()
{
	cout <<
		" *LIST OF COMMANDS*\n\n"
		"Command		Description				Equivalent\n\n"
		" h		\"command list\" \n"
		" quit		\"quit from program\" \n"
		" show		\"show quaternions\" \n"
		" q+p		\"sum Q and P\"				(<-> p+q) \n"
		" q-p		\"subtract Q and P\"				(<-> p-q) \n"
		" q*p		\"multiply Q and P\"			(<-> p*q) \n"
		" q/p		\"divide Q and P\"				(<-> p/q) \n"
		" q=		\"change / insert the values ​​of Q\"	(<-> p= ) \n"
		" rotq		\"rotate a vector V con Q\"		(<-> rotp) \n"
		" q'		\"complex conjugate of Q\"		(<-> p') \n"
		" invq		\"inverse of q\"				(<-> invp) \n"
		" modq		\"calculate Q module\"		(<-> modp) \n"
		" qmod1		\"makes Q of module 1\"	  		(<-> pmod1) \n"
		" matrq		\"shows Q as a real matrix\"		(<-> matrp) \n"
		" matcq		\"shows Q as a complex matrix\"	(<-> matcp) \n"
		" euler		\"equations of motion of a rigid body\" \n"
		"\n";
};

vettore fields(vettore omega0, vettore f, vettore incr)
{
	vettore A = omega0 + f.prodotto_con_falsoscalare(incr);
	return A;
}

template <typename arr1, typename arr2, typename quat1, typename ... Quat >
double integratore(arr1 coeff_Q[4], arr2 coeff_P[4], quat1 Q, Quat ... quatx)
{
	double coeff_inerzia[9], coeff_inerzia2[9], coeff_omega[4], coeff_tau[4];

	cout << "\nEnter the Inertia Tensor.\n\n";
	genera_I(coeff_inerzia);
	tens2 I(coeff_inerzia);
	I.couta_tens2();

	for (int i = 0; i < 9; ++i) coeff_inerzia2[i] = coeff_inerzia[i];
	coeff_inerzia2[0] = 1 / coeff_inerzia[0]; 
	coeff_inerzia2[4] = 1 / coeff_inerzia[4]; 
	coeff_inerzia2[8] = 1 / coeff_inerzia[8];

	vettore f(vettore omega_0, vettore tau, double coeff_inerzia[9], double coeff_inerzia2[9]);

	if (sizeof ... (Quat) == 0)
	{
		string input_2, input_3; const string fine, si = "y", no = "n"; 
		bool checkQ{ false };

		cout << "\n\n\nEnter the initial Angular Velocity."
				"\n\nUse an already entered quaternion? \"y/n\"\n\n";
		do
		{
			cin >> input_2, cout << "\n";
			if (input_2 == si)
			{
				cout << "\n\n\nYou entered Q=" << Q; 
				cout << "\nUse as angular velocity ?"
						"\n\n\"y\" to confirm, \"n\" to reject: ";
				do
				{
					cin >> input_3, cout << "\n";
					if (input_3 == si)
					{
						checkQ = true;
						coeff_omega[0] = 0;
						coeff_omega[1] = coeff_Q[1]; 
						coeff_omega[2] = coeff_Q[2]; 
						coeff_omega[3] = coeff_Q[3];
						input_2 = fine, input_3 = fine;
					}
					if (input_3 == no) 
					{ 
						genera_V(coeff_omega); 
						input_2 = fine; 
						input_3 = fine;
					}
					if (input_3 != fine) cout << "Command not defined," 
									"commands available: \"y/n\".\n\n";
				} while (input_3 != fine);
			}
			if (input_2 == no) genera_V(coeff_omega), input_2 = fine;
			if (input_2 == esci) exit(33);
			if (input_2 != fine) cout << "Command not defined,"
									"commands available: \"y/n\".\n\n";
		} while (input_2 != fine);

		vettore omega_0(coeff_omega);
		cout << "\n\n\nLa tua Velocita' Angolare e' \n\n Omega="; 
		omega_0.couta_vettore(); cout << "\n\n";
		// Torque menu
		cout << "Enter the Torque. \n\nUse an already entered quaternion?"
				"\"y/n\".\n\n";
		do
		{
			cin >> input_2, cout << "\n";
			if (input_2 == si)
			{
				if (checkQ == false) cout << "\n\n\nYou entered "
					"Q=" << Q; cout << "\nUse as Torque?\n\n\"y\" to"
					"confirm, \"n\" to reject: ";
				if (checkQ == true) cout << "\n\n\n\n\nHave you "
					"already used Q as angular velocity, use also as "
					"Torque?\n\Enter \"y\" to confirm, \"n\"to reject: ";
				do
				{
					cin >> input_3, cout << "\n";
					if (input_3 == si)
					{
						coeff_tau[0] = 0, coeff_tau[1] = coeff_Q[1]; 
						coeff_tau[2] = coeff_Q[2], coeff_tau[3] = coeff_Q[3];
						input_2 = fine, input_3 = fine;
					}
					if (input_3 == no)
					{
						genera_V(coeff_tau), input_2 = fine, input_3 = fine;
					}
					if (input_3 != no || input_3 != si) cout << "Command" 
						"not defined, commands available: \"y/n\".\n\n";
				} while (input_3 != fine);
			}
			if (input_2 == no) genera_V(coeff_tau), input_2 = fine;
			if (input_2 != fine) cout << "Command not defined," 
				"commands available: \"y/n\".\n\n";
		} while (input_2 != fine);
	}

	if (sizeof ... (Quat) == 1)
	{
		string input_2; const string fine, si = "y", no = "n"; 
		bool checkQ{ false }, checkP{ false };
		// angular velocity menu
		cout << "\n\n\nEnter the initial Angular Velocity."
			"\n \nUse an already entered quaternion?\"y/n\"\n\n";
		do
		{
			cin >> input_2, cout << "\n";
			if (input_2 == si)
			{
				string input_3; const string Qu = "q", Pi = "p";
				quaternione pack[1] = { quatx... };
				
				cout << "\n\n\nYou entered:\n\n Q=" << Q << "\n "
					"P=" << pack[0] << "\nWhich to use? \"q/p\"\n\n";
				do
				{
					cin >> input_3, cout << "\n";
					if (input_3 == Qu)
					{
						checkQ = true;
						coeff_omega[0] = 0; 
						coeff_omega[1] = coeff_Q[1]; 
						coeff_omega[2] = coeff_Q[2]; 
						coeff_omega[3] = coeff_Q[3];
						input_3 = fine, input_2 = fine;
					}
					if (input_3 == Pi)
					{
						checkP = true;
						coeff_omega[0] = 0; 
						coeff_omega[1] = coeff_P[1]; 
						coeff_omega[2] = coeff_P[2]; 
						coeff_omega[3] = coeff_P[3];
						input_3 = fine, input_2 = fine;
					}
					if (input_3 == no)
					{
						genera_V(coeff_omega);
						input_3 = fine;
						input_2 = fine;
					}
					if (input_3 != fine) cout << "Command not defined,"
						"commands available: \"q/p/n\".\n\n";
				} while (input_3 != fine);
			}
			if (input_2 == no) genera_V(coeff_omega), input_2 = fine;
			if (input_2 != fine) cout << "Command not defined,"
				"commands available: \"y/n\".\n\n";
		} while (input_2 != fine);

		vettore omega_0(coeff_omega);
		cout << "\n\n\nYour Angular Velocity ​​is \n\n "
			"Omega="; omega_0.couta_vettore(); cout << "\n\n";
		// torque menu
		cout << "Enter the Torque. \n \nUse an already "
			"entered quaternion? \"y/n\".\n\n";
		do
		{
			cin >> input_2, cout << "\n";
			if (input_2 == si)
			{
				string input_3; const string Qu = "q", Pi = "p";
				quaternione pack[1] = { quatx... };

				cout << "\n\n\nyou entered: \n\n Q=" << Q << "\n P=";
				cout << pack[0] << "\nWhich to use? \"q/p\"\n\n";
				do
				{
					cin >> input_3, cout << "\n";
					if (input_3 == Qu)
					{
						string input_4;

						if (checkQ == false)
						{
							coeff_tau[0] = 0; 
							coeff_tau[1] = coeff_Q[1]; 
							coeff_tau[2] = coeff_Q[2]; 
							coeff_tau[3] = coeff_Q[3];
							input_3 = fine, input_2 = fine;
						}
						if (checkQ == true)
						{
							cout << "\n\n\n\nYou already used Q as the" 
								"angular velocity, use it as Torque too?"
								"\n\nType \"y \" to confirm, \"n \" to" 
								"reject:";
							do
							{
								cin >> input_4, cout << "\n";
								if (input_4 == si)
								{
									coeff_tau[0] = 0; 
									coeff_tau[1] = coeff_Q[1]; 
									coeff_tau[2] = coeff_Q[2]; 
									coeff_tau[3] = coeff_Q[3];
									input_2 = fine, input_3 = fine;
									input_4 = fine;
								}
								if (input_4 == no)
								{
									genera_V(coeff_tau);
									input_2 = fine, input_3 = fine;
									input_4 = fine;
								}
								if (input_4 != fine) cout << "Command"
									"not defined, commands available:"
									"\"y/n\".\n\n";
							} while (input_4 != fine);
						}
					}
					if (input_3 == Pi)
					{
						string input_4;

						if (checkP == false)
						{
							coeff_omega[0] = 0; 
							coeff_tau[1] = coeff_P[1]; 
							coeff_tau[2] = coeff_P[2]; 
							coeff_tau[3] = coeff_P[3];
							input_3 = fine, input_2 = fine;
						}
						if (checkP == true)
						{
							cout << "\n\n\n\nYou already used P as the"
								"angular velocity, use it as Torque too?"
								"\n\nType \"y \" to confirm, \"n \" to"
								"reject:";
							do
							{
								cin >> input_4, cout << "\n";
								if (input_4 == si)
								{
									coeff_tau[0] = 0; 
									coeff_tau[1] = coeff_P[1]; 
									coeff_tau[2] = coeff_P[2]; 
									coeff_tau[3] = coeff_P[3];
									input_2 = fine, input_3 = fine;
									input_4 = fine;
								}
								if (input_4 == no)
								{
									genera_V(coeff_tau);
									input_2 = fine, input_3 = fine;
									input_4 = fine;
								}
								if (input_4 != fine) cout << "Command not"
									"defined, commands available:"
									"\"y/n\".\n\n";
							} while (input_4 != fine);
						}
					}
					if (input_3 == no)
					{
						genera_V(coeff_tau), input_2 = fine, input_3 = fine;
					}
					if (input_3 != fine) cout << "Command not"
						"defined, commands available: \"q/p/n\".\n\n";
				} while (input_3 != fine);
			}
			if (input_2 == no) genera_V(coeff_tau), input_2 = fine;
			if (input_2 != fine) cout << "Command not defined,"
				"commands available: \"y/n\".\n\n";
		} while (input_2 != fine);
	};

	// torque generation
	vettore tau(coeff_tau); vettore omega_0(coeff_omega);
	cout << "\n\n\nYour Torque is \n\n Tau="; tau.couta_vettore(); 
	cout << "\n\n";

	double coeff_h[4], coeff_hmez[4], coeff_sest[4], coeff_due[4];
	double coeff_unmez[4], incr;
	long T;

	cout << "\nEnter the increment in seconds (0.1 or smaller): "; 
	cin >> incr;
	if (cin.fail()) cin.clear(), throw "Error...\n\n";
	cout << "\n\nEnter the period: "; cin >> T;
	if (cin.fail()) cin.clear(), throw "Error...\n\n";

	coeff_h[0] = 0; coeff_hmez[0] = 0; coeff_sest[0] = 0; coeff_due[0] = 0; 
	coeff_unmez[0] = 0;
	for (int i = 1; i <= 3; ++i)
	{
		coeff_h[i] = incr, coeff_hmez[i] = incr / 2;
		coeff_sest[i] = incr / 6, coeff_due[i] = 2, coeff_unmez[i] = 0.5;
	}
	vettore h(coeff_h), hmez(coeff_hmez), hsest(coeff_sest), due(coeff_due);
	// auxiliary fields evaluation
	vettore fx = f(omega_0, tau, coeff_inerzia, coeff_inerzia2);
	vettore y = fields(omega_0, fx, hmez);
	vettore fy = f(y, tau, coeff_inerzia, coeff_inerzia2);
	vettore z = fields(omega_0, fy, hmez);
	vettore fz = f(z, tau, coeff_inerzia, coeff_inerzia2);
	vettore w = fields(omega_0, fz, h);
	vettore fw = f(w, tau, coeff_inerzia, coeff_inerzia2);
	// surplus becomes fx+(2*fy)+(2*fz)+fw.
	vettore surplus = fx + due.prodotto_con_falsoscalare(fy);
	surplus = surplus + due.prodotto_con_falsoscalare(fz) + fw;
	vettore surplus_hsest = hsest.prodotto_con_falsoscalare(surplus);

	vettore d[2], segnaposto; d[0] = omega_0;
	long counter = 0;
	do
	{
		if (counter == 0) // first integration with omega_0
		{
			d[1] = d[0] + surplus_hsest, ++counter;
			if (T >= 10e6) cout << "\nCalculation in progress...";
		}
		else // the following ones use (n-1)th+increase as nth value
		{
			segnaposto = d[1];
			d[1] = segnaposto + surplus_hsest, ++counter;
			if (counter == T)
			{
				cout << "\n\n\nThe angular velocity at time t=";
				cout << incr * T << "s e':\n\nomega=", d[1].couta_vettore();
				cout << "\n\nWith an error of ";
				cout << incr * incr * incr * incr << "s\n";
				vettore b = d[1];
				omega_0.prodotto_matrice(coeff_inerzia); 
				vettore K_i = omega_0.prodotto_con_falsoscalare(coeff_unmez); 
				cout << "\nThe initial kinetic energy is Ki=";
				cout << K_i.modulo() << "J" << endl;
				b.prodotto_matrice(coeff_inerzia); 
				vettore K_f = b.prodotto_con_falsoscalare(coeff_unmez); 
				cout << "\nThe final kinetic energy is Kf=";
				cout << K_f.modulo() << "J" << "\n\n";
			}
		}
	} while (counter != T);
};

vettore f(vettore omega, vettore tau, double coeff_inerzia[9], double coeff_inerzia2[9])
{
	// cout << "\nomega:"; omega.couta_vettore();
	vettore omega_D = omega;
	// cout << "\nomegaD:"; omega_D.couta_vettore();
	omega_D.prodotto_matrice(coeff_inerzia); // multiply omega 
	//vector times I tensor.
	// cout << "\nomega:"; omega.couta_vettore();
	// cout << "\nomega*D:"; omega_D.couta_vettore();
	vettore omega_mez = omega * omega_D; // vectors cross product
	// cout << "\nomegamez:"; omega_mez.couta_vettore();
	omega_mez.prodotto_matrice(coeff_inerzia2); // multiply omega 
	//vector times inverse I tensor.
	// cout << "\nomegamez*D_inv:"; omega_mez.couta_vettore();
	vettore tauD = tau; tauD.prodotto_matrice(coeff_inerzia2); // multiply 
	//tau vector times inverse I tensor
	// cout << "\ntauD:"; tauD.couta_vettore();
	vettore omega_primo = tauD - omega_mez; // tauD - omega_fin = omega_primo
	// cout << "\nomega_primo:"; omega_primo.couta_vettore(); cout << "\n";
	return omega_primo;
};

double ruota(double coeff_R[4], double coeff_W[4], quaternione R, vettore W)
{
	double coeff_Rc[4], coeff_Wc[4], theta;
	theta = 2 * (acos(coeff_R[0]));

	quaternione Rc(coeff_R), Wc(coeff_W); 	// assign to Rc the values of R, 
	//transforms W vector in Wc quaternion.
	Rc.coniuga(coeff_R); 					// Rc becomes R' (R conjugate).
	quaternione Rp = R * Wc, Rf = Rp * Rc;		// Rp is an auxiliary 
	//quaternion for the operation QVQ'. Rf is the final quaternion.
	cout << "Your vector V rotated by an angle of " << theta << " rad \n "
		"around the axis ", R.couta_puro();
		cout << " is\n\n V=", Rf.couta_puro(), cout << "\n\n";
	return 0;
};

double secondario(double coeff_P[4], double coeff_Q[4], double coeff_V[4], quaternione Q)
{
	string input_1; int contatore = 0;
	const string diventano = "\n\nThe inserted quaternions have "
			"become: \n\n Q=";

	vettore V(coeff_V);
	genera(coeff_P);
	quaternione P(coeff_P);
	cout << "\n\nThe quaternions entered are:"
		"\n\n Q=" << Q << " \n P=" << P << "\n";
	do
	{
		const string fine;
		cout << "Enter a command: ";
		cin >> input_1, cout << "\n";
		if (input_1 == kutta)
		{
			integratore <double, double, quaternione,
				quaternione>(coeff_Q, coeff_P, Q, P), input_1 = fine;
		}
		if (input_1 == mostra)
			cout << "\nThe quaternions entered are:"
			"\n\n Q=" << Q << " \n P=" << P << "\n", input_1 = fine;
		if (input_1 == h)
		{
			cout << "debug";
			aiuto(), input_1 = fine;
		}
		if (input_1 == esci)
			exit(22);
		if (input_1 == somma)
			cout << "Q+P=" << Q + P << "\n\n", input_1 = fine;
		if (input_1 == somma_1)
			cout << "P+Q=" << P + Q << "\n\n", input_1 = fine;
		if (input_1 == sottra)
			cout << "Q-P=" << Q - P << "\n\n", input_1 = fine;
		if (input_1 == sottra_1)
			cout << "P-Q=" << P - Q << "\n\n", input_1 = fine;
		if (input_1 == moltiplica)
			cout << "Q*P=" << Q * P << "\n\n", input_1 = fine;
		if (input_1 == moltiplica_1)
			cout << "P*Q=" << P * Q << "\n\n", input_1 = fine;
		if (input_1 == qdivp)
			cout << "Q/P=" << Q / P << "\n\n", input_1 = fine;
		if (input_1 == pdivq)
			cout << "P/Q=" << P / Q << "\n\n", input_1 = fine;
		if (input_1 == invertiq)
			Q.inverti(coeff_Q), cout << diventano << Q << " \n"
			"P=" << P << "\n\n", input_1 = fine;
		if (input_1 == invertip)
			P.inverti(coeff_P), cout << diventano << Q << " \n"
			"P=" << P << "\n\n", input_1 = fine;
		if (input_1 == cambia_q)
			Q.modifica(coeff_Q), cout << diventano << Q << " \n"
			"P=" << P << "\n\n", input_1 = fine;
		if (input_1 == cambia_p)
			P.modifica(coeff_P), cout << diventano << Q << " \n"
			"P=" << P << "\n\n", input_1 = fine;
		if (input_1 == con_q)
			Q.coniuga(coeff_Q), cout << diventano << Q << " \n"
			"P=" << P << "\n\n", input_1 = fine;
		if (input_1 == con_p)
			P.coniuga(coeff_P), cout << diventano << Q << " \n"
			"P=" << P << "\n\n", input_1 = fine;
		if (input_1 == mod_q)
			cout << "|Q|=" << Q.modulo() << "\n\n", input_1 = fine;
		if (input_1 == mod_p)
			cout << "|P|=" << P.modulo() << "\n\n", input_1 = fine;
		if (input_1 == minq)
			Q.minus(coeff_Q), cout << diventano << Q << " \n"
			"P=" << P << "\n", input_1 = fine;
		if (input_1 == minp)
			P.minus(coeff_P), cout << diventano << Q << " \n"
			"P=" << P << "\n", input_1 = fine;
		if (input_1 == mod1_q)
			Q.mod1(coeff_Q), cout << diventano << Q << " \n"
			"P=" << P << "\n", input_1 = fine;
		if (input_1 == mod1_p)
			P.mod1(coeff_P), cout << diventano << Q << " \n"
			"P=" << P << "\n", input_1 = fine;
		if (input_1 == qugp)
			Q = P, cout << diventano << Q << " \n"
			"P=" << P << "\n", input_1 = fine;
		if (input_1 == pugq)
			P = Q, cout << diventano << Q << " \n"
			"P=" << P << "\n", input_1 = fine;
		if (input_1 == matrq)
		{
			matrice4 MQ(coeff_Q);
			cout << "Your quaternion Q in matrix form with"
				"real coefficients e':\n\n"; MQ.couta_matrice4();
			input_1 = fine;
		}
		if (input_1 == matrp)
		{
			matrice4 MP(coeff_P);
			cout << "Your quaternion P in matrix form with"
				"real coefficients e':\n\n"; MP.couta_matrice4();
			input_1 = fine;
		}
		if (input_1 == matcq)
		{
			matrice2 McQ(coeff_Q);
			cout << "Your quaternion Q in matrix form with"
				"complex coefficients e':\n\n"; McQ.couta_matrice2();
			input_1 = fine;
		}
		if (input_1 == matcp)
		{
			matrice2 McP(coeff_P);
			cout << "Your quaternion P in matrix form with"
				"complex coefficients e':\n\n"; McP.couta_matrice2();
			input_1 = fine;
		}
		if (input_1 == cambia_v) // rotate a vector with Q.
		{
			if (Q.modulo() == 1)
			{
				genera_V(coeff_V);
				vettore V(coeff_V);
				cout << "\nIl tuo vettore e'\n\n V=";
				V.couta_vettore(); cout << "\n\n";
				ruota(coeff_Q, coeff_V, Q, V);
				input_1 = fine;
			}
			else cout << "You must enter a quaternion of"
				"modulo 1 to rotate a vector.\n\n", input_1 = fine;
		}
		if (input_1 == cambia_v2) // rotate a vector with P.
		{
			if (P.modulo() == 1)
			{
				genera_V(coeff_V);
				vettore V(coeff_V);
				cout << "\nIl tuo vettore e'\n\n V="; 
				V.couta_vettore(); cout << "\n\n";
				ruota(coeff_P, coeff_V, P, V);
				input_1 = fine;
			}
			else cout << "You must enter a quaternion of "
				"modulo 1 to rotate a vector.\n\n", input_1 = fine;
		}
		if (input_1 != fine)
		{
			++contatore;
			if (contatore <= 10) cout << "Command not defined. "
				"Type h for the command list.\n\n";
			else contatore = 0, aiuto();
		}
	} while (true);
}

int principale() try
{
	double coeff_Q[4], coeff_P[4], coeff_V[4]; string input_0; 
	int contatore = 0; bool pass = false;
	const string diventa = "\n\nThe quaternion has become: \n\n Q=";

	do
	{
		if (cin.get() == '\n') pass = true;
	} while (pass == false);

	cout << "\n\n\nAdd your first quaternion.\n";
	genera(coeff_Q);
	quaternione Q(coeff_Q);
	cout << "\n" "The inserted quaterion is Q=" << Q << "\n";
	do
	{
		const string fine;
		cout << "Enter a command: ";
		cin >> input_0, cout << "\n";
		if (input_0 == kutta)
		{
			integratore <double, double, quaternione>(coeff_Q,
			coeff_P, Q), input_0 = fine;
		}
		if (input_0 == mostra)
		{
			cout << "\nThe inserted quaterion is Q=";
			cout << Q << "\n\n", input_0 = fine;
		}
		if (input_0 == h) aiuto(), input_0 = fine;
		if (input_0 == esci) exit(22);
		if (input_0 == cambia_q)
		{
			Q.modifica(coeff_Q);
			cout << diventa << Q << "\n\n", input_0 = fine;
		}
		if (input_0 == con_q)
		{
			Q.coniuga(coeff_Q);
			cout << diventa << Q << "\n\n", input_0 = fine;
		}
		if (input_0 == mod_q)
			cout << "|Q|=" << Q.modulo() << "\n\n", input_0 = fine;
		if (input_0 == minq)
			Q.minus(coeff_Q), cout << diventa << Q << "\n\n", input_0 = fine;
		if (input_0 == minp)
			cout << "You haven't entered P yet \n\n", input_0 = fine;
		if (input_0 == invertiq)
		{
			Q.inverti(coeff_Q);
			cout << diventa << Q << "\n\n", input_0 = fine;
		}
		if (input_0 == mod1_q)
			Q.mod1(coeff_Q), cout << diventa << Q << "\n\n", input_0 = fine;
		if (input_0 == matrq)
		{
			matrice4 MQ(coeff_Q);
			cout << "Your quaternion Q in matrix form with real"
				"coefficients is :\n\n"; MQ.couta_matrice4();
			input_0 = fine;
		}
		if (input_0 == matcq)
		{
			matrice2 McQ(coeff_Q);
			cout << "Your quaternion Q in matrix form with"
				"complex coefficients is:\n\n"; McQ.couta_matrice2();
			input_0 = fine;
		}
		if (input_0 == cambia_v)
		{
			if (Q.modulo() == 1)
			{
				genera_V(coeff_V);
				vettore V(coeff_V);
				cout << "\nYour Vector is'\n V="; 
				V.couta_vettore(); cout << "\n\n";
				ruota(coeff_Q, coeff_V, Q, V);
				input_0 = fine;
			}
			else cout << "You must enter a quaternion of"
				"modulo 1 to rotate a vector.\n\n", input_0 = fine;
		}
		if (input_0 == cambia_p)
			secondario(coeff_P, coeff_Q, coeff_V, Q), input_0 = fine;
		if (input_0 == somma || input_0 == somma_1 || input_0 == sottra 
			|| input_0 == sottra_1 || input_0 == moltiplica
			|| input_0 == qdivp || input_0 == pdivq || input_0 == con_p 
			|| input_0 == mod_p || input_0 == invertip
			|| input_0 == qugp || input_0 == pugq || input_0 == mod1_p 
			|| input_0 == matrp || input_0 == matcp
			|| input_0 == cambia_v2 || input_0 == qdivp || input_0 == pdivq)
			cout << "You haven't entered P yet,"
			"type \"p = \" to add it. \n\n", input_0 = fine;
		if (input_0 != fine)
		{
			++contatore;
			if (contatore <= 10) cout << "Command not defined."
				"Type h for the command list.\n\n";
			else contatore = 0, aiuto();
		}
	} while (true);
}
catch (const char* bug) // here ends principale() execution and starts main()
{
	cout << bug;
}

void debug() // restart from principale() function
{
	cout << "Program restart in progress...\n\n";
	system("PAUSE");
	principale();
};

int main() try
{
	cout <<
		"\n			*****************************\n"
		"			 Welcome in Quaternione++!\n"
		"			*****************************\n\n\n"
		"Press Enter to get started:";
	principale();
	do
	{
		debug();
	} while (true);
}
catch (string s) // needed for modifica(), on fail triggers debug.
{
	do
	{
		debug();
	} while (true);
}