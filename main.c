#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Invalid no. of args\n");
		exit(-1);
	}
	char c;
	mpz_t temp;
	mpz_init(temp);
	mpz_t n; //for storing max number
	mpz_init(n);
	mpz_t x; //for storing current result
	mpz_init_set_ui(x, 0);
	//const mpz_t base;
	//mpz_init_set_ui(base, 10);
	FILE *out = fopen(argv[1], "w");


	fprintf(stdout, "Enter maximum number:");
	mpz_inp_str(n, stdin, 10);
	
	for (int i = 1; mpz_cmp(x, n) < 0; i++) {
		if (i == 0) {
			printf("Overflow!\n");
			mpz_clears(n, x, 0);
			fclose(out);
			exit(-2);
		}
		mpz_pow_ui(x, x, 2);
		mpz_add_ui(temp, x, 1);
		mpz_mul(x, x, temp);

		fprintf(out, "%d. ", i);
		mpz_out_str(out, 10, x);
		mpz_out_str(stdout, 10, x);
		printf("\n");
		fprintf(out, "\n");

		mpz_set_ui(x, i);
	}
	printf("Done! Shutting down (duh...)\n");
	mpz_clears(n, x, 0);
	fclose(out);
	return 0;
}
