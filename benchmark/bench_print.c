#include "../benchmark.h"

void print_m(int a)
{
	if(a % 2 == 1)
	{
		Color(FG_LGREEN);
		printf("  )  ");
		Color(RESET_ALL);
	}
	else
	{
		Color(FG_LGREEN);
		printf("  (  ");
		Color(RESET_ALL);
	}
}

void print_placar(int a ,char c, char *str)
{
	if(a == 0)
	{
		Color(RESET_ALL);
		printf(" | | =======================|    BUFFER_SIZE   |====================== | | ");

	}
	else
	{
		printf(" |%c| ", c);
	}
}

void print_line(int a)
{
	print_m(a + 1);
	Color(FG_RED);
	printf(" ========================================================================= ");
	print_m(a);
	printf("\n");
}


void print_res(int i,int print_1,int print_2, char *str,t_score *score)
{
	char *NUM[] = {"","         1        ", "         5        ", "        42        ","     10000000     "};
	char s[] = " * ";

	if(print_1 < print_2)
	{
		print_m(i);
		print_placar(i,s[1],str);
		Color(FG_BLACK);
		Color(BG_LGREEN);
		printf("%-14d Milisec.", print_1);
		Color(RESET_ALL);
		printf("|");
		Color(FG_BLUE);
		printf("%s",NUM[i]);
		Color(RESET_ALL);
		printf("|");
		Color(FG_YELLOW);
		Color(BG_RED);
		printf("%13d Milisec.",print_2);
		Color(RESET_ALL);
		print_placar(i,s[0],str);
		print_m(i + 1);
		score->gnl1++;
	}
	else if (print_2 == print_1)
	{
		print_m(i);
		Color(RESET_ALL);
		print_placar(i,s[0],str);
		printf("%-14d Milisec.", print_1);
		printf("|");
		Color(FG_BLUE);
		printf("%s",NUM[i]);
		Color(RESET_ALL);
		printf("|");
		printf("%13d Milisec.",print_2);
		print_placar(i,s[0],str);
		print_m(i + 1);
	}
	else{
		print_m(i);
		print_placar(i,s[0],str);
		Color(FG_YELLOW);
		Color(BG_RED);
		printf("%-14d Milisec.", print_1);
		Color(RESET_ALL);
		printf("|");
		Color(FG_BLUE);
		printf("%s",NUM[i]);
		Color(RESET_ALL);
		printf("|");
		Color(FG_BLACK);
		Color(BG_LGREEN);
		printf("%13d Milisec.",print_2);
		Color(RESET_ALL);
		print_placar(i,s[1],str);
		print_m(i + 1);
		score->gnl2++;
	}
}

void bench_print(char *gnl1,char *gnl2,char *str,int a, int b , t_score *score)
{
	char gnl1_s[100];
	char gnl2_s[100];
	int print_1;
	int print_2;
	FILE *gnl1_f = fopen(gnl1, "rwa");
	FILE *gnl2_f = fopen(gnl2, "rwa");

	if(a == 0)
	{
		print_line(a);

		print_m(a );
		Color(FG_BLUE);
		printf("   %-72s",str);
		print_m(a + 1);
		printf("\n");
		print_line(a);

		print_m(a);
		print_placar(a,' ',str);
		print_m(a + 1);
		printf("\n");
		a++;
	}
	else 
	{
		a++;
	}
	while(b >= 0)
	{
		fgets(gnl1_s,100,gnl1_f);
		fgets(gnl2_s,100,gnl2_f);
		b--;
	}
	print_1 = atoi(gnl1_s) ;
	print_2 = atoi(gnl2_s);
	print_res(a, print_1, print_2, str, score);
	printf("\n");
	// printf("\n");
}


void print_header(void)
{
	Color(FG_BLUE);
	printf("%-s","\t\t\t\tSTARTING BENCH MODE\n");
	Color(FG_LGREEN);
	printf("     _.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._\n");
	printf("  ._|___    ___    ___    ___    ___    ___    ___    ___    ___    ___    ___|__.\n");
	print_m(2);
	Color(FG_LBLUE);
	printf(" pts             Time of GNL1         VS        Time of GNL2          pts  ");
	print_m(1);
	printf("\n");
}

void print_end(t_score score)
{
	char end[200];
	int a;
	FILE *file = fopen("./files/end","rwa");
	print_line(0);
	print_m(0);
	if(score.gnl1 >= score.gnl2)
	{
		printf(" Points of GNL1 total:  ");
		Color(FG_BLACK);
		Color(BG_GREEN);
		printf("%d/60",score.gnl1);
		Color(RESET_ALL);
		printf("                  ");
		printf("Points of GNL2 total:  ");
		Color(FG_YELLOW);
		Color(BG_RED);
		printf("%d/60",score.gnl2);
		Color(RESET_ALL);
		printf(" ");
	}
	else
	{
		printf(" Points of GNL1 total:  ");
		Color(FG_YELLOW);
		Color(BG_RED);
		printf("%d/60",score.gnl1);
		Color(RESET_ALL);
		printf("                  ");
		printf("Points of GNL2 total:  ");
		Color(FG_BLACK);
		Color(BG_GREEN);
		printf("%d/60",score.gnl2);
		Color(RESET_ALL);
		printf(" ");
	}
	print_m(1);
	printf("\n");
	Color(FG_GREEN);
	for(a = 0 ; a <= 9 ;a++)
	{
		fgets(end, 200, file);
		printf("%s",end);
	}
	printf("\n");
	printf("\n");
	printf("\n");
}
