
#include <math.h>
#include <stdio.h>

float Crd[6];     // Coordinate
char Pnt = 'A';   // Point
float inf_Sqr[6]; // Area of  square
void type_Crd();
void is_Square();
void side_Angle();
void check_Square();
void is_Righttriagle();
void normal_Triangle();
float Pi = 3.1415926535897932384626433;
int main() {
  type_Crd();
  is_Square();
  side_Angle();
  check_Square();
};

void type_Crd() {
  int i;
  for (i = 0; i < (sizeof(Crd) / sizeof(Crd[0])); i += 2) {
    printf("\nNhap toa do diem %c:\n", Pnt);
    scanf("%f%f", &Crd[i], &Crd[i + 1]);
    printf("\n%cx :%0.2f \n%cy :%0.2f", Pnt, Crd[i], Pnt, Crd[i + 1]);
    Pnt++;
  };
  printf("\nToa do diem A da nhap: A(%.2f,%.2f)\n", Crd[0], Crd[1]);
  printf("Toa do diem B da nhap: B(%.2f,%.2f)\n", Crd[2], Crd[3]);
  printf("Toa do diem C da nhap: C(%.2f,%.2f)\n", Crd[4], Crd[5]);
};

void is_Square() {
  inf_Sqr[1] =
      sqrt(pow(Crd[4] - Crd[2], 2) + pow(Crd[5] - Crd[3], 2)); // a = BC
  inf_Sqr[2] = sqrt(pow(Crd[4] - Crd[0], 2) + pow(Crd[5] - Crd[1], 2)); // b= AC
  inf_Sqr[0] = sqrt(pow(Crd[2] - Crd[0], 2) + pow(Crd[3] - Crd[1], 2)); // c =AB

  if (inf_Sqr[1] + inf_Sqr[2] <= inf_Sqr[0] ||
      inf_Sqr[1] + inf_Sqr[0] <= inf_Sqr[2] ||
      inf_Sqr[2] + inf_Sqr[0] <= inf_Sqr[1]) {
    printf("\n3 diem A, B,C khong tao thanh tam giac");
  } else {
    printf("\n3 diem A,B,C tao thanh tam giac");
  };
};

void side_Angle() {

  printf("\nChieu dai canh BC: %.2f", inf_Sqr[1]);
  printf("\nChieu dai canh AC: %.2f", inf_Sqr[2]);
  printf("\nChieu dai canh AB: %.2f", inf_Sqr[0]);

  inf_Sqr[3] =
      acos((pow(inf_Sqr[2], 2) + pow(inf_Sqr[0], 2) - pow(inf_Sqr[1], 2)) /
           (2 * inf_Sqr[2] * inf_Sqr[0]));
  inf_Sqr[4] =
      acos((pow(inf_Sqr[1], 2) + pow(inf_Sqr[0], 2) - pow(inf_Sqr[2], 2)) /
           (2 * inf_Sqr[1] * inf_Sqr[0]));
  inf_Sqr[5] =
      acos((pow(inf_Sqr[1], 2) + pow(inf_Sqr[2], 2) - pow(inf_Sqr[0], 2)) /
           (2 * inf_Sqr[1] * inf_Sqr[2]));

  printf("\nGoc A co gia tri la: %0.2f", inf_Sqr[3]);
  printf("\nGoc B co gia tri la: %0.2f", inf_Sqr[4]);
  printf("\nGoc C co gia tri la: %0.2f", inf_Sqr[5]);
};

void check_Square() {
  if (inf_Sqr[0] == inf_Sqr[1] == inf_Sqr[2]) {
    printf("\nACB la tam giac deu");
  } else if (inf_Sqr[0] == inf_Sqr[1] || inf_Sqr[0] == inf_Sqr[2] ||
             inf_Sqr[1] == inf_Sqr[2]) {
    is_Righttriagle();
  } else {
    normal_Triangle();
  };
};

void is_Righttriagle() {
  if (inf_Sqr[0] * inf_Sqr[0] + inf_Sqr[1] * inf_Sqr[1] ==
      inf_Sqr[2] * inf_Sqr[2]) {
    printf(" \ntam giac vuong can ta B");
  } else if (inf_Sqr[0] * inf_Sqr[0] + inf_Sqr[2] * inf_Sqr[2] ==
             inf_Sqr[1] * inf_Sqr[1]) {
    printf(" \ntam giac vuong can ta A");
  } else if (inf_Sqr[1] * inf_Sqr[1] + inf_Sqr[2] * inf_Sqr[2] ==
             inf_Sqr[0] * inf_Sqr[0]) {
    printf(" \btam giac vuong can ta C");
  } else {
    if (inf_Sqr[0] == inf_Sqr[1]) {
      (inf_Sqr[4] > (Pi / 2)) ? printf("\nTam giac ACB can va tu tai B")
                              : printf("\nTam giac ACB can tai B");
    } else if (inf_Sqr[0] == inf_Sqr[2]) {
      (inf_Sqr[3] > (Pi / 2)) ? printf("\nTam giac ACB can va tu tai A")
                              : printf("\nTam giac ACB can tai A");
    } else if (inf_Sqr[1] == inf_Sqr[2]) {
      (inf_Sqr[5] > (Pi / 2)) ? printf("\nTam giac ACB can va tu tai C")
                              : printf("\nTam giac ACB can tai C");
    };
  };
};
void normal_Triangle() {
  if (inf_Sqr[4] > (Pi / 2)) {
    printf("\nTam giac ACB nhon va tu tai B");
  } else if (inf_Sqr[3] > (Pi / 2)) {
    printf("\nTam giac ACB nhon va tu tai A");
  } else if (inf_Sqr[5] > (Pi / 2)) {
    printf("\nTam giac ACB nhon va tu tai A");
  } else {
    printf("\nTam giac ACB nhon");
  };
};
