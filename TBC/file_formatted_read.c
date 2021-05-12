#include <stdio.h>
void do_avg_exam_result(FILE *fp);
int main(void)
{
    FILE *fp;
    char fname[100];
    printf("Input file name to read: ");
    scanf("%s", fname);
    fp = fopen(fname, "r");
    if (fp)
    {
        do_avg_exam_result(fp);
    }
    else
    {
        printf("Fail to open file\n");
    }
    fclose(fname);
    return 0;
}

void do_avg_exam_result(FILE *fp)
{
    char name[20];
    int id, num = 0;
    double result;
    double total = 0.0;
    while (!feof(fp))
    {
        fscanf(fp, "%d %s %lf ", &id, name, &result);
        num++;
        total += result;
        printf("%d %s %lf\n", id, name, result);
    }
    printf("Average of exam is %lf", (total / num));
    return;
}