#include <stdio.h>
#include <conio.h>

int test01();
int test02(int a);
int test03();
int Dump(char* p, int len); // �޸� ���� ��¿� �����Լ�(���̺귯�� ���� ����)
int Copy(char* p1, char* p2);

main()
{
	//test01();
	//test02(1);
	test03();
}

int test01()
{
	char* str[10] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", };
	printf("���� Ű�� �Է��ϼ���. �ش��ϴ� ���ܾ �˷��帮�ڽ��ϴ�.\n");
	printf("���α׷��� �����÷��� 'Q'Ű�� �Է��ϼ��� \n\n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch();
		int m = c - 0x30; //0x30 ASC||  --> num�� ��ȯ ���� 0x30 = 0
		printf("%c:%s\n", c, str[m]);
		/*
		if(n==1)
		{ printf("One");
		}
		else if(n==2)
		{ printf("Two");
		}
		elseif(n==3)
		{ printf("Three");
		}
		elseif(n==4)
		{ printf("Four");
		}
		elseif(n==5)
		{ printf("Five");
		}
		elseif(n==6)
		{ printf("Six");
		}
		elseif(n==7)
		{ printf("Seven");
		}
		elseif(n==8)
		{ printf("Eight");
		}
		elseif(n==9)
		{ printf("Nine");
		}
		elseif(n==0)
		{ printf("Zero");
		}
		elseif
		{
		/*
		switch ()
		{
		case (0) : printf("Zero") break;
		case (1) : printf("One") break;
		case (2) : printf("Twe") break;
		case (3) : printf("Three") break;
		case (4) : printf("Four") break;
		case (5) : printf("Five") break;
		case (6) : printf("Six") break;
		case (7) : printf("Seven") break;
		case (8) : printf("Eight") break;
		case (9) : printf("Nine") break;
		}
		*/
	}
}
int test02(int a)	// ���ڿ��� ���ڹ迭
{
	char ca[] = "Hello"; // ca0] : 'H' ... ca[4]:'o' ca[5] :\0(null)

	for (int i = 0; i < 6; i++) // 0~5
	{
		printf("ca[%d] : %c (%02x) [%08x]\n", i, ca[i], ca[i], ca + i); //%d ���� %c char // %02x 16���� %�� x ����
	}
	ca[2] -= 1;
	ca[3] -= 1;

	int ia[] = { 10,20,30,40,50 };
	for (int i = 0; i < 6; i++) // 0~5
	{
		printf("ia[%d] : %d (%08x) [%08x]\n", i, ia[i], ia[i], ia + i);
	}
	int ia2[3][2] = { 10, 20, 30, 40, 50, 60 };
	{for (int y = 0; y < 3; y++)
		for (int x = 0; x < 2; x++)
		{
			printf("ia2[%d][%d] : %d [%08x]\n", y, x, ia2[y][x], ia2 + y);
		}
	}
}
int test03()

{
	char buf[100]; // ���� �޸� ���� Ȯ��
	char* pBuf; // ���� �޸� �������� ��� ��ġ
	unsigned int addr; // ��� ��ġ ������ ���� �Էº���(�ּ�)  unsigned : - ��� X
	char kBuf[100]; // ��� ���ڿ� �Է°���

	printf("���������� �ּҴ� %u[%08x] �Դϴ�.\n", (unsigned int)buf, buf);
	printf("�Է��� ������ �ּҸ� �Է��ϼ��� : ");
	scanf("%d", &addr); // �������� �ּ� ����
	pBuf = buf + addr;
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", kBuf);
	strcpy(pBuf, kBuf); // ���ڿ� ����
	Dump(buf, 100);
}

int Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0;
}

int Dump(char* p, int len) // �޸� ���� ��¿� �����Լ�(���̺귯�� ���� ����)
{
	for (int i = 0; i < len; i++) // �������� �޸� ���� 
	{
		if (i % 16 == 0) printf("\n08x ", p); // 16����� �� �� �ٲް� �ּ� ���
		if (i % 8 == 0)  printf("  "); // 8�� ������� ��ĭ
		printf("%02x ", (unsigned char)*p++); // p�� �ּҰ� *p �ּҿ� �ش��ϴ� ������ ���ڰ�
	}
}
