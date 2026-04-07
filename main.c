#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

//./a.out -n -m -p
int main(int argn, char **args){
   int rank, size;
   char hostname[MPI_MAX_PROCESSOR_NAME];
   int len;
   int n,n_i,sum;
   MPI_Status status;

   // Inicializa el entorno MPI
   MPI_Init(&argn, &args);

   // Obtiene el número de proceso (rank)
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);

   // Obtiene el número total de procesos
   MPI_Comm_size(MPI_COMM_WORLD, &size);
   MPI_Get_processor_name(hostname, &len);

   n = rank*rank;

   //printf("Hola mundo soy el proceso %i de %i en %s\n",rank,size,hostname);
   //printf("Hola mundo soy el proceso %i de %i en %s y mi valor es %i",rank,size,hostname,rank*rank);
   sum = 0;
   if (rank==0){ //master
        for(int i =1;i<size;i++){
           MPI_Recv(&n_i,1,MPI_INT,i,0,MPI_COMM_WORLD,&status);
           sum = sum+n_1;
        }
        printf("suma=%i\n",sum);
   }else{ //slave
        n = rank*rank;
        MPI_Send(&n,1,MPI_INT,0,0,MPI_COMM_WORLD);
   }

   // Finaliza MPI
   MPI_Finalize();
   return 0;
   // Prueba para el git
}