#include"matrix.h"
#include"iostream"

#define LEN 7
void A_Fill(int **array,int size);
void B_fill(int **array, int size);

int main (int argv, char **argc){
    matrix A(LEN,A_Fill);
    matrix B(LEN,B_fill);
    matrix E(LEN,matrix::IdentityFunc);
    matrix C(LEN);
    std::cout<<"A:"<<A;
    std::cout<<"B:"<<B;
    C=A+B;
    std::cout<<"A+B:"<<C;
    C=A*(-7)+B*4;
    std::cout<<"-7A+4B:"<<C;
    C=(A*B);
    std::cout<<"A*B:"<<C;
    C=(B*4-E*3);C*=C;C-=(A*A)*2;
    std::cout<<"(4B-3E)^2-2E^2:"<<C;
    std::cout<<"\ndet(B):"<<(B).getDet()<<"\n";
    std::cout<<"\ndet(BA-E):"<<(B*A-E).getDet()<<"\n";
    return 0;
}
void A_Fill(int** array,int size){
     for(int i=0;i<size;++i){
         for(int j=0;j<size;++j){
             array[i][j]=i+j;
         }
     }
 }
 void B_fill(int **array, int size){
     int tmp=0;
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            array[i][j]=tmp%5;
            tmp++;
        }
    }

 }
