#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <math.h>
#include <string>
using namespace std;

struct quaternione
{
	double coeff_rif[4], coeff_op[4];

	void couta_puro()
	{
		cout << "(" << coeff_rif[1] << "," << coeff_rif[2] << ",";
		cout << coeff_rif[3] << ")";
	};

	double modulo()
	{
		double x;
		x = sqrt(coeff_rif[0] * coeff_rif[0] + coeff_rif[1] * coeff_rif[1] 
			+ coeff_rif[2] * coeff_rif[2] + coeff_rif[3] * coeff_rif[3]);
		return x;
	};

	void mod1(double coeff_mod[4])
	{
		double x;
		x = sqrt(coeff_rif[0] * coeff_rif[0] + coeff_rif[1] * coeff_rif[1] 
			+ coeff_rif[2] * coeff_rif[2] + coeff_rif[3] * coeff_rif[3]);
		for (int j = 0; j <= 3; ++j) coeff_mod[j] = coeff_mod[j] / x;
		for (int j = 0; j <= 3; ++j) coeff_rif[j] = coeff_mod[j];
	};

	void coniuga(double coeff_mod[4])
	{
		for (int i = 1; i <= 3; ++i) coeff_mod[i] = coeff_mod[i] * -1;
		for (int j = 0; j <= 3; ++j) coeff_rif[j] = coeff_mod[j];
	};

	void inverti(double coeff_mod[4])
	{
		double x;
		x = coeff_rif[0] * coeff_rif[0] + coeff_rif[1] * coeff_rif[1] 
			+ coeff_rif[2] * coeff_rif[2] + coeff_rif[3] * coeff_rif[3];
		for (int i = 1; i <= 3; ++i) coeff_mod[i] = coeff_mod[i] * -1;
		for (int i = 0; i <= 3; ++i) coeff_rif[i] = coeff_mod[i] / (x);
	};

	void minus(double coeff_mod[4])
	{
		for (int i = 0; i <= 3; ++i) coeff_mod[i] = coeff_mod[i] * -1;
		for (int j = 0; j <= 3; ++j) coeff_rif[j] = coeff_mod[j];
	};

	double modifica(double coeff_mod[4])
	{
		bool var = true; const string errore = "Error you didn't type a "
			"number.\n";

		do
		{
			cout << "\nEnter the new real part\n\n";
			cin >> coeff_mod[0]; cout << "\n\n";
			if (cin.fail()) cin.clear(), cout << errore, throw errore;
			cout << "Enter the new complex parts i,j,k \n\n";
			for (int i = 1; i <= 3; ++i) cin >> coeff_mod[i];
			if (cin.fail()) cin.clear(), cout << errore, throw errore;
			if (coeff_mod[0] == 0 && coeff_mod[1] == 0 && coeff_mod[2] == 0 
				&& coeff_mod[3] == 0)
			{
				cout << "\nInvalid Values. Enter at least a value"
					"different from 0.\n";
			}
			else var = false;
		} while (var == true);
		for (int j = 0; j <= 3; ++j) coeff_rif[j] = coeff_mod[j];
	};

	quaternione operator + (quaternione p)
	{
		for (int i = 0; i <= 3; ++i) coeff_op[i] = (coeff_rif[i] 
			+ p.coeff_rif[i]);
		quaternione S(coeff_op);
		return S;
	}

	quaternione operator - (quaternione p)
	{
		for (int i = 0; i <= 3; ++i) coeff_op[i] = (coeff_rif[i] 
			- p.coeff_rif[i]);
		quaternione G(coeff_op);
		return G;
	}

	quaternione operator * (quaternione p)  	// i*j=k, j*k=i, k*i=j
	{
		coeff_op[0] = coeff_rif[0] * p.coeff_rif[0] - coeff_rif[1] 
			* p.coeff_rif[1] - coeff_rif[2] * p.coeff_rif[2] 
			- coeff_rif[3] * p.coeff_rif[3];
		coeff_op[1] = coeff_rif[0] * p.coeff_rif[1] + coeff_rif[1] 
			* p.coeff_rif[0] + coeff_rif[2] * p.coeff_rif[3] 
			- coeff_rif[3] * p.coeff_rif[2];
		coeff_op[2] = coeff_rif[0] * p.coeff_rif[2] + coeff_rif[1] 
			* p.coeff_rif[3] + coeff_rif[2] * p.coeff_rif[0] 
			- coeff_rif[3] * p.coeff_rif[1];
		coeff_op[3] = coeff_rif[0] * p.coeff_rif[3] + coeff_rif[1] 
			* p.coeff_rif[2] - coeff_rif[2] * p.coeff_rif[1] 
			+ coeff_rif[3] * p.coeff_rif[0];
		quaternione M(coeff_op);
		return M;
	}

	quaternione operator / (quaternione p)
	{
		p.inverti(p.coeff_rif);
		coeff_op[0] = coeff_rif[0] * p.coeff_rif[0] - coeff_rif[1] 
			* p.coeff_rif[1] - coeff_rif[2] * p.coeff_rif[2] 
			- coeff_rif[3] * p.coeff_rif[3];
		coeff_op[1] = coeff_rif[0] * p.coeff_rif[1] + coeff_rif[1] 
			* p.coeff_rif[0] + coeff_rif[2] * p.coeff_rif[3] 
			- coeff_rif[3] * p.coeff_rif[2];
		coeff_op[2] = coeff_rif[0] * p.coeff_rif[2] + coeff_rif[1] 
			* p.coeff_rif[3] + coeff_rif[2] * p.coeff_rif[0] 
			- coeff_rif[3] * p.coeff_rif[1];
		coeff_op[3] = coeff_rif[0] * p.coeff_rif[3] + coeff_rif[1] 
			* p.coeff_rif[2] - coeff_rif[2] * p.coeff_rif[1] 
			+ coeff_rif[3] * p.coeff_rif[0];
		quaternione D(coeff_op);
		return D;
	}

	quaternione() {};
	quaternione(double coeff_class[4])
	{
		for (int i = 0; i <= 3; ++i) coeff_rif[i] = coeff_class[i];
	};
};

struct vettore :quaternione
{
	double coeff_rif[4], coeff_op[4];

	double modulo()
	{
		double x;
		x = sqrt(coeff_rif[0] * coeff_rif[0] + coeff_rif[1] * coeff_rif[1] 
			+ coeff_rif[2] * coeff_rif[2] + coeff_rif[3] * coeff_rif[3]);
		return x;
	};
	void couta_vettore()
	{
		cout << "(" << coeff_rif[1] << "," << coeff_rif[2];
		cout << "," << coeff_rif[3] << ")";
	};
	void prodotto_matrice(double coeff_mat[9])
	{
		coeff_rif[0] = 0;
		coeff_rif[1] = coeff_mat[0] * coeff_rif[1] + coeff_mat[1] 
			* coeff_rif[2] + coeff_mat[2] * coeff_rif[3];
		coeff_rif[2] = coeff_mat[3] * coeff_rif[1] + coeff_mat[4] 
			* coeff_rif[2] + coeff_mat[5] * coeff_rif[3];
		coeff_rif[3] = coeff_mat[6] * coeff_rif[1] + coeff_mat[7] 
			* coeff_rif[2] + coeff_mat[8] * coeff_rif[3];
	};
	vettore prodotto_con_falsoscalare(vettore s)
	{
		coeff_op[0] = 0;
		for (int i = 1; i <= 3; ++i) coeff_op[i] = s.coeff_rif[i] 
			* coeff_rif[i];
		vettore G(coeff_op);
		return G;
	};

	vettore operator + (vettore p)
	{
		for (int i = 1; i <= 3; ++i) coeff_op[i] = coeff_rif[i] 
			+ p.coeff_rif[i];
		vettore S(coeff_op);
		return S;
	}
	vettore operator - (vettore p)
	{
		for (int i = 1; i <= 3; ++i) coeff_op[i] = coeff_rif[i] 
			- p.coeff_rif[i];
		vettore S(coeff_op);
		return S;
	}
	vettore operator * (vettore p) // prodotto vettoriale
	{
		coeff_op[0] = 0;
		coeff_op[1] = coeff_rif[2] * p.coeff_rif[3] - coeff_rif[3] 
			* p.coeff_rif[2];
		coeff_op[2] = coeff_rif[3] * p.coeff_rif[1] - coeff_rif[1] 
			* p.coeff_rif[3];
		coeff_op[3] = coeff_rif[1] * p.coeff_rif[2] - coeff_rif[2] 
			* p.coeff_rif[1];
		vettore M(coeff_op);
		return M;
	}

	vettore() {};
	vettore(double coeff_class[4])
	{
		coeff_rif[0] = 0;
		for (int i = 1; i <= 3; ++i) coeff_rif[i] = coeff_class[i];
	};
};

struct matrice4
{
	double coeff_rif[16];

	void couta_matrice4()
	{
		cout << "	|"; 
		for (int i = 0; i <= 3; ++i) cout << "   " << coeff_rif[i]; 
		cout << "\t| \n";
		cout << "	|"; 
		for (int i = 4; i <= 7; ++i) cout << "   " << coeff_rif[i]; 
		cout << "\t| \n";
		cout << "	|"; 
		for (int i = 8; i <= 11; ++i) cout << "   " << coeff_rif[i]; 
		cout << "\t| \n";
		cout << "	|"; 
		for (int i = 12; i <= 15; ++i) cout << "   " << coeff_rif[i]; 
		cout << "\t| \n\n";
	};

	matrice4() {};
	matrice4(double coeff_class[4])
	{
		coeff_rif[0] = coeff_class[0]; //a
		coeff_rif[1] = coeff_class[1]; //b
		coeff_rif[2] = (-coeff_class[3]); //-d
		coeff_rif[3] = (-coeff_class[2]); //-c
		coeff_rif[4] = (-coeff_class[1]); //-b
		coeff_rif[5] = coeff_class[0]; //a
		coeff_rif[6] = (-coeff_class[2]); //-c
		coeff_rif[7] = coeff_class[3]; //d
		coeff_rif[8] = coeff_class[3]; //d
		coeff_rif[9] = coeff_class[2]; //c
		coeff_rif[10] = coeff_class[0]; //a
		coeff_rif[11] = coeff_class[1];//b
		coeff_rif[12] = coeff_class[2]; //c
		coeff_rif[13] = (-coeff_class[3]); //-d
		coeff_rif[14] = (-coeff_class[1]); //-b
		coeff_rif[15] = coeff_class[0]; //a
	};
};

struct matrice2
{
	double coeff_rif[8];

	void couta_matrice2()
	{
		if (coeff_rif[0] != 0) cout << "	|   " << coeff_rif[0];
		if (coeff_rif[0] == 0) cout << "	|   ";

		if (coeff_rif[1] > 0) cout << '+' << coeff_rif[1] << "i	";
		if (coeff_rif[1] < 0) cout << coeff_rif[1] << "i	";
		if (coeff_rif[1] == 0 && coeff_rif[0] != 0) cout << "	";
		if (coeff_rif[1] == 0 && coeff_rif[0] == 0) cout << "	0";

		if (coeff_rif[2] != 0) cout << coeff_rif[2];
		if (coeff_rif[2] == 0) cout << "	";

		if (coeff_rif[3] > 0) cout << '+' << coeff_rif[3] << "i	|\n";
		if (coeff_rif[3] < 0) cout << coeff_rif[3] << "i	|\n";
		if (coeff_rif[3] == 0 && coeff_rif[2] != 0) cout << "	|\n\n";
		if (coeff_rif[3] == 0 && coeff_rif[2] == 0) cout << "0	|\n\n";

		if (coeff_rif[4] != 0) cout << "	|   " << coeff_rif[4];
		if (coeff_rif[4] == 0) cout << "	|   0";

		if (coeff_rif[5] > 0) cout << '+' << coeff_rif[5] << "i	";
		if (coeff_rif[5] < 0) cout << coeff_rif[5] << "i	";
		if (coeff_rif[5] == 0 && coeff_rif[4] != 0) cout << "	";
		if (coeff_rif[5] == 0 && coeff_rif[4] == 0) cout << "0	";

		if (coeff_rif[6] != 0) cout << coeff_rif[6];
		if (coeff_rif[6] == 0) cout << "	";

		if (coeff_rif[7] > 0) cout << '+' << coeff_rif[7] << "i	|\n\n";
		if (coeff_rif[7] < 0) cout << coeff_rif[7] << "i	|\n\n";
		if (coeff_rif[7] == 0 && coeff_rif[6] != 0) cout << "	|\n\n";
		if (coeff_rif[7] == 0 && coeff_rif[6] == 0) cout << "0	|\n\n";
	};

	matrice2() {};
	matrice2(double coeff_class[4])
	{
		coeff_rif[0] = coeff_class[0]; //a
		coeff_rif[1] = coeff_class[3]; //d
		coeff_rif[2] = coeff_class[1]; //b
		coeff_rif[3] = coeff_class[2]; //c
		coeff_rif[4] = (-coeff_class[1]); //-b
		coeff_rif[5] = coeff_class[2]; //c
		coeff_rif[6] = coeff_class[0]; //a
		coeff_rif[7] = (-coeff_class[3]); //-d
	}
};

struct tens2
{
	double coeff_rif[9];

	void couta_tens2()
	{
		cout << "\n	|	" << coeff_rif[0]; cout << "	0	0	|\n";
		cout << "    I=" "	|	0	" << coeff_rif[4]; cout << "	0	|\n";
		cout << "	|	0	0	" << coeff_rif[8]; cout << "	|\n\n";
	};

	tens2() {};
	tens2(double coeff_class[9])
	{
		for (int i = 0; i < 9; ++i) coeff_rif[i] = coeff_class[i];
	}
};