#pragma once

#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h> 

typedef struct employee
{
	char name[100];
	char title;
	double hours_worked;
	double payrate;
	double salary;
}em; 

int read_payroll(FILE* infile, em payroll[]); 
double calculations_total(em payroll[], int g);
double Calc_average(em payroll[], int g, double total, double* average);
double calculate_max(em payroll[], int g);
double calculate_min(em payroll[], int g);


