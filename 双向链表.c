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
		 struct doublelist* p1=end;           //指向尾节点（左头右尾） 
		 if(end==NULL){                       //若空链表 
		 	end=stu;
		 	stu->right=NULL;
		 	stu->left=NULL;
		 }
		 else{                                  //非空链表 
		 	while(stu->num < p1->num&&p1->left!=NULL){
				p1=p1->left;
			 }
			 if(stu->num > p1->num){             //找到位置插入节点 
			 	if(p1==end){                  //成为尾节点（>尾节点的值） （左头右尾）
			 		end=stu;
					stu->left=p1;
					p1->right=stu;
					stu->right=NULL;
				 }
				 else{                         //插入中间某个节点 
				 	p1->right->left=stu;
				 	stu->right=p1->right;
				 	stu->left=p1;
				 	p1->right=stu;
				 }
			 }
			 else{                             //未找到位置成为头节点 （左头右尾）
			    p1->left=stu;
			    stu->right=p1;
			   	stu->left=NULL;
			 }
		 }
//		 n+=1;
		 return (end);
}
struct doublelist* insert1(struct doublelist* head,struct doublelist* stu){
		 struct doublelist* p1=head;            //指向头节点（左头右尾）
		 if(head==NULL){                       //若空链表 
		 	head=stu;
		 	stu->right=NULL;
		 	stu->left=NULL;
		 }
		 else{                                  //非空链表 
		 	while(stu->num > p1->num&&p1->right!=NULL){
				p1=p1->right;
			 }
			 if(stu->num < p1->num){             //找到位置插入节点 
			 	if(p1==head){                  //成为头节点（<1节点的值） （左头右尾）
			 		head=stu;
			 		stu->left=NULL;
			 		stu->right=p1;
			 		p1->left=stu;
				 }
				 else{                         //插入中间某个节点 
				 	p1->left->right=stu;
					stu->left=p1->left;
					stu->right=p1;
					p1->left=stu;
				 }
			 }
			 else{                             //未找到位置成为尾节点 （左头右尾）
			 	p1->right=stu;
			 	stu->left=p1;
			 	stu->right=NULL;
			 }
		 }
//		 n+=1;
		 return (head);
}
struct doublelist* del2(struct doublelist* end,struct doublelist* stu){
	struct doublelist* p1=end;                                  //指向尾节点（左头右尾）
	if(end==NULL){                                              //空链表无法删除 
		printf("list null\n");
		return (end);
	}
	else{
		while(stu->num!=p1->num&&p1->left!=NULL){		
			p1=p1->left;                                       //使p1指向被删除节点 
		}
		if(stu->num==p1->num){
			if(p1==end&&p1->left!=NULL){                      //删除尾结点 （左头右尾）
				printf("delete:%d %s\n",p1->num,p1->name);
				end=p1->left;
				p1->left->right=NULL;
				p1->right=NULL;
				p1->left=NULL;
			}
			else if(p1==end&&p1->left==NULL){                 //删除仅一个结点的链表的尾结点 （左头右尾）
				printf("delete:%d %s\n",p1->num,p1->name);
				end=p1->left;
				p1->right=NULL;
				p1->left=NULL;
			}
			else if(p1!=end&&p1->left!=NULL){                //删除中间结点                                
				printf("delete:%d %s\n",p1->num,p1->name);                 
				p1->right->left=p1->left;
			    p1->left->right=p1->right;
			    p1->right=NULL;
			    p1->left=NULL; 
			}
			else {                                           //删除头结点（左头右尾）
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
	struct doublelist* p1=head;                                 //指向头节点（左头右尾）
	if(head==NULL){                                             //空链表无法删除 
		printf("list null");
		return (head);
	}
	else{
		while(stu->num!=p1->num&&p1->right!=NULL){                           
			p1=p1->right;                                      //使p1指向被删除节点 
		}
		if(stu->num==p1->num){
			if(p1==head&&p1->right!=NULL){                     //删除头结点 （左头右尾）
				printf("delete:%d %s\n",p1->num,p1->name);
				head=p1->right;
				p1->right->left=NULL;
				p1->right=NULL;
				p1->left=NULL;
			}
			else if(p1==head&&p1->right==NULL){                //删除仅一个结点的链表的头结点 （左头右尾）
				head=p1->right;
				p1->right=NULL;
				p1->left=NULL;
			}
			else if(p1!=head&&p1->right!=NULL){                //删除中间结点                                             
				printf("delete:%d %s\n",p1->num,p1->name);	
				p1->left->right=p1->right;
				p1->right->left=p1->left;
				p1->left=NULL;
			    p1->right=NULL;
			}
			else {                                             //删除尾结点 （左头右尾）
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
	printf("请按升序输入数据\n");
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
	head=creat();                                     //创建链表 
	end=find1(head);                                  //定义尾节点 
	print1(head);                                     //正向输出链表
    printf("\n");
	print2(end);                                      //反向输出 
	
	struct doublelist stu;
   
	printf("请输入删除的节点的数据\n");
	scanf("%d",&stu.num);
	head=del1(head,&stu);                           //正向删除节点 
	end=find1(head);
	printf("\n");
	print1(head);                                  //输出链表 
	printf("\n");
	print2(end);                              

	printf("请输入删除的节点的数据\n");
	scanf("%d",&stu.num);
	end=del2(end,&stu);                           //反向删除节点  
	head=find2(end);
	printf("\n");
	print1(head);                                //输出链表 
	printf("\n");
	print2(end);

	printf("请输入插入的节点的数据\n");
	scanf("%d%s",&stu.num,&stu.name);
	head=insert1(head,&stu);                     //正向插入节点
	end=find1(head);
	printf("\n");
	print1(head);                                //输出链表
	printf("\n");
	print2(end);	          

	printf("请输入插入的节点的数据\n");
	scanf("%d%s",&stu.num,&stu.name);
	end=insert2(end,&stu);                       //反向插入节点
    head=find2(end);
	printf("\n");
	print1(head);                                //输出链表
	printf("\n");
	print2(end);	                              
}

