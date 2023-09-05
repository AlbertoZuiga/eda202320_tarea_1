# eda202320_tarea_1
## Las partes relevantes de esta tarea se dividen en 4 carpetas

### test
Esta carpeta contiene el codigo fuente en el archivo sort_ruts.cpp, en este codigo se llaman a las funcinones para ordenar los archivos proporcionados y el que se uso para generar el informe solicitado

### src e include
En estas carpetas se encuentran los codigos de las funciones principales (insertSort, mergeSort, quickSort, radixSort), y otras funciones secundarias, para calcular el tiempo que se demoran los algoritmos, otras funciones para abrir y crear los respectivos archivos con los datos

### build
En esta carpeta se ejecuta el cmake, es util para la primera implementacion del codigo y luego se puede dejar "en reposo" esta carpeta


## Ejecucion

### Preparacion del entorno
Como se pedia en la tarea para ejcutar el codigo se debe hacer el cmake en la carpeta build, luego ejecutar make (cada vez que se realice un cambio en alguno de los archivos)

### Modalidad 1
En esta modlaidad es la que se pedia en la tarea, se debe ingresar por el terminal "./sort_ruts <nombre_archivo> <caracter_ordenacion>", nombre_archivo es el nombre completo del archivo SIN ruta, caracter_ordenacion corresponde al caracter para señalar que algoritmo se desea utilizar para ordenar el archivo

### Modalidad 2
Esta modalidad fue la que se utilizo para generar el informe (recomiendo no ejecutarla ya que demora mucho), en esta modalidad se evaluan todos los algoritmos con todos los archivos y se guardan los resultados de los tiempos en un nuevo archivo, para utilizar esta modalidad se debe correr el programa "sort_ruts tiempo_ejecucion" 
