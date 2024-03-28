#include <stdio.h>
#include <conio.h>

int test01();
int test02(int a);
int test03();
int Dump(char* p, int len); // 메모리 공간 출력용 범용함수(라이브러리 적용 가능)
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
	printf("숫자 키를 입력하세요. 해당하는 영단어를 알려드리겠습니다.\n");
	printf("프로그램을 끝내시려면 'Q'키를 입력하세요 \n\n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch();
		int m = c - 0x30; //0x30 ASC||  --> num로 변환 가능 0x30 = 0
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
int test02(int a)	// 문자열과 문자배열
{
	char ca[] = "Hello"; // ca0] : 'H' ... ca[4]:'o' ca[5] :\0(null)

	for (int i = 0; i < 6; i++) // 0~5
	{
		printf("ca[%d] : %c (%02x) [%08x]\n", i, ca[i], ca[i], ca + i); //%d 숫자 %c char // %02x 16진수 %와 x 사이
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
	char buf[100]; // 안전 메모리 공간 확보
	char* pBuf; // 안전 메모리 공간중의 출력 위치
	unsigned int addr; // 출력 위치 지정을 위한 입력변수(주소)  unsigned : - 사용 X
	char kBuf[100]; // 출력 문자열 입력공간

	printf("안전공간의 주소는 %u[%08x] 입니다.\n", (unsigned int)buf, buf);
	printf("입력을 시작할 주소를 입력하세요 : ");
	scanf("%d", &addr); // 안전공간 주소 참고
	pBuf = buf + addr;
	printf("문자열을 입력하세요 : ");
	scanf("%s", kBuf);
	strcpy(pBuf, kBuf); // 문자열 복사
	Dump(buf, 100);
}

int Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0;
}

int Dump(char* p, int len) // 메모리 공간 출력용 범용함수(라이브러리 적용 가능)
{
	for (int i = 0; i < len; i++) // 안전공간 메모리 덤프 
	{
		if (i % 16 == 0) printf("\n08x ", p); // 16배수일 때 줄 바꿈과 주소 찍기
		if (i % 8 == 0)  printf("  "); // 8의 배수마다 빈칸
		printf("%02x ", (unsigned char)*p++); // p는 주소값 *p 주소에 해당하는 값으로 문자값
	}
}
