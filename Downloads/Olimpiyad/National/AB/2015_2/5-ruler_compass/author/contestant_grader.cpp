#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

// Contestant function.
//
void go(double tarx, double tary);

static int steps = 0;
static const double eps = 1e-8;
static const double eps_ans = 1e-3;
static std::vector< std::pair<double, double> > points;
static double tarx, tary;
static std::deque< std::vector<int> > objects;

// Helper methods.
//
static double sqdist(std::pair<double, double> a, std::pair<double, double> b);
static double dist(std::pair<double, double> a, std::pair<double, double> b);
static void get_line_coef(const std::vector<int> &line,
    double &A, double &B, double &C);
static int circle_line_intersect(double r, double A, double B, double C,
    std::pair<double, double> offset, double fac,
    int &id1, double &x1, double &y1, int &id2, double &x2, double &y2);

// Methods available to contestant
//
void done(int id) {
  if (id < 0 || id >= (int) points.size()) {
    std::cout << "Invalid point id: " << id
        << " .Points set size is " << points.size() << std::endl;
    exit(0);
  } else {
    double error = dist(points[id], std::make_pair(tarx, tary));
    if (error < eps_ans) {
      std::cout << "OK with " << steps << " steps and error "
          << std::fixed << error << std::endl;
      double score = 1.0 - (steps - 45) * 0.0085;
      if (score < 0) {
        score = 0;
      } else if (score > 1) {
        score = 1;
      }
      std::cout << "Score for this test: " << std::fixed << score << std::endl;
      exit(0);
    } else {
      std::cout << "WA with " << steps << " steps and error "
          << std::fixed << error << std::endl;
      exit(0);
    }
  }
}

void define_line(int ida, int idb) {
  std::vector<int> line;
  line.push_back(ida);
  line.push_back(idb);
  objects.push_back(line);
  while (objects.size() > 2) {
    objects.pop_front();
  }
}

void define_circle(int idc, int idr1, int idr2) {
  std::vector<int> circle;
  circle.push_back(idc);
  circle.push_back(idr1);
  circle.push_back(idr2);
  objects.push_back(circle);
  while (objects.size() > 2) {
    objects.pop_front();
  }
}

// Intersect last 2 geom objects defined.
//
int intersect(int &id1, double &x1, double &y1, int &id2, double &x2, double &y2) {
  ++steps;
  if (objects.size() != 2) {
    objects.clear();
    return 0;
  }
  if (objects[0].size() > objects[1].size()) {
    std::swap(objects[0], objects[1]);
  }
  if (objects[0].size() == 2 && objects[1].size() == 2) {
    // 2 lines intersection.
    //
    double A1, B1, C1;
    double A2, B2, C2;
    get_line_coef(objects[0], A1, B1, C1);
    get_line_coef(objects[1], A2, B2, C2);
    double det = A1 * B2 - A2 * B1;
    if (std::abs(det) < eps) {
      return 0;
    } else {
      id1 = points.size();
      x1 = (B2 * C1 - B1 * C2) / det;
      y1 = (A1 * C2 - A2 * C1) / det;
      points.push_back(std::make_pair(x1, y1));
      return 1;
    }
  } else if (objects[0].size() == 2 && objects[1].size() == 3) {
    // Move points to 0, 0.
    //
    double A, B, C;
    get_line_coef(objects[0], A, B, C);
    std::pair<double, double> cen = points[objects[1][0]];
    C = - A * (points[objects[0][0]].first - cen.first) -
          B * (points[objects[0][0]].second - cen.second);
    // Line norm should be one.
    //
    double r = dist(points[objects[1][1]], points[objects[1][2]]);
    C = C / r;
    return circle_line_intersect(1, A, B, C, cen, r, id1, x1, y1, id2, x2, y2);
  } else {
    assert(objects[0].size() == 3 && objects[1].size() == 3);
    // Normalise smaller circle to radius 1.
    // Should be 2 circles.
    //
    if (sqdist(points[objects[0][1]], points[objects[0][2]]) >
        sqdist(points[objects[1][1]], points[objects[1][2]])) {
      swap(objects[0], objects[1]);
    }
    double r1 = dist(points[objects[0][1]], points[objects[0][2]]);
    if (std::abs(r1) < eps) {
      std::cerr << "Circle too small radius" << std::endl;
      return 0;
    }
    double sr2 = sqdist(points[objects[1][1]], points[objects[1][2]]);
    std::pair<double, double> c2 = std::make_pair(
        (points[objects[1][0]].first - points[objects[0][0]].first) / r1,
        (points[objects[1][0]].second - points[objects[0][0]].second) / r1);
    double A = -2.0 * c2.first;
    double B = -2.0 * c2.second;
    double C = c2.first * c2.first + c2.second * c2.second +
        (r1 / r1) * (r1 / r1) - sr2 / (r1 * r1);
    return circle_line_intersect((r1 / r1), A, B, C, points[objects[0][0]], r1,
        id1, x1, y1, id2, x2, y2);
  }
}

int main() {
  std::cout.precision(10);
  std::cin >> tarx >> tary;
  points.push_back(std::make_pair(0, 0));
  points.push_back(std::make_pair(1, 0));

  go(tarx, tary);
  return 0;
}

static double sqdist(std::pair<double, double> a, std::pair<double, double> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}

static double dist(std::pair<double, double> a, std::pair<double, double> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}

static void get_line_coef(const std::vector<int> &line,
    double &A, double &B, double &C) {
  A = points[line[0]].second - points[line[1]].second;
  B = points[line[1]].first - points[line[0]].first;
  C = A * points[line[0]].first + B * points[line[0]].second;
  double norm = sqrt(A * A + B * B);
  A /= norm;
  B /= norm;
  C /= norm;
}

static int circle_line_intersect(double r, double A, double B, double C,
    std::pair<double, double> offset, double fac,
    int &id1, double &x1, double &y1, int &id2, double &x2, double &y2) {
  if (std::abs(A * A + B * B) < eps) {
    return 0;
  }
  double x0 = - A * C / (A * A + B * B);
  double y0 = - B * C / (A * A + B * B);
  if (C * C > r * r * (A * A + B * B) + eps) {
    return 0;
  } else if (std::abs(C * C - r * r * (A * A + B * B)) < eps) {
    id1 = points.size();
    x1 = x0 + offset.first;
    y1 = y0 + offset.second;
    points.push_back(std::make_pair(x1, y1));
    return 1;
  } else {
    double d = r * r - C * C / (A * A + B * B);
    if (d < -eps) {
      return -1;
    }
    double m = sqrt(d / (A * A + B * B));
    x1 = (x0 + B * m) * fac + offset.first;
    x2 = (x0 - B * m) * fac + offset.first;
    y1 = (y0 - A * m) * fac + offset.second;
    y2 = (y0 + A * m) * fac + offset.second;
    id1 = points.size();
    points.push_back(std::make_pair(x1, y1));
    id2 = points.size();
    points.push_back(std::make_pair(x2, y2));
    return 2;
  }
}
