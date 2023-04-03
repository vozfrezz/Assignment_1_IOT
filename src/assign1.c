#include <math.h>
#include <stdio.h>

// Define global variables
float coords[6], altitude[3], medians[3], triangle_info[6]; // Coordinate
float angleA, angleB, angleC, AB, BC, AC;
float Ah, Bh, Ch, mA, mB, mC, p, area;
float Pi = 3.1415926535897932384626433;

// Function prototypes
void input_coords();
int is_triangle();
void side_triangle();
void classify_triangle();
void is_righttriangle();
void normal_triangle();
void caculate_area();
void altitudes_caculate();
void medians_caculate();
void median_point_triangle();
void decode_triangle();

int main() {
  input_coords();
  while (is_triangle() == 0) {
    printf("\nVui long nhap lai toa do:");
    input_coords();
  };
  side_triangle();
  is_triangle();
  side_triangle();
  classify_triangle();
  caculate_area();
  altitudes_caculate();
  medians_caculate();
  median_point_triangle();
  return 0;
};
// Function to input coordinates
void input_coords() {
  char point = 'A'; // Point
  int i;
  for (i = 0; i < (sizeof(coords) / sizeof(coords[0])); i += 2) {
    printf("\nNhap toa do diem %c:\n", point);
    scanf("%f%f", &coords[i], &coords[i + 1]);
    printf("\n%cx :%0.2f\n\n%cy :%0.2f\n", point, coords[i], point,
           coords[i + 1]);
    point++;
  };
  printf("\nToa do diem A da nhap: A(%.2f,%.2f)\n", coords[0], coords[1]);
  printf("Toa do diem B da nhap: B(%.2f,%.2f)\n", coords[2], coords[3]);
  printf("Toa do diem C da nhap: C(%.2f,%.2f)\n", coords[4], coords[5]);
};

// Function to check if the entered coordinates form a triangle
int is_triangle() {
  // Calculate the side lengths
  triangle_info[0] = sqrt(pow(coords[2] - coords[0], 2) +
                          pow(coords[3] - coords[1], 2)); // c =AB

  triangle_info[1] = sqrt(pow(coords[4] - coords[2], 2) +
                          pow(coords[5] - coords[3], 2)); // a = BC

  triangle_info[2] = sqrt(pow(coords[4] - coords[0], 2) +
                          pow(coords[5] - coords[1], 2)); // b= AC
  AB = triangle_info[0];
  BC = triangle_info[1];
  AC = triangle_info[2];
  // Check if the sum of two sides is greater than the third side
  if (BC + AC <= AB || BC + AB <= AC || AC + AB <= BC) {
    printf("\n3 diem A, B,C khong tao thanh tam giac\n");
    return 0;
  } else {
    printf("\nToa do 3 diem nhap vao tao thanh tam giac\n");
    return 1;
  };
};

// Function to print, calculate side lengths and angles
void side_triangle() {
  printf("\n1. So do co ban cua tam giac:\n");
  printf("\nChieu dai canh BC: %.2f", BC);
  printf("\nChieu dai canh AC: %.2f", AC);
  printf("\nChieu dai canh AB: %.2f", AB);
  // Calculate the angles using the cosine rule
  triangle_info[3] =
      acos((pow(AC, 2) + pow(AB, 2) - pow(BC, 2)) / (2 * AC * AB));
  triangle_info[4] =
      acos((pow(BC, 2) + pow(AB, 2) - pow(AC, 2)) / (2 * BC * AB));
  triangle_info[5] =
      acos((pow(BC, 2) + pow(AC, 2) - pow(AB, 2)) / (2 * BC * AC));

  angleA = triangle_info[3] * 180 / Pi;
  angleB = triangle_info[4] * 180 / Pi;
  angleC = triangle_info[5] * 180 / Pi;
  printf("\nGoc A co gia tri la: %0.2f", angleA);
  printf("\nGoc B co gia tri la: %0.2f", angleB);
  printf("\nGoc C co gia tri la: %0.2f\n", angleC);
};

// Function to classify the triangle
void classify_triangle() {
  if (AB == BC == AC) {
    printf("\nACB la tam giac deu");
  } else if (AB == BC || AB == AC || BC == AC) {
    is_righttriangle();
  } else {
    normal_triangle();
  };
};

// Function to check if the triangle is right-angled
void is_righttriangle() {
  if (angleA == 90) {
    printf(" \ntam giac vuong can ta B");
  } else if (angleB == 90) {
    printf(" \ntam giac vuong can ta A");
  } else if (angleC == 90) {
    printf(" \btam giac vuong can ta C");
  } else {
    if (AB == BC) {
      (angleB > 90) ? printf("\nTam giac ACB can va tu tai B")
                    : printf("\nTam giac ACB can tai B");
    } else if (AB == AC) {
      (angleA > 90) ? printf("\nTam giac ACB can va tu tai A")
                    : printf("\nTam giac ACB can tai A");
    } else if (BC == AC) {
      (angleC > 90) ? printf("\nTam giac ACB can va tu tai C")
                    : printf("\nTam giac ACB can tai C");
    };
  };
};

// Function to check if the triangle is oblique
void normal_triangle() {
  if (angleB > 90) {
    printf("\nTam giac ACB nhon va tu tai B");
  } else if (angleA > 90) {
    printf("\nTam giac ACB nhon va tu tai A");
  } else if (angleC > 90) {
    printf("\nTam giac ACB nhon va tu tai C");
  } else {
    printf("\nTam giac ACB nhon");
  };
};

// Function to calculate the area of the triangle
void caculate_area() {
  p = (AB + BC + AC) / 2;
  area = sqrt(p * (p - BC) * (p - AC) * (p - AB));
  printf("\n\n2. Dien tich tam giac ACB la: %0.2f\n", area);
};

// Function to calculate the altitudes of the triangle (S = a.h/2, so h = 2S/a)
void altitudes_caculate() {
  Ah = (2 * area) / BC;
  Bh = (2 * area) / AC;
  Ch = (2 * area) / AB;
  altitude[0] = Ah;
  altitude[1] = Bh;
  altitude[2] = Ch;
  printf("\n3. So do nang cao tam giac ACB:\n");
  printf("\nDuong cao tu dinh A la:%0.2f", Ah);
  printf("\nDuong cao tu dinh B la:%0.2f", Bh);
  printf("\nDuong cao tu dinh C la:%0.2f", Ch);
};

// Function to calculate the medians
void medians_caculate() {
  mA = sqrt((AC * AC + AB * AB) / 2 - BC * BC / 4);
  mB = sqrt((BC * BC + AB * AB) / 2 - AC * AC / 4);
  mC = sqrt((BC * BC + AC * AC) / 2 - AB * AB / 4);
  medians[0] = mA;
  medians[1] = mB;
  medians[2] = mC;

  printf("\nDo dai duong trung tuyen tu dinh A: %f", mA);
  printf("\nDo dai duong trung tuyen tu dinh B: %f", mB);
  printf("\nDo dai duong trung tuyen tu dinh C: %f\n", mC);
};

// Function to find the centroid of the triangle
void median_point_triangle() {
  float median_point_G[2] = {(coords[0] + coords[2] + coords[4]) / 3,
                             (coords[1] + coords[3] + coords[5]) / 3};
  printf("\n4. Toa do diem dac biet cua tam giac ABC:\n");
  printf("\nMedian point from A: M1(%.2f, "
         "%.2f)\n-------------------------------------------------",
         median_point_G[0], median_point_G[1]);
};

// Function to decode the triangle.

void decode_triangle() {
  input_coords();
  while (is_triangle() == 0) {
    printf("\nVui long nhap lai toa do:");
    input_coords();
  };
  side_triangle();
  is_triangle();
  side_triangle();
  classify_triangle();
  caculate_area();
  altitudes_caculate();
  medians_caculate();
  median_point_triangle();
};
