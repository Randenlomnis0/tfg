from check_integrity import load_info

def load_stats() -> dict[str, dict[str, int]]:
    """
    Crea un diccionario con la frecuencia absoluta de cada veredicto por lenguaje.

    Returns:
        dict[str,dict[str,int]]: Un diccionario cuya clave es un lenguaje y cuyo valor
        es un diccionario cuya clave es un veredicto y cuyo valor es una frecuencia absoluta.
    """
    # Cargamos la meta-información
    info = load_info()

    stats = dict()

    # Iteramos sobre las entradas de la meta-información
    for (_, _, _, lan), veredict in info.items():
        # Si el lenguaje no está en el diccionario, lo añandimos
        if lan not in stats:
            stats[lan] = dict()

        # Si el veredicto no está en el diccionario del lenguaje, lo añadimos
        if veredict not in stats[lan]:
            stats[lan][veredict] = 0

        # Actualizamos la frecuencia absoluta del veredicto en el lenguaje
        stats[lan][veredict] += 1

    return stats

def print_stats(stats: dict[str, dict[str, int]]):
    """
    Muestra estadísticas por consola.
    """
    # Iteramos sobre los lenguajes
    for lan in stats:
        # Inicializamos el contador de veredictos totales
        lan_total = 0

        # Iteramos sobre los veredictos del lenguaje
        for _, cnt in stats[lan].items():
            lan_total += cnt

        # Creamos el str que contiene lo que se va a imprimir
        aux = f'{lan}\t->'

        # Añadimos la información sobre cada veredicto
        for veredict, cnt in stats[lan].items():
            aux += f'\t\033[1m{veredict}=\033[0m{cnt}(\033[1m{100 * cnt / lan_total:.2f}\033[0m%)'

        print(aux)

def main():
    """
    Muestra por consola las estadísticas correspondientes al JSON.
    """
    # Obtenemos las estadísticas
    stats = load_stats()

    # Imprimimos las estadísticas
    print_stats(stats)

if __name__ == '__main__':
    main()
