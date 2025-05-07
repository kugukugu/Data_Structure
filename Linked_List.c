#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char* data;
	struct Node* next;
};

// 전달받은 data로 새로운 노드를 생성
struct Node* create_node(char* data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = (char*)malloc(strlen(data)+1);
    strcpy(temp->data, data);
    temp ->next = NULL;
    return temp;
}

// 전달받은 node에 대해 메모리 해제
void delete_node(struct Node* node)
{
}

// 전달받은 head 를 이용해 연결리스트의 모든 노드에 대해서 메모리 해제
void delete_all(struct Node* head)
{
}

// 전달받은 head를 이용해 연결리스트의 맨 끝에 data 노드를 추가
int add_tail(struct Node** head, char* data)
{
    struct Node* temp = create_node(data);

    if(*head == NULL)
    {
        *head=temp;
    }
    else
    {
        struct Node* tmp = *head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next=temp;
    }
}

// 전달받은 head를 이용해 연결리스트의 맨 앞에 data 노드를 추가
int add_head(struct Node** head, char* data)
{
    struct Node* temp = create_node(data);
    temp->next= *head;
    *head = temp;
}

// 전달받은 head를 이용해 연결리스트의 값 중 target_data 노드의 다음에 data 노드를 추가
int add_next(struct Node** head, char* target_data, char* data)
{
}

// 전달받은 head를 이용해 연결리스트의 i번째 노드 다음에 data 노드를 추가
int add_index(struct Node** head, int i, char* data)
{
}

// 전달받은 head를 이용해 연결리스트 전체 노드의 data를 보기좋게 출력
void print_linkedlist(struct Node* head)
{
    while(head != NULL)
    {
        printf("%s >> ", head->data);
        head = head->next;
    }
}

int main()
{
  struct Node* head = NULL;

  // 연결리스트의 맨 앞에 hello 추가
  add_head(&head, "hello");

  // 연결리스트의 맨 뒤에 world 추가
  add_tail(&head, "world");

  // 연결리스트의 hello 뒤에 good 추가

  // 연결리스트의 2번째 뒤에 bad 추가

  // 전체 연결리스트 출력
    print_linkedlist(head);
  // 전체 연결리스트 삭제

	return 0;
}
