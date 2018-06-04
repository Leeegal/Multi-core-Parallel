
#define NUM 5
export void matrixTran(uniform int a[][NUM], uniform int result[][NUM], uniform int count) {
    foreach (index = 0 ... count) {
     for(int i = 0; i <= count; i++) {
       result[index][i] = a[i][index];
     }
    }
}