#include <iostream>
#include <cassert>
using namespace std;
class Matrix
{
    private:
    int data[2][2];
    public:
    Matrix(int a=0,int b=0,int c=0,int d=0)
    {
        data[0][0]=a;
        data[0][1]=b;
        data[1][0]=c;
        data[1][1]=d;
    }

    Matrix operator+(const Matrix &m)
    {
        Matrix result;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                result.data[i][j]=data[i][j]+m.data[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix &m)
    {
        Matrix result;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                result.data[i][j]=0;
                for(int k=0;k<2;k++)
                {
                    result.data[i][j]+=data[i][k]*m.data[k][j];
                }
            }
        }
        return result;
    }
    int* operator[](int index)
    {
        return data[index];
    }
    friend ostream& operator<<(ostream &out,const Matrix &m)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                out<<m.data[i][j]<<" ";
            }
            out<<endl;
        }
        return out;
    }
};
int main()
{
    Matrix A(1,2,3,4);
    Matrix B(5,6,7,8);
    Matrix Sum=A+B;
    Matrix Product=A*B;
    assert(Sum[0][0]==6);
    assert(Sum[1][1]==12);
    assert(Product[0][0]==19);  
    assert(Product[0][1]==22);
    assert(Product[1][0]==43);
    assert(Product[1][1]==50);
    cout<<"Matrix A:"<<endl;
    cout<<A;
    cout<<"Matrix B:"<<endl;
    cout<<B;
    cout<<"Addition of Matrices:"<<endl;
    cout<<Sum;
    cout<<"Multiplication of Matrices:"<<endl;
    cout<<Product;
    cout<<"All unit tests passed successfully!"<<endl;
    return 0;
}