#include <stdio.h>
#include <conio.h>

int test01();
int test02(int a);


main()
{
 test02(1);
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
			printf("ca[%d] : %c (%03x)\n", i, ca[i], ca[i]); //%d 숫자 %c char // %02x 16진수 %와 x 사이
		}
		ca[2] -= 1;
		ca[3] -= 1;

		for (int i = 0; i < 6; i++) // 0~5
		{
			printf("ca[%d] : %c (%03x)\n", i, ca[i], ca[i]); //%d 숫자 %c char // %02x 16진수 %와 x 사이}
		}
}