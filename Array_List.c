#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int head = 0;

// 전달받은 head 를 이용해 연결리스트의 모든 노드에 대해서 메모리 해제
void delete_all(char* strArray[])
{
    int i;

    for(i=0; strArray[i]!=NULL; i++)
    {
        free(strArray[i]);
    }
}

// 전달받은 head를 이용해 연결리스트의 맨 끝에 data 노드를 추가
int add_tail(char* strArray[], char* data)
{
    int i;

    for(i=0;  strArray[i] != NULL; i++)
    {

    }
    strArray[i] = (char *)malloc(strlen(data)+1);
    strcpy(strArray[i], data);
}

// 전달받은 head를 이용해 연결리스트의 맨 앞에 data 노드를 추가
int add_head(char* strArray[], char* data)
{
    int i=0;

    for(i=99;  i>0; i--)
    {
        strArray[i]=strArray[i-1];
    }

    strArray[0] = (char *)malloc(strlen(data)+1);
    strcpy(strArray[0], data);
}

// 전달받은 head를 이용해 연결리스트의 값 중 target_data 노드의 다음에 data 노드를 추가
int add_next(char* strArray[], char* target_data, char* data)
{
    int i, j;
    int count=0;

    for(i=0; i<100; i++)
    {
        if(strcmp(strArray[i], target_data)==0)
        {
            count = 1;
            break;
        }
    }

    if(i==99 || count==0)
    {
        return 0;
    }
    else if(count==1)
    {
        for(j=99; j>i+1; j--)
        {
            strArray[j]=strArray[j-1];
        }
        strArray[i+1]=(char*)malloc(strlen(data)+1);
        strcpy(strArray[i+1], data);

        return 1;
    }
}

// 전달받은 head를 이용해 연결리스트의 i번째 노드 다음에 data 노드를 추가
int add_index(char* strArray[], int index, char* data)
{
    if(strArray[99] != NULL)
    {
        return 0;
    }

    int i;
    for(i=99; i>index; i--)
    {
        strArray[i]=strArray[i-1];
    }

    strArray[i]=(char *)malloc(strlen(data)+1);
    strcpy(strArray[i], data);

    return 1;
}

int main()
{
    char* strArray[100] = {NULL, };

    //배열의 맨 앞에 hello 추가
    add_head(strArray, "hello");

    //배열의 맨 뒤에 world 추가
    add_tail(strArray, "world");

    //배열의 hello 뒤에  good 추가
    add_next(strArray, "hello", "good");

    //배열의 2번 째 인덱스에 bad를 추가
    add_index(strArray, 2, "bad");

    int i;
    for(i=0; strArray[i]!=NULL; i++)
    {
        printf("%s ", strArray[i]);
    }
    printf("\n");

    delete_all(strArray);

	return 0;
}
