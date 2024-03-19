#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct linklist)
struct linklist{
	int num;
	char name[20];
	struct linklist*next;
	};                              //链表每个节点的组成结构 
int n=0;                            //计算节点个数 
struct linklist* del(struct linklist* head,struct linklist* stu){
	struct linklist* p1=head,*p2=NULL;            //p1负责往后找，p2指向p1前一个节点 
	if(head==NULL){                              //空链表无法删除
		printf("list null");
		return (head);
	}
	else{                                             
		while(stu->num!=p1->num&&p1->next!=NULL){         //p1找到要删除的节点 
			p2=p1;
			p1=p1->next;
		}
		if(stu->num==p1->num){
			if(p1==head){                                 //删除头节点 
				head=p1->next;
				//free(p1);
			}
			else{                                         //删除中间结点 
				printf("delete:%d %s\n",p1->num,p1->name);
				p2->next=p1->next;
				//free(p1);
			}
//			n-=1;
		}
		else{
			printf("Not Found\n");
		}
	}
	return (head);
} 
struct linklist* insert(struct linklist* head,struct linklist* stu){
		 struct linklist* p1=head,*p2=NULL;
		 if(head==NULL){                       //若空链表 
		 	head=stu;
		 	stu->next=NULL;
		 }
		 else{                                  //非空链表 
		 	while(stu->num>p1->num&&p1->next!=NULL){
		 		p2=p1;
				p1=p1->next;
			 }
			 if(stu->num<p1->num){             //找到位置插入节点 
			 	if(p1==head){                  //成为头节点（<1节点的值） 
			 		head=stu;
			 		stu->next=p1;
				 }
				 else{                         //插入节点 
				 	p2->next=stu;
					 stu->next=p1; 
				 }
			 }
			 else{                             //未找到位置成为尾节点 
			 	p1->next=stu;
			 	stu->next=NULL;
			 }
		 }
//		 n+=1;
		 return (head);
}
void print(struct linklist*p){
		if(p==NULL){
			printf("NULL\n");
		} 
		while(p!=NULL){                        //输出链表 
			printf("%d %s\n",p->num,p->name);
			p=p->next; 
		}
}
struct linklist* creat(){
	struct linklist*p1,*p2,*p;
	struct linklist*head=NULL;
  printf("请按升序输入数据\n");
	p1=p2=(struct linklist*)malloc(len);
	scanf("%d%s",&p1->num,&p1->name);          //输入第一个节点数据 
	while(p1->num!=0){                        //创建链表 
		n+=1;
		if(n==1){
			head=p1;                          //定头指针 
		}
		else{
			p2->next=p1;                      //连接节点 
			p2=p1;
			}
			p1=(struct linklist*)malloc(len);
			scanf("%d%s",&p1->num,&p1->name); 
			}
		p2->next=NULL;                        //末尾指针指null
		return (head);                    
}
int main(){
	struct linklist*head=NULL;                 //头指针 
	head=creat();                             //创建链表 
	print(head);                              //输出链表 
	struct linklist stu;
    printf("请输入删除的节点的数据\n");
	scanf("%d",&stu.num);
	head=del(head,&stu);                      //删除节点 
	printf("\n");
	print(head);                              //输出链表 
	printf("请输入插入的节点的数据\n");
	scanf("%d%s",&stu.num,&stu.name);
	head=insert(head,&stu);                   //插入节点
	printf("\n");
	print(head);	                          //输出链表 
}

