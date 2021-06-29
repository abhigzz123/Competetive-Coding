      //Abhigyan's Code:
             
      //You DON'T DARE TO COPY :) 

      #include<bits/stdc++.h>
      using namespace std;
      typedef long long int ll;
      typedef unsigned long long int ull;
      #define checker cout<<"CHECKED" 
      #define modulo 1000000007
      struct bst
      {
        int data ; 
        bst* left ;
        bst* right ;
      };

       int diameter(bst* root , int* height)
      {
        if(root == NULL)
        {
          *height = 0 ; 
          return 0 ;
        }
        int lh = 0 , rh = 0 , ld =0 , rd = 0 ;

        ld = diameter(root->left , &lh) ;

        rd = diameter(root->right , &rh) ;

        *height = max(lh ,rh) + 1 ;

        return max(  lh + rh +1  , max(ld, rd)) ;


      }

      void levelled(bst* root)
      {
        if(root == NULL)
          return ;

        queue<bst*> q ;

        q.push(root);

        while(!q.empty())
        {
          bst* curr = q.front();
          cout << curr->data<< " " ;

          if(curr ->left != NULL)
            q.push(curr->left) ;

          if(curr ->right != NULL)
            q.push(curr->right) ;

            q.pop() ;  

        }

      }

      bst* getnode(int x) 
      {
        bst* newnode = new bst() ;

        newnode->data = x ;

        newnode->left = NULL;

        newnode->right = NULL;

        return newnode ;

      }

      bst* insert(bst* root , int x)
      {
        if(root ==NULL)
          root = getnode( x );
        else if(root->data >=  x )
          root->left = insert(root->left , x );
        else
          root->right = insert( root->right, x);

        return root ;
      }

      bool search(bst* root, int x)
      {
        if(root == NULL)
          return false;

        else if(root->data == x)
          return true ;

        else if(x <= root->data)
          return search(root->left , x );
        else
          return search(root->right , x );

      }

      bool isbst(bst* root ,int low , int high)
      {
        if(root == NULL)
          return true ;
        else if(root->data > low  && root->data < high && isbst(root->left, low , root->data) && isbst(root->right , root->data , high))
        {
          return true ;
        }
        else 
          return false;

      }

       bst* lca(bst* root , int n1 , int n2)
      {
        if(root ==null)
        return NULL;

        else if(root-> data == n1 || root->data ==n2 )
        {
          return root ;
        } 
          bst* lefty =   lca(root->left , n1 , n2);

          bst* righty =  lca(root->right , n1 , n2);

          if(lefty && righty)
            return root ;

          return ( (lefty != NULL ) ? lefty : righty);

      }


      int ht(bst* root)
      {
        if(root == NULL)
          return 0;

        int lh = ht(root->left);

        int rh = ht(root->right);

        return (max(lh, rh) + 1) ; 

      }

      void verticalcreator(bst* root , int hd , map<int , vector<int>> &mp)
      {
        if(root ==NULL)
          return ;

        mp[hd].push_back(root->data);

        verticalcreator(root->left , hd-1 , mp) ;

        verticalcreator(root->right , hd+1 , mp) ;  

      }

      void topview(bst* root)
      {
        if(root ==NULL) 
          return ;
        else
        {
          unordered_map<int , int> mp ;

          queue<pair<bst* , int >> q ;

          queue.push(make_pair(root , 0)) ;

          while(!q.empty())
          {
            bst* val = q.front().first;

            int hd = q.front().second;

            q.pop() ;

            if(mp.find(hd) == mp.end())
            {
              mp[hd] = val->data ;
              cout << val->data <<" ";
            }

            if(val ->left != NULL)
              q.push(make_pair(val->left , hd-1)) ;

            if(val ->right != NULL)  
              q.push(make_pair(val->right, hd+1)) ;
          }
        }
      }

      void leftview(bst* root, int level , int* max_level)
      {
        if(root==NULL)
          return ;

        if(*max_level < level)
        {
          cout << root->data<<" " ;
          *max_level = level ;
        }

        leftview(root->left , level+1, max_level);
        leftview(root->right , level + 1, max_level); 

      }


      int main()
      {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("outfitt.txt","w",stdout);
        #endif

        bst* root =NULL;

        root= insert(root , 10 );
        root= insert(root , 20 );
        root= insert(root , 30 );
        root= insert(root , 25 );
        root= insert(root , 45 );
        root= insert(root , 15 );
        root= insert(root , 17 );

        
        

       
        return 0 ;
    }
