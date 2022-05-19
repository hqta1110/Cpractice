// giai he pt dai so tuyen tinh bang pp guass siedel

#include <stdio.h>
#include <conio.h>
#include <math.h>
#define eps 1e-3
#define max 10
/* Ham xuat mang a(n,n+1)*/
void xuatmt(int a[][max], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        printf("\n");
        for (j = 1; j <= n + 1; j++) {
            printf("%5d", a[i][j]);
        }
    }
}
/* Nhap day n phan tu */
void nhap(float *a, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        scanf("%f", a + i);
    }
}
/* Xuat day n phan tu */
void xuat(float a[], int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%8.3f", a[i]);
    }
}
void solve(int a[max][max],float x[max], float y[max],int n){
    int lap,dem,i,j;
    printf("\n\n Nhap xap xi nghiem ban dau : ");
        nhap(x, n);
        dem = 0;
        do {
            lap = 0;
            dem++;
            for (i = 1; i <= n; i++) {
                float s = 0;
                for (j = 1; j <= n; j++) {
                    if (j != i) s += a[i][j] * x[j];
                }
                y[i] = a[i][n + 1] - s;
                if (a[i][i] != 0) y[i] = y[i] / a[i][i];
                else return; /* ket thuc chuong trinh */
                if (fabs(x[i] - y[i]) > eps && dem < 30) lap = 1;
            }
            for (i = 1; i <= n; i++) {
                x[i] = y[i];
            }
        } while (lap);
        if (dem < 30) {
            printf("\n Nghiem cua he phuong trinh : ");
            xuat(x, n);
        }
        else printf(" \n He phtrinh ko giai duoc bang phuong phap nay");
}
int main() {
    int a[max][max];
    float x[max], y[max];
    int n, i, j;
    char tt;
    //Nhap ma tran tu may tinh
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n + 1; j++)
            scanf("%d", &a[i][j]);
            
    printf("\n Cac he so cua he phuong trinh:\n");
    xuatmt(a, n);

    while (1) {
        solve(a,x,y,n);
        printf("\n\n Ban tiep tuc ko(c/k)?\n");
        tt =getch();
        if (tt != 'c') break;
    }

    return 0;
}