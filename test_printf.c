/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:00:00 by iportill          #+#    #+#             */
/*   Updated: 2024/06/25 10:00:00 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

// Función para imprimir separador entre pruebas
void    print_separator(void)
{
    printf("\n--------------------------------------------------\n");
}

// Función para comparar resultados entre printf original y ft_printf
void    compare_results(int original, int custom, char *test_name)
{
    if (original == custom)
        printf("\033[32m✓ PASS\033[0m - %s: Bytes devueltos: original=%d, custom=%d\n", 
               test_name, original, custom);
    else
        printf("\033[31m✗ FAIL\033[0m - %s: Bytes devueltos: original=%d, custom=%d\n", 
               test_name, original, custom);
}

int main(void)
{
    int original;
    int custom;
    char *test_name;
    
    printf("\033[1;34m========== PRUEBAS DE FT_PRINTF ==========\033[0m\n\n");
    
    // Prueba 1: Cadenas básicas
    test_name = "Cadena básica";
    printf("\033[1;33m1. %s\033[0m\n", test_name);
    
    printf("Printf original: ");
    original = printf("Esta es una cadena sin formato");
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Esta es una cadena sin formato");
    printf("\n");
    compare_results(original, custom, test_name);
    print_separator();
    
    // Prueba 2: Formato %c
    test_name = "Formato %%c";
    printf("\033[1;33m2. %s\033[0m\n", test_name);
    
    printf("Printf original: ");
    original = printf("Carácter: %c", 'A');
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Carácter: %c", 'A');
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Múltiples caracteres: %c %c %c", '1', '2', '3');
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Múltiples caracteres: %c %c %c", '1', '2', '3');
    printf("\n");
    compare_results(original, custom, test_name);
    print_separator();
    
    // Prueba 3: Formato %s
    test_name = "Formato %%s";
    printf("\033[1;33m3. %s\033[0m\n", test_name);
    
    printf("Printf original: ");
    original = printf("Cadena: %s", "Hola mundo");
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Cadena: %s", "Hola mundo");
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Cadena NULL: %s", "(null)");
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Cadena NULL: %s", NULL);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Cadena vacía: '%s'", "");
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Cadena vacía: '%s'", "");
    printf("\n");
    compare_results(original, custom, test_name);
    print_separator();
    
    // Prueba 4: Formato %d y %i
    test_name = "Formato %%d y %%i";
    printf("\033[1;33m4. %s\033[0m\n", test_name);
    
    printf("Printf original: ");
    original = printf("Entero (%%d): %d", 42);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Entero (%%d): %d", 42);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Entero (%%i): %i", 42);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Entero (%%i): %i", 42);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Entero negativo: %d", -42);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Entero negativo: %d", -42);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Entero grande: %d", INT_MAX);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Entero grande: %d", INT_MAX);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Entero mínimo: %d", INT_MIN);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Entero mínimo: %d", INT_MIN);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Cero: %d", 0);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Cero: %d", 0);
    printf("\n");
    compare_results(original, custom, test_name);
    print_separator();
    
    // Prueba 5: Formato %u
    test_name = "Formato %%u";
    printf("\033[1;33m5. %s\033[0m\n", test_name);
    
    printf("Printf original: ");
    original = printf("Entero sin signo: %u", 42);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Entero sin signo: %u", 42);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Entero grande sin signo: %u", UINT_MAX);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Entero grande sin signo: %u", UINT_MAX);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Entero negativo como sin signo: %u", -1);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Entero negativo como sin signo: %u", -1);
    printf("\n");
    compare_results(original, custom, test_name);
    print_separator();
    
    // Prueba 6: Formato %x y %X
    test_name = "Formato %%x y %%X";
    printf("\033[1;33m6. %s\033[0m\n", test_name);
    
    printf("Printf original: ");
    original = printf("Hexadecimal minúscula: %x", 42);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Hexadecimal minúscula: %x", 42);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Hexadecimal mayúscula: %X", 42);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Hexadecimal mayúscula: %X", 42);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Hexadecimal grande: %x", UINT_MAX);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Hexadecimal grande: %x", UINT_MAX);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Hexadecimal 0: %x", 0);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Hexadecimal 0: %x", 0);
    printf("\n");
    compare_results(original, custom, test_name);
    print_separator();
    
    // Prueba 7: Formato %p
    test_name = "Formato %%p";
    printf("\033[1;33m7. %s\033[0m\n", test_name);
    
    int num = 42;
    void *ptr = &num;
    
    printf("Printf original: ");
    original = printf("Puntero: %p", ptr);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Puntero: %p", ptr);
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("Printf original: ");
    original = printf("Puntero NULL: %p", NULL);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Puntero NULL: %p", NULL);
    printf("\n");
    compare_results(original, custom, test_name);
    print_separator();
    
    // Prueba 8: Formato %%
    test_name = "Formato %%%%";
    printf("\033[1;33m8. %s\033[0m\n", test_name);
    
    printf("Printf original: ");
    original = printf("Porcentaje: %%");
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Porcentaje: %%");
    printf("\n");
    compare_results(original, custom, test_name);
    print_separator();
    
    // Prueba 9: Combinaciones múltiples
    test_name = "Combinaciones múltiples";
    printf("\033[1;33m9. %s\033[0m\n", test_name);
    
    printf("Printf original: ");
    original = printf("Combinado: %c %s %d %i %u %x %X %p %%", 'A', "Hola", 42, -42, 100, 255, 255, ptr);
    printf("\nTu ft_printf:    ");
    custom = ft_printf("Combinado: %c %s %d %i %u %x %X %p %%", 'A', "Hola", 42, -42, 100, 255, 255, ptr);
    printf("\n");
    compare_results(original, custom, test_name);
    print_separator();
    
    // Prueba 10: Casos especiales
    test_name = "Casos especiales";
    printf("\033[1;33m10. %s\033[0m\n", test_name);
    
    printf("Printf original: ");
    original = printf("%d %s", 0, "");
    printf("\nTu ft_printf:    ");
    custom = ft_printf("%d %s", 0, "");
    printf("\n");
    compare_results(original, custom, test_name);
    
    printf("\033[1;34m\n========== RESUMEN ==========\033[0m\n");
    printf("Todas las pruebas han sido ejecutadas. Revisa los resultados para asegurarte\n");
    printf("de que tu implementación de ft_printf funciona correctamente.\n");
    
    return (0);
}
