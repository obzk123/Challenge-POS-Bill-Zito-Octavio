Octavio Bill Zito

Entrega de ejercios 1 y 2 del Challenge POS.
El ejercicio 1 esta hecho con una matriz de char dinamica que se expande cada vez que se agrega un numero, tome la decision de hacerlos con char por el espacio en memoria que ocuparian los long int.
El ejercicio 2 a modo de prueba se puede abrir el ejecutable del Servidor que se encuentra dentro de la carpeta ServidorDeTest/Debug/ServidorDeTest.exe

Los rangos de las tarjetas se leen desde ranges.dat y son:

minRange  HighRange len id
00000000  20000000  13  0
30000000  50000000  15  1
70000000  90000000  14  2



Los nombres de estas tarjetas se encuentran en cards.dat con el siguiente orden:

label        id
Master Card  0
Visa         1
Brubank      2

El servidor de test tiene hardcodeado siempre enviar un 00 lo cual muestra aprobada en el cliente pero si se cambia ese valor el cliente muestra rechazada.