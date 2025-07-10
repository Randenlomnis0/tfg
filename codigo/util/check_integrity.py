from settings import folder_soluciones, archivo_meta
from pathlib import Path
import json

def load_archivos() -> dict[str, set[str]]:
    """
    Recorre las carpetas en la carpeta de soluciones y obtiene los nombres
    de los archivos clasificados por extensión.

    Returns:
        dict[str,set[str]]: Un diccionario en el que las llaves son extensiones
        de archivos (sin el '.') y los valores son los nombres que le corresponden.
    """
    archivos = dict()

    # Iteramos sobre las carpetas
    for folder in folder_soluciones.iterdir():
        # Nos aseguramos de que estamos en una carpeta
        if not folder.is_dir():
            continue

        # Iteramos sobre los archivos
        for file in folder.iterdir():
            # Obtenemos la extensión
            extension = file.suffix[1:]

            # Creamos la entrada correspondiente a la extensión si no existe ya
            if extension not in archivos:
                archivos[extension] = set()

            # Añadimos el nombre del archivo al conjunto correspondiente
            archivos[extension].add(file.stem)
    return archivos

def load_info() -> dict[tuple[str,str,str,str], str]:
    """
    Lee la meta-información que hay en el archivo correspondiente y la devuelve
    en un diccionario en el que la clave define el programa y el valor es su veredicto.

    Returns:
        dict[tuple[str,str,str,str],str]: Contiene el veredicto correspondiente a un
        programa definido según (juez, categoría, nombre, lenguaje).
    """
    # Cargamos la meta-información
    with open(archivo_meta, 'r') as f:
        data = json.load(f)

    info = dict()

    # Iteramos sobre los jueces
    for juez in data:
        # Iteramos sobre los problemas del juez
        for problema in data[juez]:
            # Iteramos sobre los programas del problema
            for lenguaje, veredicto in data[juez][problema]['res'].items():
                # Añadimos el programa al resultado
                info[(juez, data[juez][problema]['cat'], problema, lenguaje)] = veredicto
    return info
