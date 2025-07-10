from check_integrity import load_info
from settings import lan
import random

def get_new(judg: str, lan: str) -> str:
    """
    Obtiene un problema no resuelto en el lenguaje definido de manera aleatoria.

    Returns:
        str: El nombre del problema que no se ha resuelto aún en el lenguaje indicado
        obtenido al azar.
    """
    # Cargamos la meta-información
    info = load_info()

    options = list()

    # Iteramos sobre los programas
    for judge, cat, problem, lang in info:
        # Comprobamos que el programa sea para el juez objetivo
        if judge != judg:
            continue

        # Comprobamos que el programa esté escrito en el lenguaje objetivo
        if lang != lan:
            continue

        # Comprobamos que el programa no esté resuelto aún
        if info[(judge, cat, problem, lang)] != 'NV':
            continue

        # Añadimos el programa a la lista de opciones
        options.append(problem)
        
    # Comprobamos que queden problemas sin resolver
    if len(options) == 0:
        return 'THERE ARE NO NEW PROBLEMS'
    
    # Devolvemos un problema al azar
    return random.choice(options)

def main():
    """
    Imprime por consola el nombre de un problema al azar que no haya
    sido resuelto aún en el lenguaje indicado.
    """
    print(f'lan={lan} -> \033[1m{get_new('kat', lan)}\033[0m')

if __name__ == '__main__':
    main()
