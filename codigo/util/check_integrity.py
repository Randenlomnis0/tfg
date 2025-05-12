from vars import folder_soluciones, archivo_meta
from pathlib import Path
import json

def load_archivos():
    archivos = dict()

    for folder in folder_soluciones.iterdir():
        if not folder.is_dir():
            continue

        for file in folder.iterdir():
            extension = file.suffix[1:]

            if extension not in archivos:
                archivos[extension] = set()

            archivos[extension].add(file.stem)
    return archivos

def load_info():
    with open(archivo_meta, 'r') as f:
        data = json.load(f)

    info = dict()

    for juez in data:
        for problema in data[juez]:
            for lenguaje, veredicto in data[juez][problema]['res'].items():
                info[(juez, problema, lenguaje)] = veredicto
    return info

def main():
    archivos = load_archivos()
    info = load_info()
            
if __name__ == '__main__':
    main()