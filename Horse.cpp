//đếm số đường đi ngắn nhất để đi con mã từ vị trí x,y đến X,Y
int64_t dist(int64_t x1, int64_t y1, int64_t x2, int64_t y2)
{
    int64_t dx = abs(x2-x1);
    int64_t dy = abs(y2-y1);
    int64_t lb=(dx+1)/2;
    lb = max(lb, (dy+1)/2);
    lb = max(lb, (dx+dy+2)/3);
    while ((lb%2)!=(dx+dy)%2) lb++;
    if (abs(dx)==1 && dy==0) return 3;
    if (abs(dy)==1 && dx==0) return 3;
    if (abs(dx)==2 && abs(dy)==2) return 4;
    return lb;
}
