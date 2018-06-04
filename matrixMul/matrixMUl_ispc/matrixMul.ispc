
#define NUM 5
export void matrixMul(uniform int a[][NUM], uniform int b[][NUM], uniform int result[][NUM], uniform int count) {
    foreach (index = 0 ... count) {
      int sum = 0;
      for(int col = 0; col < count; col++) {
        for(int i = 0; i < count; i++) {
          for(int j = 0; j < count; j++) {
            sum += a[index][i] * b[j][col];
          }
        }
        result[index][col] = sum;
      }

    }
}