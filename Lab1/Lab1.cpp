
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
        arr= new T* [r];
        for(int i=0;i<r;i++) {
            arr[i] = new T[c];
        }
    }
    Matrix(const Matrix &rhs)
    {
        rows=rhs.rows;
        cols=rhs.cols;
        arr= new T* [rows];
        for(int i=0;i<rows;i++) {
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
        if(rows != rhs.rows || cols != rhs.cols){
            for(int i = 0; i < rows; i++){
                delete[] arr[i];
            }
            delete[] arr;

            arr= new T* [rhs.rows];
            for(int i=0;i<rhs.rows;i++) {
                arr[i] = new T[rhs.cols];
            }
        }
        rows=rhs.rows;
        cols=rhs.cols;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                arr[i][j]=rhs.arr[i][j];
            }
        }
        return *this;
    }
    bool operator == (const Matrix& rhs)
    {
        if(rows!=rhs.rows || cols!=rhs.cols){
            return false;
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(arr[i][j]!=rhs.arr[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    Matrix operator += (const Matrix& rhs)
    {
        for(int i=0;i<rows;i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] += rhs.arr[i][j];
            }
        }
        return *this;
    }

    Matrix operator -= (const Matrix& rhs)
    {
        for(int i=0;i<rows;i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] -= rhs.arr[i][j];
            }
        }
        return *this;
    }


    friend Matrix operator + (const Matrix& m1, const Matrix& m2)
    {
        Matrix ans(m1.rows,m2.cols);
        for(int i=0;i<m1.rows;i++){
            for(int j=0;j<m1.cols;j++){
                ans.arr[i][j]=m1.arr[i][j]+m2.arr[i][j];
            }
        }
        return ans;
    }

    friend Matrix operator - (const Matrix& m1, const Matrix& m2)
    {
        Matrix ans(m1.rows,m2.cols);
        for(int i=0;i<m1.rows;i++){
            for(int j=0;j<m1.cols;j++){
                ans.arr[i][j]=m1.arr[i][j]-m2.arr[i][j];
            }
        }
        return ans;
    }


    friend ostream& operator<<(ostream& outs, const Matrix& rhs){
        for(int i=0;i<rhs.rows;i++){
            for(int j=0;j<rhs.cols;j++){
                outs<<rhs.arr[i][j]<<" ";
            }
            outs<<endl;
        }
        return outs;
    }

    friend istream& operator>>(istream& ins, Matrix& rhs)
    {

        for(int i=0;i<rhs.rows;i++){
            for(int j=0;j<rhs.cols;j++){
                ins>>rhs.arr[i][j];
            }
        }
        return ins;
    }


    T& operator () (const int r_index, const int c_index)
    {
        if(r_index < 0 || r_index >= rows)
        {
            cout << "Row Index out of bounds";
            exit(2);
        }

        if(c_index < 0 || c_index >= cols)
        {
            cout << "Col Index out of bounds";
            exit(3);
        }

        return arr[r_index][c_index];
    }

    const T& operator () (const int r_index, const int c_index) const
    {
        if(r_index < 0 || r_index >= rows)
        {
            cout << "Row Index out of bounds";
            exit(4);
        }

        if(c_index < 0 || c_index >= cols)
        {
            cout << "Col Index out of bounds";
            exit(5);
        }

        return arr[r_index][c_index];
    }

    Matrix& operator++()
    {       // Pre increment.
        for (int i = 0; i < rows; i++) // To Loop Through The Rows
        {
            for (int j = 0; j < cols; j++) // To Loop Through The Columns
            {
                ++arr[i][j]; // Increment The Element
            }
        }

        return *this; // We Return The Address As The Function Is Cascading
    }
    Matrix operator++(int)//post increment
    {
        Matrix<T> temp = *this;

        for(int i = 0; i < temp.rows; i++)
        {
            for(int j = 0; j < temp.cols; j++)
            {
                temp.arr[i][j]++;
            }
        }

        return temp;
    }

    ~Matrix()
    {
        for(int i = 0; i < rows; i++)
        {
            delete arr[i];
        }

        delete[] arr;
    }
    //Bonus

    int getRows(){
        return rows;
    }
    int getCols(){
        return cols;
    }


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

    Matrix <int> A(3,2),B(3,2);
    cout<<"Enter A:"<<endl;
    cin>>A;
    cout<<"Enter B:"<<endl;
    cin>>B;
    Matrix<int> Sum=(A+B);
    cout<<"A+B="<<endl;
    cout<<Sum<<endl;

    Matrix<int> C(3,2);
    cout<<"Enter C:"<<endl;
    cin>>C;
    cout<<"The Third year's details are:"<<endl;
    cout<<C-Sum<<endl;

    float total=0;
    for(int i=0;i<C.getRows();i++){
        for(int j=0;j<C.getCols();j++){
            total+=C(i,j);
        }
    }
    cout<<"The average number of wins are: ";
    int winSum=0;
    for(int j=0;j<C.getRows();j++){
        winSum+=C(j,0);
    }
    cout<<(winSum/total);
    cout<<"\nThe average number of losses are:";
    int lossSum=0;
    for(int j=0;j<C.getRows();j++){
        lossSum+=C(j,1);
    }
    cout<<(lossSum/total);
    return 0;
}