// MAI_C_2_sist_schisl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void display(uint32_t in_numb, uint16_t out_sist)
{
    uint32_t del = 1;
    int8_t step = 0, buf;

    while (in_numb > del)
    {
        del = del * out_sist;
        step++;
    }
    step--;
    del = del / out_sist;

    while (step >= 0)
    {
        if (in_numb >= del)
        {
            buf = in_numb / del;
            in_numb = in_numb - del * buf;
            if (buf > 9)
            {
                buf = buf - 10 + 'A';
            }
            else
            {
                buf = buf + '0';
            }
            cout << buf;
        }
        else
        {
            cout << '0';
        }

        del = del / out_sist;
        step--;
    }
}

uint32_t read(uint16_t in_sist)
{
    uint16_t in_numb=0;
    char c_buf;
    cin >> c_buf;
    cin >> c_buf;
    while (c_buf != ';')
    {
        in_numb = in_numb * in_sist;
        if ((c_buf >= '0') && (c_buf <= '9'))
        {
            in_numb = in_numb + c_buf - '0';
        }
        else
        {
            in_numb = in_numb + c_buf - 'A' + 10;
        }
        cin >> c_buf;

    }
    return in_numb;
}

int main()
{
    uint32_t in_numb=0;
    uint16_t in_sist, out_sist;
    
    cin >> in_sist;
        
    in_numb = read(in_sist);
    
    cin >> out_sist;

    cout << in_numb << endl;
    display(in_numb, out_sist);
}
