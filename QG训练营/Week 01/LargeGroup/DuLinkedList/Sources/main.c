#include <stdio.h>
#include <stdlib.h>
#include "DuLinkedList.h"

void *Create(int n)                                   //����˫������
{
    DuLinkedList h, p, s;
    h = (DuLinkedList)malloc(sizeof(DuLNode));        //����Ϊ��Ԫ���p��������ڴ�ռ�

    if(h == NULL)                                      //�������ʧ�ܣ�˵������ջ���
    {
        return OVERFLOW;                               //����overflow
    }

    h->data = 0;                                        //��Ԫ����д洢��Ԫ��ֵΪ0
    h->prior = NULL;
    h->next = NULL;
    p = h;

    for(int i=0; i<n; i++)
    {
        s = (DuLinkedList)malloc(sizeof(DuLNode));
        if(s == NULL)
        {
            return OVERFLOW;
        }
        p->next = s;
        printf("�������%d������Ԫ��ֵ:", i+1);
        scanf("%d", &s->data);
        s->prior = p;                                   //ʹ�¿��ٵĽ������ǰ�����
        s->next = NULL;
        p = s;
    }
    printf("�������ɹ�!\n");
    return h;
}


void *InitList_DuL(DuLinkedList L)                   //��ʼ������
{
    L = (DuLinkedList)malloc(sizeof(DuLNode));
	if(!L)
    {
        return OVERFLOW;
    }
	L->prior = L->next = NULL;                        //���������Ԫ���������
	printf("Successfully initialize a DuLinkedList!\n");
	return L;                                         //������Ԫ����ָ��
}


void DestroyList_DuL(DuLinkedList L) //��������
{
    DuLinkedList p;
    p = L;                           //�ӱ�ͷ���α�������Ԫ��
	while(p)
    {
		p = p->next;
		free(L);                     //�ͷ��ڴ�ռ�
		L = p;
	}
}


void *Insert_Node(DuLinkedList head)            //����Ԫ��
{
   DuLinkedList q;
   DuLinkedList pnext = head;
   int i = 1;
   int n;

   printf("����������λ��:");
   scanf("%d", &n);

   while((i<n) && (pnext != NULL))
   {
      i++;
      pnext = pnext->next;

   }                                            //ѭ��������pnextָ�����λ�õ�ֱ��ǰ�����

   if(pnext == NULL)
   {
     return ERROR;
   }
   else
   {
        q = (DuLinkedList)malloc(sizeof(DuLNode));//p���붯̬�����ڴ�ռ�
        printf("����������Ԫ��ֵ:");
        scanf("%d", &q->data);                    //����Ԫ��ֵ

        q->next = pnext->next;                    //�½ڵ�������ֱ�Ӻ�̽ڵ㽨��˫���߼���ϵ
        if(n = 0)
        {
          pnext->next = q;
          q->next = NULL;
        }
        else
        {
          pnext->next = q;
          pnext->next->prior = q;                  //�½ڵ��ֱ��ǰ���ڵ���֮����˫���߼���ϵ
          q->prior = pnext;
        }
   }
   return head;
}


void *DeleteList_DuL(DuLinkedList L, ElemType e)//ɾ��Ԫ��
{
    if(L == NULL || L->next == NULL)
    {
        return ERROR;
    }
    DuLinkedList q, pre;
    q = L->next;
    while(q->data != e)
    {
        pre = q;
        q = q->next;
    }                                          //ѭ��������qָ��ɾ��Ԫ�أ�preָ����ǰ�����
    pre->next = q->next;                       //�����ɾ��Ԫ���������ӣ��ﵽɾ��Ԫ�ص�Ч��
    free(q);
    printf("ɾ���ɹ�!\n");
    return L;
}


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))   //��ӡ����
{
    DuLinkedList p = L->next;
	while(p)
    {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}
void visit(ElemType e)
{
	printf("%d->",e);
}





void *SearchList(DuLinkedList L, int i) // ����ĳλ�õ�Ԫ��
{
    if(L == NULL || L->next == NULL)
    {
        printf("��������!");
        return NULL;
    }
    int j = 1;
    DuLinkedList p = L->next;
    if(i == 1)
    {
        return L;
    }
    if(i < 1)
    {
        return NULL;
    }
    while(p && i>j)
    {
        p = p->next;
        j++;
    }
    return p;
}

DuLNode* FindMidNode(DuLinkedList L)//�����м���
{
    if(L == NULL || L->next == NULL)
    {
        return L;
    }
    DuLinkedList fast, slow;
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

void IsLoopList_DuL(DuLinkedList L)//�жϳɻ�
{
    if(L == NULL || L->next == NULL)
    {
        printf("����Ϊ�ջ�����ֻ��һ�����");
        return ERROR;
    }
    DuLinkedList fast, slow;
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

void *ReverseList_DuL(DuLinkedList L)//��ת����
{
	if(L == NULL)
    {
        printf("����Ϊ��!");
        return ERROR;
    }
	DuLNode *s,*p;
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

int DuLinkedList_length(DuLinkedList L)//�������������
{
    int k = 0;
    while(L != NULL)
    {
        k++;
        L = L->next;
    }
    return k;
}

int InputNumber()
{
	int num = 0; //�洢��ת������
	int status = 0; // ��־״̬
	char str[100]; // �����ַ���
	do
	{
		scanf("%s", str);
		status = SUCCESS;
		for (int i = 0; str[i] != '\0'; i++)
		{
			// ��������Ƿ���Ϲ淶
			if (i == 0)
            {
				if (str[i] == '-' || str[i] == '+')
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
			printf("��������,����������:");
		}
		else
		{
			int i = 0;
			// ���ַ���ת������������
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
			// ����������������Խ��
			if (i >= 10)
			{
				printf("Overflow, please input again:");
				status = ERROR;
			}
		}
	} while (status == ERROR);
	return num;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------


int main()
{
    DuLinkedList head; // Head of DuLinkedList.
    int flag = 0; // Whether exist DuLinkedList.
    while(SUCCESS)
    {
        system("cls");
        printf("\n---------------------------\n");
        printf(">>> 1.����������                 \n");
        printf(">>> 2.�������                   \n");
        printf(">>> 3.��ʼ������                 \n");
        printf(">>> 4.ɾ������                   \n");
        printf(">>> 5.�����½��                 \n");
        printf(">>> 6.ɾ�����                   \n");
        printf(">>> 7.����ĳλ�õĽ��           \n");
        printf(">>> 8.�����м���               \n");
        printf(">>> 9.�жϳɻ�                   \n");
        printf(">>> 10.��ת����                  \n");
        printf(">>> 11.Exit.                     \n");
        printf("---------------------------\n");
        if(flag)
        {
            TraverseList_DuL(head, visit); // ��ӡ����
        }
        else
        {
            printf("No LinkedList.\n");
        }
        printf("---------------------------\n");
        printf("----->>> ��ѡ��:");
        switch(InputNumber())
        {
        case 1:
            {
                int n;
                printf("����������Ľ�����:");
                scanf("%d", &n);
                head = Create(n);
                flag = 1;
                break;
            }
        case 2:
            if(flag)
            {
                TraverseList_DuL(head, visit);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 3:
            head = InitList_DuL(head);
            flag = 1;
            break;
        case 4:
            if(flag)
            {
                DestroyList_DuL(head);
                flag = 0;
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 5:
            if(flag)
            {
                head = Insert_Node(head);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 6:
            if(flag)
            {
                int x;
                printf("������ɾ����Ԫ��ֵ:");
                scanf("%d", &x);
                head = DeleteList_DuL(head, x);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 7:
            if(flag)
            {
                int i;
                DuLinkedList temp;
                printf("��������ҵ�λ��:");
                scanf("%d", &i);
                temp = SearchList(head, i);
                printf("��λ��%d��Ԫ��ֵ��%d\n",i,temp->data);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 8:
             if(flag)
            {
                DuLinkedList mid, temp = head;
                mid = FindMidNode(head);           //��mid�����պ����ķ���ֵ
                if(DuLinkedList_length(head)%2 == 0)
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
        case 9:
            if(flag)
            {
                IsLoopList_DuL(head);
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 10:
            if(flag)
            {
                head = ReverseList_DuL(head);
            }
            else
            {
                printf("��������\n");
            }
            break;
        case 11:
            exit(0);
        default:
            break;
        }
        system("pause");
    }
    return 0;
}

