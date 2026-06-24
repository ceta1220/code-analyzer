// 개발자 이태규, 임세진, 윤지환

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int analyze(); // 입력 받은 비밀번호의 점수 계산
void recom(); // 입력 비밀번호를 바탕으로 새로운 안전한 비밀번호 추천
char random_char(int); // recom 함수에서 부족한 문자열을 입력 받아 그 타입의 랜덤 문자 결정
void random_pw(); // 원하는 비밀번호의 길이를 입력받아 그 길이 만큼의 랜덤 비밀번호 생성
void count(); // 비밀번호를 입력받아 총 가짓수 출력

int main() // UI & 메뉴 출력
{
    srand(time(NULL));

    printf("\n\t   ______          __        ___                __                     \n\t  / ____/___  ____/ /__     /   |  ____  ____ _/ /_  ______  ___  _____\n\t / /   / __ \\/ __  / _ \\   / /| | / __ \\/ __ `/ / / / /_  / / _ \\/ ___/\n\t/ /___/ /_/ / /_/ /  __/  / ___ |/ / / / /_/ / / /_/ / / /_/  __/ /    \n\t\\____/\\____/\\__,_/\\___/  /_/  |_/_/ /_/\\__,_/_/\\__, / /___/\\___/_/     \n\t                                              /____/                   \n");

    printf("\t1. 비밀번호 안전성 분석\n");
    printf("\t2. 안전한 비밀번호 추천\n");
    printf("\t3. 랜덤 비밀번호 생성기\n");
    printf("\t4. 비밀번호 가짓수 계산\n");

    int menu;

    printf("\n\t> ");
    scanf("%d", &menu);

    if(menu == 1)
        printf("점수 : %d\n", analyze());

    else if(menu == 2)
        recom();

    else if(menu == 3)
        random_pw();
    else if(menu == 4)
        count();
    return 0;
}

int analyze() // 입력 받은 비밀번호의 점수 계산
{
    char pw[100];
    printf("비밀번호 입력 > ");
    scanf("%99s", pw);

    int num = 0, up = 0, low = 0, oth = 0;
    int score = 0;

    for(int i = 0; pw[i] != '\0'; i++){
        if('0' <= pw[i] && pw[i] <= '9')
            num=10;
        else if('A' <= pw[i] && pw[i] <= 'Z')
            up=26;
        else if('a' <= pw[i] && pw[i] <= 'z')
            low=26;
        else
            oth=32;
    }

    int len = strlen(pw);
    double tot = len * log2(num+up+low+oth); // log를 이용하여 총 가짓수 계산 값을 간소화 했다.

    if(tot >= 128)
        score = 100;
    else if(tot >= 100)
        score = 90;
    else if(tot >= 90)
        score = 80;
    else if(tot >= 80)
        score = 70;
    else if(tot >= 70)
        score = 60;
    else if(tot >= 60)
        score = 50;
    else if(tot >= 50)
        score = 40;
    else if(tot >= 40)
        score = 30;
    else if(tot >= 30)
        score = 20;
    else if(tot >= 20)
        score = 10;
    else
        score = 0;

    return score;
}

char random_char(int type) // recom 함수에서 부족한 문자열을 입력 받아 그 타입의 랜덤 문자 결정
{
    char special[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    if(type == 0)
        return 'A' + rand() % 26;

    if(type == 1)
        return 'a' + rand() % 26;

    if(type == 2)
        return '0' + rand() % 10;

    if(type == 3)
        return special[rand() % strlen(special)];

    return random_char(rand() % 4);
}

void recom() // 입력 비밀번호를 바탕으로 새로운 안전한 비밀번호 추천
{
    char pw[100];
    printf("비밀번호 입력 > ");
    scanf("%99s", pw);

    int up = 0;
    int low = 0;
    int num = 0;
    int oth = 0;

    for(int i = 0; pw[i] != '\0'; i++)
    {
        if('A' <= pw[i] && pw[i] <= 'Z')
            up = 1;

        else if('a' <= pw[i] && pw[i] <= 'z')
            low = 1;

        else if('0' <= pw[i] && pw[i] <= '9')
            num = 1;

        else
            oth = 1;
    }

    int len = strlen(pw);

    if(!up)
        pw[len++] = random_char(0);

    if(!low)
        pw[len++] = random_char(1);

    if(!num)
        pw[len++] = random_char(2);

    if(!oth)
        pw[len++] = random_char(3);

    while(len < 15)
        pw[len++] = random_char(4);

    pw[len] = '\0';

    printf("추천 비밀번호 : %s\n", pw);
}

void random_pw() // 원하는 비밀번호의 길이를 입력받아 그 길이 만큼의 랜덤 비밀번호 생성
{
    int len;
    char ch;

    while (1)
    {
        printf("길이 입력 > ");

        if (scanf("%d%c", &len, &ch) == 2 &&
            ch == '\n' &&
            len > 0)
            break;

        printf("숫자만 입력하세요.\n");

        while (getchar() != '\n');
    }

    char pw[len-1];

    for(int i = 0; i < 20; i++)
        pw[i] = random_char(4);

    pw[len] = '\0';

    printf("랜덤 비밀번호 : %s\n", pw);
}

void count(){ // 비밀번호를 입력받아 총 가짓수 출력
    char pw[100];
    scan(pw);
    int num=0, up=0, low=0, oth=0;
    int len = strlen(pw);
    for(int i = 0; pw[i] != '\0'; i++)
    {
        if('A' <= pw[i] && pw[i] <= 'Z')
            up = 26;

        else if('a' <= pw[i] && pw[i] <= 'z')
            low = 26;

        else if('0' <= pw[i] && pw[i] <= '9')
            num = 10;

        else
            oth = 32;
    }
    double c = pow((num+up+low+oth), len); // pow를 이용하여 (num+up+low+oth)의 len 제곱을 했다.
    printf("%lf", c);
}