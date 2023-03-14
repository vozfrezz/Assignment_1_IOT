
#include <math.h>
#include <stdio.h>

float Crd[6];     // Coordinate
char Pnt = 'A';   // Point
float inf_Sqr[6]; // Area of  square
void type_Crd();
void is_Square();
void side_Angle();

int main() { type_Crd(); };

void type_Crd() {
  int i;
  for (i = 0; i < (sizeof(Crd) / sizeof(Crd[0])); i += 2) {
    printf("\nNhap toa do diem %c:\n", Pnt);
    scanf("%f%f", &Crd[i], &Crd[i + 1]);
    printf("\n%cx :%0.2f \n%cy :%0.2f", Pnt, Crd[i], Pnt, Crd[i + 1]);
    Pnt++;
  };
  // printf("\nToa do diem %c da nhap: %c(%.2f,%.2f)\n", Pnt, Pnt, Crd[i],
  //      Crd[i + 1]);
  printf("\nToa do diem A da nhap: A(%.2f,%.2f)\n", Crd[0], Crd[1]);
  printf("Toa do diem B da nhap: B(%.2f,%.2f)\n", Crd[2], Crd[3]);
  printf("Toa do diem C da nhap: C(%.2f,%.2f)\n", Crd[4], Crd[5]);
};

void is_Square() {
  S[1] = sqrt(pow(Crd[4] - Crd[2], 2) + pow(Crd[5] - Crd[3], 2)); // a = BC
  S[2] = sqrt(pow(Crd[4] - Crd[0], 2) + pow(Crd[5] - Crd[1], 2)); // b= AC
  S[0] = sqrt(pow(Crd[2] - Crd[0], 2) + pow(Crd[3] - Crd[1], 2)); // c =AB

  if (S[1] + S[2] <= S[0] || S[1] + S[0] <= S[2] || S[2] + S[0] <= S[1]) {
    printf("\n3 diem A, B,C khong tao thanh tam giac");
  } else {
    printf("\n3 diem A,B,C tao thanh tam giac");
  };
};

void side_Angle() {

  printf("\nChieu dai canh BC: %.2f", a);
  printf("\nChieu dai canh AC: %.2f", b);
  printf("\nChieu dai canh AB: %.2f", c);

  S[3] = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c));
  S[4] = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c));
  S[5] = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));

  printf("\nGoc A co gia tri la: %0.2f", S[3]);
  printf("\nGoc B co gia tri la: %0.2f", S[4]);
  printf("\nGoc C co gia tri la: %0.2f", S[5]);
};
