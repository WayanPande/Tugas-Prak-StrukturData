#include <stdio.h>
#include <conio.h>

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

    if (length % 2 == 0)
    {
        median = (mhs[ntengah] + mhs[ntengah - 1]) / 2;
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

void modus(int mhs[], int length)
{
    int total[100], jum = 0, index = 0;

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

    for (int i = 0; i < length; i++)
    {
        if (total[i] > jum)
        {
            jum = total[i];
            index = i;
        }
    }

    printf("Modus: %d, dengan Tinggi Badan: %d", jum, mhs[index]);
}

int main()
{

    // int mhs[] = {190, 168, 187, 167, 180, 191, 177, 175, 189, 190, 189, 185, 188, 188, 189, 187, 182, 181, 150, 154};
    int mhs[] = {10, 20, 20, 10, 11};
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
    int pil;
    printf("\n\nMenu\n");
    printf("1. Mencari Mean\n");
    printf("2. Mencari Median\n");
    printf("3. Mencari Modus\n");
    printf("4. Mencari Tinggi Badan Terendah\n");
    printf("5. Mencari Tinggi Badan Tertinggi\n");
    printf("Masukkan pilihan anda: ");
    scanf("%d", &pil);
    printf("\n");
    switch (pil)
    {
    case 1:
        printf("Mean: %.2f", mean(mhs, length));
        break;
    case 2:
        printf("Median: %.2f\n", median(mhs, length));
        break;
    case 3:
        modus(mhs, length);
        break;
    case 4:
        printf("Tinggi Badan Terendah: %d", terendah(mhs, length));
        break;
    case 5:
        printf("Tinggi Badan Tertinggi: %d\n", tertinggi(mhs, length));
        break;
    }

    printf("\n");
    return 0;
}