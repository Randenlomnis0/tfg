from check_integrity import load_info
from settings import lan

def get_next(judg: str, lan: str) -> str:
    """
    Devuelve el siguiente problema que no ha sido resuelto aún en el lenguaje objetivo.

    Returns:
        str: Nombre del problema que no ha sido resuelto aún en el lenguaje objetivo.
    """
    # Cargamos la meta-información
    info = load_info()

    # Iteramos sobre los programas
    for judge, cat, problem, lang in info:
        # Comprobamos que el programa corresponda al juez objetivo
        if judge != judg:
            continue

        # Comprobamos que el lenguaje en que se ha escrito el programa sea correcto
        if lang != lan:
            continue

        # Comprobamos que el programa no esté resuelto ya
        if info[(judge, cat, problem, lang)] != 'NV':
            continue

        # Devolvemos el nombre del programa
        return problem
    
    # No se ha encontrado ningún programa que cumpla las condiciones
    return 'THERE IS NO NEXT PROBLEM'

def main():
    """
    Muestra por pantalla el siguiente problema que no ha sido resuelto aún en el lenguaje objetivo.
    """
    print(f'lan={lan} -> \033[1m{get_next('kat', lan)}\033[0m')

if __name__ == '__main__':
    main()
