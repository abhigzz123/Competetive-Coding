      //Abhigyan's Code:
             
      //You DON'T DARE TO COPY :) 

      #include<bits/stdc++.h>
      using namespace std;
      typedef long long int ll;
      typedef unsigned long long int ull;
      #define checker cout<<"CHECKED" 
      #define modulo 1000000007

      struct node
      {
        int data ; 
        node* next ;

      };

      bool detectcycle(node** head)
      {
        if(*head == NULL)
          return false;

        node* slow = *head ;
        node* fast = *head ; 

       while(slow && fast && fast->next)
       {
        slow = slow->next ; 
        fast = fast->next->next ;

        if(slow == fast )
          return true ;
       }
        return false;   
      }

      void deleteatend(node** head)
      {

       if(*head == NULL)
       return ;

       else
       {
          node* temp = *head ;

          while(temp ->next ->next != NULL)
            temp = temp->next ;

          delete temp->next ; 

          temp->next = NULL;
       }
      }
      
      

      void insertatend(node** head , int x)
      {
        node* newnode = new node() ;
        newnode->data = x ;
         newnode->next = NULL;

         node* temp = *head ; 

        if(*head ==NULL)
        {
          *head = newnode ; 
        }
        else
        {
          while((temp)->next !=NULL)
            temp = (temp)->next ;

          (temp)->next = newnode ;
        }

      }


      void printer(node** head)
      {
        if(*head == NULL)
          return ;
        else
        {
          node* temp = *head ; 

          while(temp != NULL)
          {
            cout<<temp->data<<" "; 
            temp = temp->next ;
          }
        }
        cout << endl;
      }

       int main()
       {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("dekho.txt","w",stdout);
        #endif

        node* head = NULL;

        insertatend(&head , 10 );
        insertatend(&head , 20 );
        insertatend(&head , 30 );
        insertatend(&head , 40 );
        insertatend(&head , 50 );

        printer(&head) ;


        printer(&head) ;
       
            return 0 ;
        }
