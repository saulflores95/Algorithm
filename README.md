# Algorithm
Some practice exercises for sharpening your algorithm skills, written in c.
This guide will be written in spanish.

### Que es un algoritmo?
    Un algoritmo es un conjunto de instrucciones que resuelven
    un problema dado paso a paso sin generar ambiguedades.
### Lenguage maquina
    Codigo exadecimales o binarios interpretados directamente en el micro

### Lenguage de bajo nivel
    Esta muy cerca de lo que se intepreta directamente en el computador, Len
    mas directo trabaja con el hardware.
### Lenguage de alto nivel
    Se programan cosas como la web, aplicaciones mas grandes, etc. Ya que se facilita la colaboracion
    entre programadores por tener un lenguage mas natural. Utiliza un interprete, que traduce a lenguage
    de bajo nivel.

Tipos de datos:
* No tipados: sin tipo especifico
* Tipados:

  1. Numericos
     - Enteros, long.
  2. Logicos
     - Booleanos.
  3. Alfanumericos
     - Letras, numeros, etc.

### Ques una estructura de datos?
    Es una manera muy eficiente de organizar y almecenar
    la informacion que esta reciviendo.

Tipos de estructuras de datos comunes:
  1. Listas
  2. Arreglos
  3. Arboles
  4. Listas ordenadas

# Resolucion de un problema con un algoritmo

  Metodologia:

   1. Definicion del problema.
   2. Analises del problema.
   3. Diseno del algorimto.
   4. Verificacion o pruebas.

Datos a extraer del problema
    Entrada:
      - Que se necesita para realizar los pasos?
   Salida:
      - Que se obtiene al final del algoritmo?
  Tipos de Datos:
    * Numeros: enteros, reales, complejos.
    * Texto: Letras, frases.

Dos tecnicas para el plantamiento del problema son
diagramas de flujo y pesuedocodigo (plantamiento utilizando lenguage natural)

# Que es una variable?
  1. Posicion de memoria donde se almcacena un datos
  2. Se define:
    * Nombre para poder recuperar su valor
    *  Tipo, esto restringe los valores que puede almacenar.
###Difrencia fundamental entre las estructuras Do-While y Whiles
  Do-While ejecuta las instrucciones al menos una primera vez sin evaluar la condicion

  While evaluea siempre la condicion antes de ejecutar las instrucciones, por lo tanto tambien es necesario defenir el valor de la condicion.

###Que es heap?

  Es un array visualizado como un arbol binario 'casi' completo.

###Propiedad max-heap

  El indeces de un nodo es >= a los indices de sus hijos

#Operaciones heap
  Build_max_heap: genera un max heap de un array sin clasificar.

  max_heapify: Corrige un sola error de la propiedad heap, ubicado en la ruta de un sub-arbo
