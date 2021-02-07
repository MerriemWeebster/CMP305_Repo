
#include <iostream>
using namespace std;
template<class T>
class Matrix
        //wow this is really cool
{

private:
    T **arr;
    int rows;
    int cols;
public:
    Matrix(int r = 4, int c = 4): rows(r), cols(c)
    {
        arr= new T* [rows];
        for(int i;i<cols;i++) {
            arr[i] = new T[cols];
        }
    }
    Matrix(const Matrix &rhs)
    {
        rows=rhs.rows;
        cols=rhs.cols;
        arr= new T* [rows];
        for(int i;i<rows;i++) {
            arr[i] = new T[cols];
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                arr[i][j]=rhs.arr[i][j];
            }
        }
    }
    
    
    Matrix operator=(const Matrix &rhs)
    {
        rows=rhs.rows;
        cols=rhs.cols;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                arr[i][j]=rhs.arr[i][j];
            }
        }
    }
    bool operator == (const Matrix& rhs)
    {
        if(*this==rhs){
            return true;
        }
        if(rows!=rhs.rows || cols!=rhs.cols){
            return false;
        }
        bool equal=true;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(arr[i][j]!=rhs.arr[i][j]){
                    equal=false;
                    break;
                }
            }
        }
        return equal;
    }
    Matrix operator += (const Matrix& rhs)
    {
        for(int i=0;i<rows;i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] += rhs.arr[i][j];
            }
        }
    }
    
    Matrix operator -= (const Matrix& rhs)
    {
        for(int i=0;i<rows;i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] -= rhs.arr[i][j];
            }
        }
    }

    
    friend Matrix operator + (const Matrix& m1, const Matrix& m2)
    {
       
       
    }
    
    friend Matrix operator - (const Matrix& m1, const Matrix& m2)
    {
       
    }

    
    friend ostream& operator<<(ostream& outs, const Matrix& rhs)
    {
      
    }
   
    friend istream& operator>>(istream& ins, Matrix& rhs)
    {
       
      
    }

    
    T& operator () (const int r_index, const int c_index)
    {
       
    }
    
    const T& operator () (const int r_index, const int c_index) const
    {
        
    }
    Matrix& operator++(){       // Pre increment.
       
    }
    Matrix operator++(int)//post increment
    {
       
       
    }
    ~Matrix()
    {

        delete[] arr;
    }
    //Bonus
    
    
    
};

int main() {

    Matrix<int> a(2, 2), b(2, 2);
    cout << "Please enter the content of the first Matrix (A):\n";
    cin >> a;
    cout << "Please enter the content of the second Matrix (B):\n";
    cin >> b;
    cout << "Printing A and B using the << operator :\n";
    cout << "A \n" << a << "B \n" << b;
    cout << "\nTesting Copy Constructor Matrix d = a = :\n";
    Matrix<int> d = a;
    cout << d << endl;
    cout << "Testing = operator, Matrix E; E = B;\n";
    Matrix<int> e;
    e = b;
    cout << "E before changing the value of B :\n";
    cout << e << endl;


    //Testing addition “ + ” and subtraction “ - “ operators.
    //Testing addition assignment “ += ” and subtraction assignment “ - = ” operators.
    cout << "Testing D + A = :\n" << d + a;
    cout << "Testing D - A = :\n" << d - a;
    cout << endl;
    cout << "Testing E+=B = :\n";
    e += b;
    cout << e;
    cout << "Testing E-=B = :\n";
    e -= b;
    cout << e << endl;

    //Testing comparison operator “ = “
    cout << "Testing A == A = " << (a == a) << endl;
    cout << "Testing A == B = " << (a == b) << endl;

    //Testing operator ()
    cout << "Testing cout << A[index] \n";
    int index1, index2;
    cout << "Enter row index : ";
    cin >> index1;
    cout << "Enter column index : ";
    cin >> index2;
    cout << "A[" << index1 << "," << index2 << "] = " << a(index1, index2) << endl;
    cout << "Enter new value : ";
    int value;
    cin >> value;
    a(index1, index2) = value;
    cout << "A[" << index1 << "," << index2 << "] = " << a(index1, index2) << endl;
    cout << "New values of a : \n" << a;
    
    cout<<"Post increment A:"<<endl<<a++<<endl;
    cout<<"Pre increment A:"<<endl<<++a<<endl;
   
    //Ex2 Bonus
    
    
    return 0;
}



