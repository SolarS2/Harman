#include <stdio.h>
#include <conio.h>
#include<string.h>


void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();
void test08();
void test09();

void swap();
void min();
void max();
void abs();

main()
{
    int n;
    void* pF[] = { test01, test02,test03,test04, test05, test06, test07 };
    void (*pFunc)();
    while (1)
    {
        printf("\n\n\n\n");
        printf("1. �� ���ھ� ��� ��� \n");
        printf("2. ��ҹ��� ���ڿ� �빮�ڷ� ��ȯ\n");
        printf("3, ASC||�ڵ�ǥ ��� \n");
        printf("4. Swap�Լ�\n");
        printf("5. Ȧ�� �Ƕ�̵� ���\n");
        printf("6. ���� ���Ƕ�̵� ���\n");
        printf("7. �ִ����� ���\n");
        printf("8. Sin � ��� ��� \n");
        printf("0. ����\n");
        printf("======================\n ����");
        scanf("%d", &n);

        if (n == 0) return;
        pFunc = pF[n - 1];
        pFunc();
    }
}
void test01()
{
    char str[100];
    int i = 0;
    printf("���ڸ� �Է��ϼ��� : \n"); scanf("%s", str);

    while (str[i] != '\0') {
        printf("%c ", str[i]);
        i++;
    }

    return 0;
}
//char ch = 'A'; ch <= str; ch++);

void test02()
{
    char str[32];
    printf("���ڸ� �Է��ϼ��� :\n"); scanf("%s", str);

    char* p = str;
    while (*p)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p -= 32;
        }
        p++;
    }
    printf("�ҹ��� �빮�ڷ� �ڵ� ��ȯ : %s\n", str); return 0;
}
void test03()
{
    for (int ASCll = 1; ASCll <= 127; ASCll++)
    {
        printf("%d\t %x\t %c\t ", ASCll, ASCll, ASCll);

        if (ASCll % 4 == 0)
        {
            printf("\n");
        }
    }
}
void test04()
{
    int val1;
    int val2;
    printf("ù ��° ���ڸ� �Է��ϼ��� : \n"); scanf("%d", &val1);
    printf("�� ��° ���ڸ� �Է��ϼ��� : \n"); scanf("%d", &val2);

    printf("swap�� : [0001] %d ----- [0002] %d\n", val1, val2);
    swap(&val1, &val2);
    printf("swap�� : [0001] %d ----- [0002] %d\n", val1, val2);

    return 0;

}
void test05()
{

    int val;
    printf("���ڸ� �Է��ϼ��� : \n"); scanf("%d", &val);

    for (int i = 0; i < val; i++)
    {
        for (int j = i; j <= val - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= 2 * i; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
void test06()
{
    char str;
    printf("���ڸ� �Է��ϼ��� : \n"); scanf(" %c", &str);

    for (char i = 'A'; i <= str; i++)
    {
        for (char k = 'A'; k < i; k++)
        {
            printf(" ");
        }
        for (char j = str; j >= i; j--)
        {
            printf("%c", i);
        }
        printf("\n");
    } return 0;
}
void test07()
{
    int a;
    int b;
    int max;
    printf("ù ��° ���ڸ� �Է��ϼ��� : \n"); scanf("%d", &a);
    printf("�� ��° ���ڸ� �Է��ϼ��� : \n"); scanf("%d", &b);

    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            max = i;
        }
    }
    printf("�ִ������� %d �Դϴ�.", max);
    return 0;
}


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void min(int a, int b)
{
    return (a < b) ? a : b;

}
void max(int a, int b)
{
    return (a > b) ? a : b;
}
void abs(int a)
{
    return (a >= 0) ? a : -a;
}