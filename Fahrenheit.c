// Conversión de grados fahrenheit a centigrados
/* 1AM2 */
#include<stdio.h>
#include<conio.h>
void FaC(float);

int main()
{printf("Introduce la temperatura en grados fahrenheit\n");
float F;
scanf("%f",&F);
FaC(F);
getch();
}
void FaC(float F)

{double celsius;
celsius=(F-32)/1.8;
printf("La temperatura en celsius es:%.3lF",celsius);
}