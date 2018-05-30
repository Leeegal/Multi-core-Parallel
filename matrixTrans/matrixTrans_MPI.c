#include "mpi.h"  
#include<stdio.h>  
  
int main(int argc,char **argv){  
    int rows=6,cols=5;  
    int tag=0;
		double t1;
    MPI_Init(&argc,&argv);  
    int rank;  
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);  
    int A[rows][cols];  
    int B[cols][rows];  
    MPI_Datatype stype,ntype;  
    MPI_Type_vector(rows,1,cols,MPI_INT,&stype);  
    MPI_Type_hvector(cols,1,sizeof(int),stype,&ntype); 
    MPI_Type_commit(&ntype);    
    MPI_Status sta;  
  
    if(rank==0){  
        for(int i=0;i<rows;i++){  
            for(int j=0;j<cols;j++){  
            A[i][j]=i*cols+j;  
            printf("%d ",A[i][j]);  
            }  
        printf("\n");  
        }  
        printf("\n");  
        MPI_Send(A,1,ntype,1,tag,MPI_COMM_WORLD);  
    }  
    else{  
        MPI_Recv(B,rows*cols,MPI_INT,0,tag,MPI_COMM_WORLD,&sta);  
        for(int i=0;i<cols;i++){  
            for(int j=0;j<rows;j++)  
                printf("%d ",B[i][j]);  
            printf("\n");  
        }  
    }  
		MPI_Barrier(MPI_COMM_WORLD);
    MPI_Type_free(&ntype);
		if(rank == 0) {
			t1 = MPI_Wtime();
			printf("wall clock time = %f\n", t1);
		}
	
    MPI_Finalize();  
  
  
  
}  
