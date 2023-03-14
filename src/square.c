
#include <math.h>
#include <stdio.h>

// Variable,function declaration:
float T[6]; // array with 6 element for coordinate representation
float S[6];
float H[3];
float G[3];
float Pi = 3.1415926535897932384626433;
float p;       // chu vi tam giac
float s;       // dien tich tam giac
float a, b, c; // AB=C, BC=a, AC=b

void nhap_toado();
void kiemtra_tamgiac();
void gocanh_tamgiac();
void xet_tamgiac();
void dientich_tamgiac();
void duongcao_tamgiac();
void trungtuyen_tamgiac();
void tamgiac_vuong();
void tamgiac_thuong();

int main() {
  nhap_toado();
  kiemtra_tamgiac();
  gocanh_tamgiac();
  xet_tamgiac();
  dientich_tamgiac();
  duongcao_tamgiac();
  trungtuyen_tamgiac();
};

void nhap_toado() {
  printf("Nhap toa do diem A:");
  scanf("%f%f", &T[0], &T[1]);
  printf("Ax: %0.2f\n", T[0]);
  printf("Ay: %0.2f\n", T[1]);

  printf("Nhap toa do diem B:");
  scanf("%f%f", &T[2], &T[3]);
  printf("Bx: %0.2f\n", T[2]);
  printf("By: %0.2f\n", T[3]);

  printf("Nhap toa do diem C:");
  scanf("%f%f", &T[4], &T[5]);
  printf("Cx: %0.2f\n", T[4]);
  printf("Cy: %0.2f\n", T[5]);

  printf("Toa do diem A da nhap: A(%.2f,%.2f)\n", T[0], T[1]);
  printf("Toa do diem B da nhap: B(%.2f,%.2f)\n", T[2], T[3]);
  printf("Toa do diem C da nhap: C(%.2f,%.2f)\n", T[4], T[5]);
};

void kiemtra_tamgiac() {

  a = sqrt(pow(T[4] - T[2], 2) + pow(T[5] - T[3], 2)); // a = BC
  b = sqrt(pow(T[4] - T[0], 2) + pow(T[5] - T[1], 2)); // b= AC
  c = sqrt(pow(T[2] - T[0], 2) + pow(T[3] - T[1], 2)); // c =AB

  if (a + b <= c || a + c <= b || b + c <= a) {
    printf("\n3 diem A, B,C khong tao thanh tam giac");
  } else {
    printf("\n3 diem A,B,C tao thanh tam giac");
  };
};

void gocanh_tamgiac() {

  printf("\nChieu dai canh BC: %.2f", a);
  printf("\nChieu dai canh AC: %.2f", b);
  printf("\nChieu dai canh AB: %.2f", c);

  S[3] = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c));
  S[4] = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c));
  S[5] = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
  S[0] = c;
  S[1] = a;
  S[2] = b;

  printf("\nGoc A co gia tri la: %0.2f", S[3]);
  printf("\nGoc B co gia tri la: %0.2f", S[4]);
  printf("\nGoc C co gia tri la: %0.2f", S[5]);
};
//---------------------------------------------------------------------------------
void xet_tamgiac() {
  if (S[0] == S[1] == S[2]) {
    printf("\nACB la tam giac deu");
  } else if (S[0] == S[1] || S[0] == S[2] || S[1] == S[2]) {
    tamgiac_vuong();
  } else {
    tamgiac_thuong();
  };
};

void tamgiac_vuong() {
  if (S[0] * S[0] + S[1] * S[1] == S[2] * S[2]) {
    printf(" \ntam giac vuong can ta B");
  } else if (S[0] * S[0] + S[2] * S[2] == S[1] * S[1]) {
    printf(" \ntam giac vuong can ta A");
  } else if (S[1] * S[1] + S[2] * S[2] == S[0] * S[0]) {
    printf(" \btam giac vuong can ta C");
  } else {
    if (S[0] == S[1]) {
      (S[4] > (Pi / 2)) ? printf("\nTam giac ACB can va tu tai B")
                        : printf("\nTam giac ACB can tai B");
    } else if (S[0] == S[2]) {
      (S[3] > (Pi / 2)) ? printf("\nTam giac ACB can va tu tai A")
                        : printf("\nTam giac ACB can tai A");
    } else if (S[1] == S[2]) {
      (S[5] > (Pi / 2)) ? printf("\nTam giac ACB can va tu tai C")
                        : printf("\nTam giac ACB can tai C");
    };
  };
};
void tamgiac_thuong() {
  if (S[4] > (Pi / 2)) {
    printf("\nTam giac ACB nhon va tu tai B");
  } else if (S[3] > (Pi / 2)) {
    printf("\nTam giac ACB nhon va tu tai A");
  } else if (S[5] > (Pi / 2)) {
    printf("\nTam giac ACB nhon va tu tai A");
  } else {
    printf("\nTam giac ACB nhon");
  };
};

// Tinh dien tich tam giac sử dụng định lý Heron S = sqrt(p * (p-a) * (p-b) *
//(p-c)) trong đó p = (a + b + c) / 2 là nửa chu vi của tam giác.
//--------------------------------------------------------------------------
void dientich_tamgiac() {
  p = (S[1] + S[2] + S[0]) / 2;
  s = sqrt(p * (p - S[1]) * (p - S[2]) * (p - S[0]));
  printf("\nDien tich tam giac ACB la: %f", s);
};

// Duong cao tam giac S=a.h/2 vay h=2S/a
void duongcao_tamgiac() {
  H[0] = 2 * s / S[1];
  H[1] = 2 * s / S[2];
  H[2] = 2 * s / S[0];
  printf("\nDuong cao tu dinh A la:%0.2f", H[0]);
  printf("\nDuong cao tu dinh B la:%0.2f", H[1]);
  printf("\nDuong cao tu dinh C la:%0.2f", H[2]);
};

void trungtuyen_tamgiac() {
  G[0] = sqrt((b * b + c * c) / 2 - a * a / 4);
  G[1] = sqrt((a * a + c * c) / 2 - b * b / 4);
  G[2] = sqrt((a * a + b * b) / 2 - c * c / 4);
  printf("\nDo dai duong cao tu dinh A: %f", G[0]);
  printf("\nDo dai duong cao tu dinh B: %f", G[1]);
  printf("\nDo dai duong cao tu dinh C: %f", G[2]);
};
