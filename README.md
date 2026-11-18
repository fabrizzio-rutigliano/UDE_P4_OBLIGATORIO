# Trabajo obligatorio de Programación IV — 2026

Prototipo en C++ para administrar el catálogo y las ventas de una librería de barrio especializada en libros de autores nacionales. El sistema mantiene libros y autores en memoria durante la ejecución; no incluye clientes, empleados ni persistencia en disco.

## Objetivo y alcance

Implementar un sistema orientado a objetos que gestione novelas y libros de texto, registre autores de novelas y resuelva las consultas y operaciones indicadas en los requisitos. El catálogo esperado es de aproximadamente 500 títulos; no hay un límite definido para la cantidad de autores.

### Datos del dominio

- **Autor:** cédula, nombre y apellido.
- **Libro (abstracto):** ISBN, título, editorial, precio base y unidades vendidas.
- **Novela:** género literario y referencia opcional a un autor.
- **Texto:** materia y fecha de publicación.
- **Escolar:** texto con año de escuela.

El precio de venta unitario depende del tipo: las novelas infantiles tienen 20% de descuento; los textos publicados antes del 01/01/2026 cuestan 75% del precio base; los escolares aplican además 10% de descuento para 1.º a 3.º año. Los demás casos se venden al precio base.

## Funcionalidades requeridas

1. Registrar autores y rechazar cédulas duplicadas.
2. Registrar libros y rechazar ISBN duplicados; inicializar las unidades vendidas en cero.
3. Asociar un autor existente a una novela existente, validando ambos y permitiendo reemplazar la asociación.
4. Listar ISBN, título y tipo de los libros cuyos títulos comienzan exactamente con una frase dada; informar si no hay coincidencias.
5. Consultar todos los datos de un libro por ISBN, incluyendo autor si es una novela asociada.
6. Listar autores con todos sus datos ordenados por cédula ascendente; informar si no hay autores.
7. Registrar la venta de una unidad por ISBN, incrementar el contador y devolver su precio de venta.
8. Calcular la recaudación acumulada de los libros de una editorial, usando el precio de venta aplicable y las unidades vendidas.
9. Contar las unidades vendidas de libros cuyo precio base supera un umbral, separadas en novelas, textos comunes y escolares.
10. Consultar el libro con más unidades vendidas de una editorial, con todos sus datos y el autor si corresponde; informar si no hay libros de esa editorial.

Las búsquedas que requieren un identificador inexistente y las consultas sin resultados deben comunicar el error correspondiente. No se dan de baja datos durante la ejecución.

## Diseño y colecciones

Se propone separar el programa en capas y exponer la capa lógica mediante una **Fachada**. La colección de libros es polimórfica: almacena referencias a objetos `Libro` que pueden ser `Novela`, `Texto` o `Escolar`; el cálculo del precio y la identificación del tipo se resuelven según la clase concreta.

| Colección / estructura | Clave y uso |
| --- | --- |
| Autores: diccionario implementado con ABB | Cédula; permite búsqueda por clave y recorrido ordenado ascendente. Crecimiento dinámico sin cota. |
| Libros: diccionario implementado con tabla hash | ISBN; búsqueda promedio O(1) para un catálogo semiacotado de alrededor de 500 títulos. |
| Resultados / iteración: lista con puntero al principio y al final (LPPF) | Inserción al final O(1) y recorrido de resultados; implementar el iterador de objetos indicado en el UML. |

Cada novela debe apuntar al objeto `Autor` que pertenece al diccionario de autores, evitando duplicar autores en memoria. Los diccionarios almacenan punteros a objetos polimórficos cuando corresponde. Definir claramente la propiedad de memoria: cada objeto se destruye una sola vez, incluso si está referenciado desde otras estructuras; implementar destructores para las colecciones.