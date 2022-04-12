#include"Header.h"


int read_payroll(FILE * infile, em payroll[])
{
	int g = 0;

	while (!feof(infile))
	{
		fscanf(infile, "%s", &payroll[g].name);
		fscanf(infile, " %c", &payroll[g].title);
		fscanf(infile, "%lf", &payroll[g].hours_worked);
		fscanf(infile, "%lf", &payroll[g].payrate);
		payroll[g].salary = 0;
	/*	printf("name: %s\n", &payroll[g].name);
		printf("title: %c\n", &payroll[g].title);
		printf("Hours Worked: %lf\n", &payroll[g].hours_worked);
		printf("payrate: %lf\n", &payroll[g].payrate);*/

		g++;
	}
	return g-1;
} 

double calculations_total(em payroll[], int g, double* average)
{
	double total = 0;
	for (int i = 0; i < g; i++)
	{
		payroll[i].salary += payroll[i].payrate * 80; 

		if (payroll[i].hours_worked > 80.0)
		{
			if (payroll[i].title == 'B')
			{
				payroll[i].salary += (payroll[i].payrate * 1.5) * (payroll[i].hours_worked - 80);
			}
			else
			{
				payroll[i].title == 'M';
				payroll[i].salary += (payroll[i].payrate * 1.8) * (payroll[i].hours_worked - 80);
			}

		}
		total += payroll[i].salary; 
	}
	*average = total / g;
	return total;
}

//double Calc_Average(em payroll[], int g, double total)
//{
//	double average = 0; 
//	average = total / g;
//	return average; 
//}

double calculate_max(em payroll[], int g)
{
	double Max = 0, min = 0;
	Max = payroll[0].salary; 
	min = payroll[0].salary; 

	for (int i = 0; i < g; i++)
	{
		if (payroll[i].salary > Max)
			Max = payroll[i].salary; 
		if (payroll[i].salary < min)
			min = payroll[i].salary;
	}
	return Max;
} 

double calculate_min(em payroll[], int g)
{
	double Max = 0, min = 0;
	Max = payroll[0].salary;
	min = payroll[0].salary;

	for (int i = 0; i < g; i++)
	{
		if (payroll[i].salary > Max)
			Max = payroll[i].salary;
		if (payroll[i].salary < min)
			min = payroll[i].salary;
	}
	return min;
}