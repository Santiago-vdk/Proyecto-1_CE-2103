Proyecto-1_CE-2103
==================

Proyecto # 1: Análisis de Formas y Reconocimiento de Patrones



TECNOLÓGICO DE COSTA RICA
CURSO: ALGORITMOS Y ESTRUCTURAS DE DATOS II
PROFESOR: ANDRÉS VÍQUEZ VÍQUEZ
PROYECTO # 1: ANÁLISIS DE FORMAS Y RECONOCIMIENTO DE PATRONES 
VALOR: 20%
DESCRIPCIÓN DEL PROBLEMA
1. Reconstrucción de imágenes:
Desarrolle un programa que reciba una imagen mediante la cámara o una imagen guardada en 
la computadora, la misma tendrá en alguna parte una porción en blanco (o algún otro color que 
indique que una parte de la imagen ha sido borrada), por ejemplo:
Se deberá diseñar un algoritmo genético o heurístico para lograr reconstruir la imagen. En este 
caso se podrán dar aproximaciones del dibujo, no tiene que ser exacto.
Se recomienda iniciar utilizando imágenes muy simples, blanco y negro, no muy cargadas, 
después de esto se puede ir aumentando en dificultad hasta llegar a tener imágenes con colores.
2. Reconocimiento de patrones, aprendizaje y creatividad
Cree un programa que le permita a la computadora aprender algunas figuras geométricas básicas 
como líneas, círculos, cuadrados, triángulos, puntos, semicírculos, rectángulos y líneas curvas. La 
forma en que la computadora aprenderá será la siguiente:
 En un inicio el sistema no sabe nada.
 Se le presentan una hoja en blanco con una de las figuras, este la abstrae y la agrega a sus 
conocimientos.
 Se le presentan más hojas en blanco con la misma figura en diferentes posiciones y tamaños, 
el sistema deberá identificarlas, abstraer su esencia y agregarlas a su definición de la figura 
que se le está presentando.
 Si el sistema por alguna razón no se encuentra preparado para reconocer la imagen y 
clasificarla, el usuario deberá enseñarle, como un profesor a un estudiante.Al final de este ejercicio, el sistema deberá tener una noción de figuras geométricas básicas. En 
la siguiente etapa el sistema deberá ser capaz de reconocer estas figuras geométricas en una 
imagen, por ejemplo podemos presentarle está imagen.
Su programa deberá ser capaz de reconocer las componentes de está. Sí por alguna razón el 
sistema no entiende alguna parte de la misma, el usuario podrá indicar de cual se trata.
Al sistema se le presentarán muchas imágenes como las anteriores donde el mismo pueda 
reconocer patrones, estas imágenes serán tomadas como nuevo conocimiento de manera que 
el sistema podrá aprender cómo realizar composiciones de figuras. La estructuras de cómo se 
almacenarán estos conocimientos queda a creatividad del estudiante. Recuerden que al final 
podríamos decir que una línea está conformada por puntos y cualquier otra figura cómo unión
de líneas.
Al sistema deberá enseñarle muchas imágenes de este tipo con diferentes figuras para que tenga 
un mayor conocimiento. Recuerde siempre iniciar por imágenes simples, por ejemplo una casa 
conformada por un cuadrado, un rectángulo (puerta), dos cuadrados pequeños (ventanas) y un 
triángulo que es el techo, o podemos presentarle un edificio conformado por un rectángulo 
grande y varios cuadrados que son ventanas. 
Por último la creatividad, al sistema se le pasa un conjunto de figuras básicas aleatorias en 
desorden, de alguna manera con su conocimiento el sistema deberá hacer una composición de 
las mismas y dar una solución. 
EVALUACIÓN 
1) Documentación de la solución del problema (16%)
Cada grupo debe entregar un documento del proyecto que contemple como mínimo:
 Introducción.
 Estrategia de la solución y detalles de implementación.
 Diagramas de clases.
 Restricciones o suposiciones.
 Datos de pruebas.
 Recomendaciones y conclusiones.2) Reportes semanales de avance (4.5%)
Cada estudiante deberá enviar semanalmente un reporte de avance con la siguiente información:
 Qué hizo durante la semana.
 Qué hará la siguiente semana.
 Si tiene algún obstáculo que le impida alcanzar sus objetivos.
La semana que cubre cada reporte arranca cada lunes a partir de las 12:00 a.m. y termina el 
domingo a las 11:59 pm. 
El periodo de envío de los reportes empieza a partir de la semana del 1 de setiembre y terminarán 
con la entrega del proyecto.
Cada reporte semanal debe enviarse al correo del profesor con copia a todos sus compañeros.
Este aporte es individual y obligatorio para cada uno de los miembros de cada grupo.
3) Control de tiempo del equipo (4.5%)
Cada grupo deberá registrar las horas trabajadas por semana en su proyecto con el fin de ir 
recopilando un histórico de esfuerzo por grupo. Para ello, los grupos utilizarán el sistema de 
control de tiempos Actitime (http://www.actitime.com).
Cada grupo deberá crear un sitio para su proyecto y facilitar el enlace, un usuario y una contraseña 
para que el profesor pueda hacer las revisiones del tiempo. Cada grupo deberá enviar la 
información de acceso a más tardar el 7 de setiembre.
Los grupos serán responsables de definir las tareas que involucre su proyecto en coherencia con 
las actividades realizadas. 
El o la estudiante deberá iniciar el registro de sus horas dedicadas a partir del 1 de setiembre y 
hasta que se haga la entrega del proyecto. 
El profesor podrá revisar el control de tiempos cuando lo decida sin necesidad de un previo aviso. 
En caso que la información no sea consistente con el avance real del proyecto, el estudiante 
pierde los puntos de la revisión.
4) Proyecto programado (75%)
Para la evaluación de la correctitud de la parte programada se evaluará el proyecto de acuerdo 
a los criterios que se definen a continuación:
Documentación interna. (*) 2.5%
Uso adecuado de estándares de nombres para definiciones de clases, atributos, 
métodos, entre otros. (*)
2.5%
Utilización correcta del ocultamiento de la información. (*) 5%Modularidad y abstracción. (*) 5%
Reutilización de código. (*) 5%
Implementación correcta de la solución. 80%
(*) La revisión del criterio está sujeto a que la solución entregada levante sin problemas y que 
al menos un 60% de la funcionalidad de la solución este correcta.
ASPECTOS TÉCNICOS:
 La solución debe ser resuelta en el lenguaje de programación C++ utilizando el paradigma de 
programación orientado objetos y debe contemplar al menos un patrón de diseño en su 
implementación. 
 Las soluciones obtenidas por estos algoritmos no necesariamente son óptimas, en la mayoría de 
los casos serán aproximaciones, por lo que los resultados deberán de estar bien documentados y 
las limitaciones de estos también.
 Se recomienda la utilización de la biblioteca OpenCV para el reconocimiento de patrones de 
imágenes.
CONSIDERACIONES GENERALES:
 La fecha límite para la entrega es el 28 de setiembre a más tardar a las 11:59 pm. La entrega debe 
ser en formato digital a través de la plataforma TEC Digital. En caso de que la plataforma fallara, 
deberán enviarlo vía correo electrónico adjuntando una prueba del fallo de la plataforma.
 La penalidad por entrega tardía es de 10 puntos (de 100) por día natural que le serán restados a 
la nota obtenida.
 La solución al problema puede ser desarrollada en grupos de máximo cuatro estudiantes.
 No se atenderán dudas por correo electrónico, cualquier duda con respecto al proyecto debe ser 
canalizada por el espacio virtual asignado para el grupo.
 Cualquier documento entregado debe ser en formato de documento portable (PDF), no se 
revisarán documentos cuyo formato sea distinto al descrito. 
 En caso de comprobarse plagio en el desarrollo de la solución, se procederá a anular el trabajo a 
los involucrados. 
