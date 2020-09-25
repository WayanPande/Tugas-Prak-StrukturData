#include <stdio.h>

int sort(int mhs[], int length)
{

    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            if (mhs[i] > mhs[j])
            {
                int t = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = t;
            }
        }
    }

    return mhs;
}

float mean(int mhs[], int length)
{
    float rata;
    float total = 0;
    for (int i = 0; i < length; i++)
    {
        total = total + mhs[i];
    }

    rata = total / length;
    return rata;
}

float median(int mhs[], int length)
{
    sort(mhs, length);

    int ntengah = length / 2;

    float median;

    if (length % 2 != 0)
    {
        median = (mhs[ntengah] + mhs[ntengah + 1]) / 2;
    }
    else
    {
        median = mhs[ntengah];
    }

    return median;
}

int tertinggi(int mhs[], int length)
{

    sort(mhs, length);

    return mhs[length - 1];
}

int terendah(int mhs[], int length)
{

    sort(mhs, length);

    return mhs[0];
}

int modus(int mhs[], int length)
{

    int total[100], jum = 0, index = 0;

    sort(mhs, length);

    for (int i = 0; i < length; i++)
    {

        total[i] = 0;
        for (int j = 0; j < length; j++)
        {
            if (mhs[i] == mhs[j])
            {
                total[i]++;
            }
        }
    }

    // Untuk modus hanya 1
    for (int i = 0; i < length; i++)
    {
        if (total[i] > jum)
        {
            jum = total[i];
            index = i;
        }
    }

    printf("Modus: %d, tinggi: %d", jum, mhs[index]);
}

int main()
{

    int mhs[] = {190, 168, 187, 167, 180, 191, 177, 175, 189, 190, 189, 185, 188, 188, 189, 187, 182, 181, 150, 154};

    int length = sizeof(mhs) / sizeof(*mhs);

    // sort(mhs, length);
    // for (int i = 0; i < 20; i++)
    // {
    //     printf("%d ", mhs[i]);
    // }

    // printf("\nmedian: %.2f\n", median(mhs, length));
    // printf("Tertinggi: %d\n", tertinggi(mhs, length));
    // printf("Terendah: %d", terendah(mhs, length));
    // printf("\nMean: %.2f", mean(mhs, length));

    modus(mhs, length);
    return 0;
}