# proyectoIS
## Ejecutar Pruebas Unitarias
1. Se compilan a través del Makefile
2. Se ha hecho uso del framework de GoogleTest, por lo que es necesario tener alguna versión del googletest e indicar el path en el Makefile donde pone **GTEST_DIR =**
3. ./monitor_unittest

## Ejecutar Aplicación
1. Se debe compilar con g++ excluyendo el fichero de los test **monitor_unittest.cc**
2. g++ main.cc persona.cc administrativo.cc monitor.cc visitante.cc parque.cc sendero.cc ruta.cc `puedes copiar y pegar`
3. ./a.out

Have fun!
