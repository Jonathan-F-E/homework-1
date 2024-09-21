#include "sublist.h"

comparison_result_t check_lists(int *list_to_compare_begin, int *list_to_compare_end, 
    int *base_list_begin, int *base_list_end){

        //Calcular la longitud de los arreglos
        int list_to_compare_longitud = list_to_compare_end - list_to_compare_begin;
        int base_list_longitud = base_list_end - base_list_begin;

        // Verificar si los arreglos tienen la misma longitud
        if(list_to_compare_longitud == base_list_longitud){
            //Bandera para determinar si los elementos son iguales
            int iguales = 1;
            //Mientras no se llegue al fin de un arreglo, comparar sus elementos con el otro
            while(list_to_compare_begin < list_to_compare_end){
                //Si los elementos de los arreglos son distintos, la bandera vale 0
                if(*list_to_compare_begin != *base_list_begin){
                    iguales = 0;
                    break; //Se sale del bucle si los elementos no son iguales
                }
                //Se incrementan lan direcciones para comparar los siguientes elementos
                list_to_compare_begin++; 
                base_list_begin++;
            }
            //Si la bandera indica que las listas son iguales, se regresa EQUAL
            if (iguales){
                return EQUAL;
            }
        }

        //Si la longitud de la lista a comparar es menor que el tamaño de la lista base, se verifica si es sublista de la lista base
        if (list_to_compare_longitud < base_list_longitud) {
            //El bucle itera a través de la lista base para encontrar si hay una sublista
            //La condición asegura que el puntero solo recorre hasta donde haya suficiente espacio en la lista base como para tener la sublista
            for (int *inicio_lista = base_list_begin; inicio_lista <= base_list_end - list_to_compare_longitud; inicio_lista++) {
                //Punteros para recorrer y comparar las listas
                int *i = list_to_compare_begin;
                int *j = inicio_lista;
                //Compara los elementos de la lista a comparar con la sublista actual en la lista base
                while (i < list_to_compare_end && *i == *j) {
                    i++;
                    j++;
                }
                ///Si todos los elementos de la lista de comparación coinciden con una sublista en la lista base, se retorna SUBLIST
                if (i == list_to_compare_end) {
                    return SUBLIST;
                }
            }
        }

        //Si la longitud de la lista base es menor al tamaño de la lista a comparar, se verifica si es superlista de la lista base
        if (base_list_longitud < list_to_compare_longitud) {
            //El bucle itera a través de la lista de comparación para verificar si se trata de una superlista
            //La condición asegura que el puntero solo recorre hasta donde haya suficiente espacio en la lista a comparar
            for (int *inicio_lista = list_to_compare_begin; inicio_lista <= list_to_compare_end - base_list_longitud; inicio_lista++) {
                //Punteros para recorrer y comparar las listas
                int *c = base_list_begin;
                int *d = inicio_lista;
                //Compara los elementos de la lista base con la sublista actual a comparar
                while (c < base_list_end && *c == *d) {
                    c++;
                    d++;
                }
                //Si todos los elementos de la lista base cooinciden con una sublista en la lista de compararción, se retorna SUPERLIST
                if (c == base_list_end) {
                    return SUPERLIST;
                }
            }
        }
        
        //En caso que las listas no sean iguales, ni una sea sublista o superlista, se regresa que son distintas
        return UNEQUAL;

}