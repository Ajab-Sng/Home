// 5G NR ARFNC Calculator

#include<stdio.h>
float cal_5G_NR_ARFCN(float F_ref)
{
	int F_global=0;
        float F_ref_offs=0;
        int N_ref_offs=0;
	if(F_ref>=0 && F_ref<3000)
	{
		F_global=5;
		F_ref_offs=0;
		N_ref_offs=0;
	}
	if(F_ref >=3000 && F_ref<24250)
	{
		F_global=15;
	        F_ref_offs=3000;
        	N_ref_offs=600000;
	}
	if(F_ref >=24250 && F_ref<100000)
        {       
                F_global=60;
                F_ref_offs=24250.08;
                N_ref_offs=2016667;
        } 
	float result =((F_ref*1000 - F_ref_offs*1000)/F_global)+N_ref_offs;
return result;
}

int main()
{
	float n;
	printf("Enter the Frequency, MHz* = ");
	scanf("%f",&n);
	if(n>=0 && n<100000)
	{
		printf("\n5G NR ARFCN result = %.3f\n",cal_5G_NR_ARFCN(n));
	}
	else
	{
		printf("Entered frequency is out of bound.\n");
	}
	return 0;
}
