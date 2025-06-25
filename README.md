# ft_printf

## 📝 Descripción
Este proyecto consiste en replicar el funcionamiento de la función `printf` de la librería estándar de C. La función `ft_printf` implementa el manejo de los siguientes formatos:

* `%c` - Imprime un solo carácter
* `%s` - Imprime una string (cadena de caracteres)
* `%p` - Imprime un puntero en formato hexadecimal (con prefijo "0x")
* `%d` - Imprime un número decimal (base 10)
* `%i` - Imprime un entero en base 10
* `%u` - Imprime un número decimal sin signo (base 10)
* `%x` - Imprime un número hexadecimal (base 16) en minúsculas
* `%X` - Imprime un número hexadecimal (base 16) en mayúsculas
* `%%` - Imprime el símbolo de porcentaje

## 🛠️ Compilación
Para compilar la biblioteca `libftprintf.a`, ejecuta el siguiente comando:

```bash
make
```

Para limpiar los archivos objeto generados durante la compilación:

```bash
make clean
```

Para eliminar todos los archivos generados (incluida la biblioteca):

```bash
make fclean
```

Para recompilar todo el proyecto:

```bash
make re
```

## 📚 Uso
Primero, incluye el archivo de cabecera en tu programa:

```c
#include "include/ft_printf.h"
```

Luego, compila tu programa con la biblioteca:

```bash
gcc -Wall -Wextra -Werror tu_programa.c -L. -lftprintf -o tu_programa
```

Ahora puedes usar `ft_printf` de la misma manera que usarías la función `printf` original:

```c
ft_printf("Hola %s, tienes %d años\n", "Usuario", 25);
```

## ✅ Pruebas
Para probar el funcionamiento de la biblioteca, he incluido un archivo de pruebas que verifica todos los formatos implementados. Puedes compilar y ejecutar las pruebas con:

```bash
gcc -Wall -Wextra test_printf.c -L. -lftprintf -o test_ft_printf
./test_ft_printf
```

El test compara el resultado de la función original `printf` con mi implementación `ft_printf` para asegurar que ambas funcionen exactamente igual, verificando tanto la salida como el valor de retorno (número de caracteres impresos).

## 🔍 Características
- No utiliza asignación dinámica de memoria, lo que evita fugas de memoria
- Maneja correctamente todos los casos extremos (NULL, INT_MIN, INT_MAX, etc.)
- Sigue las normas de estilo de código de 42
- Incluye la biblioteca `libft` con funciones auxiliares
- Implementa una arquitectura modular con archivos separados para cada tipo de formato

## 🧪 Ejemplos

```c
// Imprimiendo caracteres y strings
ft_printf("Carácter: %c\n", 'A');
ft_printf("String: %s\n", "Hola mundo");

// Imprimiendo números
ft_printf("Entero: %d\n", 42);
ft_printf("Entero negativo: %i\n", -42);
ft_printf("Sin signo: %u\n", 4294967295);

// Imprimiendo hexadecimales
ft_printf("Hexadecimal min: %x\n", 255);  // ff
ft_printf("Hexadecimal MAY: %X\n", 255);  // FF

// Imprimiendo punteros
int num = 42;
ft_printf("Puntero: %p\n", &num);

// Imprimiendo porcentaje
ft_printf("Simbolo de porcentaje: %%\n");
```

## 📋 Evaluación
Este proyecto ha sido probado exhaustivamente para garantizar su conformidad con los requisitos del proyecto ft_printf de 42. Pasa todas las pruebas de funcionalidad y no tiene fugas de memoria.