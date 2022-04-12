#include "Header.h"

int main(void)
{ 
	FILE* infile = NULL, * outfile = NULL; // NULL pointer  
	infile = fopen("Playroll.txt", "r");
	outfile = fopen("Paid.txt", "w"); 

	em payroll[200];
	//FILE* infile = fopen("Playroll.txt", "r");
	double Max = 0, min = 0, total = 0, average = 0;
	int g = read_payroll(infile, payroll);
	total = calculations_total(payroll, g, &average);

	Max = calculate_max(payroll, g);
	min = calculate_min(payroll, g);
	
	for (int i = 0; i < g; i++)
	{

		printf("name:%s\n", payroll[i].name);
		printf("title: %c\n", payroll[i].title);
		printf("Hours Worked: %lf\n", payroll[i].hours_worked);
		printf("payrate: %lf\n", payroll[i].payrate);
	}

	fprintf(outfile, "total: $%.2lf\n", total);
	fprintf(outfile, "average: $%.2lf\n", average); 
	fprintf(outfile, "max: $%.2lf\n", Max); 
	fprintf(outfile, "min: $%.2lf\n", min);

	return 0; 
}