package org.example;

import java.util.HashMap;
import java.util.Scanner;

public class Main {
    private static final HashMap<String, String> dictionary = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int option;

        do {
            System.out.println("\nDiccionario de Términos Técnicos");
            System.out.println("1. Agregar término");
            System.out.println("2. Buscar definición");
            System.out.println("3. Eliminar término");
            System.out.println("4. Salir");
            System.out.print("Seleccione una opción: ");
            option = scanner.nextInt();
            scanner.nextLine();

            switch (option) {
                case 1:
                    addTerm(scanner);
                    break;
                case 2:
                    searchDefinition(scanner);
                    break;
                case 3:
                    removeTerm(scanner);
                    break;
                case 4:
                    System.out.println("Saliendo del programa.");
                    break;
                default:
                    System.out.println("Opción inválida. Intente de nuevo.");
            }
        } while (option != 4);
    }

    private static void addTerm(Scanner scanner) {
        System.out.print("Ingrese el término: ");
        String term = scanner.nextLine().trim().toLowerCase();
        if (dictionary.containsKey(term)) {
            System.out.println("El término ya existe en el diccionario.");
        } else {
            System.out.print("Ingrese la definición: ");
            String definition = scanner.nextLine().trim();
            dictionary.put(term, definition);
            System.out.println("Término agregado: " +  term);
        }
    }

    private static void searchDefinition(Scanner scanner) {
        System.out.print("Ingrese el término a buscar: ");
        String term = scanner.nextLine().trim().toLowerCase();
        if (dictionary.containsKey(term)) {
            System.out.println("Definición: " + dictionary.get(term));
            System.out.println("Término encontrado: " + term);
        } else {
            System.out.println("El término no está en el diccionario");
        }
    }

    private static void removeTerm(Scanner scanner) {
        System.out.print("Ingrese el término a eliminar: ");
        String term = scanner.nextLine().trim().toLowerCase();
        if (dictionary.containsKey(term)) {
            dictionary.remove(term);
            System.out.println("Término eliminado: " + term);
        } else {
            System.out.println("El término no existe en el diccionario.");
        }
    }
}