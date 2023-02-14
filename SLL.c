#include<stdio.h>
#include<stdlib.h>
 struct node
   {
      int info;
      struct node*link;
   };
 typedef struct node*NODE;
  
  NODE getnode()
  {
      NODE x;
      x=(NODE)malloc(sizeof(struct node));
      if(x==NULL)
       {
           printf("Memory is not being allocated");
           exit(0);
       }
       return x;
      
  }
  NODE insert_front(NODE first,int elem)
   {
       NODE temp;
       temp=getnode();
       temp->info=elem;
       temp->link=first;
       return temp;
      
   }
  NODE insert_rear(NODE first,int elem)
    {
        NODE cur,temp,prev;
        cur=first;
        prev=NULL;
        temp=getnode();
        temp->info=elem;
        temp->link=NULL;
        if(cur==NULL)
        return temp;
        while(cur!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=temp;
        return first;
    }
    void display(NODE first)
      {
          NODE cur=first;
          if(cur==NULL)
           {
               printf("SLL is empty\n");
           }
           printf("Display the elements of SLL\n");
           while(cur!=NULL)
           {
               printf("%d\t",cur->info);
               cur=cur->link;
           }
          
      }
      
      NODE delete_front(NODE first)
       {
           NODE next;
           next=first;
           if(next==NULL)
           {
               printf("NO node is present.\nDeletion is not possible.\n");
               return NULL;
           }
             
           int elem= next->info;
           printf("Deleting %d from SLL",elem);
           next=next->link;
           free(first);
           return next;
        }
      
      
     NODE delete_rear(NODE first)
       {
           NODE cur,prev;
           if(first==NULL)
           {
               printf("NO node is present.\nDeletion is not possible.\n");
           return NULL;
           }
           if(first->link==NULL)
           {
               int elem=first->info;
               printf("Deleting %d from SLL",elem);
               free(first);
               return NULL;
           }
         cur=first;
         prev=NULL;
         while(cur->link!=NULL)
         {
              prev=cur;
              cur=cur->link;
         }
        int  elem=cur->info;
         printf("Deleting %d from SLL",elem);
         free(cur);
         prev->link=NULL;
         return first;
       }
      
     
 int main()
  {
      NODE first=NULL;
      int choice,elem;
      while(1)
       {
          printf("\n1-To insert from front\n2-To insert from rear\n3-To delete from front\n4-To delete from rear\n5-display\n6-exit(0)\n");
          printf("Enter your choice:");
          scanf("%d",&choice);
        switch(choice)
           {
               case 1:printf("Give the element you want to enter at front:\n");
                      scanf("%d",&elem);
                      first=insert_front(first,elem);
                      break;
                case 2:printf("Give the element you want to enter at rear/back:\n");
                      scanf("%d",&elem);
                      first=insert_rear(first,elem);
                      break;
                case 3:first=delete_front(first);
                      break;
                case 4:first=delete_rear(first);
                      break;
                case 5:display(first);
                      break;
                default: exit(0);      
                
            }
        }
    }