/*
  10.6.c
  <TBC>
  Created by Chan Ho Park on <20200714>.
*/

#define _CRT_SECURE_NO_WARNINGS

#define MONTHS 12
#define YEARS 3

#include <stdio.h>

int main()
{
    double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2,	28.0, 23.1,	16.1, 6.8, 1.2 };
    double year2017[MONTHS] = { -1.8, -0.2,	6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
    double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

    double mon_ave[12] = { 0.0 };
    double year_ave[3] = { 0.0 };

    //double three_years[YEARS][MONTHS];


    //for (int i = 0; i < YEARS; i++)
    //{
    //    for (int j = 0; j < MONTHS; j++)
    //    {
    //        switch (i)
    //        {
    //        case 0:
    //            three_years[i][j] = year2016[j];
    //            break;
    //        case 1:
    //            three_years[i][j] = year2017[j];
    //            break;
    //        case 2:
    //            three_years[i][j] = year2018[j];
    //            break;
    //        default:
    //            break;
    //        }          
    //    }
    //}
    // 이렇게 작성을 마친 후에, 더 간단히 정리하는 방법을 깨달음.

    double three_years[YEARS][MONTHS] = {
        { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2,	28.0, 23.1,	16.1, 6.8, 1.2 },
        { -1.8, -0.2,	6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
        { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 }
    };
    // 그냥 복붙하면 됨.

    printf("[Temperature Data]\n");
    printf("Year Index :");

    for (int j = 0; j < MONTHS; j++)
    {
        printf("\t%d", j + 1);
    }

    for (int i = 0; i < YEARS; i++)
    {
        printf("\nYear %d\t", i);

        for (int j = 0; j < MONTHS; j++)
        {

            printf("\t%.1f", three_years[i][j]);
        }
    }

    for (int i = 0; i < YEARS; i++)
    {
        for (int j = 0; j < MONTHS; j++)
        {
            year_ave[i] += three_years[i][j];
            mon_ave[j] += three_years[i][j];
        }
    }

    
    printf("\n\n[Yearly average temperature of 3 years]\n");

    for (int i = 0; i < YEARS; i++)
    {
        printf("Year%d : average temperature = %.1f\n", i, year_ave[i]/MONTHS);
    }

    printf("\n\n\n");

    printf("\n[Monthly average temperature of 3 years]\n");
    printf("Year Index :");

    for (int j = 0; j < MONTHS; j++)
    {
        printf("\t%d", j + 1);
    }

    printf("\nAvg temps :");

    for (int j = 0; j < MONTHS; j++)
    {
        printf("\t%.1f ", mon_ave[j] / (double)YEARS);
    }

    printf("\n\n\n");
    
    return 0;
}