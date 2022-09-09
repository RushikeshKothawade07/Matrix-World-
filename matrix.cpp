/*************************************************************************
                            --------------------
Represent matrix using two dimensional arrays and perform following operations
i. Addition
ii .multiplication
iii. Transpose
iv. Saddle point
v. Lower and Upper triangular Matrix

*******************************************************************************/
#include <iostream>

using namespace std;

class Matrix{
    private:
        int m,n,p,q;
        int A[10][10],B[10][10],ans[10][10]; 
    public:
        void create1();
        void create2();

        void display1();
        void display2();
        
        void addition();
        void subtract();
        void multiply();
        void transpose();
        void saddle();
        void upperTri();
        void lowerTri();
};

void Matrix::create1()
{
    cout<<"Enter size of matrix1 : ";
    cin>>m>>n;
    cout<<"Enter "<<m<<"x"<<n<<" matrix A : "<<endl; 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
}
void Matrix::create2()
{
    cout<<"Enter size of matrix2 : ";
    cin>>p>>q;
    cout<<"Enter "<<p<<"x"<<q<<" matrix B : "<<endl; 
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            cin>>B[i][j];
        }
    }
}


void Matrix:: display1()
{
    cout<<"Matrix A is : \n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void Matrix:: display2()
{
    cout<<"Matrix B is : \n";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            cout<<B[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void Matrix :: addition()
{ 
    create1();
    create2();
    display1();
    display2();
    if(m==p && n==q)
    {
        cout<<"Addition Matrix is : \n";
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<p;j++)
            {
                ans[i][j]=A[i][j]+B[i][j];
                cout << ans[i][j] << "\t";
    		}
    		cout << endl;
        }
    }
    else
        cout<<"Matrix A and Matrix B cannot be added !"<<endl;
}
void Matrix :: subtract()
{ 
    create1();
    create2();
    display1();
    display2();
    if(m==p && n==q)
    {
        cout<<"Subtraction  Matrix is : \n";
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<p;j++)
            {
                ans[i][j]=A[i][j]-B[i][j];
                cout << ans[i][j] << "\t";
    		}
    		cout << endl;
        }
    }
    else
        cout<<"Matrix A and Matrix B cannot be subtracted !"<<endl;
}

void Matrix :: multiply()
{ 
    create1();
    create2();
    display1();
    display2();
    if(n==p)
    {
        cout<<"Multiplication  Matrix is : \n";
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<q;j++)
            {
                ans[i][j]=0;
                for(int k=0;k<p;k++)
                {
                    ans[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        //matrix dimensions will be mxq
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<q;j++)
            {
                cout<<ans[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    else
        cout<<"Matrix A and Matrix B cannnot be multiplied !"<<endl;
}

void Matrix :: transpose()
{
    create1();
    display1();
    cout<<"\nTranspose matrix is : "<<endl;
    int temp;
    for(int i=0;i<m;i++)
    {
        for(int j=i;j<n;j++)
        {
            // swap
            temp=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=temp;
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
    
}

void Matrix :: saddle()
{
    create1();
    display1(); 
    
    //saddle pt 
    int flag=0,i=0,j=0,k=0,c=0,max=0,min=0;
    for(i=0;i<m;i++)
    {
        min=A[i][0];
        c=0;
        for(j=0;j<n;j++)
        {
            if(A[i][j]<min)
            {
                min=A[i][j];
                c=j;
            }
        }
        max=A[0][c];
        for(k=0;k<n;k++)
        {
            if(A[k][c]>max)
            {
                max=A[k][c];
            }
        }
        
        if(min==max)
        {
            cout<<"\nSaddle point of matrix is "<<max<<endl;
            flag=1;
            return;
        }
    }
    cout<<"\nSaddle element not found !"<<endl;
}

void Matrix :: upperTri()
{
    create1();
    display1();
    int flag=0;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i>j) && A[i][j]==0)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
        cout<<"\nIt is an upper triangular matrix !"<<endl;
    else
        cout<<"\nNot an upper triangular matrix !"<<endl;
    
}

void Matrix :: lowerTri()
{
    create1();
    display1();
    int flag=0;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i<j) && A[i][j]==0)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
        cout<<"\nIt is a lower triangular matrix !"<<endl;
    else
        cout<<"\nNot a lower triangular matrix !"<<endl;
    
}
int main()
{
    Matrix m;
    int ch;
    cout<<"\n                          Welcome to the ----MATRIX WORLD !----                          "<<endl;
    cout<<"____________________________________________________________________________________________"<<endl;
    cout<<endl;
    
do
{
    cout<<endl;
    cout<<"////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
    cout<<"\n\nWhich operation would you like to perform ??"<<endl;
    cout<<"\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Saddle Point\n6. Is Matrix upper triangular?\n7. Is Matrix lower triangular?"<<endl;
    cout<<"Enter choice : [1-7] and '0' to Exit  "<<endl;
    cin>>ch;
    if(ch==0)
        return 0;
    
    switch(ch)
    {
        case 1: 
            cout<<"You selected Addition!"<<endl;
            m.addition();
            break;
        case 2: 
            cout<<"You selected Subtraction!"<<endl;
            m.subtract();
            break;
        case 3: 
            cout<<"You selected Multiplication!"<<endl;
            m.multiply();
            break;
        case 4: 
            cout<<"You selected transpose!"<<endl;
            m.transpose();
            break;
        case 5: 
            cout<<"You selected to find saddle point!"<<endl;
            m.saddle();
            break;
        case 6: 
            cout<<"You selected to check if matrix is upper triangular!"<<endl;
            m.upperTri();
            break;
        case 7: 
            cout<<"You selected to check if matrix is lower triangular!"<<endl;
            m.lowerTri();
            break;
        default:
            cout<<"Invalid Choice !!"<<endl;
            break;
    }
}while(1);
   
    return 0;
}






