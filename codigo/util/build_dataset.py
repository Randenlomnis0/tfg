import csv
import os
from pathlib import Path
import re
import statistics

from check_integrity import load_info
from settings import folder_soluciones

def load_data() -> list[list]:
    """
    Crea una lista cuyo primer elemento representa los nombres de las columnas de un csv, mientras que el
    resto de filas representan entradas de ese dataset.

    Returns:
        list[list]: Lista cuyo primer elemento representa los nombres de las columnas de un csv, mientras que
        el resto de filas representan entradas de ese dataset.
    """
    # Cargamos la meta-información
    all_data = load_info()

    selected_data = []

    # Iteramos sobre los programas
    for (plat, cat, name, lan), v in all_data.items():
        valid = True

        # Comprobamos que el problema haya sido resuelto en todos los lenguajes
        for l in ['cpp', 'py', 'java']:
            if all_data[(plat, cat, name, l)] == 'AC':
                continue

            valid = False

        # Si el problema no ha sido resuelto en todos los lenguajes, no lo incluimos
        if not valid:
            continue

        selected_data.append([plat, cat, name, lan])

    # Iteramos sobre los elementos del dataset, para añadir información
    for data in selected_data:
        file_name = Path(f"{data[2]}.{data[3]}")
        file_path = folder_soluciones / Path(plat) / file_name

        # Añadimos el tamaño en bytes
        data.append(os.path.getsize(file_path))
        
        with open(file_path, mode='r', encoding='utf-8') as file:
            content = file.read()

        # Añadimos el tamaño en caracteres
        data.append(len(content))

        # Añadimos el tamaño en caracteres, ignorando espacios en blanco
        data.append(len(re.sub(r'\s+', '', content)))

        # Añadimos el número de líneas
        data.append(content.count('\n'))

        tokens = content.split()

        # Añadimos el número de tokens
        data.append(len(tokens))

        # Añadimos la longitud media de los tokens
        data.append(sum(len(token) for token in tokens) / len(tokens))

        # Añadimos la desviación estándar de las longitudes de los tokens
        data.append(statistics.stdev(len(token) for token in tokens))

    # Definimos los nombres de las columnas
    fields = [['Platform', 'Category', 'Name', 'Language', 'Size', 'Characters', 'NonWhitespaceCharacters', 'Lines', 'Tokens', 'AverageTokenLength', 'SDTokenLength']]

    # Devolvemos los nombres de las columnas + las entradas obtenidas
    return fields + selected_data

def main():
    """
    Crea un archivo csv con la información sobre los programas que hay en el repositorio.
    """
    # Creamos el contenido del csv
    data = load_data()

    # Guardamos el contenido del csv
    with open('tfg.csv', mode='w', newline='', encoding='utf-8') as file:
        writer = csv.writer(file, quoting=csv.QUOTE_MINIMAL)
        writer.writerows(data)

if __name__ == '__main__':
    main()
