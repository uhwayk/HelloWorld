#include "linkedListDemo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void *InitList(LinkedList L)                 //��ʼ������
{
    if(!L)                                  // �ж�����ͷ����Ƿ����
    {
        return ERROR;                       //�������ڣ����ʼ��ʧ�ܣ�����error
    }
    L = (LinkedList)malloc(sizeof(LNode)); // Ϊͷ��㶯̬�����ڴ�
    if(L == NULL)                          // �ж��Ƿ�����ɹ�
    {
        return OVERFLOW;                    //������ʧ�ܣ�˵��ջ���������overflow
    }
    printf("�����ʼ���ɹ�!\n");
    L->next = NULL;                          //����һ��ֻ��ͷ��������
    return L;
}


Status DestroyList(LinkedList L)             //��������
{
    LinkedList p;                            //����ṹ��ָ��p����ÿһ�����
    p = L;                                   //ָ��pָ��������ʼλ��
    while(p)
    {
        p = p->next;                         //ָ��pָ����һ�����
        free(L);                            // �ͷ�L��ָ������ڴ�ռ�
        L = p;                               //ָ��Lָ��ָ��p
    }
    printf("����ɾ���ɹ�!\n");
    return SUCCESS;
}


void *InsertList(LinkedList L, int i, ElemType x)//����Ԫ��
{
    if(L == NULL)
    {
        printf("��������!");
        return ERROR;
    }
    LinkedList pre;
    pre = L;
    for(int temp=1; temp < i; temp++)      //��ָ��preָ�����λ�õ�ǰ�����
    {
        pre = pre->next;
    }
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));  //Ϊ����Ľ������ռ�
    q->data = x;
    q->next = pre->next;                    //���ò��������Ӻ��ý��
    pre->next = q;                          //����ǰ��������Ӳ�����

    printf("Ԫ�ز���ɹ�!\n");
    return L;
}


void *DeleteList(LinkedList L, ElemType x)       //ɾ�������е�ָ��Ԫ��
{
    if(L == NULL || L->next == NULL)
    {
        printf("����Ϊ��!");
        return ERROR;
    }
    LinkedList q, pre;
    q = L->next;
    while(q->data != x)                         //pre�ҵ�Ҫɾ��Ԫ��ֵ��ǰ����㣬��ʱqָ��ɾ���Ľ��
    {
        pre = q;
        q = q->next;
    }
    pre->next = q->next;
    free(q);                                     //�ͷű�ɾ�������ڴ�ռ�
    printf("Ԫ��ֵɾ���ɹ�!");
    return L;
}


void TraverseList(LinkedList L, void (*visit)(ElemType e))//����������ӡ
{
    LinkedList p = L->next;        //ָ��p�ҵ���һ�����
    while(p)
    {
        visit(p->data);            //�ӵ�һ����㿪ʼ�����ӡԪ��ֵ
        p = p->next;
    }
    printf("\n");
}
void visit(ElemType e)
{
    printf("%d->", e);
}


void *SearchList(LinkedList L, int i) // ����ָ��λ�õĽ��
{
    if(L == NULL || L->next == NULL)
    {
        printf("����Ϊ��!");
        return NULL;
    }
    int j = 1;                   //jΪ������
    LinkedList p = L->next;
    if(i == 1)                   //��ֻ��һ����㣬ֱ�ӷ���ͷָ��
    {
        return L;
    }
    if(i < 1)                    //λ��С��1������null����
    {
        return NULL;
    }
    while(p && i>j)               //��j=iʱ����ѭ��������ָ��
    {
        p = p->next;
        j++;
    }
    return p;
}


void *ReverseList(LinkedList L)//��ת����
{
	if(L == NULL)
    {
        printf("����Ϊ��!");
        return ERROR;
    }
	LNode *s,*p;
	p = L->next;           //׼���׶Σ��ȼ�¼��һ������λ�ã����Ͽ�L�͵�һ����������
	L->next = NULL;
	while(p)
	{
		s = p;              //s��¼p��λ��
		p = p->next;        //pָ����һ�����
		s->next = L->next;  //����s��ָ�������L�ĺ��ý��
		L->next = s;        //����L����s��ָ���
	}

	return L;
}


void IsLoopList(LinkedList L)//�жϳɻ�
{
    if(L == NULL || L->next == NULL)
    {
        printf("����Ϊ�ջ�����ֻ��һ�����");
        return ERROR;
    }
    LinkedList fast, slow;
    slow = L;
    fast = L->next;
    while(1)
    {
        if(!fast || !fast->next)                     //��ָ�������null��˵�������ɻ�
        {
            printf("���ǳɻ�����\n");
            return SUCCESS;
        }
        else if(fast == slow || fast->next == slow) // ��ָ������ָ��������˵������ɻ�
        {
            printf("�ǳɻ�����\n");
            return SUCCESS;
        }
        else
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
}


LNode* ReverseEvenList(LinkedList L)
{
    LinkedList cur = L->next;
    LinkedList pre;
    LinkedList phead = (LinkedList)malloc(sizeof(LNode));
    phead->next = NULL;
    LinkedList ph = phead;

    while( cur && cur->next )
    {
        pre = cur;
        ph->next = pre->next; // First point to the second node in two groups.
        ph = ph->next; // Move ph pointer.
        cur = cur->next->next; // Move the cur pointer for the next round of swaps.
        ph->next = pre; // Point to the first node in two sets.
        ph = ph->next; // Move ph pointer.
    }
    ph->next = cur; // Finally point to the remaining element if cur is NULL or odd.
    return phead;
}


LNode* FindMidNode(LinkedList L)//�����м���
{
    if(L == NULL || L->next == NULL)
    {
        return L;
    }
    LinkedList fast, slow;
    fast = slow = L;
    while(fast!=NULL)
    {
        if(fast->next == NULL) //���fastָ��ָ�����һ����㣬������һ�����ָ��NULL
        {
            fast = fast->next;
        }
        else
        {
            fast = fast->next->next;//fastָ�����������
        }
        slow = slow->next;//slowָ����һ�����
    }
    return slow;  //fast�������һ�����ʱ��slowָ��ָ���м���
}


void *Create()
{
    LinkedList head;
    LinkedList p, s;                                               //���������ṹ��ָ��s��p��s���������ڴ�ʹ������ݣ�p������¼ǰ�ý��λ�úͽ������
    ElemType x, cycle = 1;
    int i=1;
    head = (LinkedList)malloc(sizeof(LNode));
    p = head;
    while(cycle)
    {
        printf("�������%d������(input non-integer to exit):",i++);//����0~9����������ַ���������Ĵ���
        if(scanf("%d", &x) == 1)                                   //�������������Ϲ淶����scanf��ȷ���յ�������ֵΪ1
        {
            s = (LinkedList)malloc(sizeof(LNode));
            s->data = x;
            p->next = s;
            p = s;
        }
        else
        {
            cycle = 0;
        }
    }
    printf("�������ɹ�!\n");
    p->next = NULL;
    return head;
}


int LinkedList_length(LinkedList L)//�������������
{
    int k = 0;
    while(L != NULL)
    {
        k++;
        L = L->next;
    }
    return k;
}


int InputNumber()  //��������
{
	int num = 0; // Store converted numbers.
	int status = 0; // ��¼����״̬
	char str[100]; // �����ַ���
	do
	{
		scanf("%s", str);
		status = SUCCESS;
		for (int i = 0; str[i] != '\0'; i++)
		{
			//������޲��Ϲ淶���ַ�
			if (i == 0)
            {
				if (str[i] == '-' || str[i] == '+')  //�洢��Ԫ�ؿ���Ϊ����
					continue;
			}
			else
			{
				if (str[i] < '0' || str[i] > '9')
				{
					status = ERROR;
				}
			}
		}
		if (status == ERROR)
        {
			printf("�����������,����������:");
		}
		else
		{
			int i = 0;
			// Convert string to number.
			for (i = 0, num = 0; str[i] != '\0'; i++)
			{
				if (i == 0)
                {
					if (str[i] == '-' || str[i] == '+')
					{
						continue;
					}
					else
					{
						num *= 10;
						num += (str[i] - 48);
					}
				}
				else
				{
					num *= 10;
					num += (str[i] - 48);
				}
			}
			if (str[0] == '-')
            {
				num = -num;
			}
			// Check if the number entered is out of bounds.
			if (i >= 10)
			{
				printf("Overflow, please input again:");
				status = ERROR;
			}
		}
	} while (status == ERROR);
	return num;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    LinkedList head; // ���������ͷָ��
    int flag = 0; // flag�ж������Ƿ����
    while(SUCCESS)
    {
        system("cls");
        printf("\n\n\n----------------------------------\n");
        printf(">>> 1.��������                   \n");
        printf(">>> 2.��ӡ����                   \n");
        printf(">>> 3.��ʼ������                 \n");
        printf(">>> 4.����ɾ��                   \n");
        printf(">>> 5.����Ԫ��                   \n");
        printf(">>> 6.ɾ��Ԫ��                   \n");
        printf(">>> 7.����Ԫ��                   \n");
        printf(">>> 8.��������                   \n");
        printf(">>> 9.����������/ż�����.       \n");
        printf(">>> 10.�����м���              \n");
        printf(">>> 11.�жϳɻ�                  \n");
        printf(">>> 12.Exit.                     \n");
        printf("---------------------------------\n");
        if(flag)
        {
            TraverseList(head, visit); // ��ӡ����
        }
        else
        {
            printf("No LinkedList.\n");
        }
        printf("---------------------------------\n");
        printf("----->>> ��ѡ��:");
        switch(InputNumber())
        {
        case 1:
            head = Create();
            flag = 1;
            break;
        case 2:
            if(flag)
            {
                TraverseList(head, visit);
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 3:
            head = InitList(head);
            flag = 1;
            break;
        case 4:
            if(flag)
            {
                DestroyList(head);
                flag = 0;
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 5:
            if(flag)
            {
                int i;
                ElemType x;
                printf("����������λ�� ");
                scanf("%d", &i);
                printf("���������Ԫ�ص�ֵ:");
                scanf("%d", &x);
                head = InsertList(head, i, x);
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 6:
            if(flag)
            {
                ElemType x;
                printf("������ɾ����Ԫ��ֵ ");
                scanf("%d", &x);
                DeleteList(head, x);
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 7:
            if(flag)
            {
                int i;
                LinkedList temp;
                printf("��������ҵ�λ��");
                scanf("%d", &i);
                temp = SearchList(head, i);
                printf("��%d������Ԫ����%d\n",i,temp->data);
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 8:
            if(flag)
            {
                head = ReverseList(head);
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 9:
            if(flag)
            {
                head = ReverseEvenList(head);
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 10:
            if(flag)
            {
                LinkedList mid, temp = head;
                mid = FindMidNode(head);           //��mid�����պ����ķ���ֵ
                if(LinkedList_length(head)%2 == 0)
                {
                    printf("�м����Ԫ��ֵ��%d\n", mid->data);
                }
                else                             // ���������Ϊż�������ӡ�м��������.
                {
                    while(temp->next != mid)     // ����һ���м�����mid����ǰ��
                    {
                        temp = temp->next;
                    }
                    printf("�м����Ԫ��ֵ��%d��%d\n", temp->data, temp->next->data);
                }
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 11:
            if(flag)
            {
                IsLoopList(head);
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 12:
            exit(0);
        default:
            break;
        }
        system("pause");
    }
    return 0;
}
