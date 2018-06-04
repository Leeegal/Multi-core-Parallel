
export uniform double calPi(uniform int count) {
    uniform double sum = 0.0;
    uniform double step = 1.0/(double) count;
    double p = 0.0;
    foreach (index = 0 ... count) {
       double x = (index+0.5) * step;
       p += step * 4.0 / (1.0 + x * x);
    }
    sum = reduce_add(p);
    return sum;
}