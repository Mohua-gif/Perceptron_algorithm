#include <stdio.h>
#include <time.h>
#define C 1
#include <stdlib.h>

int main()
{
    int i, j, k, N1, N2, x[20][2], s[3], d[20], array[20][4], w[4];

    printf(" ��֪���㷨����������⣩\n");
    printf("�������һ���������\n");
    scanf("%d", &N1);
    printf("�������1��������꣺\n");
    for (i = 0; i < N1; i++)
    {
        scanf("%d%d", &x[i][0], &x[i][1]);
    }

    printf("�������2���������N2��\n");
    scanf("%d", &N2);
    printf("�������2��������꣺\n");
    for (i = 0; i < N2; i++)
    {
        scanf("%d%d", &x[i + N1][0], &x[i + N1][1]);
    }

    for (i = 0; i < N1; i++) //��ӡ�������ĵ����ꣻ???
    {
        printf("����ĵ�1�������Ϊ");
        printf("{%d,%d}", x[i][0], x[i][1]);
    }
    printf("\n");
    for (i = 0; i < N2; i++) //��ӡ�������ĵ����ꣻ??
    {
        printf("����ĵ�2�������Ϊ");
        printf("{%d,%d}", x[i + N1][0], x[i + N2][1]);
    }
    printf("\n");
    printf("����ĵ�1���Ϊ:\n");
    for (j = 0; j < N1; j++)
    {
        array[j][0] = 1;
        array[j][1] = x[j][0];
        array[j][2] = x[j][1];
        array[j][3] = 1;
        printf("(%d,%d,%d)\n", array[j][1], array[j][2], array[j][3]);
    }
    printf("����ĵ�2���Ϊ:\n");
    for (j = N1; j < (N1 + N2); j++)
    {
        array[j][0] = 2;
        array[j][1] = (-1) * x[j][0];
        array[j][2] = (-1) * x[j][1];
        array[j][3] = -1;
        printf("(%d,%d,%d)\n", array[j][1], array[j][2], array[j][3]);
    }
    printf("ȡ����CΪ:%d\n", C);
    printf("��ʼ����Ϊ:\n");
    w[0] = 1;
    w[1] = 0;
    w[2] = 0;
    w[3] = 0;
    printf("{%d,%d,%d}\n", w[1], w[2], w[3]);
    do
    {
        for (i = 0; i < (N1 + N2); i++)
        {
            for (j = 0; j < 3; j++)
                s[j] = array[i][j + 1] * w[j + 1];
            d[i] = s[0] + s[1] + s[2];
            if (d[i] <= 0)
            {
                for (k = 0; k < 3; k++)
                    w[k + 1] = C * array[i][k + 1] + w[k + 1];
            }
        }
        for (j = (N1 + N2 - 1); j >= 0; j--)
            k = (d[j] <= 0) || (d[j + 1] <= 0);

    } while (k);
    //while((d[0]<=0)||(d[1]<=0)||(d[2]<=0)||(d[3]<=0));????
    printf("�Ż��������w=:( ");
    for (k = 0; k < 3; k++)
    {
        if (k != 0)
        {
            printf(",%d", w[k + 1]);
        }
        else if (k == 0)
        {
            printf("%d", w[k + 1]);
        }
    }

    printf(" )\n");
    system("pause");
    return 0;
}