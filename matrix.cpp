#include"matrix.h"
#include<iostream>


matrix matrix::getIdentity(int size){
    matrix tmp(size,IdentityFunc);
    return tmp;
}

void matrix::IdentityFunc(int **arr, int size){
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            if(i!=j){
                arr[i][j]=0;
            }else{
                arr[i][j]=1;
            }
        }
    }
}

matrix::matrix(int size,func funFill){
    this->size=size;
    FillMatrix=funFill;
    this->array=new int*[this->size];
    for(int i=0;i<this->size;++i){
        array[i]=new int[this->size];
    }
    FillMatrix(array, this->size);
}

matrix::matrix(int size){
    this->size=size;
    this->array=new int*[this->size];
    for(int i=0;i<this->size;++i){
        array[i]=new int[this->size];
    }
}

//private constructor
matrix::matrix(const matrix& matr){
    this->size=matr.size;
    this->array=new int*[this->size];
    for(int i=0;i<this->size;++i){
        array[i]=new int[this->size];
    }
    for(int i=0;i<this->size;++i){
        for(int j=0;j<this->size;++j){
            this->array[i][j]=matr.array[i][j];
        }
    }
}


matrix::~matrix(){
    for(int i=0;i<this->size;++i){
        delete[] this->array[i];
    }
    delete[] this->array;
}

void matrix::print(){
    for(int i=0;i<this->size;++i){
        std::cout<<"\n[ ";
        for(int j=0;j<this->size;++j){
            std::cerr<<this->array[i][j];
            if(j!=this->size-1){
                std::cout<<", ";
            }
        }
        std::cout<<" ]";
    }
    std::cout<<"\n";
}

int matrix::getSize(){
    return this->size;
}

double matrix::getDet(){
    double tmp[this->getSize()][this->getSize()];
    int sign;
    double det=1;
    for(int i=0;i<this->getSize();++i){
        for(int j=0;j<this->getSize();++j){
            tmp[i][j]=this->array[i][j];
            }
    }
    sign=1;
    for(int i=0;i<this->getSize();++i){
        if (tmp[i][i]==0){
            bool flag=false;
            for(int j=i+1;j<this->getSize();++j){
                if(tmp[i][j]==0){
                    return 0;
                }else{
                    for(int k=0;k<this->getSize();++k){
                        double temp=tmp[i][k];
                        tmp[i][k]=tmp[j][k];
                        tmp[j][k]=temp;
                    }
                    sign*=-1;
                    flag=true;
                    break;
                }
                if(!flag){
                    return 0;
                }
            }
        }
        for(int j=i+1;j<this->getSize();++j){
            for(int k=this->getSize()-1;k>=0;--k){
                tmp[j][k]=tmp[j][k]-tmp[i][k]*tmp[j][i]/tmp[i][i];
            }
        }
    }
    for(int i=0;i<this->getSize();++i){
        det*=tmp[i][i];
    }
    return det*sign;

}

matrix matrix::operator*( int val){
    matrix tmp(this->getSize());
    for(int i=0;i<tmp.getSize();++i){
        for(int j=0;j<tmp.getSize();++j){
            tmp.array[i][j]=this->array[i][j]*val;
        }
    }
    return tmp;
}


matrix matrix::operator=( const matrix& matr){
    if(this->getSize()==matr.size){
        for(int i=0;i<this->size;++i){
             for(int j=0;j<this->size;++j){
                 this->array[i][j]=matr.array[i][j];
             }
        }
    }
    return *this;
}

matrix matrix::operator +(const matrix& matr){
    matrix tmp(this->size);
    if(this->getSize()==matr.size){
         for(int i=0;i<this->size;++i){
             for(int j=0;j<this->size;++j){
                 tmp.array[i][j]=this->array[i][j]+matr.array[i][j];
             }
         }
    }
    return tmp;
}

matrix matrix::operator -(const matrix& matr){
    matrix tmp(this->size);
    if(this->getSize()==matr.size){
        for(int i=0;i<this->size;++i){
            for(int j=0;j<this->size;++j){
                tmp.array[i][j]=this->array[i][j]-matr.array[i][j];
            }
        }
    }
    return tmp;
}

void matrix::operator +=(const matrix& matr){
    if(this->getSize()==matr.size){
        for(int i=0;i<this->size;++i){ 
            for(int j=0;j<this->size;++j){
                this->array[i][j]+=matr.array[i][j];
            }
        }
    }
}

void matrix::operator -=(const matrix& matr){
     if(this->getSize()==matr.size){
         for(int i=0;i<this->size;++i){
             for(int j=0;j<this->size;++j){
                this->array[i][j]-=matr.array[i][j];
             }
         }
     }
}

matrix matrix::operator*(const matrix& matr){
    matrix tmp(this->size);
    if(this->getSize()==matr.size){
        for(int i=0;i<this->size;++i){
            for(int j=0;j<this->size;++j){
                tmp.array[i][j]=0;
                for(int k=0;k<this->size;++k){
                    tmp.array[i][j]+=this->array[i][k]*matr.array[k][j];
                }
            }
        }
    }
    return tmp;
}

 void matrix::operator*=(const matrix& matr){
    *this=*this * matr;
 }

 void matrix::operator*=(const int val){
     *this=*this*val;
 }

std::ostream& operator<<(std::ostream& ostr, matrix& matr){
    for(int i=0;i<matr.getSize();++i){
        ostr<<"\n[ ";
        for(int j=0;j<matr.getSize();++j){
            ostr<<matr.array[i][j];
            if(j!=matr.getSize()-1){
                ostr<<", ";
            }
        }
        ostr<<" ]";
    }
    ostr<<"\n";
    return ostr;
}
