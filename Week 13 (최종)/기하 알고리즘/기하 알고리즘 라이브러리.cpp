// 0차원 도형 : 점

#define EPS 1e-9

// struct point_i { int x, y; };                    // 가장 기본적인, 최소한의 형태
struct point_i {                                    // 가능하면 point_i를 사용 (정수형)
    int x, y;
    point_i() { x = y = 0; }                        // 기본 생성자
    point_i(int _x, int _y) : x(_x), y(_y) {}       // 사용자 정의 생성자

    // 점들을 정렬해야 하는 경우
    bool operator < (point_i other) const {         // 연산자를 재정의한다.
        if (fabs(x-other.x) > EPS)                  // 이 연산자는 점들을 정렬할 때 유용하게 사용된다.
            return x < other.x;                     // 먼저는 x좌표를 기준으로 비교하고
        return y < other.y;                         // 다음으로는 y좌표를 기준으로 비교한다.
    };

};

struct point {                                      // 좌표를 실수 값으로 표현해야 하는 경우에만 사용
    double x, y;
    point() { x = y = 0; }                          // 기본 생성자
    point(double _x, double _y) : x(_x), y(_y) {}   // 사용자 정의 생성자

    // 점들을 정렬해야 하는 경우
    bool operator < (point other) const {           // 연산자를 재정의한다.
        if (fabs(x-other.x) > EPS)                  // 이 연산자는 점들을 정렬할 때 유용하게 사용된다.
            return x < other.x;                     // 먼저는 x좌표를 기준으로 비교하고
        return y < other.y;                         // 다음으로는 y좌표를 기준으로 비교한다.
    };

    // 두 점이 서로 같은지를 검사해야 하는 경우
    // 두 실수가 서로 같은지를 비교할 때는 EPS(1e-9)를 사용한다.
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    };

    // 유클리드 거리 구하기
    double dist(point p1, point p2) {
        //hypot(dx, dy)는 sqrt(dx * dx + dy * dy)를 반환한다.
        return hypot(p1.x - p2.x, p1.y - p2.y); // double형을 반환한다.
    };

    // p를 원점 (0, 0)을 중심으로 반시계 방향으로 theta도 회전한다.
    point rotate(point p, double theta) {
        double rad = DEG_TO_RAD(theta); // theta에 (PI / 180.0)을 곱한다.
        return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
    };
};

// int main 함수 내부, vector <point> P를 미리 생성해두었다고 가정
sort(P.begin(), P.end());   // 비교 연산자를 위에서 정의하였다. 

// int maiN 함수 내부, == 사용 예시
point P1(0,0), P2(0,0), P3(0,1);
printf("%d\n", P1 == P2);   // 참
printf("%d\n", P1 == P3);   // 거짓

// 1차원 도형 : 직선
// 직선의 방정식 ax + by + c = 0, 여기에서 직선이 수직선인 경우 b = 0, 수직선이 아닐 경우 b = 1
struct line { double a, b, c };

// 만약 직선을 지나는 점이 적어도 두 개 주어졌다면, 직선의 방정식을 세울 수 있다.
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {                      // 수직선도 괜찮다.
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;              // 기본 값
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;                                      // 중요 : b의 값을 1.0으로 고정한다.
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

// 두 직선이 평행(parallel)한지를 검사하려면, 계수 a와 b가 서로 같은지 검사하면 된다.
bool areParallel(line l1, line l2) {    // 계수 a와 b를 검사한다.
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

// 두 직선이 일치(same)하는지를 검사하려면, 두 직선이 평행하며 계수 c가 서로 같은지 검사해보면 된다.
// 이 경우 계수 a, b, c 세 개가 모두 서로 같은지 검사한다.
bool areSame(line l1, line l2) {        // 계수 c도 검사한다.
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// 두 직선이 서로 평행하지 않다면(일치하지도 않다면), 둘은 한 점에서 교차(intersect)한다.
// 그 교점(intersection point) (x,y)를 구하려면, 미지수가 두 개이며 선형 방정식 두 개로 이루어진 연립 방정식을 풀어야 한다.
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;  // 교차하지 않는다.

    // 미지수가 두 개이며 선형 방정식 두 개로 이루어진 연립 방정식을 푼다.
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    // 예외 케이스, 0으로 나누지 않도록 하기 위해 수직선인지를 검사한다.
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}

// 선분부터 써보자