#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct linklist)
struct linklist{
	int num;
	char name[20];
	struct linklist*next;
	};                              //����ÿ���ڵ����ɽṹ 
int n=0;                            //����ڵ���� 
struct linklist* del(struct linklist* head,struct linklist* stu){
	struct linklist* p1=head,*p2=NULL;            //p1���������ң�p2ָ��p1ǰһ���ڵ� 
	if(head==NULL){                              //�������޷�ɾ��
		printf("list null");
		return (head);
	}
	else{                                             
		while(stu->num!=p1->num&&p1->next!=NULL){         //p1�ҵ�Ҫɾ���Ľڵ� 
			p2=p1;
			p1=p1->next;
		}
		if(stu->num==p1->num){
			if(p1==head){                                 //ɾ��ͷ�ڵ� 
				head=p1->next;
				//free(p1);
			}
			else{                                         //ɾ���м��� 
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
		 if(head==NULL){                       //�������� 
		 	head=stu;
		 	stu->next=NULL;
		 }
		 else{                                  //�ǿ����� 
		 	while(stu->num>p1->num&&p1->next!=NULL){
		 		p2=p1;
				p1=p1->next;
			 }
			 if(stu->num<p1->num){             //�ҵ�λ�ò���ڵ� 
			 	if(p1==head){                  //��Ϊͷ�ڵ㣨<1�ڵ��ֵ�� 
			 		head=stu;
			 		stu->next=p1;
				 }
				 else{                         //����ڵ� 
				 	p2->next=stu;
					 stu->next=p1; 
				 }
			 }
			 else{                             //δ�ҵ�λ�ó�Ϊβ�ڵ� 
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
		while(p!=NULL){                        //������� 
			printf("%d %s\n",p->num,p->name);
			p=p->next; 
		}
}
struct linklist* creat(){
	struct linklist*p1,*p2,*p;
	struct linklist*head=NULL;
  printf("�밴������������\n");
	p1=p2=(struct linklist*)malloc(len);
	scanf("%d%s",&p1->num,&p1->name);          //�����һ���ڵ����� 
	while(p1->num!=0){                        //�������� 
		n+=1;
		if(n==1){
			head=p1;                          //��ͷָ�� 
		}
		else{
			p2->next=p1;                      //���ӽڵ� 
			p2=p1;
			}
			p1=(struct linklist*)malloc(len);
			scanf("%d%s",&p1->num,&p1->name); 
			}
		p2->next=NULL;                        //ĩβָ��ָnull
		return (head);                    
}
int main(){
	struct linklist*head=NULL;                 //ͷָ�� 
	head=creat();                             //�������� 
	print(head);                              //������� 
	struct linklist stu;
    printf("������ɾ���Ľڵ������\n");
	scanf("%d",&stu.num);
	head=del(head,&stu);                      //ɾ���ڵ� 
	printf("\n");
	print(head);                              //������� 
	printf("���������Ľڵ������\n");
	scanf("%d%s",&stu.num,&stu.name);
	head=insert(head,&stu);                   //����ڵ�
	printf("\n");
	print(head);	                          //������� 
}

