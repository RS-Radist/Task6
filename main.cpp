
#include <iostream>

#define TEST(testRet, testName) std::cout << testName; \
    testRet ? std::cout << "SUCCESS \t" : std::cout << "FAILED \t"

/*
 + - * /  Арифметические
 < > == <= >= != Логические 
 && || Булевые
 [] оператор индексации
 = оператор присваивания
 
 ++ -- унарные
 постфиксные obj++ obj--
 префиксные ++obj --obj
 
 += -= /= *=
 
 int double DynamicArray - операторы преобразования типов
 
 new delete new[] delete[] - операторы выделения динамической памяти
 
 */

class DynamicArray
{
private:
    size_t size;   // размер массива динам. памяти
    size_t current_idx; // реальный размер массива
    int* ar; // массив
public:
    DynamicArray(size_t size=0);
    DynamicArray(const DynamicArray& obj); // To Do / Конструктор копирования
    DynamicArray& operator=(const DynamicArray& obj); // Оператор копирования
    int Get (size_t index);
    void Push (int a);
    size_t GetSize() const;
    size_t GetCapacity() const;
    
    
    
    friend DynamicArray operator+(const DynamicArray& l, const DynamicArray& r);//+
    friend DynamicArray operator+(const DynamicArray& l, int x);//+
    friend DynamicArray operator-(const DynamicArray& l,const DynamicArray& r);//+
    friend DynamicArray operator-(const DynamicArray& l,int x);//+
    friend DynamicArray operator*(const DynamicArray& l,int x);//+
    friend DynamicArray operator*(const DynamicArray& l,const DynamicArray& r);//+
    friend DynamicArray operator/(const DynamicArray& l,int x);//+
    friend DynamicArray operator/(const DynamicArray& l,const DynamicArray& r);//+
    friend bool operator==(const DynamicArray& l,const DynamicArray& r);//+  ??
    int& operator[](int idx); // one[0] = 12;   ??
    const int& operator[](int idx) const;     //??
    DynamicArray& operator++(); // Prefix +
    DynamicArray& operator--(); // Prefix +
    DynamicArray operator++(int); // Postfix +
    DynamicArray operator--(int); // Postfix +
    /*
    DynamicArray* operator new[](size_t size);
    void operator delete[](void* ptr);
    */
    
    
    //no Friend
    DynamicArray& operator+=(int x);//+
    DynamicArray& operator-=(int x);//+
    DynamicArray& operator/=(int x);//+
    DynamicArray& operator*=(int x);//+
    DynamicArray& operator+=(const DynamicArray& x);
    DynamicArray& operator-=(const DynamicArray& x);//+
    DynamicArray& operator/=(const DynamicArray& x);//+
    DynamicArray& operator*=(const DynamicArray& x);//+
    int * GetR()
    {
        return ar;
    }
};


void RandomArray(DynamicArray &x, size_t size)
{
    for (int i =0 ; i<size;++i)
    {
        x.Push(arc4random()%9+1);
    }
}
void ShowArray(DynamicArray &x)
{
    for (int i =0 ; i<x.GetSize();++i)
    {
        std::cout<<x.Get(i) << " " ;
    }
    std::cout << "\n";
}
bool IsArraysEqual(DynamicArray one, DynamicArray two)
{
    if(one.GetSize() != two.GetSize())
        return false;
    
    for (int i =0; i<one.GetSize(); ++i)
    {
        if(one[i]!=two[i]) // one.operator[](i)
            return false;
    }
    return true;
}

//TEST

bool TestPlusFunction (DynamicArray one,DynamicArray two,DynamicArray exp) // +
{
    DynamicArray ret=one+two;
    return IsArraysEqual (ret,exp);
    
}
bool TestPlus_X_Function (DynamicArray one,int x,DynamicArray exp) // +
{
    DynamicArray ret=one+x;
    return IsArraysEqual (ret,exp);
}
bool TestPlus_X_Equal_Function (DynamicArray one,int x,DynamicArray exp)  // -
{
    
    one+=x;
    return IsArraysEqual (one,exp);
}
bool TestPlus_X_Equal_Mas_Function (DynamicArray one,DynamicArray two,DynamicArray exp) // -
{
    one+=two;
    DynamicArray ret=one;
    return IsArraysEqual (ret,exp);
}


bool TestMinusFunction (DynamicArray one,DynamicArray two,DynamicArray exp) // -
{
    DynamicArray ret=one-two;
    return (ret == exp) ? true : false;
}
bool TestMinus_X_Function (DynamicArray one,int x,DynamicArray exp)   // -
{
    DynamicArray ret=one-x;
    return (ret == exp) ? true : false;
}
bool TestMinus_X_Equal_Function (DynamicArray one,int x,DynamicArray exp) // -
{
    one-=x;
    DynamicArray ret=one;
    return IsArraysEqual (ret,exp);
}
bool TestMinus_X_Equal_Mas_Function (DynamicArray one,DynamicArray two,DynamicArray exp)
{
    one-=two;
    DynamicArray ret=one;
    return IsArraysEqual (ret,exp);
}



bool TestMultFunction (DynamicArray one,DynamicArray two,DynamicArray exp)
{
    DynamicArray ret=one * two;
    return (ret == exp) ? true : false;
}
bool TestMult_X_Function (DynamicArray one,int x,DynamicArray exp)
{
    DynamicArray ret=one * x;
    return (ret == exp) ? true : false;
}
bool TestMult_X_Eual_Function (DynamicArray one,int x,DynamicArray exp)
{
    one *= x;
    return (one == exp) ? true : false;
}
bool TestMult_X_Equal_Mas_Function (DynamicArray one,DynamicArray two,DynamicArray exp)
{
    one*=two;
    return (one == exp) ? true : false;
}



bool TestDivFunction (DynamicArray one,DynamicArray two,DynamicArray exp)
{
    DynamicArray ret=one / two;
    return (ret == exp) ? true : false;
}
bool TestDiv_X_Function (DynamicArray one,int x,DynamicArray exp)
{
    DynamicArray ret=one / x;
    return (ret == exp) ? true : false;
}
bool TestDiv_X_Eual_Function (DynamicArray one,int x,DynamicArray exp)
{
    one /= x;
    return (one == exp) ? true : false;
}
bool TestDiv_X_Eual_Mas_Function (DynamicArray one,DynamicArray two,DynamicArray exp)
{
    one /= two;
    return (one == exp) ? true : false;
}








        
int main()
{
    /*
    int ar1[3] = {2, 4, 7};
    int ar2[5] = {5, 8, 3, 2, 9};
    
    // ar1 - ar2
    
    int ret[3] = {0};
    
    int k = 0;
    for(int i = 0; i < 3; ++i)
    {
        int j = 0;
        for(; j < 5; ++j)
        {
            if(ar1[i] == ar2[j])
            {
                break;
            }
        }
        if( j == 5 )
        {
            ret[k++] = ar1[i];
        }
    }
    */
    /*
    DynamicArray a1(5);                     // Первый массив
    RandomArray(a1, 5);                     // Случайные цыфры первого массива
    ShowArray(a1);                          // Вывод массива на экран
    DynamicArray a2(2);                     // Второй массив
    RandomArray(a2, 2);                     // Случайные цыфры второго массива
    ShowArray(a2);                          // Вывод второго массива на экран
    DynamicArray z=a1+a2;                   // Создание массива массива при сумировании 1 и 2
    TEST(TestPlusFunction(a1,a2,z), "Test PLUS + ");// Функция для проверки массива.
    ShowArray(z);                           // Вывод третьего массива на экран
    
    std::cout<<"\n";
    std::cout<<"Test Minus\n";
    DynamicArray TestMinus(5);
    RandomArray(TestMinus, 5);
    ShowArray(TestMinus);
    
    DynamicArray TestMinus1(3);
    RandomArray(TestMinus1, 2);
    ShowArray(TestMinus1);
    DynamicArray SumTestminus = TestMinus - TestMinus1;
    TEST(TestMinusFunction(TestMinus,TestMinus1,SumTestminus), "Test MINUS - ");
    ShowArray(SumTestminus);
    std::cout<<"\n";
    ////////////////////////////
    std::cout<<"Test Mult * 2\n";
    DynamicArray TestMultX2(3);
    RandomArray(TestMultX2, 3);
    ShowArray(TestMultX2);
    DynamicArray SumArrayX2=TestMultX2*2;
    TEST(TestMultFunction(TestMultX2,SumArrayX2),"Test Multiplication * ");
    ShowArray(SumArrayX2);
    std::cout<<"\n";
    std::cout<<"Test Div / 2\n";
    DynamicArray TestDivX2(3);
    RandomArray(TestDivX2, 3);
    ShowArray(TestDivX2);
    DynamicArray SumArrayDiv=TestDivX2/2;
    TEST (TestDivFunction (TestDivX2,SumArrayDiv),"Test Division / ");
    ShowArray(SumArrayDiv);
    std::cout<<"\n";
    std::cout<<"Test EUAL ==\n";
    DynamicArray TesEqual(3);
    RandomArray(TesEqual, 3);
    ShowArray(TesEqual);
    DynamicArray TesEqual2(3);
    RandomArray(TesEqual2, 3);
    ShowArray(TesEqual2);
    DynamicArray SumArrayEual;
    TEST (IsArraysEqual(TesEqual,SumArrayEual),"Test Euqal == ");
    ShowArray(SumArrayEual);
     */
    // Реализация коструктора копировния.
    /*
    DynamicArray Mas(5);
    RandomArray(Mas,5);
    ShowArray(Mas);
    std::cout<<std::endl;
    DynamicArray Mas1(5);
    RandomArray(Mas1,5);
    ShowArray(Mas1);
    // Оператор копирования
    DynamicArray  CopyMas(Mas1);
    ShowArray(CopyMas);
    CopyMas.~DynamicArray();
    ShowArray(Mas1);
    
    CopyMas=Mas; // copyMas.operator=(Mas)
    ShowArray(Mas);
    Mas+=5;
    ShowArray(Mas);
    Mas-=2;
    ShowArray(Mas);
     */
    /*
    DynamicArray Mas(5);
    RandomArray(Mas, 5);
    ShowArray(Mas);
    std::cout<<std::endl;
    DynamicArray Mas1(5);
    RandomArray(Mas1, 5);
    Mas*=2;
    ShowArray(Mas);
     */
    /*
    //    Проверка Методов
    DynamicArray Mas(5);
    RandomArray(Mas,5);
    ShowArray(Mas);
    std::cout<<std::endl;
    DynamicArray Mas1(5);
    RandomArray(Mas1,5);
    ShowArray(Mas1);
    std::cout<<" DynamicArray operator+(const DynamicArray& r); ";
    DynamicArray sum=Mas+Mas1;
    ShowArray(sum);
    std::cout<<std::endl;
    std::cout<<" DynamicArray operator+(int x); ";
    DynamicArray sum1=Mas+5;
    ShowArray(sum1);
    std::cout<<std::endl;
    std::cout<<" DynamicArray operator-(const DynamicArray& r); "; // Объяснить как считается минус
    // Создаем новые
    DynamicArray Mass(5);
    RandomArray(Mass,5);
    DynamicArray Mass1(5);
    RandomArray(Mass1,5);
    DynamicArray sum2=Mass-Mass1;
    ShowArray(sum2);
    std::cout<<std::endl;
    std::cout<<" DynamicArray operator-(int x); ";
    DynamicArray MassMinus(5);
    RandomArray(MassMinus,5);
    ShowArray(MassMinus);
    DynamicArray sumMinus2=MassMinus-3;
    std::cout<<"СТАЛ--> ";
    ShowArray(sumMinus2);
      */
    
     /*
    //TEST 1
    int size=5;
    int dynamycSize;
    DynamicArray Mas(2);
    RandomArray(Mas,2);
    ShowArray(Mas);
    std::cout<<std::endl;
    DynamicArray Mas1(size);
    RandomArray(Mas1,size);
    ShowArray(Mas1);
    DynamicArray MasSum=Mas+Mas1;
    TEST(TestPlusFunction(Mas, Mas1, MasSum), "TEST + (Mas + Mas) ");
    std::cout<<std::endl;
    ShowArray(MasSum);
    */
    
    //TEST 2
    /*
    DynamicArray Mas(2);
    RandomArray(Mas,2);
    ShowArray(Mas);
    std::cout<<std::endl;
    int x=2;
    DynamicArray MasSum=Mas+x;
    TEST(TestPlus_X_Function(Mas, x, MasSum), "TEST + (Mas + X) ");
    std::cout<<std::endl;
    ShowArray(MasSum);
    */
    
    //TEST 3
    /*
    DynamicArray Mas(5);
    RandomArray(Mas,5);
    ShowArray(Mas);
    std::cout<<std::endl;
    int x=5;
    Mas+=x;
    TEST(TestPlus_X_Equal_Function(Mas, x, Mas), "TEST + (Mas + X)");
    std::cout<<std::endl;
    ShowArray(Mas);
       */                   //-
    
    //TEST 4
    /*
    DynamicArray Mas(5);
    RandomArray(Mas,5);
    ShowArray(Mas);
    std::cout<<std::endl;
    DynamicArray Mas1(5);
    RandomArray(Mas1,5);
    ShowArray(Mas1);
    Mas+=Mas1;
    TEST(TestPlus_X_Equal_Mas_Function(Mas, Mas1, Mas), "TEST + (Mas + X)");
    std::cout<<std::endl;
    ShowArray(Mas);
    */                  //-
    
    //TEST 5               // -
    /*
     DynamicArray Mas(5);
     RandomArray(Mas,5);
     ShowArray(Mas);
     std::cout<<std::endl;
     DynamicArray Mas1(5);
     RandomArray(Mas1,5);
     ShowArray(Mas1);
     DynamicArray MasSum=Mas-Mas1;
     TEST(TestMinusFunction(Mas, Mas1, MasSum), "TEST + (Mas + X)");
     std::cout<<std::endl;
     ShowArray(MasSum);
    *
    
    //TEST 6 //ПРОВАЛ
    /*
    DynamicArray Mas(5);
    RandomArray(Mas,5);
    ShowArray(Mas);
    std::cout<<std::endl;
    int x=3;
    DynamicArray MasSum=Mas-x;
    TEST(TestMinus_X_Function(Mas, x, MasSum), "TEST + (Mas + Mas)");
    std::cout<<std::endl;
    ShowArray(MasSum);
     */
    
    //TEST 7               //-
    /*
     DynamicArray Mas(10);
     RandomArray(Mas,10);
     ShowArray(Mas);
     std::cout<<std::endl;
     Mas-=6;
     DynamicArray Sum=Mas;
     TEST(TestMinus_X_Equal_Function(Mas, 6, Sum), "TEST + (Mas - X)");
     std::cout<<std::endl;
     ShowArray(Sum);
    */
    
    //TEST 8
    /*
     DynamicArray Mas(5);
     RandomArray(Mas,5);
     ShowArray(Mas);
     std::cout<<std::endl;
     DynamicArray Mas1(5);
     RandomArray(Mas1,5);
     ShowArray(Mas1);
     Mas+=Mas1;
     DynamicArray Sum=Mas;
     TEST(TestMinus_X_Equal_Mas_Function(Mas, Mas1, Sum), "TEST + (Mas + X)");
     std::cout<<std::endl;
     ShowArray(Sum);
    */

}
/*
DynamicArray* DynamicArray:: operator new[](size_t size)
{
    DynamicArray* ptr = (DynamicArray*)malloc(size);
    if (ptr)
    {
        std::cout << size << " Memmory allocated\n";
    }
    else
    {
    std::cout << "Error memory allocation\n";
    }
    return ptr;
}
void operator delete[](void* ptr)
{
    free(ptr);
    std::cout << "Memory delete\n";
}
*/

DynamicArray::DynamicArray(size_t size): size(size), current_idx(0)
{
    ar = new int [size]; // выделение памяти .  ar = new int
}
DynamicArray::DynamicArray(const DynamicArray& obj)
{
    current_idx=obj.current_idx;
    size = obj.current_idx;
    ar=new int [obj.current_idx];
    if (!ar)
    {
        std::cerr << "Error allocation mamory!\n";
        return;
    }
        //exit(1); ///  Завершение с кодом ошибки ,
    for (int i=0;i<obj.current_idx;++i)
        ar[i]=obj.ar[i];
}
int DynamicArray::Get (size_t index)
{
    if (index>=size)
    {
        return ar[0];
    }
    return ar[index];
}
void DynamicArray:: Push (int a)
{
    current_idx += 1;  // добавление + 1 // реальнjuj размерf массива
    if(current_idx < size) // проверка размера
    {
        ar[current_idx-1] = a; //
        return;
    }
    int * numberTemp;                             ////
    numberTemp=new int [size + 1];                //// ВЫУЧИТЬ
    memcpy(numberTemp, ar, sizeof(int) * size);   ////
    numberTemp[size] = a;                         ////
    size += 1; ////
    delete[] ar;////
    ar = numberTemp;////
}
size_t DynamicArray::GetSize() const
{
    return current_idx;
}
size_t DynamicArray::GetCapacity() const
{
    return size;
}
DynamicArray& DynamicArray::operator=(const DynamicArray& obj)
{
    int* temp = new int[obj.current_idx];
    if(!temp)
    {
        std::cerr << "Error allocation\n";
        return *this;
    }
    
    if(this->ar)
        delete[] this->ar;
    this->size = obj.current_idx;
    this->current_idx=obj.current_idx;
    this->ar = temp;
    
    for (int i=0;i<obj.current_idx;++i)
       this->ar[i]=obj.ar[i];
    return *this;
}
DynamicArray operator+(const DynamicArray& l, const DynamicArray& r)
{
    DynamicArray ret(l.current_idx + r.current_idx);// создаем объект массив и выделяем память размером current_idx + r.current_idx
    memcpy(ret.ar,l.ar, sizeof(int) * l.current_idx);// копируем кол-во байт из ar в ret.ar
    memcpy(ret.ar+l.current_idx, r.ar, sizeof(int) * r.current_idx);//докапируем в ret.ar+current_idx из r.ar
    ret.size = l.current_idx + r.current_idx + 1; //
    ret.current_idx = ret.size - 1;
    return ret;
}
DynamicArray operator+(const DynamicArray& l,int x)
{
    DynamicArray ret(l.current_idx+1);
    memcpy(ret.ar,l.ar, sizeof(int) * l.current_idx);
    memcpy(ret.ar+l.current_idx, &x, sizeof(int));
    ret.current_idx = ret.size;
    return ret;
    
    
}
DynamicArray operator-(const DynamicArray & l,const DynamicArray& r) // -ПРОВЕРИТЬ
{
    if(l.current_idx != r.current_idx)
        return l;
    DynamicArray ret(l.current_idx);
    for (int i=0;i<l.current_idx;++i)
    {
        ret[i] -= r.ar[i];
    }
    return ret;
}
DynamicArray operator/(const DynamicArray& l,const DynamicArray& r)
{
    if(l.current_idx != r.current_idx)
        return l;
    DynamicArray ret(l.current_idx);
    for (int i=0;i<l.current_idx;++i)
    {
        ret.ar[i] /= r.ar[i];
    }
    return ret;
}
DynamicArray operator-(const DynamicArray& l,int x)
{
    DynamicArray ret(l.current_idx);
    for (int i=0;i<l.current_idx;++i)
    {
        ret.ar[i] = l.ar[i]-x;
    }
    return ret;
}
DynamicArray operator*(const DynamicArray& l,int x)
{
    DynamicArray ret(l.current_idx);
    for (int i=0;i<l.current_idx;++i)
    {
        ret[i] = l.ar[i]*x;
    }
    return ret;
}
DynamicArray operator*(const DynamicArray& l,const DynamicArray& r)
{
    if(l.current_idx != r.current_idx)
        return *l.ar;
    DynamicArray ret(l.current_idx);
    for (int i=0;i<l.current_idx;++i)
    {
        ret[i] *= r[i];
    }
    return ret;
}
DynamicArray operator/(const DynamicArray& l,int x)
{
    DynamicArray ret(l.current_idx);
    for (int i=0;i<l.current_idx;++i)
    {
        ret[i] = l.ar[i]/x;
    }
    return ret;
}
bool operator==(const DynamicArray& l,const DynamicArray& r)
{
    if (l.ar!=r.ar)
    {
        return false;
    }
    return true;
}
int& DynamicArray::operator[](int idx)
{
    if(idx > this->current_idx)
    {
        std::cerr << "Index out of range\n";
    }
    return ar[idx];
}
const int&  DynamicArray::operator[](int idx) const
{
    if(idx > this->current_idx)
    {
        std::cerr << "Index out of range\n";
    }
    return ar[idx];
}
DynamicArray& DynamicArray::operator++()
{
    for (int i = 0;i<current_idx;++i)
{
    this->ar[i]+=1;
}
    return *this;
}
DynamicArray& DynamicArray::operator--()
{
    for (int i = 0;i<current_idx;++i)
{
    this->ar[i]-=1;
}
    return *this;
}
DynamicArray DynamicArray::operator++(int x)
{
    DynamicArray tmp(*this); // copy
    operator++();
    return tmp;
}
DynamicArray DynamicArray::operator--(int x)
{
DynamicArray tmp(*this); // copy
operator--();
    return tmp;
}

        


        
        
        
        
DynamicArray& DynamicArray::operator/=(int x)
{
    for (int i =0;i<this->current_idx;++i)
    {
        this->ar[i]/=x;
    }
    return *this;
}
DynamicArray& DynamicArray::operator+=(int x)
{
    
    for (int i = 0;i<this->current_idx;++i)
    {
        this->ar[i]+=x;
    }
    return *this;
}
DynamicArray& DynamicArray::operator+=(const DynamicArray& x)
{
    if(this->current_idx != x.current_idx)
        return *this;
    for (int i=0;i < this->current_idx;++i)
    {
        this->ar[i]+=x[i];
    }
    return *this;
    
}
DynamicArray& DynamicArray::operator-=(int x)
{
    for (int i =0;i<this->current_idx;++i)
    {
        this->ar[i]-=x;
    }
    return *this;
    
}
DynamicArray& DynamicArray::operator*=(int x)
{
    for (int i =0;i<current_idx;++i)
    {
        this->ar[i]*=x;
    }
    return *this;
}
DynamicArray& DynamicArray::operator-=(const DynamicArray& x)
{
    if(this->current_idx != x.current_idx)
        return *this;
    
    for (int i=0;i < this->current_idx;++i)
    {
        this->ar[i]-=x[i];
    }
    return *this;

}
DynamicArray& DynamicArray::operator/=(const DynamicArray& x)
{
    if(this->current_idx != x.current_idx)
        return *this;
    
    for (int i=0;i < this->current_idx;++i)
    {
        this->ar[i]/=x[i];
    }
    return *this;
}
DynamicArray& DynamicArray::operator*=(const DynamicArray& x)
{
    if(this->current_idx != x.current_idx)
        return *this;
    
    for (int i=0;i < this->current_idx;++i)
    {
        this->ar[i]*=x[i];
    }
    return *this;
}



