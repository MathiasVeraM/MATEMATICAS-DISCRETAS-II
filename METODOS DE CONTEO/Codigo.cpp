#include <iostream>
#include <string>
#include <cmath>
//Hecho por Brandon Arellano 
using namespace std;

// Función para convertir un número binario en formato IPv4 a decimal
unsigned int binarioADecimalIPv4(string binario) {
    unsigned int decimal = 0; // Variable para almacenar el resultado decimal
    int longitud = binario.length(); // Obtener la longitud del número binario

    for (int i = 0; i < longitud; ++i) { // Recorrer cada bit del número binario
        if (binario[i] == '1') { // Si el bit es '1'
            decimal += pow(2, longitud - 1 - i); // Agregar el valor correspondiente a la posición
        } else if (binario[i] != '0') { // Si el bit no es ni '0' ni '1', el número binario es inválido
            cout << "El número binario ingresado es inválido." << endl;
            return 0; // Devolver 0 indicando un error
        }
    }

    return decimal; // Devolver el valor decimal convertido
}

// Función para convertir un número binario en formato IPv6 a hexadecimal
string binarioAHexadecimalIPv6(string binario) {
    unsigned long long decimal = 0; // Variable para almacenar el resultado decimal
    int longitud = binario.length(); // Obtener la longitud del número binario

    for (int i = 0; i < longitud; ++i) { // Recorrer cada bit del número binario
        if (binario[i] == '1') { // Si el bit es '1'
            decimal += pow(2, longitud - 1 - i); // Agregar el valor correspondiente a la posición
        } else if (binario[i] != '0') { // Si el bit no es ni '0' ni '1', el número binario es inválido
            cout << "El número binario ingresado es inválido." << endl;
            return ""; // Devolver una cadena vacía indicando un error
        }
    }

    string hexadecimal = ""; // Variable para almacenar el resultado hexadecimal
    while (decimal > 0) { // Mientras haya un valor decimal para convertir
        int residuo = decimal % 16; // Obtener el residuo al dividir por 16
        char digitoHexadecimal;
        if (residuo < 10) { // Si el residuo es menor que 10, el dígito hexadecimal es el mismo
            digitoHexadecimal = residuo + '0';
        } else { // Si el residuo es mayor o igual a 10, se convierte a una letra hexadecimal
            digitoHexadecimal = residuo - 10 + 'A';
        }
        hexadecimal = digitoHexadecimal + hexadecimal; // Agregar el dígito al resultado
        decimal /= 16; // Dividir el valor decimal entre 16 para continuar con la siguiente posición
    }

    // Completar con ceros a la izquierda para asegurar que cada bloque sea de 4 dígitos hexadecimales
    while (hexadecimal.length() < 4) {
        hexadecimal = '0' + hexadecimal;
    }

    return hexadecimal; // Devolver el valor hexadecimal convertido
}

int main() {
    string binarioIPv4[4]; // Array para almacenar los cuatro octetos de una dirección IPv4 en formato binario
    string binarioIPv6 = ""; // Variable para almacenar una dirección IPv6 en formato binario

    cout << "Ingrese un número binario en formato IPv4 (1er Octeto): ";
    cin >> binarioIPv4[0]; // Leer el primer octeto
    cout << "Ingrese un número binario en formato IPv4 (2do Octeto): ";
    cin >> binarioIPv4[1]; // Leer el segundo octeto 
    cout << "Ingrese un número binario en formato IPv4 (3er Octeto): ";
    cin >> binarioIPv4[2]; // Leer el tercer octeto 
    cout << "Ingrese un número binario en formato IPv4 (4to Octeto): ";
    cin >> binarioIPv4[3]; // Leer el cuarto octeto 

    unsigned int decimalIPv4[4]; // Array para almacenar los cuatro octetos de una dirección IPv4 en formato decimal
    for (int i = 0; i < 4; ++i) { // Convertir cada octeto de binario a decimal
        decimalIPv4[i] = binarioADecimalIPv4(binarioIPv4[i]);
    }

    cout << "El número binario IPv4 ";
    for (int i = 0; i < 4; ++i) { // Mostrar la dirección IPv4 en formato binario
        cout << binarioIPv4[i];
        if (i < 3) {
            cout << ".";
        }
    }
    cout << " es equivalente a ";
    for (int i = 0; i < 4; ++i) { // Mostrar la dirección IPv4 en formato decimal
        cout << decimalIPv4[i];
        if (i < 3) {
            cout << ".";
        }
    }
    cout << " en decimal." << endl;
    
    // Bucle para ingresar gradualmente los 128 bits de una dirección IPv6
    for (int i = 0; i < 8; ++i) {
        cout << "Ingrese los 16 bits para el bloque " << (i + 1) << " de la dirección IPv6: ";
        string bloqueBinario;
        cin >> bloqueBinario;

        // Verificar si el bloque tiene exactamente 16 bits
        if (bloqueBinario.length() != 16) {
            cout << "El número binario ingresado no tiene 16 bits." << endl;
            return 1; // Salir del programa con código de error 1
        }

        // Concatenar el bloque binario al número binario IPv6
        binarioIPv6 += bloqueBinario;
    }

    // Convertir el número binario IPv6 a su equivalente hexadecimal
    string hexadecimalIPv6 = "";
    int inicio = 0;
    for (int i = 0; i < 8; ++i) {
        string bloqueBinario = binarioIPv6.substr(inicio, 16); // Obtener cada bloque de 16 bits
        string bloqueHexadecimal = binarioAHexadecimalIPv6(bloqueBinario); // Convertir a hexadecimal
        hexadecimalIPv6 += bloqueHexadecimal; // Agregar al resultado
        if (i < 7) {
            hexadecimalIPv6 += ":"; // Agregar el separador ':'
        }
        inicio += 16; // Mover al siguiente bloque
    }

    cout << "El número binario IPv6 ingresado es: " << binarioIPv6 << endl;
    cout << "Su equivalente hexadecimal es: " << hexadecimalIPv6 << endl;


    return 0;
}