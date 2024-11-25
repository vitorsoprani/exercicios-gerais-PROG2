#include "esfera_utils.h"

/**
 * @brief Calcula o volume de uma esfera com raio R.
 * @param R O raio da esfera.
 * @return O volume da esfera.
 */
float calcula_volume(float R) {
    return (4.0 / 3.0) * (PI * R * R * R);
}

/**
 * @brief Calcula a área de superfície de uma esfera com raio R.
 * @param R O raio da esfera.
 * @return A área de superfície da esfera.
 */
float calcula_area(float R) {
    return 4 * PI * R * R;
}