#include<stdio.h>
#include<string.h>
#include"链表.h"
#include<stdbool.h>
//1.删除链表中等于给定值 val 的所有节
//第一种方法：创建一个新链表，若不是v则给新链表尾插
struct Node* removeElements(struct Node* head, int val)
{
	Node*node = (Node*)malloc(sizeof(node));
	struct Node* node = head;
	struct Node* last = NULL;
	struct Node* result = NULL;
	while (node != NULL)
	{
		struct Node* next =node->next;
		if (node->value != val)
		{
			if (result == NULL)
			{
				result = node;
				last = node;
			}
			else
			{
				last->next = node;
				last = node;
			}
		}
		else
		{
		}
		node = next;
	}
	if (last != NULL)
	{
		last->next = NULL;
	}
	return result;
}


//第二种方法：向后查删，若是v则free指向下一个非v
//**ppHead(*ppHead,v)
void Remove(Node **ppHead, int v)
{
	if (*ppHead = NULL)
	{
		return;
	}
	Node*cur = *ppHead;
	if (cur->value == v)
	{
		*ppHead = cur->next;
		free(cur);
		return;
	}
	while (cur->next != NULL)//当没有到结尾时
	{
		if (cur->next->value == v)
		{
			Node*next = cur->next;
			cur->next = next->next;
			free(next);
			return;
		}
		cur = cur->next;
	}
}

//逆向链表
struct Node* reverseList(struct Node* head)
{
	struct Node *prev = NULL;
	struct Node *cur = head;

	while (cur != NULL) {
		struct Node *next = cur->next;
		cur->next = prev;

		prev = cur;
		cur = next;
	}

	return prev;
}


//将两个有序链表合并为一个新的有序链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。
struct Node* mergeTwoLists(struct Node* l1, struct Node* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	struct Node* c1 = l1;
	struct Node* c2 = l2;
	struct Node* last=NULL;
	struct Node* result=NULL;
	while (c1 != NULL&&c2 != NULL)
	{
		if (c1->value <= c2->value)
		{
			struct Node *next = c1->next;
			c1->next = NULL;
			if (result == NULL)
			{
				result = c1;
				last = c1;
			}
			else//result已经有值了
			{
				last->next = c1;
				last = c1;
			}
			c1 = next;
		}
		else
		{
				struct ListNode *next = c2->next;
				c2->next = NULL;
				if (result == NULL)
				{
					result = c2;
					last = c2;
				}
				else//result已经有值了
				{
					last->next = c2;
					last = c2;
				}
				c2 = next;
		}
	}
	//始终给结尾加NULL，防止链表结尾遗漏
	last->next = NULL;
	return result;
}

// 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 
 struct Node* partition(Node* pHead, int x)
{
	 Node* small = NULL;
	 Node* small_last = NULL;
	 Node* big = NULL;
	 Node* big_last = NULL;
	 Node* cur = pHead;
	 while (cur != NULL)
	 {
		 Node* next = cur->next;
		 if (cur->value <= x)
		 {
			 //small为NULL时
			 if (small == NULL)
			 {
				 small = cur;
				 small_last = cur;
			 }
			 else
			 {
				 small_last->next = cur;
				 small_last = cur;
			 }
		 }
		 else
		 {
			 if (big == NULL)
			 {
				 big = cur;
				 big_last = cur;
			 }
			 else
			 {
				 big_last->next = cur;
				 big_last = cur;
			 }
		 }
		 cur = next;
	 }
	 if (small == NULL)
	 {
		 return big;
	 }
	 else if (big == NULL)
	 {
		 return small;
	 }
	 else
	 {
		 small_last->next = big;
		 return small;
	 }
 }

// 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
	 //如果有两个中间结点，则返回第二个 中间结点
 struct Node* middleNode(struct Node* head)
	 //用快慢倆指针快的为慢的两倍速度，当快的走完时慢的必然是快的一半
 {
	 struct Node *fast = head;
	 struct Node *slow = head;
	 while (fast != NULL)
	 {
		 fast=fast->next;//快走一步
		 slow=slow->next;//慢走一步
		 //当快的走到头时
		 if (fast == NULL)
		 {
			 return slow;
		 }
		 //若没走到头则快的再多走一步
		 fast = fast->next;
	 }
	 return slow;
 }

 //输入一个链表，输出该链表中倒数第k个结点
Node* FindKthToTail(Node* pListHead, unsigned int k)
 {
	Node* front = pListHead;
	Node* back = pListHead;
	int i;
	for (i = 0; front != NULL&&front <= k - 1; k++)//front没走到头时让front先走k-1步
	{
		front = front->next;
	}
	
	while (front != NULL)//
	{
		front = front->next;
		if (front == NULL)//front走到头了，back不走
		{
			//k的值超出了链表长度,为NULL时//例如链表长度为5，找倒数第8个数则，8-1=7，i走不到7就会到头找到NULL
			if (i < k - 1)
			{
				NULL;
			}
			break;
		}
		back = back->next;
	}
	return back;
 }

// 链表的回文结构
bool chkPalindrome(Node* A)
{
	Node* head = A;
	//求链表长度
	int len;
	for (Node*cur = head; cur != NULL; cur = cur->next)
	{
		len++;
	}
	//找寻链表中点
	Node*middle = head;
	for (int i = 0; i < len / 2; i++)
	{
		middle = middle->next;
	}
	//逆置链表的后半部分
	Node*phead = NULL;//虚拟结点代表middle前一个
	Node*node = middle;
	Node*next = node->next;
	while (next != NULL)
	{
		node->next = phead;
		phead = node;
		node = next;
		next = next->next;
	}
	//判断是否为回文
	Node*p1 = head;
	Node*p2 = phead;
	while (p1 != NULL&&p2 != NULL)
	{
		if (p1 != p2)
		{
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;//循环能走到头说明是回文
}

//在一个排序的链表中，存在重复的结点，
//请删除该链表中重复的结点，重复的结点不保留，返回链表头 指针
Node* deleteDuplication(Node* pHead)
{
	//先判断链表是否为空
	if (pHead == NULL)
	{
		return NULL;
	}
	//设置三个指针fake、p1、p2分别为前中后进行向后移动
	Node* fake = (Node*)malloc(sizeof(Node));
	Node*prev = fake;
	fake->next = pHead;
	Node*p1 = pHead;
	Node*p2 = pHead->next;
	//若p1与p2不等则三个继续向后
	while (p2 != NULL)
	{
		if (p1 ->value!= p2->value)
		{
			prev = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else
		{
			while(p1->value == p2->value)
			{
				p2 = p2->next;
			}//只要相等就一直向后查找所以用while
			prev->next = p2;//前一个假结点直接跳过p1，指向p2
			p1 = p2;
			if (p2 != NULL)
			{
				p2 = p2->next;
			}
		}
	}
	//若p1与p2相等则将p2向后移动找到下一个不一样的之后将fake指向p2
	//p1取代p2，p2后移一个
	pHead = fake->next;//将头重新指向假结点的下一个，假结点除了next其他值始终不变
	free(fake);//用完后释放假结点
	return pHead;
}


//输入两个链表，找出它们的第一个公共结点。
int getLen(struct ListNode *head)//判断两个链表长度
{
	int len;
	for (Node*cur = head; cur != NULL; cur = cur->next)
	{
		len++;
	}
}
struct Node *getIntersectionNode(struct Node *headA, struct Node *headB)
{
	int lenA=getlen(headA);
	int lenB=getlen(headB);
	int diff = lenA - lenB;
	Node*longer = headA;
	Node*shorter = headB;
	if (lenA < lenB)
	{
		longer = headB;
		shorter = headA;
	}//判断两链表长度及差值diff
	for (int i = 0; i < diff; i++)
	{
		longer = longer->next;
	}//将较长链表向后diff个结点，把俩链表变为一样长
	while (longer != shorter)//两链表同时向后查找知道地址相同则为第一个公共结点
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return shorter;//返回任一链表
}