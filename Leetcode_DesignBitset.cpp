/*
2166. Design Bitset

Input
["Bitset", "fix", "fix", "flip", "all", "unfix", "flip", "one", "unfix", "count", "toString"]
[[5], [3], [1], [], [], [0], [], [], [0], [], []]
Output
[null, null, null, null, false, null, null, true, null, 2, "01010"]
*/
class Bitset
{
    int *bits;
    int *flippedBits;
    int size;
    int countOne = 0;

public:
    Bitset(int size)
    {
        this->size = size;
        bits = new int[size];
        flippedBits = new int[size];
        for (int i = 0; i < size; i++)
        {
            bits[i] = 0;
            flippedBits[i] = 1;
        }
    }

    void fix(int idx)
    {
        if (bits[idx])
        {
            return;
        }
        else
        {
            bits[idx] = 1;
            flippedBits[idx] = 0;
            countOne++;
        }
    }

    void unfix(int idx)
    {
        if (bits[idx])
        {
            bits[idx] = 0;
            flippedBits[idx] = 1;
            countOne--;
        }
        else
        {
            return;
        }
    }

    void flip()
    {
        int *temp = bits;
        bits = flippedBits;
        flippedBits = temp;
        countOne = size - countOne;
    }

    bool all()
    {
        if (countOne == size)
        {
            return true;
        }
        return false;
    }

    bool one()
    {
        if (countOne >= 1)
        {
            return true;
        }
        return false;
    }

    int count()
    {
        return countOne;
    }

    string toString()
    {
        string ans;
        for (int i = 0; i < size; i++)
        {
            ans += to_string(bits[i]);
        }
        return ans;
    }
};
