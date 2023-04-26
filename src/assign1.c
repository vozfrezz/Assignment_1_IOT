#include <math.h>
#include <stdio.h>

// Define global variables
float coords[6], altitude[3], medians[3], triangle_info[6]; // Coordinate
float angleA, angleB, angleC, AB, BC, AC;
float Ah, Bh, Ch, mA, mB, mC, p, area;
float rightAngle = 90;
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
    printf("\nEnter the coordinates again.");
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
    printf("\nEnter the coordinates of point %c:\n", point);
    scanf("%f%f", &coords[i], &coords[i + 1]);
    printf("\n%cx :%0.2f\n\n%cy :%0.2f\n", point, coords[i], point,
           coords[i + 1]);
    point++;
  };
  printf("\nThe coordinates of point A: A(%.2f,%.2f)\n", coords[0], coords[1]);
  printf("The coordinates of point B: B(%.2f,%.2f)\n", coords[2], coords[3]);
  printf("The coordinates of point C: C(%.2f,%.2f)\n", coords[4], coords[5]);
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
    printf("\nABC is not a triangle\n");
    return 0;
  } else {
    printf("\nABC is a triangle\n");
    return 1;
  };
};

// Function to print, calculate side lengths and angles
void side_triangle() {
  printf("\n1. The basic diagram of triangle:\n");
  printf("\nLength of side BC: %.2f", BC);
  printf("\nLength of side AC: %.2f", AC);
  printf("\nLength of side AB: %.2f", AB);
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
  printf("\nAngle A equal: %0.2f", angleA);
  printf("\nAngle B equal: %0.2f", angleB);
  printf("\nAngle C equal: %0.2f\n", angleC);
};

// Function to classify the triangle
void classify_triangle() {
  if (AB == BC && BC == AC) {
    printf("\nACB is equilateral triangle");
  } else if (AB == BC || AB == AC || BC == AC) {
    is_righttriangle();
  } else {
    normal_triangle();
  };
};

// Function to check if the triangle is right-angled
void is_righttriangle() {
  if (fabs(angleA - 90) < 0.01) {
    printf(" \nABC is an isosceles right triangle at vertex A.");
  } else if (fabs(angleB - 90) < 0.01) {
    printf(" \nABC is an isosceles right triangle at vertex B.");
  } else if (fabs(angleC - 90) < 0.01) {
    printf(" \nABC is an isosceles right triangle at vertex C.");
  } else {
    if (AB == BC) {
      if (angleB > 90) {
        printf("\nABC is an isosceles triangle and obtuse at B.");
      } else {
        printf("\nABC is an isosceles triangle at B.");
      }
    } else if (AB == AC) {
      if (angleA > 90) {
        printf("\nABC is an isosceles triangle and obtuse at A.");
      } else {
        printf("\nABC is an isosceles triangle at A.");
      }
    } else if (BC == AC) {
      if (angleC > 90) {
        printf("\nABC is an isosceles triangle and obtuse at C.");
      } else {
        printf("\nABC is an isosceles triangle at C.");
      }
    };
  };
};

// Function to check if the triangle is oblique
void normal_triangle() {
  if (angleB > 90) {
    printf("\nACB is an obtuse triangle at B.");
  } else if (angleA > 90) {
    printf("\nACB is an obtuse triangle at A.");
  } else if (angleC > 90) {
    printf("\nACB is an obtuse triangle at C.");
  } else if (fabs(angleA - 90) < 0.01) {
    printf("\nACB is a right triangle at A.");
  } else if (fabs(angleB - 90) < 0.01) {
    printf("\nACB is a right triangle at B.");
  } else if (fabs(angleC - 90) < 0.01) {
    printf("\nACB is a right triangle at C.");
  } else {
    printf("\nACB is an acute triangle.");
  };
};

// Function to calculate the area of the triangle
void caculate_area() {
  p = (AB + BC + AC) / 2;
  area = sqrt(p * (p - BC) * (p - AC) * (p - AB));
  printf("\n\n2. The area of triangle ABC equal: %0.2f\n", area);
};

// Function to calculate the altitudes of the triangle (S = a.h/2, so h = 2S/a)
void altitudes_caculate() {
  Ah = (2 * area) / BC;
  Bh = (2 * area) / AC;
  Ch = (2 * area) / AB;
  altitude[0] = Ah;
  altitude[1] = Bh;
  altitude[2] = Ch;
  printf("\n 3.Advanced diagram of a triangle ACB:\n");
  printf("\nAltitude from vertex A:%0.2f", Ah);
  printf("\nAltitude from vertex B:%0.2f", Bh);
  printf("\nAltitude from vertex C:%0.2f", Ch);
};

// Function to calculate the medians
void medians_caculate() {
  mA = sqrt((AC * AC + AB * AB) / 2 - BC * BC / 4);
  mB = sqrt((BC * BC + AB * AB) / 2 - AC * AC / 4);
  mC = sqrt((BC * BC + AC * AC) / 2 - AB * AB / 4);
  medians[0] = mA;
  medians[1] = mB;
  medians[2] = mC;

  printf("\nMedian lengths from vertex A: %0.2f", mA);
  printf("\nMedian lengths from vertex B: %0.2f", mB);
  printf("\nMedian lengths from vertex C: %0.2f\n", mC);
};

// Function to find the centroid of the triangle
void median_point_triangle() {
  float median_point_G[2] = {(coords[0] + coords[2] + coords[4]) / 3,
                             (coords[1] + coords[3] + coords[5]) / 3};
  printf("\n4. The special coordinates of triangle ACB:\n");
  printf("\nMedian point from A: M1(%.2f, "
         "%.2f)\n-------------------------------------------------",
         median_point_G[0], median_point_G[1]);
};

// Function to decode the triangle.

void decode_triangle() {
  input_coords();
  while (is_triangle() == 0) {
    printf("\nEnter the coordinates again:");
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
