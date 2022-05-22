#include <stdio.h>
#include <stdlib.h>
struct Array{
    int A[10];
    int size;
    int length;
};
void display(struct Array *arr)
{
    for (int i=0;i<arr->length;i++)
    {
        printf("%d ", arr->A[i]);
    }
}
int max(struct Array arr)
{
    int max = arr.A[0];
    for (int i=0;i<arr.length;i++)
    {
        if (max<arr.A[i])
        max = arr.A[i];
    }
    return max;
}
int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i=0;i<arr.length;i++)
    {
        if (min>arr.A[i])
        min = arr.A[i];
    }
    return min;
}
void append(struct Array *arr, int x)
{
    if (arr->length<arr->size)
    {
        arr->A[arr->length++] = x;
    }
}
void insert(struct Array *arr, int index, int x)
{
    if (index>arr->length && index<arr->size) index = arr->length;
    if (index>=0 && index<=arr->length)
    {
        for (int i=arr->length;i>index;i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
void del(struct Array *arr, int index)
{
    if (index>=0 && index<arr->length)
    {
        for (int i=index;i<arr->length-1;i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}
void delete_all(struct Array *a, int x) {
    for(int i=0; i<a->length; i++)
     {
        if(a->A[i] == x) 
        {
            for(int j=i; j<a->length-1; j++)
            {
                a->A[j] = a->A[j+1];
            }
            a->length--;
            i--;
        }
    }

}
void reverse(struct Array *arr)
{
    int i=0, j=arr->length-1;
    int temp =0;
    while (i<=j)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
        i++;
        j--;
    }
}
void Lshift(struct Array *arr)
{
    arr->A[arr->length] = arr->A[0];
    for (int i=0;i<arr->length;i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length] = 0;

}
void Rshift(struct Array *arr)
{
    arr->A[arr->length] = arr->A[arr->length-1];
    for (int i=arr->length-1;i>0;i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = arr->A[arr->length];
    arr->A[arr->length] = 0;
}
void SortedInsert(struct Array *arr, int x)
{
    if (arr->length==arr->size) return;
    int i=arr->length-1;
    while (arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->length++;
    arr->A[i+1] = x;
}
void merge(struct Array *arr1, struct Array arr2)
{
    if (arr1->size<arr1->length+arr2.length) return;
    for (int i=0;i<arr2.length;i++)
    {
        SortedInsert(arr1, arr2.A[i]);
    }
}
void concatenate(struct Array *arr1, struct Array arr2)
{
    if (arr1->size<arr1->length+arr2.length) return;
    int length = arr1->length;
    for (int i=0;i<arr2.length;i++)
    {
        arr1->A[i+length] = arr2.A[i];
        arr1->length++;
    }
}
int search(struct Array *arr, int x)
{
    for (int i=0;i<arr->length;i++)
    {
        if (arr->A[i]==x) return i;
    }
    return -1;
}
void uni(struct Array *arr1, struct Array arr2)
{
    int length = arr1->length;
    for (int i=0;i<arr2.length;i++)
    {
        if (search(arr1,arr2.A[i])==-1)
        {
            arr1->A[i+length] = arr2.A[i];
            arr1->length++;
        }
    }
}
void diff(struct Array *arr1, struct Array arr2)
{
    int index;
    for (int i=0;i<arr2.length;i++)
    {
        if (search(arr1, arr2.A[i])!=-1)
        {
            index = search(arr1, arr2.A[i]);
            del(arr1, index);
        }
    }
}
void findDiff(struct Array arr)
{
    int diff = arr.A[0];
    for (int i=0;i<arr.length;i++)
    {
        while (diff!=arr.A[i]-i)
        {
            printf("%d ",i+diff);
            diff++;
        }
    } 
}
void findDiff2(struct Array arr)
{
    int maximum = max(arr);
    int* temp = (int *)malloc(maximum*sizeof(int));
    for (int i=0;i<maximum;i++) temp[i] = 0;
    for (int i=0;i<arr.length;i++)
    {
        temp[arr.A[i]]++;
    }
    for (int i=min(arr);i<maximum;i++)
    {
        if (temp[i]==0) printf("%d ",i);
    }
    free(temp);
}
void findDup(struct Array arr)
{
    int maximum = max(arr);
    int* temp = (int *)malloc(maximum*sizeof(int));
    for (int i=0;i<maximum;i++) temp[i] = 0;
    for (int i=0;i<arr.length;i++)
    {
        temp[arr.A[i]]++;
    }
     for (int i=0;i<maximum;i++)
    {
        if (temp[i]>=2) printf("%d: %d times\n", i, temp[i]);
    }
}
void sumofpair(struct Array arr, int k)
{
    int maximum = max(arr);
    int* temp = (int *)malloc(maximum*sizeof(int));
    for (int i=0;i<=maximum;i++) temp[i] = 0;
    for (int i=0;i<arr.length;i++)
    {
        temp[arr.A[i]]++;
    }
    for (int i=0;i<=maximum;i++) printf("%d: %d ",i,temp[i]); printf("\n");
    for (int i=min(arr);i<=maximum;i++)
    {
        if (temp[i]==1)
        {
            if (temp[k-i]==1)
            {
            printf("%d + %d\n", i, k-i);
            temp[i]=0;
            }
        }
    }
    free(temp);
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}
void bubblesort(struct Array *arr)
{
    for (int i=0;i<arr->length-1;i++)
    {
        int flag;
        flag=0;
        for (int j=0;j<arr->length-1-i;j++)
        {
            if (arr->A[j]>arr->A[j+1])
            {
                swap(&arr->A[j], &arr->A[j+1]);
                flag=1;
            }
        }
        if (flag==0) break;
    }
}
void insertionsort(struct Array *arr)
{
    for (int i=1;i<arr->length;i++)
    {
        int j=i-1;
        int x=arr->A[i];
        while (j>-1 && arr->A[j]>x)
        {
            arr->A[j+1] = arr->A[j];
            j--;
        }
        arr->A[j+1] = x;
                display(arr);
        printf("\n");
    }
}
int c=0;
void selectionsort(struct Array *arr)
{
    int k, j;   //convert to pointer *j,*k
    for (int i=0;i<arr->length-1;i++)
    {      // k = j = &arr->A[i]
        for (int j=k=i;j<arr->length;j++)   // loop for t
        {
            if (arr->A[j]<arr->A[k])  //   *j<*k
            {
                k = j;
            }
        }   //j++
        swap(&arr->A[i], &arr->A[k]);
        printf("%d: ",c++);
        display(arr);
        printf("\n"); // swap(A[i],k)
    }
}
void select(struct Array *arr)
{
    int length = arr->length;
    for (int i=0;i<length-1;i++)
    {
        for (int j=i+1;j<length;j++)
        {
            if (arr->A[j]>arr->A[i]) swap(&arr->A[i], &arr->A[j]);
        }
        printf("Voi i = %d: ", c++);
        display(arr);
        printf("\n");
    }
}

int main()
{
    struct Array arr1 = {{10,15,10,10,3,4}, 10,6};
    struct Array arr2 = {{4,1,6}, 10,3};
     delete_all(&arr1, 10);
     display(&arr1);
    
    return 0;
}