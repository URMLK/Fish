#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct doublelist)
struct doublelist{
	int num;
	char name[20];
	struct doublelist* left;
	struct doublelist* right;
};
int n=0;

struct doublelist* insert2(struct doublelist* end,struct doublelist* stu){
		 struct doublelist* p1=end;           //ָ��β�ڵ㣨��ͷ��β�� 
		 if(end==NULL){                       //�������� 
		 	end=stu;
		 	stu->right=NULL;
		 	stu->left=NULL;
		 }
		 else{                                  //�ǿ����� 
		 	while(stu->num < p1->num&&p1->left!=NULL){
				p1=p1->left;
			 }
			 if(stu->num > p1->num){             //�ҵ�λ�ò���ڵ� 
			 	if(p1==end){                  //��Ϊβ�ڵ㣨>β�ڵ��ֵ�� ����ͷ��β��
			 		end=stu;
					stu->left=p1;
					p1->right=stu;
					stu->right=NULL;
				 }
				 else{                         //�����м�ĳ���ڵ� 
				 	p1->right->left=stu;
				 	stu->right=p1->right;
				 	stu->left=p1;
				 	p1->right=stu;
				 }
			 }
			 else{                             //δ�ҵ�λ�ó�Ϊͷ�ڵ� ����ͷ��β��
			    p1->left=stu;
			    stu->right=p1;
			   	stu->left=NULL;
			 }
		 }
//		 n+=1;
		 return (end);
}
struct doublelist* insert1(struct doublelist* head,struct doublelist* stu){
		 struct doublelist* p1=head;            //ָ��ͷ�ڵ㣨��ͷ��β��
		 if(head==NULL){                       //�������� 
		 	head=stu;
		 	stu->right=NULL;
		 	stu->left=NULL;
		 }
		 else{                                  //�ǿ����� 
		 	while(stu->num > p1->num&&p1->right!=NULL){
				p1=p1->right;
			 }
			 if(stu->num < p1->num){             //�ҵ�λ�ò���ڵ� 
			 	if(p1==head){                  //��Ϊͷ�ڵ㣨<1�ڵ��ֵ�� ����ͷ��β��
			 		head=stu;
			 		stu->left=NULL;
			 		stu->right=p1;
			 		p1->left=stu;
				 }
				 else{                         //�����м�ĳ���ڵ� 
				 	p1->left->right=stu;
					stu->left=p1->left;
					stu->right=p1;
					p1->left=stu;
				 }
			 }
			 else{                             //δ�ҵ�λ�ó�Ϊβ�ڵ� ����ͷ��β��
			 	p1->right=stu;
			 	stu->left=p1;
			 	stu->right=NULL;
			 }
		 }
//		 n+=1;
		 return (head);
}
struct doublelist* del2(struct doublelist* end,struct doublelist* stu){
	struct doublelist* p1=end;                                  //ָ��β�ڵ㣨��ͷ��β��
	if(end==NULL){                                              //�������޷�ɾ�� 
		printf("list null\n");
		return (end);
	}
	else{
		while(stu->num!=p1->num&&p1->left!=NULL){		
			p1=p1->left;                                       //ʹp1ָ��ɾ���ڵ� 
		}
		if(stu->num==p1->num){
			if(p1==end&&p1->left!=NULL){                      //ɾ��β��� ����ͷ��β��
				printf("delete:%d %s\n",p1->num,p1->name);
				end=p1->left;
				p1->left->right=NULL;
				p1->right=NULL;
				p1->left=NULL;
			}
			else if(p1==end&&p1->left==NULL){                 //ɾ����һ�����������β��� ����ͷ��β��
				printf("delete:%d %s\n",p1->num,p1->name);
				end=p1->left;
				p1->right=NULL;
				p1->left=NULL;
			}
			else if(p1!=end&&p1->left!=NULL){                //ɾ���м���                                
				printf("delete:%d %s\n",p1->num,p1->name);                 
				p1->right->left=p1->left;
			    p1->left->right=p1->right;
			    p1->right=NULL;
			    p1->left=NULL; 
			}
			else {                                           //ɾ��ͷ��㣨��ͷ��β��
				printf("delete:%d %s\n",p1->num,p1->name);
			    p1->right->left=NULL;
				p1->left=NULL;
				p1->right=NULL;
			}
//			n-=1;
		}
		else{
			printf("Not Found\n");
		}
	}
	return (end);
} 
struct doublelist* del1(struct doublelist* head,struct doublelist* stu){
	struct doublelist* p1=head;                                 //ָ��ͷ�ڵ㣨��ͷ��β��
	if(head==NULL){                                             //�������޷�ɾ�� 
		printf("list null");
		return (head);
	}
	else{
		while(stu->num!=p1->num&&p1->right!=NULL){                           
			p1=p1->right;                                      //ʹp1ָ��ɾ���ڵ� 
		}
		if(stu->num==p1->num){
			if(p1==head&&p1->right!=NULL){                     //ɾ��ͷ��� ����ͷ��β��
				printf("delete:%d %s\n",p1->num,p1->name);
				head=p1->right;
				p1->right->left=NULL;
				p1->right=NULL;
				p1->left=NULL;
			}
			else if(p1==head&&p1->right==NULL){                //ɾ����һ�����������ͷ��� ����ͷ��β��
				head=p1->right;
				p1->right=NULL;
				p1->left=NULL;
			}
			else if(p1!=head&&p1->right!=NULL){                //ɾ���м���                                             
				printf("delete:%d %s\n",p1->num,p1->name);	
				p1->left->right=p1->right;
				p1->right->left=p1->left;
				p1->left=NULL;
			    p1->right=NULL;
			}
			else {                                             //ɾ��β��� ����ͷ��β��
				printf("delete:%d %s\n",p1->num,p1->name);
				p1->left->right=NULL;
				p1->left=NULL;
				p1->right=NULL;
			}
//			n-=1;
		}
		else{
			printf("Not Found\n");
		}
	}
	return (head);
} 
void print2(struct doublelist* end){
	struct doublelist*p=end;
	if(p==NULL){
			printf("NULL\n");
		} 
		while(p!=NULL){
		printf("%d %s\n",p->num,p->name);
		p=p->left;
	}
}
void print1(struct doublelist* head){
	struct doublelist*p=head;
	if(p==NULL){
			printf("NULL\n");
		} 
		while(p!=NULL){
		printf("%d %s\n",p->num,p->name);
		p=p->right;
	}
}
struct doublelist* find2(struct doublelist* end){
	struct doublelist*p1=end;
	struct doublelist*p2=NULL;
		while(p1!=NULL){
			p2=p1;
		p1=p1->left;
	}
	return (p2);
}
struct doublelist* find1(struct doublelist* head){
	struct doublelist*p1=head;
	struct doublelist*p2=NULL;
		while(p1!=NULL){
			p2=p1;
		p1=p1->right;
	}
	return (p2);
}
struct doublelist* creat(){
	struct doublelist* head=NULL;
	struct doublelist*p1,*p2=NULL;
	printf("�밴������������\n");
	p1=p2=(struct doublelist*)malloc(len);
	scanf("%d%s",&p1->num,&p1->name);
	while(p1->num!=0){
		n+=1;
		if(n==1){
			head=p1;
			p1->left=NULL;
		}
		else{
			p2->right=p1;
			p1->left=p2;
			p2=p1;
		}
		p1=(struct doublelist*)malloc(len);
		scanf("%d%s",&p1->num,&p1->name);	
	}
	p2->right=NULL;
	return (head);
}
int main(){
	struct doublelist* head=NULL;
	struct doublelist* end=NULL;
	head=creat();                                     //�������� 
	end=find1(head);                                  //����β�ڵ� 
	print1(head);                                     //�����������
    printf("\n");
	print2(end);                                      //������� 
	
	struct doublelist stu;
   
	printf("������ɾ���Ľڵ������\n");
	scanf("%d",&stu.num);
	head=del1(head,&stu);                           //����ɾ���ڵ� 
	end=find1(head);
	printf("\n");
	print1(head);                                  //������� 
	printf("\n");
	print2(end);                              

	printf("������ɾ���Ľڵ������\n");
	scanf("%d",&stu.num);
	end=del2(end,&stu);                           //����ɾ���ڵ�  
	head=find2(end);
	printf("\n");
	print1(head);                                //������� 
	printf("\n");
	print2(end);

	printf("���������Ľڵ������\n");
	scanf("%d%s",&stu.num,&stu.name);
	head=insert1(head,&stu);                     //�������ڵ�
	end=find1(head);
	printf("\n");
	print1(head);                                //�������
	printf("\n");
	print2(end);	          

	printf("���������Ľڵ������\n");
	scanf("%d%s",&stu.num,&stu.name);
	end=insert2(end,&stu);                       //�������ڵ�
    head=find2(end);
	printf("\n");
	print1(head);                                //�������
	printf("\n");
	print2(end);	                              
}

