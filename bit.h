#ifndef BIT_SET_TEST_LIB
#define BIT_SET_TEST_LIB

class bit_array
{
private:
    char* array;
    int size;
    static const int CELL_LENGTH;
public:
    int get_size() const{ return size;}
    bool set_bit(const int position, const bool status);
    bool test_bit(const int position) const;
    bit_array(int length);
    ~bit_array(){
        delete array;
    }
};

const int bit_array::CELL_LENGTH = int(sizeof(char))*8;

bit_array::bit_array(int length):size(length)
{
    array = new char[((CELL_LENGTH - length%CELL_LENGTH)%CELL_LENGTH + length)/CELL_LENGTH]();//只能申请整数倍的整形
}

bit_array::~bit_array()
{
    delete array;
}

bool bit_array::set_bit(const int position, const bool status = 1)
{
    if(position >= size) return 0;
    const char maker = 1 << (CELL_LENGTH-(position+1)%CELL_LENGTH)%CELL_LENGTH;
    switch (status)
    {
    case 0:
        array[position/CELL_LENGTH] &= ~maker;
        break;
    
    case 1:
        array[position/CELL_LENGTH] |= maker;
        break;
    }
    return 1;
}

bool bit_array::test_bit(const int position)const
{
    const char maker = 1 << (CELL_LENGTH-(position+1)%CELL_LENGTH)%CELL_LENGTH;
    return array[position/CELL_LENGTH] & maker; //为0说明该位是0
}
#endif
